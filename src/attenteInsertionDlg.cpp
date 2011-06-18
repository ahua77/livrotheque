///-----------------------------------------------------------------
///
/// @file      attenteInsertionDlg.cpp
/// @author    cubbiste
/// Created:   16/06/2011 22:45:26
/// @section   DESCRIPTION
///            attenteInsertionDlg class implementation
///
///------------------------------------------------------------------

#include "attenteInsertionDlg.h"

#include "attenteInsertion.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// attenteInsertionDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(attenteInsertionDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(attenteInsertionDlg::OnClose)
END_EVENT_TABLE()
////Event Table End

attenteInsertionDlg::attenteInsertionDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

attenteInsertionDlg::~attenteInsertionDlg()
{
} 

void attenteInsertionDlg::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxBoxSizer1 = new wxBoxSizer(wxVERTICAL);
	this->SetSizer(WxBoxSizer1);
	this->SetAutoLayout(true);

	WxFlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	WxBoxSizer1->Add(WxFlexGridSizer1, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, wxT("isbn"), wxPoint(29, 5), wxDefaultSize, 0, wxT("WxStaticText1"));
	WxFlexGridSizer1->Add(WxStaticText1,0,wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL,5);

	m_ET_isbn = new wxTextCtrl(this, ID_WX_ET_ISBN, wxT("m_ET_isbn"), wxPoint(229, 5), wxSize(121, 19), 0, wxDefaultValidator, wxT("m_ET_isbn"));
	WxFlexGridSizer1->Add(m_ET_isbn,0,wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL | wxALL,5);

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, wxT("titre"), wxPoint(30, 34), wxDefaultSize, 0, wxT("WxStaticText2"));
	WxFlexGridSizer1->Add(WxStaticText2,0,wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL,5);

	m_ET_titre = new wxTextCtrl(this, ID_WX_ET_TITRE, wxT("m_ET_titre"), wxPoint(90, 34), wxSize(400, 19), 0, wxDefaultValidator, wxT("m_ET_titre"));
	WxFlexGridSizer1->Add(m_ET_titre,0,wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL | wxALL,5);

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, wxT("auteur"), wxPoint(23, 63), wxDefaultSize, 0, wxT("WxStaticText3"));
	WxFlexGridSizer1->Add(WxStaticText3,0,wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL,5);

	m_ET_auteur = new wxTextCtrl(this, ID_WX_ET_AUTEUR, wxT("m_ET_auteur"), wxPoint(90, 63), wxSize(400, 19), 0, wxDefaultValidator, wxT("m_ET_auteur"));
	WxFlexGridSizer1->Add(m_ET_auteur,0,wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL | wxALL,5);

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, wxT("commentaire"), wxPoint(5, 92), wxDefaultSize, 0, wxT("WxStaticText4"));
	WxFlexGridSizer1->Add(WxStaticText4,0,wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL | wxALL,5);

	m_ET_commentaire = new wxTextCtrl(this, ID_WX_ET_COMMENTAIRE, wxT("m_ET_commentaire"), wxPoint(90, 92), wxSize(400, 19), 0, wxDefaultValidator, wxT("m_ET_commentaire"));
	WxFlexGridSizer1->Add(m_ET_commentaire,0,wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL | wxALL,5);

	WxStdDialogButtonSizer1 = new wxStdDialogButtonSizer;
	btnOK = new wxButton( this, wxID_OK );
	WxStdDialogButtonSizer1->AddButton( btnOK );
	btnCANCEL = new wxButton( this, wxID_CANCEL );
	WxStdDialogButtonSizer1->AddButton( btnCANCEL );
	WxStdDialogButtonSizer1->Realize();
	WxBoxSizer1->Add(WxStdDialogButtonSizer1, 0, wxALIGN_CENTER | wxALL, 5);

	SetTitle(wxT("livre en attente d'insertion"));
	SetIcon(wxNullIcon);
	
	GetSizer()->Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
}

void attenteInsertionDlg::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

void attenteInsertionDlg::initDialog(attenteInsertion* item)
{
    if (!item)
        return;
    
    m_ET_isbn->SetValue(item->isbn());
    m_ET_titre->SetValue(item->titre());
    m_ET_auteur->SetValue(item->auteur());
    m_ET_commentaire->SetValue(item->commentaire());
}

void attenteInsertionDlg::updateItem(attenteInsertion* item)
{
    if (!item)
        return;

    item->isbn(m_ET_isbn->GetValue());
    item->titre(m_ET_titre->GetValue());
    item->auteur(m_ET_auteur->GetValue());
    item->commentaire(m_ET_commentaire->GetValue());
}
