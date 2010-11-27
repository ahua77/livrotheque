///-----------------------------------------------------------------
///
/// @file      ParametreDlg.cpp
/// @author    cubbiste
/// Created:   12/12/2009 18:10:19
/// @section   DESCRIPTION
///            ParametreDlg class implementation
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
///
///------------------------------------------------------------------

#include "ParametreDlg.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

#include "ParamManager.h"
#include "curl_util.h"

long ParametreDlg::s_nbInstances = 0;

//----------------------------------------------------------------------------
// ParametreDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(ParametreDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(ParametreDlg::OnClose)
	EVT_INIT_DIALOG(ParametreDlg::ParametreDlgInitDialog)
	EVT_CHECKBOX(ID_WXCHECKBOX_PROXY,ParametreDlg::WxCheckBox_proxyClick)
	EVT_BUTTON(ID_WX_BNCANCEL,ParametreDlg::BN_CANCELClick)
	EVT_BUTTON(ID_WX_BNOK,ParametreDlg::BN_OKClick)
	EVT_BUTTON(ID_WX_BN_PARCOURIR_SAVE,ParametreDlg::BN_ParcourirSaveClick)
	EVT_RADIOBUTTON(ID_WX_RB_SAUVE_DOSSIER_SPECIFIE,ParametreDlg::RB_SauveDossierSpecifieClick)
	EVT_RADIOBUTTON(ID_WX_RB_SAUVE_DOSSIER_BASE,ParametreDlg::RB_SauveDossierBaseClick)
	EVT_CHECKBOX(ID_WX_CK_UseSauvegarde,ParametreDlg::CK_UseSauvegardeClick)
	EVT_CHECKBOX(ID_WX_CK_UseTopN,ParametreDlg::CK_useTopNClick)
	EVT_CHECKBOX(ID_WX_CK_USE_LARGEUR_MAX_COLONNES,ParametreDlg::CK_use_largeur_max_colonnesClick)
END_EVENT_TABLE()
////Event Table End

ParametreDlg::ParametreDlg(wxWindow *parent, int ongletActif, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
    s_nbInstances++;
    wxLogMessage("ParametreDlg::ParametreDlg() - nbInstances = %ld", s_nbInstances);

	CreateGUIControls();
	
	WxNotebook1->SetSelection(ongletActif);
}

ParametreDlg::~ParametreDlg()
{
    s_nbInstances--;
    wxLogMessage("ParametreDlg::~ParametreDlg() - nbInstances = %ld", s_nbInstances);
} 

