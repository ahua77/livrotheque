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
	EVT_SIZE(ParametreDlg::ParametreDlgSize)
	EVT_INIT_DIALOG(ParametreDlg::ParametreDlgInitDialog)
	EVT_BUTTON(wxID_OK, ParametreDlg::BN_OKClick)
	EVT_BUTTON(wxID_CANCEL, ParametreDlg::BN_CANCELClick)
	EVT_CHECKBOX(ID_WXCHECKBOX_PROXY,ParametreDlg::WxCheckBox_proxyClick)
	EVT_BUTTON(ID_BN_PARCOURIRSAVE,ParametreDlg::BN_ParcourirSaveClick)
	EVT_RADIOBUTTON(ID_RB_SAUVEDOSSIERSPECIFIE,ParametreDlg::RB_SauveDossierSpecifieClick)
	EVT_RADIOBUTTON(ID_RB_SAUVEDOSSIERBASE,ParametreDlg::RB_SauveDossierBaseClick)
	EVT_CHECKBOX(ID_CK_USESAUVEGARDE,ParametreDlg::CK_UseSauvegardeClick)
	EVT_CHECKBOX(ID_CK_USETOPN,ParametreDlg::CK_useTopNClick)
	EVT_CHECKBOX(ID_WX_CK_USE_LARGEUR_MAX_COLONNES,ParametreDlg::CK_use_largeur_max_colonnesClick)
	
	EVT_NOTEBOOK_PAGE_CHANGED(ID_WXNOTEBOOK1,ParametreDlg::WxNotebook1PageChanged)
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
	ParamManager* param = ParamManager::GetInstance("config");
    long taillePolice = 10;
    param->GetOrSet("config", "INIT", "TAILLE_POLICE", taillePolice);
    wxFont fonte = GetFont();
    fonte.SetPointSize(taillePolice);
    SetFont(fonte);
    
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	this->SetSizer(WxBoxSizer1);
	this->SetAutoLayout(true);

	WxBoxSizer2 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer1->Add(WxBoxSizer2, 1, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	WxNotebook1 = new wxNotebook(this, ID_WXNOTEBOOK1, wxPoint(5, 5), wxSize(460, 341), wxNB_DEFAULT | wxNB_MULTILINE);
	WxBoxSizer2->Add(WxNotebook1,1,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	WxNoteBookPage4 = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE4, wxPoint(4, 26), wxSize(452, 311));
	WxNotebook1->AddPage(WxNoteBookPage4, wxT("Général"));

	WxBoxSizer10 = new wxBoxSizer(wxVERTICAL);
	WxNoteBookPage4->SetSizer(WxBoxSizer10);
	WxNoteBookPage4->SetAutoLayout(true);

	WxBoxSizer25 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer10->Add(WxBoxSizer25, 0, wxALIGN_CENTER | wxEXPAND | wxALL, 0);

	WxStaticText7 = new wxStaticText(WxNoteBookPage4, ID_WXSTATICTEXT21, wxT("Taille des caractères pour l'affichage"), wxPoint(5, 5), wxDefaultSize, 0, wxT("WxStaticText7"));
	WxBoxSizer25->Add(WxStaticText7,0,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	ET_TaillePoliceAffichage = new wxTextCtrl(WxNoteBookPage4, ID_WX_ET_TAILLE_POLICE_AFFICHAGE, wxT("ET_TaillePoliceAffichage"), wxPoint(210, 5), wxSize(46, 19), 0, wxDefaultValidator, wxT("ET_TaillePoliceAffichage"));
	WxBoxSizer25->Add(ET_TaillePoliceAffichage,0,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	WxStaticLine2 = new wxStaticLine(WxNoteBookPage4, ID_WXSTATICLINE2, wxPoint(5, 34), wxSize(422, -1), wxLI_HORIZONTAL);
	WxBoxSizer10->Add(WxStaticLine2,0,wxALIGN_CENTER | wxALL,5);

	WxBoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer10->Add(WxBoxSizer11, 0, wxALIGN_CENTER | wxEXPAND | wxALL, 0);

	WxStaticText2 = new wxStaticText(WxNoteBookPage4, ID_WXSTATICTEXT2, wxT("Avertir avant de créer un nouveau groupe des types cochés ci-dessous :"), wxPoint(5, 5), wxDefaultSize, 0, wxT("WxStaticText2"));
	WxBoxSizer11->Add(WxStaticText2,0,wxALIGN_CENTER | wxALL,5);

	WxGridSizer3 = new wxGridSizer(0, 3, 0, 0);
	WxBoxSizer10->Add(WxGridSizer3, 0, wxALIGN_CENTER | wxEXPAND | wxALL, 0);

	CK_avertirNouveau_auteur = new wxCheckBox(WxNoteBookPage4, ID_WX_CK_avertirNouveau_auteur, wxT("Auteurs"), wxPoint(11, 3), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_auteur"));
	WxGridSizer3->Add(CK_avertirNouveau_auteur,1,wxALIGN_LEFT | wxEXPAND | wxALL,3);

	CK_avertirNouveau_format = new wxCheckBox(WxNoteBookPage4, ID_WX_CK_avertirNouveau_format, wxT("Formats"), wxPoint(130, 3), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_format"));
	WxGridSizer3->Add(CK_avertirNouveau_format,1,wxALIGN_LEFT | wxEXPAND | wxALL,3);

	CK_avertirNouveau_serie_o = new wxCheckBox(WxNoteBookPage4, ID_WX_CK_avertirNouveau_serie_o, wxT("Séries originales"), wxPoint(241, 3), wxSize(113, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_serie_o"));
	WxGridSizer3->Add(CK_avertirNouveau_serie_o,1,wxALIGN_LEFT | wxEXPAND | wxALL,3);

	CK_avertirNouveau_serie = new wxCheckBox(WxNoteBookPage4, ID_WX_CK_avertirNouveau_serie, wxT("Séries"), wxPoint(11, 26), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_serie"));
	WxGridSizer3->Add(CK_avertirNouveau_serie,1,wxALIGN_LEFT | wxEXPAND | wxALL,3);

	CK_avertirNouveau_artiste = new wxCheckBox(WxNoteBookPage4, ID_WX_CK_avertirNouveau_artiste, wxT("Artistes"), wxPoint(130, 26), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_artiste"));
	WxGridSizer3->Add(CK_avertirNouveau_artiste,1,wxALIGN_LEFT | wxEXPAND | wxALL,3);

	CK_avertirNouveau_pays = new wxCheckBox(WxNoteBookPage4, ID_WX_CK_avertirNouveau_pays, wxT("Pays"), wxPoint(249, 26), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_pays"));
	WxGridSizer3->Add(CK_avertirNouveau_pays,1,wxALIGN_LEFT | wxEXPAND | wxALL,3);

	CK_avertirNouveau_genre = new wxCheckBox(WxNoteBookPage4, ID_WX_CK_avertirNouveau_genre, wxT("Genres"), wxPoint(11, 49), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_genre"));
	WxGridSizer3->Add(CK_avertirNouveau_genre,1,wxALIGN_LEFT | wxEXPAND | wxALL,3);

	CK_avertirNouveau_etat = new wxCheckBox(WxNoteBookPage4, ID_WX_CK_avertirNouveau_etat, wxT("Etats"), wxPoint(130, 49), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_etat"));
	WxGridSizer3->Add(CK_avertirNouveau_etat,1,wxALIGN_LEFT | wxEXPAND | wxALL,3);

	CK_avertirNouveau_langue = new wxCheckBox(WxNoteBookPage4, ID_WX_CK_avertirNouveau_langue, wxT("Langues"), wxPoint(249, 49), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_langue"));
	WxGridSizer3->Add(CK_avertirNouveau_langue,1,wxALIGN_LEFT | wxEXPAND | wxALL,3);

	CK_avertirNouveau_editeur = new wxCheckBox(WxNoteBookPage4, ID_WX_CK_avertirNouveau_editeur, wxT("Editeurs"), wxPoint(11, 72), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_editeur"));
	WxGridSizer3->Add(CK_avertirNouveau_editeur,1,wxALIGN_LEFT | wxEXPAND | wxALL,3);

	CK_avertirNouveau_localisation = new wxCheckBox(WxNoteBookPage4, ID_WX_CK_avertirNouveau_localisation, wxT("Localisations"), wxPoint(130, 72), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_localisation"));
	WxGridSizer3->Add(CK_avertirNouveau_localisation,1,wxALIGN_LEFT | wxEXPAND | wxALL,3);

	CK_avertirNouveau_traducteur = new wxCheckBox(WxNoteBookPage4, ID_WX_CK_avertirNouveau_traducteur, wxT("Traducteurs"), wxPoint(249, 72), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_traducteur"));
	WxGridSizer3->Add(CK_avertirNouveau_traducteur,1,wxALIGN_LEFT | wxEXPAND | wxALL,3);

	WxStaticLine3 = new wxStaticLine(WxNoteBookPage4, ID_WXSTATICLINE3, wxPoint(5, 172), wxSize(422, -1), wxLI_HORIZONTAL);
	WxBoxSizer10->Add(WxStaticLine3,0,wxALIGN_CENTER | wxALL,5);

	WxBoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer10->Add(WxBoxSizer12, 0, wxALIGN_LEFT | wxEXPAND | wxALL, 0);

	CK_use_splash_screen = new wxCheckBox(WxNoteBookPage4, ID_WX_CK_UseSplashScreen, wxT("Afficher l'écran de démarrage"), wxPoint(5, 5), wxSize(185, 17), 0, wxDefaultValidator, wxT("CK_use_splash_screen"));
	WxBoxSizer12->Add(CK_use_splash_screen,1,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	WxBoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer10->Add(WxBoxSizer13, 0, wxALIGN_CENTER | wxEXPAND | wxALL, 0);

	CK_cleanTmpOnExit = new wxCheckBox(WxNoteBookPage4, ID_WX_CK_CLEAN_TMP_ON_EXIT, wxT("Effacer les fichiers temporaires en quittant le programme"), wxPoint(5, 5), wxSize(402, 17), 0, wxDefaultValidator, wxT("CK_cleanTmpOnExit"));
	WxBoxSizer13->Add(CK_cleanTmpOnExit,1,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	WxStaticLine4 = new wxStaticLine(WxNoteBookPage4, ID_WXSTATICLINE4, wxPoint(5, 243), wxSize(422, -1), wxLI_HORIZONTAL);
	WxBoxSizer10->Add(WxStaticLine4,0,wxALIGN_CENTER | wxALL,5);

	WxBoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer10->Add(WxBoxSizer14, 0, wxALIGN_CENTER | wxEXPAND | wxALL, 0);

	CK_use_largeur_max_colonnes = new wxCheckBox(WxNoteBookPage4, ID_WX_CK_USE_LARGEUR_MAX_COLONNES, wxT(" "), wxPoint(5, 6), wxSize(16, 17), 0, wxDefaultValidator, wxT("CK_use_largeur_max_colonnes"));
	WxBoxSizer14->Add(CK_use_largeur_max_colonnes,0,wxALIGN_CENTER | wxALL,5);

	WxStaticText21 = new wxStaticText(WxNoteBookPage4, ID_WXSTATICTEXT21, wxT("Limiter les colonnes à environ "), wxPoint(31, 5), wxDefaultSize, 0, wxT("WxStaticText21"));
	WxBoxSizer14->Add(WxStaticText21,50,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	ET_LargeurMaxColonnes = new wxTextCtrl(WxNoteBookPage4, ID_WX_ET_LARGEUR_MAX_COLONNES, wxT("ET_LargeurMaxColonnes"), wxPoint(205, 5), wxSize(46, 19), 0, wxDefaultValidator, wxT("ET_LargeurMaxColonnes"));
	WxBoxSizer14->Add(ET_LargeurMaxColonnes,10,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	WxStaticText3 = new wxStaticText(WxNoteBookPage4, ID_WXSTATICTEXT3, wxT("caractères de large"), wxPoint(261, 5), wxDefaultSize, 0, wxT("WxStaticText3"));
	WxBoxSizer14->Add(WxStaticText3,40,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	WxNoteBookPage2 = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE2, wxPoint(4, 26), wxSize(452, 311));
	WxNotebook1->AddPage(WxNoteBookPage2, wxT("Statistiques"));

	WxBoxSizer17 = new wxBoxSizer(wxVERTICAL);
	WxNoteBookPage2->SetSizer(WxBoxSizer17);
	WxNoteBookPage2->SetAutoLayout(true);

	WxBoxSizer18 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer17->Add(WxBoxSizer18, 0, wxALIGN_LEFT | wxEXPAND | wxALL, 5);

	CK_useTopN = new wxCheckBox(WxNoteBookPage2, ID_CK_USETOPN, wxT(""), wxPoint(5, 6), wxSize(21, 17), 0, wxDefaultValidator, wxT("CK_useTopN"));
	WxBoxSizer18->Add(CK_useTopN,0,wxALIGN_LEFT | wxEXPAND | wxALL,5);

	WxStaticText10 = new wxStaticText(WxNoteBookPage2, ID_WXSTATICTEXT10, wxT("Limiter l'affichage aux "), wxPoint(36, 5), wxDefaultSize, 0, wxT("WxStaticText10"));
	WxBoxSizer18->Add(WxStaticText10,50,wxALIGN_LEFT | wxEXPAND | wxALL,5);

	ET_ValueTopN = new wxTextCtrl(WxNoteBookPage2, ID_ET_VALUETOPN, wxT("ET_ValueTopN"), wxPoint(169, 5), wxSize(41, 19), 0, wxDefaultValidator, wxT("ET_ValueTopN"));
	WxBoxSizer18->Add(ET_ValueTopN,10,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	WxStaticText1 = new wxStaticText(WxNoteBookPage2, ID_WXSTATICTEXT1, wxT("premiers résultats"), wxPoint(220, 5), wxDefaultSize, 0, wxT("WxStaticText1"));
	WxBoxSizer18->Add(WxStaticText1,40,wxALIGN_LEFT | wxEXPAND | wxALL,5);

	WxStaticLine1 = new wxStaticLine(WxNoteBookPage2, ID_WXSTATICLINE1, wxPoint(5, 44), wxSize(422, -1), wxLI_HORIZONTAL);
	WxBoxSizer17->Add(WxStaticLine1,0,wxALIGN_CENTER | wxALL,5);

	WxNoteBookPage3 = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE3, wxPoint(4, 26), wxSize(452, 311));
	WxNotebook1->AddPage(WxNoteBookPage3, wxT("Sauvegarde"));

	WxBoxSizer19 = new wxBoxSizer(wxVERTICAL);
	WxNoteBookPage3->SetSizer(WxBoxSizer19);
	WxNoteBookPage3->SetAutoLayout(true);

	WxBoxSizer24 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer19->Add(WxBoxSizer24, 0, wxALIGN_LEFT | wxEXPAND | wxALL, 5);

	CK_UseSauvegarde = new wxCheckBox(WxNoteBookPage3, ID_CK_USESAUVEGARDE, wxT("Activer les sauvegardes automatiques de la base"), wxPoint(5, 5), wxSize(282, 17), 0, wxDefaultValidator, wxT("CK_UseSauvegarde"));
	WxBoxSizer24->Add(CK_UseSauvegarde,1,wxALIGN_LEFT | wxEXPAND | wxALL,5);

	WxFlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
	WxBoxSizer19->Add(WxFlexGridSizer1, 0, wxALIGN_LEFT | wxEXPAND | wxLEFT, 5);

	WxStaticText4 = new wxStaticText(WxNoteBookPage3, ID_WXSTATICTEXT4, wxT("Fréquence de sauvegarde :"), wxPoint(32, 5), wxDefaultSize, 0, wxT("WxStaticText4"));
	WxFlexGridSizer1->Add(WxStaticText4,0,wxALIGN_LEFT | wxEXPAND | wxALL,5);

	ET_FrequenceSauvegarde = new wxTextCtrl(WxNoteBookPage3, ID_ET_FREQUENCESAUVEGARDE, wxT("ET_FrequenceSauvegarde"), wxPoint(214, 5), wxSize(59, 19), 0, wxDefaultValidator, wxT("ET_FrequenceSauvegarde"));
	WxFlexGridSizer1->Add(ET_FrequenceSauvegarde,0,wxALIGN_LEFT | wxEXPAND | wxALL,5);

	WxStaticText6 = new wxStaticText(WxNoteBookPage3, ID_WXSTATICTEXT6, wxT("jours"), wxPoint(283, 5), wxDefaultSize, 0, wxT("WxStaticText6"));
	WxFlexGridSizer1->Add(WxStaticText6,0,wxALIGN_LEFT | wxEXPAND | wxALL,5);

	WxStaticText5 = new wxStaticText(WxNoteBookPage3, ID_WXSTATICTEXT5, wxT("Nombre de sauvegardes conservées :"), wxPoint(5, 34), wxDefaultSize, 0, wxT("WxStaticText5"));
	WxFlexGridSizer1->Add(WxStaticText5,0,wxALIGN_LEFT | wxEXPAND | wxALL,5);

	ET_NB_CONSERVATION = new wxTextCtrl(WxNoteBookPage3, ID_ET_NB_CONSERVATION, wxT("ET_NB_CONSERVATION"), wxPoint(214, 34), wxSize(59, 19), 0, wxDefaultValidator, wxT("ET_NB_CONSERVATION"));
	WxFlexGridSizer1->Add(ET_NB_CONSERVATION,0,wxALIGN_LEFT | wxEXPAND | wxALL,5);

	WxBoxSizer20 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer19->Add(WxBoxSizer20, 0, wxALIGN_LEFT | wxEXPAND | wxLEFT, 5);

	WxStaticText11 = new wxStaticText(WxNoteBookPage3, ID_WXSTATICTEXT11, wxT("Emplacement de la sauvegarde :"), wxPoint(5, 5), wxDefaultSize, 0, wxT("WxStaticText11"));
	WxBoxSizer20->Add(WxStaticText11,1,wxALIGN_LEFT | wxEXPAND | wxALL,5);

	WxBoxSizer21 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer19->Add(WxBoxSizer21, 0, wxALIGN_LEFT | wxEXPAND | wxALL, 5);

	RB_SauveDossierBase = new wxRadioButton(WxNoteBookPage3, ID_RB_SAUVEDOSSIERBASE, wxT("Dans le sous-dossier \"sauvegardes\" du dossier de la base de données"), wxPoint(5, 0), wxSize(385, 17), 0, wxDefaultValidator, wxT("RB_SauveDossierBase"));
	WxBoxSizer21->Add(RB_SauveDossierBase,1,wxALIGN_LEFT | wxEXPAND | wxLEFT,5);

	WxBoxSizer22 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer19->Add(WxBoxSizer22, 0, wxALIGN_LEFT | wxEXPAND | wxLEFT, 5);

	RB_SauveDossierSpecifie = new wxRadioButton(WxNoteBookPage3, ID_RB_SAUVEDOSSIERSPECIFIE, wxT("Dans le dossier ci-dessous :"), wxPoint(5, 0), wxSize(168, 17), 0, wxDefaultValidator, wxT("RB_SauveDossierSpecifie"));
	WxBoxSizer22->Add(RB_SauveDossierSpecifie,1,wxALIGN_LEFT | wxEXPAND | wxLEFT,5);

	WxBoxSizer23 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer19->Add(WxBoxSizer23, 0, wxALIGN_LEFT | wxEXPAND | wxALL, 5);

	ET_Rep_Sauvegarde = new wxTextCtrl(WxNoteBookPage3, ID_ET_REP_SAUVEGARDE, wxT("ET_Rep_Sauvegarde"), wxPoint(10, 1), wxSize(329, 19), 0, wxDefaultValidator, wxT("ET_Rep_Sauvegarde"));
	WxBoxSizer23->Add(ET_Rep_Sauvegarde,1,wxALIGN_LEFT | wxEXPAND | wxLEFT,10);

	BN_ParcourirSave = new wxButton(WxNoteBookPage3, ID_BN_PARCOURIRSAVE, wxT("..."), wxPoint(339, 0), wxSize(31, 22), 0, wxDefaultValidator, wxT("BN_ParcourirSave"));
	WxBoxSizer23->Add(BN_ParcourirSave,0,wxALIGN_CENTER | wxEXPAND | wxALL,0);

	WxStaticLine7 = new wxStaticLine(WxNoteBookPage3, ID_WXSTATICLINE7, wxPoint(5, 205), wxSize(402, -1), wxLI_HORIZONTAL);
	WxBoxSizer19->Add(WxStaticLine7,0,wxALIGN_CENTER | wxALL,5);

	WxST_Sauvegarde_1 = new wxStaticText(WxNoteBookPage3, ID_WXSTATICTEXT8, wxT("Une sauvegarde est réalisée à la fermeture de la base de données, si "), wxPoint(26, 222), wxDefaultSize, 0, wxT("WxST_Sauvegarde_1"));
	WxBoxSizer19->Add(WxST_Sauvegarde_1,0,wxALIGN_CENTER | wxALL,5);

	WxST_Sauvegarde_2 = new wxStaticText(WxNoteBookPage3, ID_WXSTATICTEXT7, wxT("la précédente sauvegarde est plus ancienne que la fréquence demandée."), wxPoint(13, 251), wxDefaultSize, 0, wxT("WxST_Sauvegarde_2"));
	WxBoxSizer19->Add(WxST_Sauvegarde_2,0,wxALIGN_CENTER | wxALL,5);

	WxNoteBookPage7 = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE7, wxPoint(4, 26), wxSize(452, 311));
	WxNotebook1->AddPage(WxNoteBookPage7, wxT("Réseau"));

	WxBoxSizer8 = new wxBoxSizer(wxVERTICAL);
	WxNoteBookPage7->SetSizer(WxBoxSizer8);
	WxNoteBookPage7->SetAutoLayout(true);

	WxBoxSizer16 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer8->Add(WxBoxSizer16, 0, wxALIGN_CENTER | wxEXPAND | wxALL, 0);

	WxCheckBox_proxy = new wxCheckBox(WxNoteBookPage7, ID_WXCHECKBOX_PROXY, wxT("Utiliser un proxy"), wxPoint(5, 5), wxSize(114, 15), 0, wxDefaultValidator, wxT("WxCheckBox_proxy"));
	WxCheckBox_proxy->SetToolTip(wxT("Cochez si votre connexion internet utilise un proxy"));
	WxCheckBox_proxy->SetHelpText(wxT("Cocher la case si vous voulez utiliser un proxy"));
	WxBoxSizer16->Add(WxCheckBox_proxy,1,wxALIGN_LEFT | wxEXPAND | wxALL,5);

	wxStaticBox* WxStaticBoxSizer1_StaticBoxObj = new wxStaticBox(WxNoteBookPage7, wxID_ANY, wxT("Paramètres du proxy"));
	WxStaticBoxSizer1 = new wxStaticBoxSizer(WxStaticBoxSizer1_StaticBoxObj, wxHORIZONTAL);
	WxBoxSizer8->Add(WxStaticBoxSizer1, 0, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	WxGridSizer2 = new wxFlexGridSizer(0, 4, 0, 0);
	WxStaticBoxSizer1->Add(WxGridSizer2, 1, wxALIGN_CENTER | wxEXPAND | wxALL, 0);

	WxStaticText_proxy_adr = new wxStaticText(WxNoteBookPage7, ID_WXSTATICTEXT_PROXY_ADR, wxT("Adresse : "), wxPoint(5, 6), wxDefaultSize, 0, wxT("WxStaticText_proxy_adr"));
	WxGridSizer2->Add(WxStaticText_proxy_adr,1,wxALIGN_CENTER | wxALL,5);

	WxEdit_proxy_adr = new wxTextCtrl(WxNoteBookPage7, ID_WXEDIT_PROXY_ADR, wxT(""), wxPoint(69, 5), wxSize(142, 21), 0, wxDefaultValidator, wxT("WxEdit_proxy_adr"));
	WxEdit_proxy_adr->Enable(false);
	WxGridSizer2->Add(WxEdit_proxy_adr,1,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	WxStaticText_proxy_util = new wxStaticText(WxNoteBookPage7, ID_WXSTATICTEXT_PROXY_UTIL, wxT("Utilisateur : "), wxPoint(222, 6), wxDefaultSize, 0, wxT("WxStaticText_proxy_util"));
	WxGridSizer2->Add(WxStaticText_proxy_util,1,wxALIGN_CENTER | wxALL,5);

	WxEdit_proxy_util = new wxTextCtrl(WxNoteBookPage7, ID_WXEDIT_PROXY_UTIL, wxT(""), wxPoint(299, 5), wxSize(136, 21), 0, wxDefaultValidator, wxT("WxEdit_proxy_util"));
	WxEdit_proxy_util->Enable(false);
	WxGridSizer2->Add(WxEdit_proxy_util,1,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	WxStaticText_proxy_port = new wxStaticText(WxNoteBookPage7, ID_WXSTATICTEXT_PROXY_PORT, wxT("Port : "), wxPoint(14, 37), wxDefaultSize, 0, wxT("WxStaticText_proxy_port"));
	WxGridSizer2->Add(WxStaticText_proxy_port,1,wxALIGN_CENTER | wxALL,5);

	WxEdit_proxy_port = new wxTextCtrl(WxNoteBookPage7, ID_WXEDIT_PROXY_PORT, wxT(""), wxPoint(69, 36), wxSize(143, 21), 0, wxDefaultValidator, wxT("WxEdit_proxy_port"));
	WxEdit_proxy_port->Enable(false);
	WxGridSizer2->Add(WxEdit_proxy_port,1,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	WxStaticText_proxy_pass = new wxStaticText(WxNoteBookPage7, ID_WXSTATICTEXT_PROXY_PASS, wxT("Password : "), wxPoint(223, 37), wxDefaultSize, 0, wxT("WxStaticText_proxy_pass"));
	WxGridSizer2->Add(WxStaticText_proxy_pass,1,wxALIGN_CENTER | wxALL,5);

	WxEdit_proxy_pass = new wxTextCtrl(WxNoteBookPage7, ID_WXEDIT_PROXY_PASS, wxT(""), wxPoint(298, 36), wxSize(138, 21), wxTE_PASSWORD, wxDefaultValidator, wxT("WxEdit_proxy_pass"));
	WxEdit_proxy_pass->Enable(false);
	WxGridSizer2->Add(WxEdit_proxy_pass,1,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	WxBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer8->Add(WxBoxSizer9, 0, wxALIGN_LEFT | wxEXPAND | wxALL, 5);

	WxStaticText9 = new wxStaticText(WxNoteBookPage7, ID_WXSTATICTEXT9, wxT("Timeout (secondes)"), wxPoint(5, 5), wxDefaultSize, 0, wxT("WxStaticText9"));
	WxBoxSizer9->Add(WxStaticText9,0,wxALIGN_CENTER | wxALL,5);

	WxEdit_timeout = new wxTextCtrl(WxNoteBookPage7, ID_WX_TIMEOUT, wxT("WxEdit_timeout"), wxPoint(124, 5), wxSize(121, 19), 0, wxDefaultValidator, wxT("WxEdit_timeout"));
	WxBoxSizer9->Add(WxEdit_timeout,0,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	WxBoxSizer15 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer8->Add(WxBoxSizer15, 0, wxALIGN_CENTER | wxEXPAND | wxALL, 0);

	WxCheck_verifVersion = new wxCheckBox(WxNoteBookPage7, ID_WXCHECK_VERIFVERSION, wxT("Vérifier la dernière version au lancement du programme"), wxPoint(5, 5), wxSize(315, 17), 0, wxDefaultValidator, wxT("WxCheck_verifVersion"));
	WxBoxSizer15->Add(WxCheck_verifVersion,1,wxALIGN_LEFT | wxEXPAND | wxALL,5);

	WxNoteBookPage5 = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE5, wxPoint(4, 26), wxSize(452, 311));
	WxNotebook1->AddPage(WxNoteBookPage5, wxT("Impressions"));

	WxBoxSizer4 = new wxBoxSizer(wxVERTICAL);
	WxNoteBookPage5->SetSizer(WxBoxSizer4);
	WxNoteBookPage5->SetAutoLayout(true);

	wxStaticBox* WxStaticBoxSizer2_StaticBoxObj = new wxStaticBox(WxNoteBookPage5, wxID_ANY, wxT("En-tête"));
	WxStaticBoxSizer2 = new wxStaticBoxSizer(WxStaticBoxSizer2_StaticBoxObj, wxVERTICAL);
	WxBoxSizer4->Add(WxStaticBoxSizer2, 0, wxALIGN_LEFT | wxEXPAND | wxALL, 0);

	WxBoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	WxStaticBoxSizer2->Add(WxBoxSizer6, 0, wxALIGN_CENTER | wxEXPAND | wxALL, 0);

	ET_EnteteGauche = new wxTextCtrl(WxNoteBookPage5, ID_ET_ENTETEGAUCHE, wxT("ET_EnteteGauche"), wxPoint(5, 5), wxSize(135, 19), 0, wxDefaultValidator, wxT("ET_EnteteGauche"));
	WxBoxSizer6->Add(ET_EnteteGauche,1,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	ET_EnteteCentre = new wxTextCtrl(WxNoteBookPage5, ID_ET_ENTETECENTRE, wxT("WxEdit1"), wxPoint(150, 5), wxSize(135, 19), wxTE_CENTRE, wxDefaultValidator, wxT("ET_EnteteCentre"));
	WxBoxSizer6->Add(ET_EnteteCentre,1,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	ET_EnteteDroite = new wxTextCtrl(WxNoteBookPage5, ID_ET_ENTETEDROITE, wxT("WxEdit1"), wxPoint(295, 5), wxSize(135, 19), wxTE_RIGHT, wxDefaultValidator, wxT("ET_EnteteDroite"));
	WxBoxSizer6->Add(ET_EnteteDroite,1,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	wxStaticBox* WxStaticBoxSizer3_StaticBoxObj = new wxStaticBox(WxNoteBookPage5, wxID_ANY, wxT("Pied de page"));
	WxStaticBoxSizer3 = new wxStaticBoxSizer(WxStaticBoxSizer3_StaticBoxObj, wxVERTICAL);
	WxBoxSizer4->Add(WxStaticBoxSizer3, 0, wxALIGN_LEFT | wxEXPAND | wxALL, 0);

	WxBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	WxStaticBoxSizer3->Add(WxBoxSizer5, 1, wxALIGN_CENTER | wxEXPAND | wxALL, 0);

	ET_PiedPageGauche = new wxTextCtrl(WxNoteBookPage5, ID_ET_PIEDPAGEGAUCHE, wxT("WxEdit1"), wxPoint(5, 5), wxSize(135, 19), 0, wxDefaultValidator, wxT("ET_PiedPageGauche"));
	WxBoxSizer5->Add(ET_PiedPageGauche,1,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	ET_PiedPageCentre = new wxTextCtrl(WxNoteBookPage5, ID_ET_PIEDPAGECENTRE, wxT("WxEdit1"), wxPoint(150, 5), wxSize(135, 19), wxTE_CENTRE, wxDefaultValidator, wxT("ET_PiedPageCentre"));
	WxBoxSizer5->Add(ET_PiedPageCentre,1,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	ET_PiedPageDroite = new wxTextCtrl(WxNoteBookPage5, ID_ET_PIEDPAGEDROITE, wxT("WxEdit1"), wxPoint(295, 5), wxSize(135, 19), wxTE_RIGHT, wxDefaultValidator, wxT("ET_PiedPageDroite"));
	WxBoxSizer5->Add(ET_PiedPageDroite,1,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	WxGridSizer1 = new wxGridSizer(0, 2, 0, 0);
	WxBoxSizer4->Add(WxGridSizer1, 0, wxALIGN_CENTER | wxALL, 5);

	WxST_Impression_1 = new wxStaticText(WxNoteBookPage5, ID_WXSTATICTEXT15, wxT("@DATE@ : date d'impression"), wxPoint(19, 5), wxDefaultSize, 0, wxT("WxST_Impression_1"));
	WxGridSizer1->Add(WxST_Impression_1,0,wxALIGN_CENTER | wxALL,5);

	WxST_Impression_2 = new wxStaticText(WxNoteBookPage5, ID_WXSTATICTEXT14, wxT("@TIME@ : heure d'impression"), wxPoint(212, 5), wxDefaultSize, 0, wxT("WxST_Impression_2"));
	WxGridSizer1->Add(WxST_Impression_2,0,wxALIGN_CENTER | wxALL,5);

	WxST_Impression_3 = new wxStaticText(WxNoteBookPage5, ID_WXSTATICTEXT16, wxT("@PAGENUM@ : numéro de page"), wxPoint(8, 34), wxDefaultSize, 0, wxT("WxST_Impression_3"));
	WxGridSizer1->Add(WxST_Impression_3,0,wxALIGN_CENTER | wxALL,5);

	WxST_Impression_4 = new wxStaticText(WxNoteBookPage5, ID_WXSTATICTEXT17, wxT("@PAGESCNT@ : nombre de pages"), wxPoint(201, 34), wxDefaultSize, 0, wxT("WxST_Impression_4"));
	WxGridSizer1->Add(WxST_Impression_4,0,wxALIGN_CENTER | wxALL,5);

	WxStaticLine5 = new wxStaticLine(WxNoteBookPage5, ID_WXSTATICLINE5, wxPoint(13, 171), wxSize(418, -1), wxLI_HORIZONTAL);
	WxBoxSizer4->Add(WxStaticLine5,0,wxALIGN_CENTER | wxALL,5);

	WxBoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer4->Add(WxBoxSizer7, 0, wxALIGN_LEFT | wxALL, 5);

	WxStaticText13 = new wxStaticText(WxNoteBookPage5, ID_WXSTATICTEXT13, wxT("Taille des caractères pour l'impression :"), wxPoint(5, 7), wxDefaultSize, 0, wxT("WxStaticText13"));
	WxBoxSizer7->Add(WxStaticText13,0,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	ET_TailleCarImpression = new wxTextCtrl(WxNoteBookPage5, ID_WX_ET_TAILLE_CAR_IMPRESSION, wxT("ET_TailleCarImpression"), wxPoint(225, 5), wxSize(30, 23), 0, wxDefaultValidator, wxT("ET_TailleCarImpression"));
	WxBoxSizer7->Add(ET_TailleCarImpression,0,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	WxNoteBookPage6 = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE6, wxPoint(4, 26), wxSize(452, 311));
	WxNotebook1->AddPage(WxNoteBookPage6, wxT("Saisie rapide"));

	WxBoxSizer3 = new wxBoxSizer(wxVERTICAL);
	WxNoteBookPage6->SetSizer(WxBoxSizer3);
	WxNoteBookPage6->SetAutoLayout(true);

	wxStaticBox* WxSBB_saisieRapide_StaticBoxObj = new wxStaticBox(WxNoteBookPage6, wxID_ANY, wxT("Lors de la saisie d'un ISBN dans la barre d'outils :"));
	WxSBB_saisieRapide = new wxStaticBoxSizer(WxSBB_saisieRapide_StaticBoxObj, wxVERTICAL);
	WxBoxSizer3->Add(WxSBB_saisieRapide, 0, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	WxBoxSizer27 = new wxBoxSizer(wxVERTICAL);
	WxSBB_saisieRapide->Add(WxBoxSizer27, 1, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	WxStaticText19 = new wxStaticText(WxNoteBookPage6, ID_WXSTATICTEXT19, wxT("- si l'ISBN n'est pas présent en base :"), wxPoint(76, 5), wxDefaultSize, 0, wxT("WxStaticText19"));
	WxBoxSizer27->Add(WxStaticText19,0,wxALIGN_LEFT | wxEXPAND | wxALL,5);

	wxArrayString arrayStringFor_CH_saisieRapide_ISBNabsent;
	CH_saisieRapide_ISBNabsent = new wxChoice(WxNoteBookPage6, ID_CH_SAISIERAPIDE_ISBNABSENT, wxPoint(15, 29), wxSize(317, 23), arrayStringFor_CH_saisieRapide_ISBNabsent, 0, wxDefaultValidator, wxT("CH_saisieRapide_ISBNabsent"));
	CH_saisieRapide_ISBNabsent->SetSelection(-1);
	WxBoxSizer27->Add(CH_saisieRapide_ISBNabsent,0,wxALIGN_LEFT | wxEXPAND | wxLEFT | wxRIGHT,15);

	WxStaticText20 = new wxStaticText(WxNoteBookPage6, ID_WXSTATICTEXT20, wxT("- si l'ISBN est présent en base :"), wxPoint(92, 57), wxDefaultSize, 0, wxT("WxStaticText20"));
	WxBoxSizer27->Add(WxStaticText20,0,wxALIGN_LEFT | wxEXPAND | wxALL,5);

	wxArrayString arrayStringFor_CH_saisieRapide_ISBNpresent;
	CH_saisieRapide_ISBNpresent = new wxChoice(WxNoteBookPage6, ID_CH_SAISIERAPIDE_ISBNPRESENT, wxPoint(15, 81), wxSize(317, 23), arrayStringFor_CH_saisieRapide_ISBNpresent, 0, wxDefaultValidator, wxT("CH_saisieRapide_ISBNpresent"));
	CH_saisieRapide_ISBNpresent->SetSelection(-1);
	WxBoxSizer27->Add(CH_saisieRapide_ISBNpresent,0,wxALIGN_LEFT | wxEXPAND | wxLEFT | wxRIGHT,15);

	WxBoxSizer26 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer3->Add(WxBoxSizer26, 0, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	WxStaticText8 = new wxStaticText(WxNoteBookPage6, ID_WXSTATICTEXT_lecteurCodesBarre, wxT("Lecteur de codes barre :"), wxPoint(5, 5), wxDefaultSize, 0, wxT("WxStaticText8"));
	WxBoxSizer26->Add(WxStaticText8,30,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	ET_lecteurCodesBarre = new wxTextCtrl(WxNoteBookPage6, ID_WXEDIT1, wxT("ET_lecteurCodesBarre"), wxPoint(144, 5), wxSize(121, 19), 0, wxDefaultValidator, wxT("ET_lecteurCodesBarre"));
	WxBoxSizer26->Add(ET_lecteurCodesBarre,60,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	WxStdDialogButtonSizer1 = new wxStdDialogButtonSizer;
	btnOK = new wxButton( this, wxID_OK );
	WxStdDialogButtonSizer1->AddButton( btnOK );
	btnCANCEL = new wxButton( this, wxID_CANCEL );
	WxStdDialogButtonSizer1->AddButton( btnCANCEL );
	WxStdDialogButtonSizer1->Realize();
	WxBoxSizer2->Add(WxStdDialogButtonSizer1, 0, wxALIGN_CENTER | wxALL, 5);

	SetTitle(wxT("Paramètres"));
	SetIcon(wxNullIcon);
	
	GetSizer()->Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
	
	btnCANCEL->SetLabel("Annuler");
	
	// passage en italique des textes d'aide
	// (le designer ne permet pas de fixer le style italic sans fixer la taille de la police)
    fonte.SetStyle(wxFONTSTYLE_ITALIC);
    WxST_Impression_1->SetFont(fonte);
    WxST_Impression_2->SetFont(fonte);
    WxST_Impression_3->SetFont(fonte);
    WxST_Impression_4->SetFont(fonte);
    WxST_Sauvegarde_1->SetFont(fonte);
    WxST_Sauvegarde_2->SetFont(fonte);
    
    // forcer les tailles des éléments qui ne se dimensionnent pas correctement avec les sizer ...
    CK_avertirNouveau_auteur->SetMinSize(wxSize(-1, (int)(taillePolice*1.5)));
    CK_use_splash_screen->SetMinSize(wxSize(-1, (int)(taillePolice*1.5)));
    CK_cleanTmpOnExit->SetMinSize(wxSize(-1, (int)(taillePolice*1.5)));
    CK_UseSauvegarde->SetMinSize(wxSize(-1, (int)(taillePolice*1.5)));
    RB_SauveDossierBase->SetMinSize(wxSize(-1, (int)(taillePolice*1.5)));
    RB_SauveDossierSpecifie->SetMinSize(wxSize(-1, (int)(taillePolice*1.5)));
    ET_Rep_Sauvegarde->SetMinSize(wxSize(-1, (int)(taillePolice*1.8)));
    WxCheckBox_proxy->SetMinSize(wxSize(-1, (int)(taillePolice*1.5)));
    WxCheck_verifVersion->SetMinSize(wxSize(-1, (int)(taillePolice*1.5)));
    ET_EnteteGauche->SetMinSize(wxSize(-1, (int)(taillePolice*1.8)));
    ET_PiedPageGauche->SetMinSize(wxSize(-1, (int)(taillePolice*1.8)));
    CH_saisieRapide_ISBNabsent->SetMinSize(wxSize(-1, (int)(taillePolice*2)));
    WxSBB_saisieRapide->SetMinSize(wxSize(-1, (int)(taillePolice*12)));
//    WxStaticText20->SetMinSize(wxSize(-1, (int)(taillePolice*2)));

    // remettre la taille mémorisée +
    // forcer un changement de taille pour que les éléments se redimensionnent
    long dlgW = 500;
    long dlgH = 460;
    param->GetOrSet("config", "INIT", "SIZE_PARAM_DLG", dlgW, dlgH);
    SetSize(wxSize(dlgW+1, dlgH));
    SetSize(wxSize(dlgW, dlgH));
    Center();
}

void ParametreDlg::OnClose(wxCloseEvent& /*event*/)
{
	ParamManager* param = ParamManager::GetInstance("config");
    param->Set("config", "INIT", "SIZE_PARAM_DLG", (long)(GetSize().x), (long)(GetSize().y));

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

    param->Set("config", "INIT", "SIZE_PARAM_DLG", (long)(GetSize().x), (long)(GetSize().y));

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

    // taille de police limitée entre 6 et 32 pour éviter des situations de blocage si une valeur "absurde" était saisie
    str2 = ET_TaillePoliceAffichage->GetValue();
    long taillePolice = 0;
    sscanf(str2, "%ld", &taillePolice);
    if (taillePolice < 6)
        taillePolice = 6;
    if (taillePolice > 32)
        taillePolice = 32;
    param->Set("config", "INIT", "TAILLE_POLICE", taillePolice);

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
        
    // lignes PRINT
    wxLogMessage("ParametreDlg::BN_OKClick() - ligne PRINT");
    param->Set("config", "PRINT", "LEFT", ET_EnteteGauche->GetValue(), ET_PiedPageGauche->GetValue());
    param->Set("config", "PRINT", "CENTER", ET_EnteteCentre->GetValue(), ET_PiedPageCentre->GetValue());
    param->Set("config", "PRINT", "RIGHT", ET_EnteteDroite->GetValue(), ET_PiedPageDroite->GetValue());

    wxString str1 = "Arial";
    str2 = ET_TailleCarImpression->GetValue();
    long val2 = 8;
    sscanf(str2, "%ld", &val2);
    param->Set("config", "PRINT", "FONT", str1, val2);
    
    // lignes SAISIE_RAPIDE
    wxLogMessage("ParametreDlg::BN_OKClick() - ligne SAISIE_RAPIDE");
    long idAbsent = -1;
    int index = CH_saisieRapide_ISBNabsent->GetSelection();
    if (index != wxNOT_FOUND)
        idAbsent = (int)(CH_saisieRapide_ISBNabsent->GetClientData(index));
    long idPresent = -1;
    index = CH_saisieRapide_ISBNpresent->GetSelection();
    if (index != wxNOT_FOUND)
        idPresent = (int)(CH_saisieRapide_ISBNpresent->GetClientData(index));
    param->Set("config", "SAISIE_RAPIDE", "ABSENT_PRESENT", idAbsent, idPresent);
    param->Set("config", "SAISIE_RAPIDE", "LECTEUR_CODE_BARRE", ET_lecteurCodesBarre->GetValue());
    
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
	ParamManager* param = ParamManager::GetInstance("config");
    param->Set("config", "INIT", "SIZE_PARAM_DLG", (long)(GetSize().x), (long)(GetSize().y));

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
    
    long taillePolice = 10;
    param->GetOrSet("config", "INIT", "TAILLE_POLICE", taillePolice);
    wxString str_taillePolice = wxString::Format("%ld", taillePolice);
    ET_TaillePoliceAffichage->SetValue(str_taillePolice);    
    
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

    // onglet impressions
    str1 = "";
    str2 = "@DATE@ @TIME@";
    param->GetOrSet("config", "PRINT", "LEFT", str1, str2);
    ET_EnteteGauche->SetValue(str1);
    ET_PiedPageGauche->SetValue(str2);

    str1 = "Livrothèque";
    str2 = "";
    param->GetOrSet("config", "PRINT", "CENTER", str1, str2);
    ET_EnteteCentre->SetValue(str1);
    ET_PiedPageCentre->SetValue(str2);

    str1 = "";
    str2 = "@PAGENUM@ / @PAGESCNT@";
    param->GetOrSet("config", "PRINT", "RIGHT", str1, str2);
    ET_EnteteDroite->SetValue(str1);
    ET_PiedPageDroite->SetValue(str2);
    
    str1 = "Arial";
    val2 = 8;
    param->GetOrSet("config", "PRINT", "FONT", str1, val2);
    str2.Printf("%ld", val2);
    ET_TailleCarImpression->SetValue(str2);
    
    // onglet Saisie rapide
    valLong = E_CA_chercherSurInternet;
    val2 = E_CP_selectionner;
    param->GetOrSet("config", "SAISIE_RAPIDE", "ABSENT_PRESENT", valLong, val2);
	for (int choixAbsent = 0; choixAbsent < E_CA_LASTVALUE; choixAbsent++) {
        int index = CH_saisieRapide_ISBNabsent->Append(choixAbsentStr((E_choixAbsent)choixAbsent), (void*)(choixAbsent));
        if (choixAbsent == valLong)
            CH_saisieRapide_ISBNabsent->Select(index);
    }
	for (int choixPresent = 0; choixPresent < E_CP_LASTVALUE; choixPresent++) {
        int index = CH_saisieRapide_ISBNpresent->Append(choixPresentStr((E_choixPresent)choixPresent), (void*)(choixPresent));
        if (choixPresent == val2)
            CH_saisieRapide_ISBNpresent->Select(index);
    }
    str1 = "";
    param->GetOrSet("config", "SAISIE_RAPIDE", "LECTEUR_CODE_BARRE", str1);
    ET_lecteurCodesBarre->SetValue(str1);
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

wxString ParametreDlg::choixAbsentStr(E_choixAbsent val)
{
    wxString ret = "valeur inconnue";
    switch (val) {
        case E_CA_neRienFaire:            ret = "ne rien faire";            break;
        case E_CA_prevenir:               ret = "prévenir";                 break;
        case E_CA_chercherSurInternet:    ret = "chercher sur internet";    break;

        default: 
            ret = wxString::Format("E_CA inconnu : %d", val);
            break;
    }
    return ret;
}

wxString ParametreDlg::choixPresentStr(E_choixPresent val)
{
    wxString ret = "valeur inconnue";
    switch (val) {
        case E_CP_neRienFaire:          ret = "ne rien faire";                                      break;
        case E_CP_prevenir:             ret = "prévenir";                                           break;
        case E_CP_selectionner:         ret = "sélectionner le ou les livres";                      break;
        case E_CP_ajouterSelection:     ret = "ajouter le ou les livres à la sélection en cours";   break;
        case E_CP_modifier:             ret = "sélectionner et modifier le premier livre trouvé";   break;
        
        default: 
            ret = wxString::Format("E_CP inconnu : %d", val);
            break;
    }
    return ret;
}

/*
 * WxNotebook1PageChanged
 */
void ParametreDlg::WxNotebook1PageChanged(wxNotebookEvent& event)
{
	wxLogMessage("WxNotebook1PageChanged()");
}

/*
 * ParametreDlgSize
 */
void ParametreDlg::ParametreDlgSize(wxSizeEvent& event)
{
	wxLogMessage("ParametreDlgSize()");

	event.Skip();
    
    // WxNotebook1->SetSelection(WxNotebook1->GetSelection()) force un pseudo-changement d'onglet 
    // qui permet un retaillage correct de tous les composants même quand le nombre de lignes d'onglet change
    Freeze();
    WxNotebook1->SetSelection(WxNotebook1->GetSelection());
    Thaw();
}
