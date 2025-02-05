/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2012 Alexander Lunev <al.lunev@yahoo.com>
 * Copyright (C) 2012-2021 KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

/**
 * @file pcad_plugin.cpp
 * @brief Pcbnew PLUGIN for P-Cad 200x ASCII *.pcb format.
 */

#include <pcad/pcad_plugin.h>
#include <pcad/pcb.h>
#include <pcad/s_expr_loader.h>

#include <board.h>
#include <locale_io.h>

#include <cerrno>
#include <wx/string.h>
#include <wx/filename.h>
#include <wx/xml/xml.h>

using namespace PCAD2KICAD;


PCAD_PLUGIN::PCAD_PLUGIN()
{
    m_board = nullptr;
    m_props = nullptr;
}


PCAD_PLUGIN::~PCAD_PLUGIN()
{
}


const wxString PCAD_PLUGIN::PluginName() const
{
    return wxT( "P-Cad" );
}


const wxString PCAD_PLUGIN::GetFileExtension() const
{
    return wxT( "pcb" );
}


BOARD* PCAD_PLUGIN::Load( const wxString& aFileName, BOARD* aAppendToMe,
                          const STRING_UTF8_MAP* aProperties, PROJECT* aProject,
                          PROGRESS_REPORTER* aProgressReporter )
{
    wxXmlDocument   xmlDoc;

    m_props = aProperties;

    m_board = aAppendToMe ? aAppendToMe : new BOARD();

    // Give the filename to the board if it's new
    if( !aAppendToMe )
        m_board->SetFileName( aFileName );

    PCB pcb( m_board );

    LOCALE_IO toggle;    // toggles on, then off, the C locale.

    LoadInputFile( aFileName, &xmlDoc );
    pcb.ParseBoard( nullptr, &xmlDoc, wxT( "PCB" ) );
    pcb.AddToBoard();

    return m_board;
}