void ParametreDlg::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxNotebook1 = new wxNotebook(this, ID_WXNOTEBOOK1, wxPoint(0, 0), wxSize(435, 265), wxNB_DEFAULT);

	WxNoteBookPage1 = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE1, wxPoint(4, 26), wxSize(427, 235));
	WxNotebook1->AddPage(WxNoteBookPage1, wxT("Général"));

	WxStaticText2 = new wxStaticText(WxNoteBookPage1, ID_WXSTATICTEXT2, wxT("Avertir avant de créer un nouveau groupe des types cochés ci-dessous :"), wxPoint(4, 6), wxDefaultSize, 0, wxT("WxStaticText2"));

	CK_avertirNouveau_auteur = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_auteur, wxT("Auteurs"), wxPoint(4, 30), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_auteur"));

	CK_avertirNouveau_serie = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_serie, wxT("Séries"), wxPoint(4, 54), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_serie"));

	CK_avertirNouveau_genre = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_genre, wxT("Genres"), wxPoint(4, 78), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_genre"));

	CK_avertirNouveau_editeur = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_editeur, wxT("Editeurs"), wxPoint(4, 102), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_editeur"));

	CK_avertirNouveau_format = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_format, wxT("Formats"), wxPoint(140, 30), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_format"));

	CK_avertirNouveau_artiste = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_artiste, wxT("Artistes"), wxPoint(140, 54), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_artiste"));

	CK_avertirNouveau_etat = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_etat, wxT("Etats"), wxPoint(140, 78), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_etat"));

	CK_avertirNouveau_localisation = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_localisation, wxT("Localisations"), wxPoint(140, 102), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_localisation"));

	CK_avertirNouveau_serie_o = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_serie_o, wxT("Séries originales"), wxPoint(276, 30), wxSize(113, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_serie_o"));

	CK_avertirNouveau_pays = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_pays, wxT("Pays"), wxPoint(276, 54), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_pays"));

	CK_avertirNouveau_langue = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_langue, wxT("Langues"), wxPoint(276, 78), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_langue"));

	CK_avertirNouveau_traducteur = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_traducteur, wxT("Traducteurs"), wxPoint(276, 102), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_traducteur"));

	WxStaticLine2 = new wxStaticLine(WxNoteBookPage1, ID_WXSTATICLINE2, wxPoint(-4, 126), wxSize(422, -1), wxLI_HORIZONTAL);

	CK_use_splash_screen = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_UseSplashScreen, wxT("Afficher l'écran de démarrage"), wxPoint(4, 141), wxSize(185, 17), 0, wxDefaultValidator, wxT("CK_use_splash_screen"));

	CK_cleanTmpOnExit = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_CLEAN_TMP_ON_EXIT, wxT("Effacer les fichiers temporaires en quittant le programme"), wxPoint(4, 162), wxSize(402, 17), 0, wxDefaultValidator, wxT("CK_cleanTmpOnExit"));

	WxStaticLine3 = new wxStaticLine(WxNoteBookPage1, ID_WXSTATICLINE3, wxPoint(0, 187), wxSize(417, -1), wxLI_HORIZONTAL);

	CK_use_largeur_max_colonnes = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_USE_LARGEUR_MAX_COLONNES, wxT("Limiter les colonnes à environ "), wxPoint(4, 200), wxSize(175, 17), 0, wxDefaultValidator, wxT("CK_use_largeur_max_colonnes"));

	ET_LargeurMaxColonnes = new wxTextCtrl(WxNoteBookPage1, ID_WX_ET_LARGEUR_MAX_COLONNES, wxT("ET_LargeurMaxColonnes"), wxPoint(181, 200), wxSize(46, 19), 0, wxDefaultValidator, wxT("ET_LargeurMaxColonnes"));

	WxStaticText3 = new wxStaticText(WxNoteBookPage1, ID_WXSTATICTEXT3, wxT("caractères de large"), wxPoint(232, 201), wxDefaultSize, 0, wxT("WxStaticText3"));

	WxNoteBookPage2 = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE2, wxPoint(4, 26), wxSize(427, 235));
	WxNotebook1->AddPage(WxNoteBookPage2, wxT("Statistiques"));

	CK_useTopN = new wxCheckBox(WxNoteBookPage2, ID_WX_CK_UseTopN, wxT("Limiter l'affichage aux "), wxPoint(12, 14), wxSize(137, 17), 0, wxDefaultValidator, wxT("CK_useTopN"));

	ET_ValueTopN = new wxTextCtrl(WxNoteBookPage2, ID_WXEDIT1, wxT("ET_ValueTopN"), wxPoint(156, 13), wxSize(41, 19), 0, wxDefaultValidator, wxT("ET_ValueTopN"));

	WxStaticText1 = new wxStaticText(WxNoteBookPage2, ID_WXSTATICTEXT1, wxT("premiers résultats"), wxPoint(204, 13), wxDefaultSize, 0, wxT("WxStaticText1"));

	WxStaticLine1 = new wxStaticLine(WxNoteBookPage2, ID_WXSTATICLINE1, wxPoint(-4, 38), wxSize(422, -1), wxLI_HORIZONTAL);

	WxNoteBookPage3 = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE3, wxPoint(4, 26), wxSize(427, 235));
	WxNotebook1->AddPage(WxNoteBookPage3, wxT("Sauvegarde"));

	CK_UseSauvegarde = new wxCheckBox(WxNoteBookPage3, ID_WX_CK_UseSauvegarde, wxT("Activer les sauvegardes automatiques de la base"), wxPoint(10, 13), wxSize(393, 17), 0, wxDefaultValidator, wxT("CK_UseSauvegarde"));

	ET_FrequenceSauvegarde = new wxTextCtrl(WxNoteBookPage3, ID_WX_ET_FREQ_SAUVE, wxT("ET_FrequenceSauvegarde"), wxPoint(237, 36), wxSize(59, 19), 0, wxDefaultValidator, wxT("ET_FrequenceSauvegarde"));

	ET_NB_CONSERVATION = new wxTextCtrl(WxNoteBookPage3, ID_WX_ET_NB_CONSERV, wxT("ET_NB_CONSERVATION"), wxPoint(237, 57), wxSize(59, 19), 0, wxDefaultValidator, wxT("ET_NB_CONSERVATION"));

	WxStaticText4 = new wxStaticText(WxNoteBookPage3, ID_WXSTATICTEXT4, wxT("Fréquence de sauvegarde :"), wxPoint(29, 38), wxDefaultSize, 0, wxT("WxStaticText4"));

	WxStaticText5 = new wxStaticText(WxNoteBookPage3, ID_WXSTATICTEXT5, wxT("Nombre de sauvegardes conservées :"), wxPoint(29, 57), wxDefaultSize, 0, wxT("WxStaticText5"));

	WxStaticLine4 = new wxStaticLine(WxNoteBookPage3, ID_WXSTATICLINE4, wxPoint(11, 156), wxSize(402, -1), wxLI_HORIZONTAL);

	WxStaticText7 = new wxStaticText(WxNoteBookPage3, ID_WXSTATICTEXT7, wxT("la précédente sauvegarde est plus ancienne que la fréquence demandée."), wxPoint(10, 181), wxDefaultSize, 0, wxT("WxStaticText7"));
	WxStaticText7->SetFont(wxFont(9, wxSWISS, wxITALIC, wxNORMAL, false));

	WxStaticText8 = new wxStaticText(WxNoteBookPage3, ID_WXSTATICTEXT8, wxT("Une sauvegarde est réalisée à la fermeture de la base de données, si "), wxPoint(10, 164), wxDefaultSize, 0, wxT("WxStaticText8"));
	WxStaticText8->SetFont(wxFont(9, wxSWISS, wxITALIC, wxNORMAL, false));

	WxStaticText6 = new wxStaticText(WxNoteBookPage3, ID_WXSTATICTEXT6, wxT("jours"), wxPoint(312, 38), wxDefaultSize, 0, wxT("WxStaticText6"));

	WxStaticText11 = new wxStaticText(WxNoteBookPage3, ID_WXSTATICTEXT11, wxT("Emplacement de la sauvegarde :"), wxPoint(29, 79), wxDefaultSize, 0, wxT("WxStaticText11"));

	RB_SauveDossierBase = new wxRadioButton(WxNoteBookPage3, ID_WX_RB_SAUVE_DOSSIER_BASE, wxT("Dans le sous-dossier \"sauvegardes\" du dossier de la base de données"), wxPoint(29, 95), wxSize(385, 17), 0, wxDefaultValidator, wxT("RB_SauveDossierBase"));

	RB_SauveDossierSpecifie = new wxRadioButton(WxNoteBookPage3, ID_WX_RB_SAUVE_DOSSIER_SPECIFIE, wxT("Dans le dossier ci-dessous :"), wxPoint(29, 114), wxSize(361, 17), 0, wxDefaultValidator, wxT("RB_SauveDossierSpecifie"));

	ET_Rep_Sauvegarde = new wxTextCtrl(WxNoteBookPage3, ID_WX_ET_REP_SAUVE, wxT("ET_Rep_Sauvegarde"), wxPoint(46, 132), wxSize(329, 19), 0, wxDefaultValidator, wxT("ET_Rep_Sauvegarde"));

	BN_ParcourirSave = new wxButton(WxNoteBookPage3, ID_WX_BN_PARCOURIR_SAVE, wxT("..."), wxPoint(381, 130), wxSize(31, 22), 0, wxDefaultValidator, wxT("BN_ParcourirSave"));

	BN_OK = new wxButton(this, ID_WX_BNOK, wxT("OK"), wxPoint(102, 270), wxSize(75, 25), 0, wxDefaultValidator, wxT("BN_OK"));

	BN_CANCEL = new wxButton(this, ID_WX_BNCANCEL, wxT("Annuler"), wxPoint(286, 270), wxSize(75, 25), 0, wxDefaultValidator, wxT("BN_CANCEL"));

	WxNoteBookPage4 = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE4, wxPoint(4, 26), wxSize(427, 235));
	WxNotebook1->AddPage(WxNoteBookPage4, wxT("Réseau"));

	WxCheckBox_proxy = new wxCheckBox(WxNoteBookPage4, ID_WXCHECKBOX_PROXY, wxT("Utiliser un proxy"), wxPoint(7, 7), wxSize(114, 26), 0, wxDefaultValidator, wxT("WxCheckBox_proxy"));
	WxCheckBox_proxy->SetToolTip(wxT("Cochez si votre connexion internet utilise un proxy"));
	WxCheckBox_proxy->SetHelpText(wxT("Cocher la case si vous voulez utiliser un proxy"));

	WxStaticBox_proxy = new wxStaticBox(WxNoteBookPage4, ID_WXSTATICBOX_PROXY, wxT("Paramètre du Proxy"), wxPoint(7, 35), wxSize(417, 81));

	WxEdit_proxy_adr = new wxTextCtrl(WxNoteBookPage4, ID_WXEDIT_PROXY_ADR, wxT(""), wxPoint(66, 53), wxSize(142, 21), 0, wxDefaultValidator, wxT("WxEdit_proxy_adr"));
	WxEdit_proxy_adr->Enable(false);

	WxEdit_proxy_port = new wxTextCtrl(WxNoteBookPage4, ID_WXEDIT_PROXY_PORT, wxT(""), wxPoint(65, 84), wxSize(143, 21), 0, wxDefaultValidator, wxT("WxEdit_proxy_port"));
	WxEdit_proxy_port->Enable(false);

	WxStaticText_proxy_adr = new wxStaticText(WxNoteBookPage4, ID_WXSTATICTEXT_PROXY_ADR, wxT("Adresse : "), wxPoint(14, 55), wxDefaultSize, 0, wxT("WxStaticText_proxy_adr"));

	WxStaticText_proxy_port = new wxStaticText(WxNoteBookPage4, ID_WXSTATICTEXT_PROXY_PORT, wxT("Port : "), wxPoint(28, 85), wxDefaultSize, 0, wxT("WxStaticText_proxy_port"));

	WxStaticText_proxy_util = new wxStaticText(WxNoteBookPage4, ID_WXSTATICTEXT_PROXY_UTIL, wxT("Utilisateur : "), wxPoint(218, 55), wxDefaultSize, 0, wxT("WxStaticText_proxy_util"));

	WxStaticText_proxy_pass = new wxStaticText(WxNoteBookPage4, ID_WXSTATICTEXT_PROXY_PASS, wxT("Password : "), wxPoint(216, 88), wxDefaultSize, 0, wxT("WxStaticText_proxy_pass"));

	WxEdit_proxy_util = new wxTextCtrl(WxNoteBookPage4, ID_WXEDIT_PROXY_UTIL, wxT(""), wxPoint(279, 54), wxSize(136, 21), 0, wxDefaultValidator, wxT("WxEdit_proxy_util"));
	WxEdit_proxy_util->Enable(false);

	WxEdit_proxy_pass = new wxTextCtrl(WxNoteBookPage4, ID_WXEDIT_PROXY_PASS, wxT(""), wxPoint(279, 85), wxSize(138, 21), wxTE_PASSWORD, wxDefaultValidator, wxT("WxEdit_proxy_pass"));
	WxEdit_proxy_pass->Enable(false);

	WxEdit_timeout = new wxTextCtrl(WxNoteBookPage4, ID_WX_TIMEOUT, wxT("WxEdit_timeout"), wxPoint(127, 125), wxSize(121, 19), 0, wxDefaultValidator, wxT("WxEdit_timeout"));

	WxStaticText9 = new wxStaticText(WxNoteBookPage4, ID_WXSTATICTEXT9, wxT("Timeout (secondes)"), wxPoint(11, 126), wxDefaultSize, 0, wxT("WxStaticText9"));

	WxCheck_verifVersion = new wxCheckBox(WxNoteBookPage4, ID_WXCHECKBOX1, wxT("Vérifier la dernière version au lancement du programme"), wxPoint(10, 159), wxSize(415, 17), 0, wxDefaultValidator, wxT("WxCheck_verifVersion"));

	SetTitle(wxT("Paramètres"));
	SetIcon(wxNullIcon);
	SetSize(8,8,455,334);
	Center();
	
	////GUI Items Creation End
}

