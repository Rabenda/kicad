///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include "dialog_shim.h"
#include <wx/string.h>
#include <wx/listbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/grid.h>
#include <wx/radiobox.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class DIALOG_CONFIG_EQUFILES_BASE
///////////////////////////////////////////////////////////////////////////////
class DIALOG_CONFIG_EQUFILES_BASE : public DIALOG_SHIM
{
	private:

	protected:
		enum
		{
			ID_ADD_EQU = 1000,
			ID_REMOVE_EQU,
			ID_EQU_UP,
			ID_EQU_DOWN
		};

		wxListBox* m_ListEquiv;
		wxButton* m_buttonAddEqu;
		wxButton* m_buttonRemoveEqu;
		wxButton* m_buttonMoveUp;
		wxButton* m_buttonMoveDown;
		wxButton* m_buttonEdit;
		wxStaticText* m_staticText2;
		wxGrid* m_gridEnvVars;
		wxRadioBox* m_rbPathOptionChoice;
		wxStdDialogButtonSizer* m_sdbSizer;
		wxButton* m_sdbSizerOK;
		wxButton* m_sdbSizerCancel;

		// Virtual event handlers, override them in your derived class
		virtual void OnCloseWindow( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnAddFiles( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveFiles( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonMoveUp( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonMoveDown( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditEquFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOkClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		DIALOG_CONFIG_EQUFILES_BASE( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );

		~DIALOG_CONFIG_EQUFILES_BASE();

};

