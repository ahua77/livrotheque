//---------------------------------------------------------------------------
//
// Name:        rech_internet.cpp
// Author:      Epaillard
// Created:     06/06/05 17:52:38
//
//Copyright  PE Epaillard, 06/06/05 
//
//Fougny@gmail.com
//
//Ce logiciel est un programme informatique servant à [rappeler les
//caractéristiques techniques de votre logiciel]. 
//
//Ce logiciel est régi par la licence CeCILL soumise au droit français et
//respectant les principes de diffusion des logiciels libres. Vous pouvez
//utiliser, modifier et/ou redistribuer ce programme sous les conditions
//de la licence CeCILL telle que diffusée par le CEA, le CNRS et l'INRIA 
//sur le site "http://www.cecill.info".
//
//En contrepartie de l'accessibilité au code source et des droits de copie,
//de modification et de redistribution accordés par cette licence, il n'est
//offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
//seule une responsabilité restreinte pèse sur l'auteur du programme,  le
//titulaire des droits patrimoniaux et les concédants successifs.
//
//A cet égard  l'attention de l'utilisateur est attirée sur les risques
//associés au chargement,  à l'utilisation,  à la modification et/ou au
//développement et à la reproduction du logiciel par l'utilisateur étant 
//donné sa spécificité de logiciel libre, qui peut le rendre complexe à 
//manipuler et qui le réserve donc à des développeurs et des professionnels
//avertis possédant  des  connaissances  informatiques approfondies.  Les
//utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
//logiciel à leurs besoins dans des conditions permettant d'assurer la
//sécurité de leurs systèmes et ou de leurs données et, plus généralement, 
//à l'utiliser et l'exploiter dans les mêmes conditions de sécurité. 
//
//Le fait que vous puissiez accéder à cet en-tête signifie que vous avez 
//pris connaissance de la licence CeCILL, et que vous en avez accepté les
//termes.
//
//---------------------------------------------------------------------------

#include "rech_internet.h"

#include <wx/filename.h>

#include "ParamManager.h"

//Do not add custom headers.
//wx-dvcpp designer will remove them
////Header Include Start
////Header Include End



//----------------------------------------------------------------------------
// rech_internet
//----------------------------------------------------------------------------
     //Add Custom Events only in the appropriate Block.
    // Code added in  other places will be removed by wx-dvcpp 
    ////Event Table Start