void ParametreDlg::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * BN_OKClick
 */
void ParametreDlg::BN_OKClick(wxCommandEvent& event)
{
    wxLogMessage("ParametreDlg::BN_OKClick()");
    // sauvegarder en base les paramètres de tous les onglets
	ParamManager* param = ParamManager::GetInstance("config");
	if (!param) {
        wxMessageBox ("instance de ParamManager non créée");
        return;
    }

    // Onglet Général
    wxLogMessage("ParametreDlg::BN_OKClick() - onglet General");
    param->Set("config", "INIT", "USE_SPLASH", CK_use_splash_screen->GetValue());
    param->Set("config", "INIT", "CLEAN_TMP_ON_EXIT", CK_cleanTmpOnExit->GetValue());

    param->Set("config", "VERIF_NOUVEAU", "traducteur", CK_avertirNouveau_traducteur->GetValue());
    param->Set("config", "VERIF_NOUVEAU", "langue", CK_avertirNouveau_langue->GetValue());
    param->Set("config", "VERIF_NOUVEAU", "pays", CK_avertirNouveau_pays->GetValue());
    param->Set("config", "VERIF_NOUVEAU", "serie_o", CK_avertirNouveau_serie_o->GetValue());
    param->Set("config", "VERIF_NOUVEAU", "localisation", CK_avertirNouveau_localisation->GetValue());
    param->Set("config", "VERIF_NOUVEAU", "etat", CK_avertirNouveau_etat->GetValue());
    param->Set("config", "VERIF_NOUVEAU", "artiste", CK_avertirNouveau_artiste->GetValue());
    param->Set("config", "VERIF_NOUVEAU", "format", CK_avertirNouveau_format->GetValue());
    param->Set("config", "VERIF_NOUVEAU", "editeur", CK_avertirNouveau_editeur->GetValue());
    param->Set("config", "VERIF_NOUVEAU", "genre", CK_avertirNouveau_genre->GetValue());
    param->Set("config", "VERIF_NOUVEAU", "serie", CK_avertirNouveau_serie->GetValue());
    param->Set("config", "VERIF_NOUVEAU", "auteur", CK_avertirNouveau_auteur->GetValue());

    BOOL useLargeurMaxColonnes = CK_use_largeur_max_colonnes->GetValue();
    long largeurMaxColonnes = 0;
    wxString str2 = ET_LargeurMaxColonnes->GetValue();
    sscanf(str2, "%ld", &largeurMaxColonnes);
    param->Set("config", "INIT", "LARGEUR_MAX_COLONNE", useLargeurMaxColonnes, largeurMaxColonnes);

    // ligne STAT / USE_TOP_N
    wxLogMessage("ParametreDlg::BN_OKClick() - ligne STAT / USE_TOP_N");
    BOOL useTopN = CK_useTopN->GetValue();
    long seuilTopN = 0;
    str2 = ET_ValueTopN->GetValue();
    sscanf(str2, "%ld", &seuilTopN);
    param->Set("config", "STAT", "USE_TOP_N", useTopN, seuilTopN);

    // lignes SAVE
    wxLogMessage("ParametreDlg::BN_OKClick() - ligne SAVE");
    BOOL useSave = CK_UseSauvegarde->GetValue();
    long frequence = 0;
    str2 = ET_FrequenceSauvegarde->GetValue();
    sscanf(str2, "%ld", &frequence);
    param->Set("config", "SAVE", "ACTIVE", useSave, frequence);
    long nbJours = 0;
    str2 = ET_NB_CONSERVATION->GetValue();
    sscanf(str2, "%ld", &nbJours);
    param->Set("config", "SAVE", "NB_CONSERVATION", nbJours);
    BOOL useDirSpec = RB_SauveDossierSpecifie->GetValue();
    wxString dirSpec = ET_Rep_Sauvegarde->GetValue();
    param->Set("config", "SAVE", "DIR_SAVE", useDirSpec, dirSpec);

    // lignes PROXY
    wxLogMessage("ParametreDlg::BN_OKClick() - ligne PROXY");
    param->Set("rech_internet", "PROXY", "UTILISE", (long)(WxCheckBox_proxy->GetValue()));
    param->Set("rech_internet", "PROXY", "ADRESSE", WxEdit_proxy_adr->GetValue());
    param->Set("rech_internet", "PROXY", "PORT", WxEdit_proxy_port->GetValue());
    param->Set("rech_internet", "PROXY", "USER", WxEdit_proxy_util->GetValue());
    param->Set("rech_internet", "PROXY", "PASS", WxEdit_proxy_pass->GetValue());
    param->Set("rech_internet", "NETWORK", "TIMEOUT", WxEdit_timeout->GetValue());
    
    
    // mettre à jour l'objet curl_util avec les paramètres de proxy
    curl_util* curl = curl_util::GetInstance();
    if (curl) {
        long port = 0;
        WxEdit_proxy_util->GetValue().ToLong(&port);
        curl->SetProxy(WxCheckBox_proxy->GetValue(), WxEdit_proxy_adr->GetValue(), (int)port, WxEdit_proxy_util->GetValue(), WxEdit_proxy_pass->GetValue());
        long timeout = 0;
        WxEdit_timeout->GetValue().ToLong(&timeout);
        curl->SetTimeout(timeout);
    }

    // lignes VERIF_VERSION
    wxLogMessage("ParametreDlg::BN_OKClick() - ligne VERIF_VERSION");
    param->Set("config", "INIT", "VERIF_VERSION", WxCheck_verifVersion->GetValue());
        
    // fermer la fenêtre
	this->EndDialog(0);
	this->Destroy();

    wxLogMessage("ParametreDlg::BN_OKClick() - sortie");
}

