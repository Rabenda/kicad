/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2022 KiCad Developers, see AUTHORS.TXT for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one at
 * http://www.gnu.org/licenses/
 */

#include <schematic_file_util.h>

#include <settings/settings_manager.h>

#include <connection_graph.h>
#include <lib_textbox.h>
#include <schematic.h>
#include <sch_screen.h>

// For SCH parsing
#include <sch_plugins/kicad/sch_sexpr_plugin.h>
#include <sch_plugins/kicad/sch_sexpr_parser.h>
#include <richio.h>

#include <qa_utils/stdstream_line_reader.h>

namespace KI_TEST
{

#ifndef QA_EESCHEMA_DATA_LOCATION
    #define QA_EESCHEMA_DATA_LOCATION "???"
#endif

std::string getEeschemaTestDataDir()
{
    const char* env = std::getenv( "KICAD_TEST_EESCHEMA_DATA_DIR" );
    std::string fn;

    if( !env )
    {
        // Use the compiled-in location of the data dir (i.e. where the files were at build time)
        fn = QA_EESCHEMA_DATA_LOCATION;
    }
    else
    {
        // Use whatever was given in the env var
        fn = env;
    }

    // Ensure the string ends in / to force a directory interpretation
    fn += "/";

    return fn;
}


void DumpSchematicToFile( SCHEMATIC& aSchematic, SCH_SHEET& aSheet, const std::string& aFilename )
{
    SCH_SEXPR_PLUGIN io;
    io.Save( aFilename, &aSheet, &aSchematic );
}

void LoadSheetSchematicContents( const std::string& fileName, SCH_SHEET* sheet )
{
    std::ifstream fileStream;
    fileStream.open( fileName );
    wxASSERT( fileStream.is_open() );
    STDISTREAM_LINE_READER reader;
    reader.SetStream( fileStream );
    SCH_SEXPR_PARSER parser( &reader );
    parser.ParseSchematic( sheet );
}

void LoadHierarchy( SCHEMATIC* schematic, SCH_SHEET* sheet, const std::string& sheetFilename,
                    std::unordered_map<std::string, SCH_SCREEN*>& parsedScreens )
{
    SCH_SCREEN* screen = nullptr;

    if( !sheet->GetScreen() )
    {
        // Construct paths
        const wxFileName  fileName( sheetFilename );
        const std::string filePath( fileName.GetPath( wxPATH_GET_VOLUME | wxPATH_GET_SEPARATOR ) );
        const std::string fileBareName( fileName.GetFullName() );

        // Check for existing screen
        auto screenFound = parsedScreens.find( fileBareName );
        if( screenFound != parsedScreens.end() )
            screen = screenFound->second;

        // Configure sheet with existing screen, or load screen
        if( screen )
        {
            // Screen already loaded - assign to sheet
            sheet->SetScreen( screen );
            sheet->GetScreen()->SetParent( schematic );
        }
        else
        {
            // Load screen and assign to sheet
            screen = new SCH_SCREEN( schematic );
            parsedScreens.insert( { fileBareName, screen } );
            sheet->SetScreen( screen );
            sheet->GetScreen()->SetFileName( sheetFilename );
            LoadSheetSchematicContents( sheetFilename, sheet );
        }

        // Recurse through child sheets
        for( SCH_ITEM* item : sheet->GetScreen()->Items().OfType( SCH_SHEET_T ) )
        {
            SCH_SHEET* childSheet = static_cast<SCH_SHEET*>( item );
            wxFileName childSheetFilename = childSheet->GetFileName();
            if( !childSheetFilename.IsAbsolute() )
                childSheetFilename.MakeAbsolute( filePath );
            std::string childSheetFullFilename( childSheetFilename.GetFullPath() );
            LoadHierarchy( schematic, childSheet, childSheetFullFilename, parsedScreens );
        }
    }
}

std::unique_ptr<SCHEMATIC> LoadHierarchyFromRoot( const std::string& rootFilename,
                                                  PROJECT*           project )
{
    std::unique_ptr<SCHEMATIC>                   schematic( new SCHEMATIC( nullptr ) );
    std::unordered_map<std::string, SCH_SCREEN*> parsedScreens;

    schematic->SetProject( project );
    SCH_SHEET* rootSheet = new SCH_SHEET( schematic.get() );
    schematic->SetRoot( rootSheet );
    LoadHierarchy( schematic.get(), rootSheet, rootFilename, parsedScreens );

    return schematic;
}


void LoadSchematic( SETTINGS_MANAGER& aSettingsManager, const wxString& aRelPath,
                    std::unique_ptr<SCHEMATIC>& aSchematic )
{
    if( aSchematic )
    {
        PROJECT* prj = &aSchematic->Prj();

        aSchematic->SetProject( nullptr );
        aSettingsManager.UnloadProject( prj, false );
        aSchematic->Reset();
    }

    std::string absPath = getEeschemaTestDataDir() + aRelPath.ToStdString();
    wxFileName  projectFile( absPath + ".kicad_pro" );
    wxFileName  legacyProject( absPath + ".pro" );
    std::string schematicPath = absPath + ".kicad_sch";

    if( projectFile.Exists() )
        aSettingsManager.LoadProject( projectFile.GetFullPath() );
    else if( legacyProject.Exists() )
        aSettingsManager.LoadProject( legacyProject.GetFullPath() );
    else
        aSettingsManager.LoadProject( "" );

    aSettingsManager.Prj().SetElem( PROJECT::ELEM_SCH_SYMBOL_LIBS, nullptr );

    aSchematic = LoadHierarchyFromRoot( schematicPath, &aSettingsManager.Prj() );

    aSchematic->CurrentSheet().push_back( &aSchematic->Root() );

    SCH_SCREENS screens( aSchematic->Root() );

    for( SCH_SCREEN* screen = screens.GetFirst(); screen; screen = screens.GetNext() )
        screen->UpdateLocalLibSymbolLinks();

    SCH_SHEET_LIST sheets = aSchematic->GetSheets();

    // Restore all of the loaded symbol instances from the root sheet screen.
    sheets.UpdateSymbolInstanceData( aSchematic->RootScreen()->GetSymbolInstances() );
    sheets.UpdateSheetInstanceData( aSchematic->RootScreen()->GetSheetInstances() );

    if( aSchematic->RootScreen()->GetFileFormatVersionAtLoad() < 20221206 )
    {
        for( SCH_SCREEN* screen = screens.GetFirst(); screen; screen = screens.GetNext() )
            screen->MigrateSimModels();
    }

   sheets.AnnotatePowerSymbols();

   // NOTE: This is required for multi-unit symbols to be correct
   // Normally called from SCH_EDIT_FRAME::FixupJunctions() but could be refactored
   for( SCH_SHEET_PATH& sheet : sheets )
       sheet.UpdateAllScreenReferences();

   // NOTE: SchematicCleanUp is not called; QA schematics must already be clean or else
   // SchematicCleanUp must be freed from its UI dependencies.

   aSchematic->ConnectionGraph()->Recalculate( sheets, true );
}

} // namespace KI_TEST
