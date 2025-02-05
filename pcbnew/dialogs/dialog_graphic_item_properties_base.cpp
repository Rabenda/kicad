///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "pcb_layer_box_selector.h"

#include "dialog_graphic_item_properties_base.h"

///////////////////////////////////////////////////////////////////////////

DIALOG_GRAPHIC_ITEM_PROPERTIES_BASE::DIALOG_GRAPHIC_ITEM_PROPERTIES_BASE( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : DIALOG_SHIM( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );

	wxBoxSizer* bMainSizer;
	bMainSizer = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bUpperSizer;
	bUpperSizer = new wxBoxSizer( wxVERTICAL );

	m_sizerLeft = new wxGridBagSizer( 5, 3 );
	m_sizerLeft->SetFlexibleDirection( wxBOTH );
	m_sizerLeft->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	m_sizerLeft->SetEmptyCellSize( wxSize( 5,5 ) );

	m_startPointLabel = new wxStaticText( this, wxID_ANY, _("Start Point"), wxDefaultPosition, wxDefaultSize, 0 );
	m_startPointLabel->Wrap( -1 );
	m_sizerLeft->Add( m_startPointLabel, wxGBPosition( 0, 0 ), wxGBSpan( 1, 3 ), wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	m_startXLabel = new wxStaticText( this, wxID_ANY, _("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_startXLabel->Wrap( -1 );
	m_sizerLeft->Add( m_startXLabel, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

	m_startXCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sizerLeft->Add( m_startXCtrl, wxGBPosition( 1, 1 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL, 5 );

	m_startXUnits = new wxStaticText( this, wxID_ANY, _("unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_startXUnits->Wrap( -1 );
	m_sizerLeft->Add( m_startXUnits, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxRIGHT, 15 );

	m_startYLabel = new wxStaticText( this, wxID_ANY, _("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_startYLabel->Wrap( -1 );
	m_sizerLeft->Add( m_startYLabel, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

	m_startYCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sizerLeft->Add( m_startYCtrl, wxGBPosition( 2, 1 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL, 5 );

	m_startYUnits = new wxStaticText( this, wxID_ANY, _("unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_startYUnits->Wrap( -1 );
	m_sizerLeft->Add( m_startYUnits, wxGBPosition( 2, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxRIGHT, 15 );

	m_endPointLabel = new wxStaticText( this, wxID_ANY, _("End Point"), wxDefaultPosition, wxDefaultSize, 0 );
	m_endPointLabel->Wrap( -1 );
	m_sizerLeft->Add( m_endPointLabel, wxGBPosition( 0, 3 ), wxGBSpan( 1, 3 ), wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	m_endXLabel = new wxStaticText( this, wxID_ANY, _("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_endXLabel->Wrap( -1 );
	m_sizerLeft->Add( m_endXLabel, wxGBPosition( 1, 3 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

	m_endXCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sizerLeft->Add( m_endXCtrl, wxGBPosition( 1, 4 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL, 5 );

	m_endXUnits = new wxStaticText( this, wxID_ANY, _("unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_endXUnits->Wrap( -1 );
	m_sizerLeft->Add( m_endXUnits, wxGBPosition( 1, 5 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );

	m_endYLabel = new wxStaticText( this, wxID_ANY, _("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_endYLabel->Wrap( -1 );
	m_sizerLeft->Add( m_endYLabel, wxGBPosition( 2, 3 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

	m_endYCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sizerLeft->Add( m_endYCtrl, wxGBPosition( 2, 4 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL, 5 );

	m_endYUnits = new wxStaticText( this, wxID_ANY, _("unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_endYUnits->Wrap( -1 );
	m_sizerLeft->Add( m_endYUnits, wxGBPosition( 2, 5 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );

	m_bezierCtrlPt1Label = new wxStaticText( this, wxID_ANY, _("Bezier Control Pt"), wxDefaultPosition, wxDefaultSize, 0 );
	m_bezierCtrlPt1Label->Wrap( -1 );
	m_sizerLeft->Add( m_bezierCtrlPt1Label, wxGBPosition( 4, 0 ), wxGBSpan( 1, 3 ), wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );

	m_BezierPointC1XLabel = new wxStaticText( this, wxID_ANY, _("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_BezierPointC1XLabel->Wrap( -1 );
	m_sizerLeft->Add( m_BezierPointC1XLabel, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

	m_BezierC1X_Ctrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sizerLeft->Add( m_BezierC1X_Ctrl, wxGBPosition( 5, 1 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL, 5 );

	m_BezierPointC1XUnit = new wxStaticText( this, wxID_ANY, _("unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_BezierPointC1XUnit->Wrap( -1 );
	m_sizerLeft->Add( m_BezierPointC1XUnit, wxGBPosition( 5, 2 ), wxGBSpan( 1, 1 ), wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );

	m_BezierPointC1YLabel = new wxStaticText( this, wxID_ANY, _("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_BezierPointC1YLabel->Wrap( -1 );
	m_sizerLeft->Add( m_BezierPointC1YLabel, wxGBPosition( 6, 0 ), wxGBSpan( 1, 1 ), wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );

	m_BezierC1Y_Ctrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sizerLeft->Add( m_BezierC1Y_Ctrl, wxGBPosition( 6, 1 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL, 5 );

	m_BezierPointC1YUnit = new wxStaticText( this, wxID_ANY, _("unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_BezierPointC1YUnit->Wrap( -1 );
	m_sizerLeft->Add( m_BezierPointC1YUnit, wxGBPosition( 6, 2 ), wxGBSpan( 1, 1 ), wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );

	m_bezierCtrlPt2Label = new wxStaticText( this, wxID_ANY, _("Bezier Control Pt"), wxDefaultPosition, wxDefaultSize, 0 );
	m_bezierCtrlPt2Label->Wrap( -1 );
	m_sizerLeft->Add( m_bezierCtrlPt2Label, wxGBPosition( 4, 3 ), wxGBSpan( 1, 3 ), wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );

	m_BezierPointC2XLabel = new wxStaticText( this, wxID_ANY, _("X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_BezierPointC2XLabel->Wrap( -1 );
	m_sizerLeft->Add( m_BezierPointC2XLabel, wxGBPosition( 5, 3 ), wxGBSpan( 1, 1 ), wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );

	m_BezierC2X_Ctrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sizerLeft->Add( m_BezierC2X_Ctrl, wxGBPosition( 5, 4 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL, 5 );

	m_BezierPointC2XUnit = new wxStaticText( this, wxID_ANY, _("unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_BezierPointC2XUnit->Wrap( -1 );
	m_sizerLeft->Add( m_BezierPointC2XUnit, wxGBPosition( 5, 5 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxRIGHT, 5 );

	m_BezierPointC2YLabel = new wxStaticText( this, wxID_ANY, _("Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_BezierPointC2YLabel->Wrap( -1 );
	m_sizerLeft->Add( m_BezierPointC2YLabel, wxGBPosition( 6, 3 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxLEFT, 5 );

	m_BezierC2Y_Ctrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sizerLeft->Add( m_BezierC2Y_Ctrl, wxGBPosition( 6, 4 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL, 5 );

	m_BezierPointC2YUnit = new wxStaticText( this, wxID_ANY, _("unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_BezierPointC2YUnit->Wrap( -1 );
	m_sizerLeft->Add( m_BezierPointC2YUnit, wxGBPosition( 6, 5 ), wxGBSpan( 1, 1 ), wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );


	bUpperSizer->Add( m_sizerLeft, 0, wxEXPAND, 20 );

	wxBoxSizer* bMiddleSizer;
	bMiddleSizer = new wxBoxSizer( wxVERTICAL );

	wxGridBagSizer* gbSizer2;
	gbSizer2 = new wxGridBagSizer( 5, 0 );
	gbSizer2->SetFlexibleDirection( wxBOTH );
	gbSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_angleLabel = new wxStaticText( this, wxID_ANY, _("Arc angle:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_angleLabel->Wrap( -1 );
	gbSizer2->Add( m_angleLabel, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_angleCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_angleCtrl, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxEXPAND|wxTOP|wxBOTTOM, 5 );

	m_angleUnits = new wxStaticText( this, wxID_ANY, _("deg"), wxDefaultPosition, wxDefaultSize, 0 );
	m_angleUnits->Wrap( -1 );
	gbSizer2->Add( m_angleUnits, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_locked = new wxCheckBox( this, wxID_ANY, _("Locked"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_locked, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxRIGHT|wxLEFT, 5 );

	m_filledCtrl = new wxCheckBox( this, wxID_ANY, _("Filled shape"), wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_filledCtrl, wxGBPosition( 2, 0 ), wxGBSpan( 1, 2 ), wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	m_thicknessLabel = new wxStaticText( this, wxID_ANY, _("Line width:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_thicknessLabel->Wrap( -1 );
	gbSizer2->Add( m_thicknessLabel, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	m_thicknessCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer2->Add( m_thicknessCtrl, wxGBPosition( 3, 1 ), wxGBSpan( 1, 1 ), wxEXPAND|wxALIGN_CENTER_VERTICAL|wxTOP, 5 );

	m_thicknessUnits = new wxStaticText( this, wxID_ANY, _("unit"), wxDefaultPosition, wxDefaultSize, 0 );
	m_thicknessUnits->Wrap( -1 );
	gbSizer2->Add( m_thicknessUnits, wxGBPosition( 3, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );

	m_lineStyleLabel = new wxStaticText( this, wxID_ANY, _("Line style:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lineStyleLabel->Wrap( -1 );
	gbSizer2->Add( m_lineStyleLabel, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );

	m_lineStyleCombo = new wxBitmapComboBox( this, wxID_ANY, _("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY );
	m_lineStyleCombo->SetMinSize( wxSize( 210,-1 ) );

	gbSizer2->Add( m_lineStyleCombo, wxGBPosition( 4, 1 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxEXPAND, 5 );

	m_LayerLabel = new wxStaticText( this, wxID_ANY, _("Layer:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_LayerLabel->Wrap( -1 );
	gbSizer2->Add( m_LayerLabel, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT, 5 );

	m_LayerSelectionCtrl = new PCB_LAYER_BOX_SELECTOR( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	gbSizer2->Add( m_LayerSelectionCtrl, wxGBPosition( 5, 1 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );


	gbSizer2->AddGrowableCol( 1 );

	bMiddleSizer->Add( gbSizer2, 1, wxEXPAND|wxTOP|wxBOTTOM, 5 );


	bUpperSizer->Add( bMiddleSizer, 0, wxBOTTOM|wxEXPAND, 5 );


	bMainSizer->Add( bUpperSizer, 1, wxEXPAND|wxALL, 5 );

	m_StandardButtonsSizer = new wxStdDialogButtonSizer();
	m_StandardButtonsSizerOK = new wxButton( this, wxID_OK );
	m_StandardButtonsSizer->AddButton( m_StandardButtonsSizerOK );
	m_StandardButtonsSizerCancel = new wxButton( this, wxID_CANCEL );
	m_StandardButtonsSizer->AddButton( m_StandardButtonsSizerCancel );
	m_StandardButtonsSizer->Realize();

	bMainSizer->Add( m_StandardButtonsSizer, 0, wxALL|wxEXPAND, 5 );


	this->SetSizer( bMainSizer );
	this->Layout();
	bMainSizer->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DIALOG_GRAPHIC_ITEM_PROPERTIES_BASE::OnClose ) );
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( DIALOG_GRAPHIC_ITEM_PROPERTIES_BASE::OnInitDlg ) );
	m_filledCtrl->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_GRAPHIC_ITEM_PROPERTIES_BASE::onFilledCheckbox ), NULL, this );
}

DIALOG_GRAPHIC_ITEM_PROPERTIES_BASE::~DIALOG_GRAPHIC_ITEM_PROPERTIES_BASE()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DIALOG_GRAPHIC_ITEM_PROPERTIES_BASE::OnClose ) );
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( DIALOG_GRAPHIC_ITEM_PROPERTIES_BASE::OnInitDlg ) );
	m_filledCtrl->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( DIALOG_GRAPHIC_ITEM_PROPERTIES_BASE::onFilledCheckbox ), NULL, this );

}