/*
 * BN_CANCELClick
 */
void ParametreDlg::BN_CANCELClick(wxCommandEvent& event)
{
    // fermer la fenêtre
	this->EndDialog(0);
    this->Destroy();
}

/*
 * CK_useTopNClick
 */
void ParametreDlg::CK_useTopNClick(wxCommandEvent& event)
{
    // rendre actif / inactif le champ de saisie ET_valueTopN
    if (CK_useTopN->GetValue())
        ET_ValueTopN->Enable();
    else
        ET_ValueTopN->Disable();
}

/*
 * ParametreDlgInitDialog
 */
void ParametreDlg::ParametreDlgInitDialog(wxInitDialogEvent& event)
{
	// initialiser en fonction des valeurs présentes en base
	ParamManager* param = ParamManager::GetInstance("config");
	if (!param) {
        wxMessageBox ("instance de ParamManager non créée");
        return;
    }

    // onglet général
    BOOL useSplashScreen = true;
    param->GetOrSet("config", "INIT", "USE_SPLASH", useSplashScreen);    
    CK_use_splash_screen->SetValue(useSplashScreen);
    
    BOOL cleanTmpOnExit = false;
    param->GetOrSet("config", "INIT", "CLEAN_TMP_ON_EXIT", cleanTmpOnExit);    
    CK_cleanTmpOnExit->SetValue(cleanTmpOnExit);
    
    BOOL useLargeurMaxColonnes = false;
    long largeurMaxColonnes = 0;
    param->GetOrSet("config", "INIT", "LARGEUR_MAX_COLONNE", useLargeurMaxColonnes, largeurMaxColonnes);    
    if (useLargeurMaxColonnes) {
       CK_use_largeur_max_colonnes->SetValue(true);
	   ET_LargeurMaxColonnes->Enable();
    } else {
       CK_use_largeur_max_colonnes->SetValue(false);
	   ET_LargeurMaxColonnes->Disable();
    }
    wxString str_largeurMaxColonnes;
    str_largeurMaxColonnes.Printf("%ld", largeurMaxColonnes);
    ET_LargeurMaxColonnes->SetValue(str_largeurMaxColonnes);
    
    
    BOOL avertirNouveau = true;
    param->GetOrSet("config", "VERIF_NOUVEAU", "auteur", avertirNouveau);
	CK_avertirNouveau_auteur->SetValue(avertirNouveau);
	
	avertirNouveau = true;
    param->GetOrSet("config", "VERIF_NOUVEAU", "traducteur", avertirNouveau);
    CK_avertirNouveau_traducteur->SetValue(avertirNouveau);

	avertirNouveau = true;
    param->GetOrSet("config", "VERIF_NOUVEAU", "langue", avertirNouveau);
    CK_avertirNouveau_langue->SetValue(avertirNouveau);

	avertirNouveau = true;
    param->GetOrSet("config", "VERIF_NOUVEAU", "pays", avertirNouveau);
    CK_avertirNouveau_pays->SetValue(avertirNouveau);

	avertirNouveau = true;
    param->GetOrSet("config", "VERIF_NOUVEAU", "serie_o", avertirNouveau);
    CK_avertirNouveau_serie_o->SetValue(avertirNouveau);

	avertirNouveau = true;
    param->GetOrSet("config", "VERIF_NOUVEAU", "localisation", avertirNouveau);
    CK_avertirNouveau_localisation->SetValue(avertirNouveau);

	avertirNouveau = true;
    param->GetOrSet("config", "VERIF_NOUVEAU", "etat", avertirNouveau);
    CK_avertirNouveau_etat->SetValue(avertirNouveau);

	avertirNouveau = true;
    param->GetOrSet("config", "VERIF_NOUVEAU", "artiste", avertirNouveau);
    CK_avertirNouveau_artiste->SetValue(avertirNouveau);

	avertirNouveau = true;
    param->GetOrSet("config", "VERIF_NOUVEAU", "format", avertirNouveau);
    CK_avertirNouveau_format->SetValue(avertirNouveau);

	avertirNouveau = true;
    param->GetOrSet("config", "VERIF_NOUVEAU", "editeur", avertirNouveau);
    CK_avertirNouveau_editeur->SetValue(avertirNouveau);

	avertirNouveau = true;
    param->GetOrSet("config", "VERIF_NOUVEAU", "genre", avertirNouveau);
    CK_avertirNouveau_genre->SetValue(avertirNouveau);

	avertirNouveau = true;
    param->GetOrSet("config", "VERIF_NOUVEAU", "serie", avertirNouveau);
    CK_avertirNouveau_serie->SetValue(avertirNouveau);

    
    // onglet Statistiques
    BOOL val1 = true;
    long val2 = 20;
    param->GetOrSet("config", "STAT", "USE_TOP_N", val1, val2);
    if (val1) {
       CK_useTopN->SetValue(true);
	   ET_ValueTopN->Enable();
    } else {
       CK_useTopN->SetValue(false);
	   ET_ValueTopN->Disable();
    }
    wxString str2;
    str2.Printf("%ld", val2);
    ET_ValueTopN->SetValue(str2);
    
    // onglet Sauvegardes
    val1 = false;
    val2 = 1;
    param->GetOrSet("config", "SAVE", "ACTIVE", val1, val2);
    if (val1) {
        CK_UseSauvegarde->SetValue(true);
        ET_NB_CONSERVATION->Enable();
        ET_FrequenceSauvegarde->Enable();
    } else {
        CK_UseSauvegarde->SetValue(false);
        ET_NB_CONSERVATION->Disable();
        ET_FrequenceSauvegarde->Disable();
    }
    str2.Printf("%ld", val2);
    ET_FrequenceSauvegarde->SetValue(str2);

    val2 = 1;
    param->GetOrSet("config", "SAVE", "NB_CONSERVATION", val2);
    str2.Printf("%ld", val2);
    ET_NB_CONSERVATION->SetValue(str2);
    
    BOOL useDirSpec = false;
    wxString dirSpec;
    param->GetOrSet("config", "SAVE", "DIR_SAVE", useDirSpec, dirSpec);
    RB_SauveDossierSpecifie->SetValue(useDirSpec);
    RB_SauveDossierBase->SetValue(!useDirSpec);
    ET_Rep_Sauvegarde->SetValue(dirSpec);
    if (useDirSpec) {
        ET_Rep_Sauvegarde->Enable();
    } else {
        ET_Rep_Sauvegarde->Disable();
    }
    
    // onglet Réseau
    long valLong = 0;
    param->GetOrSet("rech_internet", "PROXY", "UTILISE", valLong);
    WxCheckBox_proxy->SetValue((bool)valLong);
    change_etat_proxy();
    
    wxString str1 = "";
    param->GetOrSet("rech_internet", "PROXY", "ADRESSE", str1);
    WxEdit_proxy_adr->SetValue(str1);

    valLong = 0;
    param->GetOrSet("rech_internet", "PROXY", "PORT", valLong);
    str1.Printf("%ld", valLong);
    WxEdit_proxy_port->SetValue(str1);

    str1 = "";
    param->GetOrSet("rech_internet", "PROXY", "USER", str1);
    WxEdit_proxy_util->SetValue(str1);

    str1 = "";
    param->GetOrSet("rech_internet", "PROXY", "PASS", str1);
    WxEdit_proxy_pass->SetValue(str1);

    BOOL verifVersion = true;
    param->GetOrSet("config", "INIT", "VERIF_VERSION", verifVersion);
    WxCheck_verifVersion->SetValue(verifVersion);

    valLong = 10;
    param->GetOrSet("rech_internet", "NETWORK", "TIMEOUT", valLong);
    str1.Printf("%ld", valLong);
    WxEdit_timeout->SetValue(str1);
}

