///-----------------------------------------------------------------
///
/// @file      VersionDlg.cpp
/// @author    Cubbiste
/// Created:   10/11/2010 20:44:26
/// @section   DESCRIPTION
///            VersionDlg class implementation
///
///------------------------------------------------------------------

#include "VersionDlg.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

// #nclude <wx/font.h>
#include "VersionXml.h"

//----------------------------------------------------------------------------
// VersionDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(VersionDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(VersionDlg::OnClose)
END_EVENT_TABLE()
////Event Table End

VersionDlg::VersionDlg(wxWindow *parent, VersionXml& version, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style), m_version(version)
{
	CreateGUIControls();
}

VersionDlg::~VersionDlg()
{
} 

void VersionDlg::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxBoxSizer1 = new wxBoxSizer(wxVERTICAL);
	this->SetSizer(WxBoxSizer1);
	this->SetAutoLayout(true);

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, wxT("WxStaticText1"), wxPoint(223, 5), wxDefaultSize, 0, wxT("WxStaticText1"));
	WxStaticText1->SetFont(wxFont(14, wxSWISS, wxNORMAL, wxBOLD, false));
	WxBoxSizer1->Add(WxStaticText1,0,wxALIGN_LEFT | wxLEFT | wxTOP,5);

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, wxT("WxStaticText2"), wxPoint(251, 34), wxDefaultSize, 0, wxT("WxStaticText2"));
	WxBoxSizer1->Add(WxStaticText2,0,wxALIGN_LEFT | wxLEFT,5);

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, wxT("WxStaticText3"), wxPoint(251, 53), wxDefaultSize, 0, wxT("WxStaticText3"));
	WxBoxSizer1->Add(WxStaticText3,0,wxALIGN_LEFT | wxLEFT,5);

	WxBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer1->Add(WxBoxSizer2, 0, wxALIGN_LEFT | wxALL, 0);

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, wxT("WxStaticText4"), wxPoint(5, 0), wxDefaultSize, 0, wxT("WxStaticText4"));
	WxBoxSizer2->Add(WxStaticText4,0,wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL | wxEXPAND | wxLEFT,5);

	WxHyperLinkCtrl1 = new wxHyperlinkCtrl(this, ID_WXHYPERLINKCTRL1, wxT("WxHyperLinkCtrl1"), wxT("http://wxdsgn.sf.net"), wxPoint(87, 1), wxSize(150, 17), wxNO_BORDER | wxHL_CONTEXTMENU, wxT("WxHyperLinkCtrl1"));
	WxHyperLinkCtrl1->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, true, wxT("MS Sans Serif")));
	WxBoxSizer2->Add(WxHyperLinkCtrl1,0,wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL | wxEXPAND | wxLEFT,5);

	WxMemo1 = new wxTextCtrl(this, ID_WXMEMO1, wxEmptyString, wxPoint(5, 96), wxSize(564, 47), wxTE_MULTILINE, wxDefaultValidator, wxT("WxMemo1"));
	WxMemo1->SetMaxLength(0);
	WxMemo1->AppendText(wxT("WxMemo1"));
	WxMemo1->SetFocus();
	WxMemo1->SetInsertionPointEnd();
	WxBoxSizer1->Add(WxMemo1,0,wxALIGN_CENTER | wxALL,5);

	WxMemo2 = new wxTextCtrl(this, ID_WXMEMO2, wxEmptyString, wxPoint(5, 153), wxSize(564, 200), wxTE_RICH | wxTE_MULTILINE, wxDefaultValidator, wxT("WxMemo2"));
	WxMemo2->SetMaxLength(0);
	WxMemo2->AppendText(wxT("WxMemo2"));
	WxMemo2->SetFocus();
	WxMemo2->SetInsertionPointEnd();
	WxBoxSizer1->Add(WxMemo2,1,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	WxStdDialogButtonSizer1 = new wxStdDialogButtonSizer;
	btnOK = new wxButton( this, wxID_OK );
	WxStdDialogButtonSizer1->AddButton( btnOK );
	WxStdDialogButtonSizer1->Realize();
	WxBoxSizer1->Add(WxStdDialogButtonSizer1, 0, wxALIGN_RIGHT | wxALL, 5);

	SetTitle(wxT("Vérification de la version"));
	SetIcon(wxNullIcon);
	
	GetSizer()->Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
	
	
	if (m_version.ok() == false) {
        WxStaticText1->SetLabel("Problème lors de la récupération des informations de version");
        WxStaticText2->Show(false);
        WxStaticText3->Show(false);
        WxStaticText4->Show(false);
        WxHyperLinkCtrl1->Show(false);
        WxMemo2->Show(false);
    } else if (m_version.aJour()) {
        WxStaticText1->SetLabel("Vous utilisez la dernière version");
        wxString tmpStr;
        tmpStr.Printf("Vous utilisez actuellement la version %s.", m_version.versionCourante().c_str());
        WxStaticText2->SetLabel(tmpStr);
        WxStaticText3->Show(false);
        WxStaticText4->Show(false);
        WxHyperLinkCtrl1->Show(false);
        WxMemo2->Show(false);
    } else {
        WxStaticText1->SetLabel("Une nouvelle version est disponible");
        wxString tmpStr;
        tmpStr.Printf("Vous utilisez actuellement la version %s.", m_version.versionCourante().c_str());
        WxStaticText2->SetLabel(tmpStr);
        tmpStr.Printf("La version %s est disponible.", m_version.idVersion().c_str());
        WxStaticText3->SetLabel(tmpStr);
        WxStaticText4->SetLabel("Allez sur le site pour la télécharger :");
        WxStaticText4->Show(false);
        WxHyperLinkCtrl1->SetLabel("site de téléchargement");
        WxHyperLinkCtrl1->SetURL(m_version.urlDownload());
        WxHyperLinkCtrl1->SetVisitedColour(WxHyperLinkCtrl1->GetNormalColour());
        
        // récupération directement dans le xml des informations sur les versions entre la version courante et la dernière version dispo
        WxMemo2->ChangeValue("");

        wxFont policeGras;
        policeGras.SetWeight(wxFONTWEIGHT_BOLD);
        wxTextAttr gras;
        gras.SetFont (policeGras);

        wxTextAttr defaultStyle = WxMemo2->GetDefaultStyle();

        wxXmlNode* child = m_version.xmlDoc().GetRoot()->GetChildren();
        while (child) {
            wxString childName = child->GetName();
            // wxLogMessage(childName.c_str());
            if (childName == "version") {
                wxString idVersion = child->GetPropVal("id", "");
                wxString strDate = child->GetPropVal("dateMad", "");
                // wxLogMessage("version : %s - strDate : %s", idVersion.c_str(), strDate.c_str());

                if (m_version.afficherVersion(idVersion)) {
                    WxMemo2->SetDefaultStyle(gras);
                    WxMemo2->AppendText(strDate + " : " + idVersion + "\n");
    
                    wxXmlNode* messageChild = child->GetChildren();
                    while (messageChild) {
                        if (messageChild->GetName() == "description") {
                            wxXmlNode* messageChild2 = messageChild->GetChildren();
                            while (messageChild2) {
                                if (messageChild2->GetName() == "general") {
                                    wxString texte = messageChild2->GetPropVal("value", "");
                                    WxMemo2->SetDefaultStyle(defaultStyle);
                                    WxMemo2->AppendText(texte + "\n");
                                } else if (messageChild2->GetName() == "item") {
                                    wxString texte = messageChild2->GetPropVal("value", "");
                                    WxMemo2->SetDefaultStyle(defaultStyle);
                                    WxMemo2->AppendText(" - " + texte + "\n");
                                }
                                messageChild2 = messageChild2->GetNext();
                            }
                        }
                        messageChild = messageChild->GetNext();
                    }
                    
                    WxMemo2->AppendText("\n");
                } else {
                    // wxLogMessage ("version %s non affichée", idVersion.c_str());
                }
            }

            child = child->GetNext();
        }

    }
    if (m_version.afficherMessage()) {
        WxMemo1->ChangeValue("");
        WxMemo1->AppendText(m_version.message());
    } else {
        WxMemo1->Show(false);
    }
	
	WxMemo1->SetEditable(false);
	WxMemo2->SetEditable(false);
    WxMemo2->SetInsertionPoint(0);
    
    btnOK->SetLabel("Fermer");
	btnOK->SetFocus();
	
	WxBoxSizer1->Layout();
}

void VersionDlg::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}