BEGIN_EVENT_TABLE(rech_internet,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(rech_internet::rech_internetClose)
	EVT_BUTTON(ID_WXBUTTON_ANNULER,rech_internet::WxButton_annulerClick)
	EVT_BUTTON(ID_WXBUTTON_OK,rech_internet::WxButton_OKClick)
	EVT_CHECKBOX(ID_WXCHECKBOX_IMAGE_DOS,rech_internet::WxCheckBox_Click)
	EVT_CHECKBOX(ID_WXCHECKBOX_IMAGE_FACE,rech_internet::WxCheckBox_Click)
	EVT_CHECKBOX(ID_WXCHECKBOX_COMMENTAIRE,rech_internet::WxCheckBox_Click)
	EVT_CHECKBOX(ID_WXCHECKBOX_PRIX,rech_internet::WxCheckBox_Click)
	EVT_CHECKBOX(ID_WXCHECKBOX_TRADUCTEUR,rech_internet::WxCheckBox_Click)
	EVT_CHECKBOX(ID_WXCHECKBOX_LANGUE,rech_internet::WxCheckBox_Click)
	EVT_CHECKBOX(ID_WXCHECKBOX_DATE_PUB,rech_internet::WxCheckBox_Click)
	EVT_CHECKBOX(ID_WXCHECKBOX_GENRE,rech_internet::WxCheckBox_Click)
	EVT_CHECKBOX(ID_WXCHECKBOX_EDITEUR,rech_internet::WxCheckBox_Click)
	EVT_CHECKBOX(ID_WXCHECKBOX_TITRE,rech_internet::WxCheckBox_Click)
	EVT_CHECKBOX(ID_WXCHECKBOX_AUTEUR,rech_internet::WxCheckBox_Click)
	EVT_CHECKBOX(ID_WXCHECKBOX_MINUSCULE,rech_internet::WxCheckBox_Click)
	EVT_CHECKBOX(ID_WXCHECKBOX_AUTEUR_INVERSE,rech_internet::WxCheckBox_Click)
	
	EVT_TEXT_URL(ID_WXMEMO_URL,rech_internet::WxMemo_URLClickUrl)
	EVT_CHECKBOX(ID_WXCHECKBOX_PROXY,rech_internet::WxCheckBox_proxyClick)
	EVT_BUTTON(ID_WXBUTTON_LANCER,rech_internet::WxButton_lancerClick)
END_EVENT_TABLE()
    ////Event Table End



rech_internet::rech_internet( wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    isbn="0";
    auteur="";
    traducteur="";
    titre="";
    genre="";
    recherche_auto=false;
    type_recherche=-1;
    CreateGUIControls();
}

rech_internet::rech_internet( wxString p_isbn , wxWindow *parent, int moteur_recherche, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    isbn=p_isbn;
    auteur="";
    traducteur="";
    titre="";
    genre="";
    recherche_auto=true;
    type_recherche=moteur_recherche;
    CreateGUIControls();
  /*  if (moteur_recherche != -1) {
        WxRadioBox_choix_recherche->SetSelection(moteur_recherche);
    }*/
}

rech_internet::~rech_internet() {} 

void rech_internet::CreateGUIControls(void)
{
    //Do not add custom Code here
    //wx-devcpp designer will remove them.
    //Add the custom code before or after the Blocks
    ////GUI Items Creation Start

	WxStaticText_isbn = new wxStaticText(this, ID_WXSTATICTEXT_ISBN, wxT("I.S.B.N :"), wxPoint(14, 14), wxDefaultSize, 0, wxT("WxStaticText_isbn"));
	WxStaticText_isbn->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_isbn = new wxTextCtrl(this, ID_WXEDIT_ISBN, wxT(""), wxPoint(66, 10), wxSize(124, 21), wxTE_PROCESS_TAB | wxTE_READONLY, wxDefaultValidator, wxT("WxEdit_isbn"));
	WxEdit_isbn->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_lancer = new wxButton(this, ID_WXBUTTON_LANCER, wxT("Lancer la recherche"), wxPoint(174, 56), wxSize(121, 34), 0, wxDefaultValidator, wxT("WxButton_lancer"));
	WxButton_lancer->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticBox_proxy = new wxStaticBox(this, ID_WXSTATICBOX_PROXY, wxT("Paramêtre du Proxy"), wxPoint(325, 30), wxSize(417, 81));
	WxStaticBox_proxy->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_proxy = new wxCheckBox(this, ID_WXCHECKBOX_PROXY, wxT("Utiliser un proxy"), wxPoint(325, 2), wxSize(114, 26), 0, wxDefaultValidator, wxT("WxCheckBox_proxy"));
	WxCheckBox_proxy->SetToolTip(wxT("Coc"));
	WxCheckBox_proxy->SetHelpText(wxT("Cocher la case si vous voulez utiliser un proxy"));
	WxCheckBox_proxy->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_proxy_adr = new wxStaticText(this, ID_WXSTATICTEXT_PROXY_ADR, wxT("Adresse : "), wxPoint(332, 50), wxDefaultSize, 0, wxT("WxStaticText_proxy_adr"));
	WxStaticText_proxy_adr->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_proxy_adr = new wxTextCtrl(this, ID_WXEDIT_PROXY_ADR, wxT(""), wxPoint(384, 48), wxSize(142, 21), 0, wxDefaultValidator, wxT("WxEdit_proxy_adr"));
	WxEdit_proxy_adr->Enable(false);
	WxEdit_proxy_adr->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_proxy_util = new wxStaticText(this, ID_WXSTATICTEXT_PROXY_UTIL, wxT("Utilisateur : "), wxPoint(536, 50), wxDefaultSize, 0, wxT("WxStaticText_proxy_util"));
	WxStaticText_proxy_util->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_proxy_util = new wxTextCtrl(this, ID_WXEDIT_PROXY_UTIL, wxT(""), wxPoint(597, 49), wxSize(136, 21), 0, wxDefaultValidator, wxT("WxEdit_proxy_util"));
	WxEdit_proxy_util->Enable(false);
	WxEdit_proxy_util->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_proxy_port = new wxStaticText(this, ID_WXSTATICTEXT_PROXY_PORT, wxT("Port : "), wxPoint(346, 80), wxDefaultSize, 0, wxT("WxStaticText_proxy_port"));
	WxStaticText_proxy_port->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_proxy_port = new wxTextCtrl(this, ID_WXEDIT_PROXY_PORT, wxT(""), wxPoint(383, 79), wxSize(143, 21), 0, wxDefaultValidator, wxT("WxEdit_proxy_port"));
	WxEdit_proxy_port->Enable(false);
	WxEdit_proxy_port->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_proxy_pass = new wxStaticText(this, ID_WXSTATICTEXT_PROXY_PASS, wxT("Password : "), wxPoint(534, 83), wxDefaultSize, 0, wxT("WxStaticText_proxy_pass"));
	WxStaticText_proxy_pass->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_aide = new wxStaticText(this, ID_WXSTATICTEXT_AIDE, wxT("Cochez Les éléments que vous désirez importer"), wxPoint(202, 113), wxDefaultSize, 0, wxT("WxStaticText_aide"));
	WxStaticText_aide->SetFont(wxFont(14, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_url = new wxStaticText(this, ID_WXSTATICTEXT_URL, wxT("Url : "), wxPoint(5, 149), wxDefaultSize, 0, wxT("WxStaticText_url"));
	WxStaticText_url->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxMemo_URL = new wxTextCtrl(this, ID_WXMEMO_URL, wxEmptyString, wxPoint(30, 141), wxSize(724, 30), wxNO_BORDER | wxTE_READONLY | wxTE_AUTO_URL | wxTE_MULTILINE, wxDefaultValidator, wxT("WxMemo_URL"));
	WxMemo_URL->SetMaxLength(0);
	WxMemo_URL->AppendText(wxT("http://www.alapage.com/"));
	WxMemo_URL->SetFocus();
	WxMemo_URL->SetInsertionPointEnd();
	WxMemo_URL->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_proxy_pass = new wxTextCtrl(this, ID_WXEDIT_PROXY_PASS, wxT(""), wxPoint(597, 80), wxSize(138, 21), wxTE_PASSWORD, wxDefaultValidator, wxT("WxEdit_proxy_pass"));
	WxEdit_proxy_pass->Enable(false);
	WxEdit_proxy_pass->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	/* A cocher si vous voulez inverser le prénom/nom de l'auteur (marche moyen pour les noms triples
	*/
	WxCheckBox_auteur_inverse = new wxCheckBox(this, ID_WXCHECKBOX_AUTEUR_INVERSE, wxT("Inverser nom/prénom"), wxPoint(67, 174), wxSize(119, 14), 0, wxDefaultValidator, wxT("WxCheckBox_auteur_inverse"));
	WxCheckBox_auteur_inverse->SetToolTip(wxT("A cocher si vous voulez inverser le prénom/nom de l'auteur et du traducteur (marche moyen pour les noms triples"));
	WxCheckBox_auteur_inverse->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_minuscule = new wxCheckBox(this, ID_WXCHECKBOX_MINUSCULE, wxT("Mettre en minuscule"), wxPoint(467, 174), wxSize(134, 14), 0, wxDefaultValidator, wxT("WxCheckBox_minuscule"));
	WxCheckBox_minuscule->SetToolTip(wxT("Cocher Pour mettre titre et genre en minuscule"));
	WxCheckBox_minuscule->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_auteur = new wxStaticText(this, ID_WXSTATICTEXT_AUTEUR, wxT("Auteur :"), wxPoint(8, 193), wxDefaultSize, 0, wxT("WxStaticText_auteur"));
	WxStaticText_auteur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_auteur = new wxTextCtrl(this, ID_WXEDIT_AUTEUR, wxT(""), wxPoint(55, 191), wxSize(260, 21), 0, wxDefaultValidator, wxT("WxEdit_auteur"));
	WxEdit_auteur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_auteur = new wxCheckBox(this, ID_WXCHECKBOX_AUTEUR, wxT(""), wxPoint(322, 194), wxSize(20, 17), 0, wxDefaultValidator, wxT("WxCheckBox_auteur"));
	WxCheckBox_auteur->SetValue(true);
	WxCheckBox_auteur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_titre = new wxStaticText(this, ID_WXSTATICTEXT_TITRE, wxT("Titre :"), wxPoint(393, 197), wxDefaultSize, 0, wxT("WxStaticText_titre"));
	WxStaticText_titre->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_titre = new wxTextCtrl(this, ID_WXEDIT_TITRE, wxT(""), wxPoint(430, 191), wxSize(261, 21), 0, wxDefaultValidator, wxT("WxEdit_titre"));
	WxEdit_titre->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_titre = new wxCheckBox(this, ID_WXCHECKBOX_TITRE, wxT(""), wxPoint(696, 190), wxSize(22, 18), 0, wxDefaultValidator, wxT("WxCheckBox_titre"));
	WxCheckBox_titre->SetValue(true);
	WxCheckBox_titre->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_editeur = new wxStaticText(this, ID_WXSTATICTEXT_EDITEUR, wxT("Editeur :"), wxPoint(10, 214), wxDefaultSize, 0, wxT("WxStaticText_editeur"));
	WxStaticText_editeur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_editeur = new wxTextCtrl(this, ID_WXEDIT_EDITEUR, wxT(""), wxPoint(55, 214), wxSize(261, 21), 0, wxDefaultValidator, wxT("WxEdit_editeur"));
	WxEdit_editeur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_editeur = new wxCheckBox(this, ID_WXCHECKBOX_EDITEUR, wxT(""), wxPoint(323, 217), wxSize(21, 19), 0, wxDefaultValidator, wxT("WxCheckBox_editeur"));
	WxCheckBox_editeur->SetValue(true);
	WxCheckBox_editeur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_genre = new wxStaticText(this, ID_WXSTATICTEXT_GENRE, wxT("Genre :"), wxPoint(387, 217), wxDefaultSize, 0, wxT("WxStaticText_genre"));
	WxStaticText_genre->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_genre = new wxTextCtrl(this, ID_WXEDIT_GENRE, wxT(""), wxPoint(431, 214), wxSize(262, 21), 0, wxDefaultValidator, wxT("WxEdit_genre"));
	WxEdit_genre->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_genre = new wxCheckBox(this, ID_WXCHECKBOX_GENRE, wxT(""), wxPoint(698, 214), wxSize(20, 21), 0, wxDefaultValidator, wxT("WxCheckBox_genre"));
	WxCheckBox_genre->SetValue(true);
	WxCheckBox_genre->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_date_pub = new wxStaticText(this, ID_WXSTATICTEXT_DATE_PUB, wxT("Date de publication :"), wxPoint(5, 240), wxDefaultSize, 0, wxT("WxStaticText_date_pub"));
	WxStaticText_date_pub->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_date_pub = new wxTextCtrl(this, ID_WXEDIT_DATE_PUB, wxT(""), wxPoint(114, 237), wxSize(202, 21), 0, wxDefaultValidator, wxT("WxEdit_date_pub"));
	WxEdit_date_pub->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_date_pub = new wxCheckBox(this, ID_WXCHECKBOX_DATE_PUB, wxT(""), wxPoint(323, 237), wxSize(23, 22), 0, wxDefaultValidator, wxT("WxCheckBox_date_pub"));
	WxCheckBox_date_pub->SetValue(true);
	WxCheckBox_date_pub->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_langue = new wxStaticText(this, ID_WXSTATICTEXT_LANGUE, wxT("Langue d'origine :"), wxPoint(388, 239), wxDefaultSize, 0, wxT("WxStaticText_langue"));
	WxStaticText_langue->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_langue = new wxTextCtrl(this, ID_WXEDIT_LANGUE, wxT(""), wxPoint(480, 237), wxSize(213, 21), 0, wxDefaultValidator, wxT("WxEdit_langue"));
	WxEdit_langue->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_langue = new wxCheckBox(this, ID_WXCHECKBOX_LANGUE, wxT(""), wxPoint(698, 237), wxSize(22, 23), 0, wxDefaultValidator, wxT("WxCheckBox_langue"));
	WxCheckBox_langue->SetValue(true);
	WxCheckBox_langue->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_traducteur = new wxStaticText(this, ID_WXSTATICTEXT_TRADUCTEUR, wxT("Traducteur :"), wxPoint(6, 263), wxDefaultSize, 0, wxT("WxStaticText_traducteur"));
	WxStaticText_traducteur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_traducteur = new wxTextCtrl(this, ID_WXEDIT_TRADUCTEUR, wxT(""), wxPoint(74, 260), wxSize(244, 21), 0, wxDefaultValidator, wxT("WxEdit_traducteur"));
	WxEdit_traducteur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_traducteur = new wxCheckBox(this, ID_WXCHECKBOX_TRADUCTEUR, wxT(""), wxPoint(323, 262), wxSize(21, 17), 0, wxDefaultValidator, wxT("WxCheckBox_traducteur"));
	WxCheckBox_traducteur->SetValue(true);
	WxCheckBox_traducteur->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_prix = new wxStaticText(this, ID_WXSTATICTEXT_PRIX, wxT("Prix :"), wxPoint(394, 263), wxDefaultSize, 0, wxT("WxStaticText_prix"));
	WxStaticText_prix->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_prix = new wxTextCtrl(this, ID_WXEDIT_PRIX, wxT(""), wxPoint(425, 260), wxSize(269, 21), 0, wxDefaultValidator, wxT("WxEdit_prix"));
	WxEdit_prix->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_prix = new wxCheckBox(this, ID_WXCHECKBOX_PRIX, wxT(""), wxPoint(698, 260), wxSize(23, 21), 0, wxDefaultValidator, wxT("WxCheckBox_prix"));
	WxCheckBox_prix->SetValue(true);
	WxCheckBox_prix->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxMemo_commentaire = new wxTextCtrl(this, ID_WXMEMO_COMMENTAIRE, wxEmptyString, wxPoint(17, 342), wxSize(331, 156), wxTE_MULTILINE, wxDefaultValidator, wxT("WxMemo_commentaire"));
	WxMemo_commentaire->SetMaxLength(0);
	WxMemo_commentaire->SetFocus();
	WxMemo_commentaire->SetInsertionPointEnd();
	WxMemo_commentaire->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_commentaire = new wxStaticText(this, ID_WXSTATICTEXT_COMMENTAIRE, wxT("Résumé :"), wxPoint(44, 322), wxDefaultSize, 0, wxT("WxStaticText_commentaire"));
	WxStaticText_commentaire->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_commentaire = new wxCheckBox(this, ID_WXCHECKBOX_COMMENTAIRE, wxT(""), wxPoint(117, 319), wxSize(23, 21), 0, wxDefaultValidator, wxT("WxCheckBox_commentaire"));
	WxCheckBox_commentaire->SetValue(true);
	WxCheckBox_commentaire->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_image_face = new wxStaticText(this, ID_WXSTATICTEXT_IMAGE_FACE, wxT("recto : "), wxPoint(366, 322), wxDefaultSize, 0, wxT("WxStaticText_image_face"));
	WxStaticText_image_face->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxPanel_image_face = new wxPanel(this, ID_WXPANEL_IMAGE_FACE, wxPoint(363, 344), wxSize(170, 213));
	WxPanel_image_face->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_image_face = new wxCheckBox(this, ID_WXCHECKBOX_IMAGE_FACE, wxT(""), wxPoint(404, 321), wxSize(21, 22), 0, wxDefaultValidator, wxT("WxCheckBox_image_face"));
	WxCheckBox_image_face->SetValue(true);
	WxCheckBox_image_face->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxPanel_image_dos = new wxPanel(this, ID_WXPANEL_IMAGE_DOS, wxPoint(561, 344), wxSize(170, 213));
	WxPanel_image_dos->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_image_dos = new wxCheckBox(this, ID_WXCHECKBOX_IMAGE_DOS, wxT(""), wxPoint(604, 319), wxSize(22, 21), 0, wxDefaultValidator, wxT("WxCheckBox_image_dos"));
	WxCheckBox_image_dos->SetValue(true);
	WxCheckBox_image_dos->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_image_verso = new wxStaticText(this, ID_WXSTATICTEXT_IMAGE_VERSO, wxT("Verso :"), wxPoint(565, 323), wxDefaultSize, 0, wxT("WxStaticText_image_verso"));
	WxStaticText_image_verso->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxButton_OK = new wxButton(this, ID_WXBUTTON_OK, wxT("Importer"), wxPoint(27, 519), wxSize(86, 27), 0, wxDefaultValidator, wxT("WxButton_OK"));
	WxButton_OK->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxID_CANCEL = new wxButton(this, ID_WXBUTTON_ANNULER, wxT("Annuler"), wxPoint(165, 519), wxSize(86, 27), 0, wxDefaultValidator, wxT("wxID_CANCEL"));
	wxID_CANCEL->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_nb_pages = new wxStaticText(this, ID_WXSTATICTEXT_NB_PAGES, wxT("NB_Pages :"), wxPoint(11, 284), wxDefaultSize, 0, wxT("WxStaticText_nb_pages"));
	WxStaticText_nb_pages->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_nb_pages = new wxTextCtrl(this, ID_WXEDIT_NB_PAGES, wxT(""), wxPoint(74, 283), wxSize(243, 21), 0, wxDefaultValidator, wxT("WxEdit_nb_pages"));
	WxEdit_nb_pages->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_nb_pages = new wxCheckBox(this, ID_WXCHECKBOX_NB_PAGES, wxT(""), wxPoint(323, 283), wxSize(17, 17), 0, wxDefaultValidator, wxT("WxCheckBox_nb_pages"));
	WxCheckBox_nb_pages->SetValue(true);
	WxCheckBox_nb_pages->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxStaticText_format = new wxStaticText(this, ID_WXSTATICTEXT_FORMAT, wxT("Format :"), wxPoint(380, 286), wxDefaultSize, 0, wxT("WxStaticText_format"));
	WxStaticText_format->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxEdit_format = new wxTextCtrl(this, ID_WXEDIT_FORMAT, wxT(""), wxPoint(426, 285), wxSize(268, 19), 0, wxDefaultValidator, wxT("WxEdit_format"));
	WxEdit_format->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	WxCheckBox_format = new wxCheckBox(this, ID_WXCHECKBOX_FORMAT, wxT(""), wxPoint(699, 283), wxSize(20, 17), 0, wxDefaultValidator, wxT("WxCheckBox_format"));
	WxCheckBox_format->SetValue(true);
	WxCheckBox_format->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	wxArrayString arrayStringFor_WxRadioBox_choix_recherche;
	arrayStringFor_WxRadioBox_choix_recherche.Add(wxT("Amazon (fr)"));
	arrayStringFor_WxRadioBox_choix_recherche.Add(wxT("Alapage (fr)"));
	arrayStringFor_WxRadioBox_choix_recherche.Add(wxT("Amazon (us)"));
	arrayStringFor_WxRadioBox_choix_recherche.Add(wxT("Amazon (uk)"));
	WxRadioBox_choix_recherche = new wxRadioBox(this, ID_WXRADIOBOX_CHOIX_RECHERCHE, wxT("Moteur de recherche"), wxPoint(18, 32), wxSize(122, 94), arrayStringFor_WxRadioBox_choix_recherche, 1, wxRA_SPECIFY_COLS, wxDefaultValidator, wxT("WxRadioBox_choix_recherche"));
	WxRadioBox_choix_recherche->SetToolTip(wxT("Choix du moteur de recherche"));
	WxRadioBox_choix_recherche->SetSelection(0);
	WxRadioBox_choix_recherche->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));

	SetTitle(wxT("recherche sur internet"));
	SetIcon(wxNullIcon);
	SetSize(8,8,774,622);
	Center();
	
    ////GUI Items Creation End
  
    // initialisation des variables internes
    //WxMemo_URL->SetWindowStyleFlag(wxNO_3D | wxNO_BORDER );
    WxMemo_URL->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    WxMemo_URL->Refresh();
    WxEdit_isbn->SetValue(isbn);
    img_recto=gettempdir()+"\\"+ isbn + "_r.jpeg";
    img_verso=gettempdir()+"\\"+ isbn + "_v.jpeg";
    load_config();
    change_etat_proxy();
    if (type_recherche != -1) {
        WxRadioBox_choix_recherche->SetSelection(type_recherche);
    }
    if (recherche_auto==true) {
        lancer_recherche();
    }
}

void rech_internet::rech_internetClose(wxCloseEvent& event)
{
    // --> Don't use Close with a wxDialog,
    // use Destroy instead.
    Destroy();
}

/*
 * WxButton_OKClick
 */
void rech_internet::WxButton_OKClick(wxCommandEvent& event)
{
    //wxMessageBox(isbn,"probleme", wxOK | wxICON_EXCLAMATION, this);
	// insert your code here
	sauve_config();
    SetReturnCode(0);
    Destroy();
	event.Skip();
}

/*
 * WxButton_annulerClick
 */
void rech_internet::WxButton_annulerClick(wxCommandEvent& event)
{
	// insert your code here
	sauve_config();
    SetReturnCode(-1);
    Destroy();
	event.Skip();
}

void rech_internet::lancer_recherche() {
    LIVRE_HTML l_livre;
    caracteristiques l_carac;
    int largeur_obj, hauteur_obj;
    //wxImage image_face;
    ImageCanvas *canvas_image_face;
    //wxImage image_dos;
    ImageCanvas *canvas_image_dos;
    //bool tt;

     wxSetCursor(wxCursor(wxCURSOR_WAIT));
    l_livre.setproxy(WxCheckBox_proxy->GetValue(), WxEdit_proxy_adr->GetValue(), WxEdit_proxy_port->GetValue(), WxEdit_proxy_util->GetValue(), WxEdit_proxy_pass->GetValue());
    l_livre.traiter_isbn(isbn,img_recto,img_verso, l_carac,WxRadioBox_choix_recherche->GetSelection());
    /*if (ret<0) {
       wxMessageBox("Problême lors de la récupérationdes données","Probême", wxOK | wxICON_EXCLAMATION);
    }*/
        
    /*traiter_isbn();*/
    auteur=l_carac.Auteur;
    if (auteur.Len() == 0) {
       auteur = " ";
    }   

    traducteur=l_carac.Traducteur;
    if ((l_carac.Traducteur.Len() == 0) && (WxCheckBox_traducteur->GetValue() == true)) {
        WxCheckBox_traducteur->SetValue(false);
    }
    //WxEdit_traducteur->SetValue(l_carac.Traducteur);
    inverse_auteur();
    titre=l_carac.Titre;
    genre=l_carac.Genre;
    minusculisation();
    //WxEdit_titre->SetValue(l_carac.Titre);
    WxEdit_editeur->SetValue(l_carac.Editeur);
    if ((l_carac.Editeur.Len() == 0) && (WxCheckBox_editeur->GetValue() == true)) {
        WxCheckBox_editeur->SetValue(false);
    }
    //WxEdit_genre->SetValue(l_carac.Genre);
    WxEdit_date_pub->SetValue(l_carac.Date_parution);
    if ((l_carac.Date_parution.Len()) == 0 && (WxCheckBox_date_pub->GetValue() == true)) {
        WxCheckBox_date_pub->SetValue(false);
    }
    WxEdit_langue->SetValue(l_carac.Langue);
    if ((l_carac.Langue.Len()) == 0 && (WxCheckBox_langue->GetValue() == true)) {
        WxCheckBox_langue->SetValue(false);
    }
    WxEdit_prix->SetValue(l_carac.Prix);
    if ((l_carac.Prix.Len() == 0) && (WxCheckBox_prix->GetValue() == true)) {
        WxCheckBox_prix->SetValue(false);
    }
    WxEdit_nb_pages->SetValue(l_carac.Nb_pages);
    if ((l_carac.Nb_pages.Len() == 0) && (WxCheckBox_nb_pages->GetValue() == true)) {
        WxCheckBox_nb_pages->SetValue(false);
    }
    WxEdit_format->SetValue(l_carac.Presentation);
    if ((l_carac.Presentation.Len() == 0) && (WxCheckBox_format->GetValue() == true)) {
        WxCheckBox_format->SetValue(false);
    }
    WxMemo_commentaire->SetValue(l_carac.Commentaires);
    if ((l_carac.Commentaires.Len() == 0) && (WxCheckBox_commentaire->GetValue() == true)) {
        WxCheckBox_commentaire->SetValue(false);
    }
    
    wxFileName fich_img_recto(img_recto);
    if (fich_img_recto.FileExists() == true && fich_img_recto.GetSize()>500) {
        WxCheckBox_image_face->SetValue(true);
        WxPanel_image_face->GetSize(&largeur_obj,&hauteur_obj);
        canvas_image_face = new ImageCanvas(WxPanel_image_face, ID_IMAGE_FACE, wxPoint(0,0),wxSize(largeur_obj,hauteur_obj) );
        canvas_image_face->init(img_recto);
    } else {
        WxCheckBox_image_face->SetValue(false);
    }
/*    tt=image_face.LoadFile(img_recto);
    if (tt==true) {
        rempli_canvas(canvas_image_face, &image_face);
    } else {
        wxMessageBox("Probleme de chargement de l'image rectos","probleme", wxOK | wxICON_EXCLAMATION, this);
    }*/
    wxFileName fich_img_verso(img_verso);
    if (fich_img_verso.FileExists() == true && fich_img_verso.GetSize()>500) {
        //wxMessageBox("verso" + img_verso+"test "+fich_img_verso.GetHumanReadableSize() ,"info", wxOK | wxICON_EXCLAMATION, this);
        WxCheckBox_image_dos->SetValue(true);
        WxPanel_image_dos->GetSize(&largeur_obj,&hauteur_obj);
        canvas_image_dos = new ImageCanvas(WxPanel_image_dos, ID_IMAGE_DOS, wxPoint(0,0),wxSize(largeur_obj,hauteur_obj) );
        canvas_image_dos->init(img_verso);
    } else {
        WxCheckBox_image_dos->SetValue(false);
    }
/*    tt=image_dos.LoadFile(img_verso);
    if (tt==true) {
        rempli_canvas(canvas_image_dos, &image_dos);
    } else {
        wxMessageBox("Probleme de chargement de l'image versos","probleme", wxOK | wxICON_EXCLAMATION, this);
    }*/
    WxMemo_URL->SetValue(l_carac.Url);
    wxSetCursor(wxNullCursor);
}
/*
 * WxButton_lancerClick
 */
void rech_internet::WxButton_lancerClick(wxCommandEvent& event)
{
    lancer_recherche();
	// insert your code here
	event.Skip();
}
 
/*
 * WxCheckBox_proxyClick
 */
void rech_internet::WxCheckBox_proxyClick(wxCommandEvent& event)
{
    change_etat_proxy();
	// insert your code here
	event.Skip();
}
void rech_internet::change_etat_proxy(){
    bool etat_check;
    
    etat_check=WxCheckBox_proxy->IsChecked();
    WxEdit_proxy_pass->Enable(etat_check);
    WxEdit_proxy_util->Enable(etat_check);
    WxEdit_proxy_port->Enable(etat_check);
    WxEdit_proxy_adr->Enable(etat_check);
}

void rech_internet::sauve_config() {
    ParamManager* param = ParamManager::GetInstance("config");
    if (param == NULL) {
        wxMessageBox("rech_internet::sauve_config() : pas de ParamManager disponible");
        return;
    }

    param->Set("rech_internet", "PROXY", "UTILISE", (long)(WxCheckBox_proxy->GetValue()));
    param->Set("rech_internet", "PROXY", "ADRESSE", WxEdit_proxy_adr->GetValue());
    param->Set("rech_internet", "PROXY", "PORT", WxEdit_proxy_port->GetValue());
    param->Set("rech_internet", "PROXY", "USER", WxEdit_proxy_util->GetValue());
    param->Set("rech_internet", "PROXY", "PASS", WxEdit_proxy_pass->GetValue());
    param->Set("rech_internet", "PROXY", "MOTEUR", (long)(WxRadioBox_choix_recherche->GetSelection()));
    
    param->Set("rech_internet", "OPTION", "INVERSE", (long)(WxCheckBox_auteur_inverse->GetValue()));
    param->Set("rech_internet", "OPTION", "MINUSCULE", (long)(WxCheckBox_minuscule->GetValue()));
    
/*    

    wxString fichier_conf;
    wxString query, mess;
    int ret;
    
    fichier_conf=::wxGetCwd();
    fichier_conf+="\\config";
    config.ouvrir(fichier_conf);
    query = "DROP TABLE rech_internet";
    config.exec_rapide(query);
    query="CREATE TABLE rech_internet (type_param TEXT , nom_param TEXT, val1 TEXT, val2 TEXT)";
    ret=config.exec_rapide(query);
    if (ret<0) {
        config.get_erreur(mess);
        wxMessageBox(mess,"sauvegarde de la configuration du proxy", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    query="INSERT INTO rech_internet (type_param, nom_param, val1) VALUES ('PROXY', 'UTILISE', '"+wxString::Format("%d",WxCheckBox_proxy->GetValue())+"')";
    ret=config.exec_rapide(query);
    if (ret<0) {
        config.get_erreur(mess);
        wxMessageBox(mess,"sauvegarde de la configuration du proxy", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    query="INSERT INTO rech_internet (type_param, nom_param, val1) VALUES ('PROXY', 'ADRESSE', '"+WxEdit_proxy_adr->GetValue()+"')";
    ret=config.exec_rapide(query);
    if (ret<0) {
        config.get_erreur(mess);
        wxMessageBox(mess,"sauvegarde de la configuration du proxy", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    query="INSERT INTO rech_internet (type_param, nom_param, val1) VALUES ('PROXY', 'PORT', '"+WxEdit_proxy_port->GetValue()+"')";
    ret=config.exec_rapide(query);
    if (ret<0) {
        config.get_erreur(mess);
        wxMessageBox(mess,"sauvegarde de la configuration du proxy", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    query="INSERT INTO rech_internet (type_param, nom_param, val1) VALUES ('PROXY', 'USER', '"+WxEdit_proxy_util->GetValue()+"')";
    ret=config.exec_rapide(query);
    if (ret<0) {
        config.get_erreur(mess);
        wxMessageBox(mess,"sauvegarde de la configuration du proxy", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    query="INSERT INTO rech_internet (type_param, nom_param, val1) VALUES ('PROXY', 'PASS', '"+WxEdit_proxy_pass->GetValue()+"')";
    ret=config.exec_rapide(query);
    if (ret<0) {
        config.get_erreur(mess);
        wxMessageBox(mess,"sauvegarde de la configuration du proxy", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    
    mess.Printf("%d",WxCheckBox_auteur_inverse->GetValue());
    query="INSERT INTO rech_internet (type_param, nom_param, val1) VALUES ('OPTION', 'INVERSE', '"+mess+"')";
    ret=config.exec_rapide(query);
    if (ret<0) {
        config.get_erreur(mess);
        wxMessageBox(mess,"sauvegarde de la configuration d'option d'inversion", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    mess.Printf("%d",WxCheckBox_minuscule->GetValue());
    query="INSERT INTO rech_internet (type_param, nom_param, val1) VALUES ('OPTION', 'MINUSCULE', '"+mess+"')";
    ret=config.exec_rapide(query);
    if (ret<0) {
        config.get_erreur(mess);
        wxMessageBox(mess,"sauvegarde de la configuration d'option de minusculisation", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    query="INSERT INTO rech_internet (type_param, nom_param, val1) VALUES ('PROXY', 'MOTEUR', '"+wxString::Format("%d",WxRadioBox_choix_recherche->GetSelection())+"')";
    ret=config.exec_rapide(query);
    if (ret<0) {
        config.get_erreur(mess);
        wxMessageBox(mess,"sauvegarde de la configuration du moteur", wxOK | wxICON_EXCLAMATION, this);
        return;
    }
    
    config.fermer();
*/
}    

void rech_internet::load_config() {
    ParamManager* param = ParamManager::GetInstance("config");
    if (param == NULL) {
        wxMessageBox("rech_internet::load_config() : pas de ParamManager disponible");
        return;
    }

    long valLong = 0;
    param->GetOrSet("rech_internet", "PROXY", "UTILISE", valLong);
    WxCheckBox_proxy->SetValue((bool)valLong);

    wxString valStr = "";
    param->GetOrSet("rech_internet", "PROXY", "ADRESSE", valStr);
    WxEdit_proxy_adr->SetValue(valStr);

    valStr = "";
    param->GetOrSet("rech_internet", "PROXY", "PORT", valStr);
    WxEdit_proxy_port->SetValue(valStr);

    valStr = "";
    param->GetOrSet("rech_internet", "PROXY", "USER", valStr);
    WxEdit_proxy_util->SetValue(valStr);

    valStr = "";
    param->GetOrSet("rech_internet", "PROXY", "PASS", valStr);
    WxEdit_proxy_pass->SetValue(valStr);
    
    valLong = 0;
    param->GetOrSet("rech_internet", "PROXY", "MOTEUR", valLong);
    WxRadioBox_choix_recherche->SetSelection((int)valLong);
/*
    wxString fichier_conf, mess;
    wxString query,nom_param, valeur="";
    int ret, taille; 
    long utilise;
    
    fichier_conf=::wxGetCwd();
    fichier_conf+="\\config";
    config.ouvrir(fichier_conf);
    query = "SELECT nom_param, val1 FROM rech_internet WHERE type_param='PROXY'";
    ret=config.transac_prepare(query);

    ret=config.transac_step();

    while(ret==SQLITE_ROW ) {
        config.get_value_char(0,nom_param,taille);
        config.get_value_char(1,valeur,taille);
        if (nom_param == "UTILISE") {
            valeur.ToLong(&utilise);
            WxCheckBox_proxy->SetValue((bool)utilise);
        } else if (nom_param == "ADRESSE") {
            WxEdit_proxy_adr->SetValue(valeur);
        } else if (nom_param == "PORT") {
            WxEdit_proxy_port->SetValue(valeur);
        } else if (nom_param == "USER") {
            WxEdit_proxy_util->SetValue(valeur);
        } else if (nom_param == "PASS") {
            WxEdit_proxy_pass->SetValue(valeur);
        } else if (nom_param == "MOTEUR") {
            valeur.ToLong(&utilise);
            WxRadioBox_choix_recherche->SetSelection((int)utilise);
        }
        ret=config.transac_step();
    }  
    config.transac_fin();
*/
    
    valLong = 0;
    param->GetOrSet("rech_internet", "OPTION", "INVERSE", valLong);
    WxCheckBox_auteur_inverse->SetValue((bool)valLong);
    
    valLong = 0;
    param->GetOrSet("rech_internet", "OPTION", "MINUSCULE", valLong);
    WxCheckBox_minuscule->SetValue((bool)valLong);
    
/*
    query = "SELECT nom_param, val1 FROM rech_internet WHERE type_param='OPTION'";
    ret=config.transac_prepare(query);

    ret=config.transac_step();
    int check;
    while(ret==SQLITE_ROW ) {
        config.get_value_char(0,nom_param,taille);
        config.get_value_int(1,check);
        if (nom_param == "INVERSE") {
             WxCheckBox_auteur_inverse->SetValue((bool)check);
        } else if (nom_param == "MINUSCULE") {
             WxCheckBox_minuscule->SetValue((bool)check);
        }
        ret=config.transac_step();
    }  
    
    config.transac_fin();
    //wxMessageBox(valeur,"probleme", wxOK | wxICON_EXCLAMATION, this);
    config.fermer();
*/
}    

void rech_internet::inverse_auteur() {
    //wxMessageBox(auteur,"auteur", wxOK | wxICON_EXCLAMATION, this);
    if (WxCheckBox_auteur_inverse->IsChecked()) {
        wxString fin_ch=auteur.AfterLast(' ');
        wxString debut_ch=auteur.BeforeLast(' ');
        WxEdit_auteur->SetValue(fin_ch+wxT(" ")+debut_ch);
        fin_ch=traducteur.AfterLast(' ');
        debut_ch=traducteur.BeforeLast(' ');
        WxEdit_traducteur->SetValue(fin_ch+wxT(" ")+debut_ch);
    }else {
        WxEdit_auteur->SetValue(auteur);
        WxEdit_traducteur->SetValue(traducteur);
    }
}

/* et encore vous avez échappé à lowercasisation... */
void rech_internet::minusculisation() {
    //wxMessageBox(auteur,"auteur", wxOK | wxICON_EXCLAMATION, this);
    if (WxCheckBox_minuscule->IsChecked()) {
        wxString fin_ch=titre.Right(titre.Length()-1);
        wxString debut_ch=titre.Left(1);
        WxEdit_titre->SetValue(debut_ch+fin_ch.MakeLower());
        fin_ch=genre.Right(genre.Length()-1);
        debut_ch=genre.Left(1);
        WxEdit_genre->SetValue(debut_ch+fin_ch.MakeLower());
    }else {
        WxEdit_titre->SetValue(titre);
        WxEdit_genre->SetValue(genre);
    }
}

/*
 * WxCheckBox_auteurClick
 */
void rech_internet::WxCheckBox_Click(wxCommandEvent& event)
{
    int id;
    
    id = event.GetId();
    if (id == ID_WXCHECKBOX_AUTEUR) {
        WxEdit_auteur->Enable(event.IsChecked());
    } else if (id == ID_WXCHECKBOX_TITRE) {
        WxEdit_titre->Enable(event.IsChecked());
    } else if (id == ID_WXCHECKBOX_EDITEUR) {
        WxEdit_editeur->Enable(event.IsChecked());
    } else if (id == ID_WXCHECKBOX_GENRE) {
        WxEdit_genre->Enable(event.IsChecked());
    } else if (id == ID_WXCHECKBOX_DATE_PUB) {
        WxEdit_date_pub->Enable(event.IsChecked());
    } else if (id == ID_WXCHECKBOX_LANGUE) {
        WxEdit_langue->Enable(event.IsChecked());
    } else if (id == ID_WXCHECKBOX_TRADUCTEUR) {
        WxEdit_traducteur->Enable(event.IsChecked());
    } else if (id == ID_WXCHECKBOX_PRIX) {
        WxEdit_prix->Enable(event.IsChecked());
    } else if (id == ID_WXCHECKBOX_COMMENTAIRE) {
        WxMemo_commentaire->Enable(event.IsChecked());
    } else if (id == ID_WXCHECKBOX_IMAGE_FACE) {
        WxPanel_image_face->Enable(event.IsChecked());
    } else if (id == ID_WXCHECKBOX_IMAGE_DOS) {
        WxPanel_image_dos->Enable(event.IsChecked());
    } else if (id == ID_WXCHECKBOX_MINUSCULE) {
        minusculisation();
    } else if (id == ID_WXCHECKBOX_AUTEUR_INVERSE) {
        inverse_auteur();
    }
	// insert your code here
	event.Skip();
}

/*
 * WxMemo_URLClickUrl
 */
void rech_internet::WxMemo_URLClickUrl(wxTextUrlEvent& event)
{
    wxMouseEvent souris=event.GetMouseEvent();
    
    if (souris.m_leftDown == true) {
        ::wxLaunchDefaultBrowser(WxMemo_URL->GetValue());
//        ::wxShell("start "+WxMemo_URL->GetValue()+"");
    }
	// insert your code here
    souris.Skip();
	event.Skip();
}