/*
 * CK_use_largeur_max_colonnesClick
 */
void ParametreDlg::CK_use_largeur_max_colonnesClick(wxCommandEvent& event)
{
    // rendre actif / inactif le champ de saisie ET_valueTopN
    if (CK_use_largeur_max_colonnes->GetValue())
        ET_LargeurMaxColonnes->Enable();
    else
        ET_LargeurMaxColonnes->Disable();
}

/*
 * CK_UseSauvegardeClick
 */
void ParametreDlg::CK_UseSauvegardeClick(wxCommandEvent& event)
{
    // rendre actifs / inactifs les champs de saisie ET_NB_CONSERVATION et ET_FrequenceSauvegarde
    if (CK_UseSauvegarde->GetValue()) {
        ET_NB_CONSERVATION->Enable();
        ET_FrequenceSauvegarde->Enable();
        ET_Rep_Sauvegarde->Enable();
        RB_SauveDossierSpecifie->Enable();
        RB_SauveDossierBase->Enable();
    } else {
        ET_NB_CONSERVATION->Disable();
        ET_FrequenceSauvegarde->Disable();
        ET_Rep_Sauvegarde->Disable();
        RB_SauveDossierSpecifie->Disable();
        RB_SauveDossierBase->Disable();
    }
}

/*
 * RB_SauveDossierBaseClick
 */
