/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2020-2023 KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <confirm.h>
#include <sch_edit_frame.h>
#include <schematic.h>
#include <kiface_base.h>
#include <dialog_sch_import_settings.h>
#include <dialogs/panel_setup_netclasses.h>
#include <dialogs/panel_setup_severities.h>
#include <dialogs/panel_setup_buses.h>
#include <panel_setup_formatting.h>
#include <panel_setup_pinmap.h>
#include <erc_item.h>
#include <panel_text_variables.h>
#include <project/project_file.h>
#include <project/net_settings.h>
#include <settings/settings_manager.h>
#include "dialog_schematic_setup.h"
#include "panel_template_fieldnames.h"


DIALOG_SCHEMATIC_SETUP::DIALOG_SCHEMATIC_SETUP( SCH_EDIT_FRAME* aFrame ) :
        PAGED_DIALOG( aFrame, _( "Schematic Setup" ), true,
                      _( "Import Settings from Another Project..." ), wxSize( 920, 460 ) ),
        m_frame( aFrame )
{
    SetEvtHandlerEnabled( false );

    m_pinToPinError = ERC_ITEM::Create( ERCE_PIN_TO_PIN_WARNING );

    /*
     * WARNING: If you change page names you MUST update calls to ShowSchematicSetupDialog().
     */

    m_treebook->AddPage( new wxPanel( GetTreebook() ), _( "General" ) );

    m_formattingPage = m_treebook->GetPageCount();
    m_treebook->AddLazySubPage(
            [this]( wxWindow* aParent ) -> wxWindow*
            {
                return new PANEL_SETUP_FORMATTING( aParent, m_frame );
            }, _( "Formatting" ) );

    m_fieldNameTemplatesPage = m_treebook->GetPageCount();
    m_treebook->AddLazySubPage(
            [this]( wxWindow* aParent ) -> wxWindow*
            {
                SCHEMATIC_SETTINGS& settings = m_frame->Schematic().Settings();
                return new PANEL_TEMPLATE_FIELDNAMES( aParent, &settings.m_TemplateFieldNames );
            }, _( "Field Name Templates" ) );

    m_treebook->AddPage( new wxPanel( GetTreebook() ), _( "Electrical Rules" ) );

    m_severitiesPage = m_treebook->GetPageCount();
    m_treebook->AddLazySubPage(
            [this]( wxWindow* aParent ) -> wxWindow*
            {
                ERC_SETTINGS& ercSettings = m_frame->Schematic().ErcSettings();
                return new PANEL_SETUP_SEVERITIES( aParent, ERC_ITEM::GetItemsWithSeverities(),
                                                   ercSettings.m_ERCSeverities,
                                                   m_pinToPinError.get() );
            }, _( "Violation Severity" ) );

    m_pinMapPage = m_treebook->GetPageCount();
    m_treebook->AddLazySubPage(
            [this]( wxWindow* aParent ) -> wxWindow*
            {
                return new PANEL_SETUP_PINMAP( aParent, m_frame );
            }, _( "Pin Conflicts Map" ) );

    m_treebook->AddPage( new wxPanel( GetTreebook() ), _( "Project" ) );

    m_netclassesPage = m_treebook->GetPageCount();
    m_treebook->AddLazySubPage(
            [this]( wxWindow* aParent ) -> wxWindow*
            {
                SCHEMATIC& schematic = m_frame->Schematic();
                return new PANEL_SETUP_NETCLASSES( aParent, m_frame,
                                                   m_frame->Prj().GetProjectFile().NetSettings(),
                                                   schematic.GetNetClassAssignmentCandidates(),
                                                   true );
            }, _( "Net Classes" ) );

    m_busesPage = m_treebook->GetPageCount();
    m_treebook->AddLazySubPage(
            [this]( wxWindow* aParent ) -> wxWindow*
            {
                return new PANEL_SETUP_BUSES( aParent, m_frame );
            }, _( "Bus Alias Definitions" ) );

    m_treebook->AddLazySubPage(
            [this]( wxWindow* aParent ) -> wxWindow*
            {
                return new PANEL_TEXT_VARIABLES( aParent, &Prj() );
            }, _( "Text Variables" ) );

    for( size_t i = 0; i < m_treebook->GetPageCount(); ++i )
        m_treebook->ExpandNode( i );

    SetEvtHandlerEnabled( true );

    finishDialogSettings();

    if( Prj().IsReadOnly() )
    {
        m_infoBar->ShowMessage( _( "Project is missing or read-only. Settings will not be "
                                   "editable." ), wxICON_WARNING );
    }

    wxBookCtrlEvent evt( wxEVT_TREEBOOK_PAGE_CHANGED, wxID_ANY, 0 );

    wxQueueEvent( m_treebook, evt.Clone() );
}


