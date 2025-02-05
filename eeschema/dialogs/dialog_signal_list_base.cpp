///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "dialog_signal_list_base.h"

///////////////////////////////////////////////////////////////////////////

DIALOG_SIGNAL_LIST_BASE::DIALOG_SIGNAL_LIST_BASE( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : DIALOG_SHIM( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	m_signals = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_EXTENDED|wxLB_NEEDED_SB|wxLB_SORT );
	m_signals->SetMinSize( wxSize( 450,400 ) );

	bSizer6->Add( m_signals, 1, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 10 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Add signal by name:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer2->Add( m_staticText1, 0, wxTOP|wxRIGHT|wxLEFT, 5 );

	m_signalEntry = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer2->Add( m_signalEntry, 0, wxALL|wxEXPAND, 5 );


	bSizer6->Add( bSizer2, 0, wxEXPAND|wxTOP|wxRIGHT|wxLEFT, 5 );

	m_sdbSizer = new wxStdDialogButtonSizer();
	m_sdbSizerOK = new wxButton( this, wxID_OK );
	m_sdbSizer->AddButton( m_sdbSizerOK );
	m_sdbSizerCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer->AddButton( m_sdbSizerCancel );
	m_sdbSizer->Realize();

	bSizer6->Add( m_sdbSizer, 0, wxEXPAND|wxALL, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();
	bSizer6->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_signals->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( DIALOG_SIGNAL_LIST_BASE::onSignalAdd ), NULL, this );
	m_signalEntry->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( DIALOG_SIGNAL_LIST_BASE::onSignalAdd ), NULL, this );
}

DIALOG_SIGNAL_LIST_BASE::~DIALOG_SIGNAL_LIST_BASE()
{
	// Disconnect Events
	m_signals->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( DIALOG_SIGNAL_LIST_BASE::onSignalAdd ), NULL, this );
	m_signalEntry->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( DIALOG_SIGNAL_LIST_BASE::onSignalAdd ), NULL, this );

}