void ParametreDlg::RB_SauveDossierBaseClick(wxCommandEvent& event)
{
    if (RB_SauveDossierSpecifie->GetValue()) {
        ET_Rep_Sauvegarde->Enable();
    } else {
        ET_Rep_Sauvegarde->Disable();
    }
}

/*
 * RB_SauveDossierSpecifieClick
 */
void ParametreDlg::RB_SauveDossierSpecifieClick(wxCommandEvent& event)
{
    if (RB_SauveDossierSpecifie->GetValue()) {
        ET_Rep_Sauvegarde->Enable();
    } else {
        ET_Rep_Sauvegarde->Disable();
    }
}

/*
 * BN_ParcourirSaveClick
 */
void ParametreDlg::BN_ParcourirSaveClick(wxCommandEvent& event)
{
	wxString dir = wxDirSelector("Choisissez le répertoire de sauvegarde", ET_Rep_Sauvegarde->GetValue());
	if (!dir.empty())  // si vide : utilisateur a fait "cancel" dans la fenêtre de sélection
    	ET_Rep_Sauvegarde->SetValue(dir);
}

void ParametreDlg::WxCheckBox_proxyClick(wxCommandEvent& event)
{
    change_etat_proxy();
	// insert your code here
	event.Skip();
}

void ParametreDlg::change_etat_proxy(){
    bool etat_check;
    
    etat_check=WxCheckBox_proxy->IsChecked();
    WxEdit_proxy_pass->Enable(etat_check);
    WxEdit_proxy_util->Enable(etat_check);
    WxEdit_proxy_port->Enable(etat_check);
    WxEdit_proxy_adr->Enable(etat_check);
}