DIALOG_SCHEMATIC_SETUP::~DIALOG_SCHEMATIC_SETUP()
{
}


void DIALOG_SCHEMATIC_SETUP::onPageChanged( wxBookCtrlEvent& aEvent )
{
    PAGED_DIALOG::onPageChanged( aEvent );

    int page = aEvent.GetSelection();

    if( Prj().IsReadOnly() )
        KIUI::Disable( m_treebook->GetPage( page ) );
}


void DIALOG_SCHEMATIC_SETUP::onAuxiliaryAction( wxCommandEvent& event )
{
    DIALOG_SCH_IMPORT_SETTINGS importDlg( this, m_frame );

    if( importDlg.ShowModal() == wxID_CANCEL )
        return;

    wxFileName projectFn( importDlg.GetFilePath() );

    if( !m_frame->GetSettingsManager()->LoadProject( projectFn.GetFullPath(), false ) )
    {
        wxString msg = wxString::Format( _( "Error importing settings from project:\n"
                                            "Project file %s could not be loaded." ),
                                         projectFn.GetFullPath() );
        DisplayErrorMessage( this, msg );

        return;
    }

    PROJECT*      otherPrj = m_frame->GetSettingsManager()->GetProject( projectFn.GetFullPath() );
    SCHEMATIC     otherSch( otherPrj );
    PROJECT_FILE& file = otherPrj->GetProjectFile();

    wxASSERT( file.m_SchematicSettings );

    file.m_SchematicSettings->LoadFromFile();

    if( importDlg.m_FormattingOpt->GetValue() )
    {
        static_cast<PANEL_SETUP_FORMATTING*>( m_treebook->ResolvePage( m_formattingPage ) )
                ->ImportSettingsFrom( *file.m_SchematicSettings );
    }

    if( importDlg.m_FieldNameTemplatesOpt->GetValue() )
    {
        static_cast<PANEL_TEMPLATE_FIELDNAMES*>( m_treebook->ResolvePage( m_fieldNameTemplatesPage ) )
                ->ImportSettingsFrom( &otherSch.Settings().m_TemplateFieldNames );
    }

    if( importDlg.m_PinMapOpt->GetValue() )
    {
        static_cast<PANEL_SETUP_PINMAP*>( m_treebook->ResolvePage( m_pinMapPage ) )
                ->ImportSettingsFrom( file.m_ErcSettings->m_PinMap );
    }

    if( importDlg.m_SeveritiesOpt->GetValue() )
    {
        static_cast<PANEL_SETUP_SEVERITIES*>( m_treebook->ResolvePage( m_severitiesPage ) )
                ->ImportSettingsFrom( file.m_ErcSettings->m_ERCSeverities );
    }

    if( importDlg.m_NetClassesOpt->GetValue() )
    {
        static_cast<PANEL_SETUP_NETCLASSES*>( m_treebook->ResolvePage( m_netclassesPage ) )
                ->ImportSettingsFrom( file.m_NetSettings );
    }

    m_frame->GetSettingsManager()->UnloadProject( otherPrj, false );
}
