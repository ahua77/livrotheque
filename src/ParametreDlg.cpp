///-----------------------------------------------------------------
///
/// @file      ParametreDlg.cpp
/// @author    cubbiste
/// Created:   12/12/2009 18:10:19
/// @section   DESCRIPTION
///            ParametreDlg class implementation
//
//Ce logiciel est un programme informatique servant � [rappeler les
//caract�ristiques techniques de votre logiciel]. 
//
//Ce logiciel est r�gi par la licence CeCILL soumise au droit fran�ais et
//respectant les principes de diffusion des logiciels libres. Vous pouvez
//utiliser, modifier et/ou redistribuer ce programme sous les conditions
//de la licence CeCILL telle que diffus�e par le CEA, le CNRS et l'INRIA 
//sur le site "http://www.cecill.info".
//
//En contrepartie de l'accessibilit� au code source et des droits de copie,
//de modification et de redistribution accord�s par cette licence, il n'est
//offert aux utilisateurs qu'une garantie limit�e.  Pour les m�mes raisons,
//seule une responsabilit� restreinte p�se sur l'auteur du programme,  le
//titulaire des droits patrimoniaux et les conc�dants successifs.
//
//A cet �gard  l'attention de l'utilisateur est attir�e sur les risques
//associ�s au chargement,  � l'utilisation,  � la modification et/ou au
//d�veloppement et � la reproduction du logiciel par l'utilisateur �tant 
//donn� sa sp�cificit� de logiciel libre, qui peut le rendre complexe � 
//manipuler et qui le r�serve donc � des d�veloppeurs et des professionnels
//avertis poss�dant  des  connaissances  informatiques approfondies.  Les
//utilisateurs sont donc invit�s � charger  et  tester  l'ad�quation  du
//logiciel � leurs besoins dans des conditions permettant d'assurer la
//s�curit� de leurs syst�mes et ou de leurs donn�es et, plus g�n�ralement, 
//� l'utiliser et l'exploiter dans les m�mes conditions de s�curit�. 
//
//Le fait que vous puissiez acc�der � cet en-t�te signifie que vous avez 
//pris connaissance de la licence CeCILL, et que vous en avez accept� les
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
	EVT_BUTTON(ID_WX_BNCANCEL,ParametreDlg::BN_CANCELClick)
	EVT_BUTTON(ID_WX_BNOK,ParametreDlg::BN_OKClick)
	EVT_CHECKBOX(ID_WX_CK_UseTopN,ParametreDlg::CK_useTopNClick)
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

	WxNotebook1 = new wxNotebook(this, ID_WXNOTEBOOK1, wxPoint(0, 0), wxSize(425, 265), wxNB_DEFAULT);

	WxNoteBookPage1 = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE1, wxPoint(4, 26), wxSize(417, 235));
	WxNotebook1->AddPage(WxNoteBookPage1, wxT("G�n�ral"));

	WxStaticText2 = new wxStaticText(WxNoteBookPage1, ID_WXSTATICTEXT2, wxT("Avertir avant de cr�er un nouveau groupe des types coch�s ci-dessous :"), wxPoint(4, 6), wxDefaultSize, 0, wxT("WxStaticText2"));

	CK_avertirNouveau_auteur = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_auteur, wxT("Auteurs"), wxPoint(4, 30), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_auteur"));

	CK_avertirNouveau_serie = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_serie, wxT("S�ries"), wxPoint(4, 54), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_serie"));

	CK_avertirNouveau_genre = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_genre, wxT("Genres"), wxPoint(4, 78), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_genre"));

	CK_avertirNouveau_editeur = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_editeur, wxT("Editeurs"), wxPoint(4, 102), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_editeur"));

	CK_avertirNouveau_format = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_format, wxT("Formats"), wxPoint(140, 30), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_format"));

	CK_avertirNouveau_artiste = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_artiste, wxT("Artistes"), wxPoint(140, 54), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_artiste"));

	CK_avertirNouveau_etat = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_etat, wxT("Etats"), wxPoint(140, 78), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_etat"));

	CK_avertirNouveau_localisation = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_localisation, wxT("Localisations"), wxPoint(140, 102), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_localisation"));

	CK_avertirNouveau_serie_o = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_serie_o, wxT("S�ries originales"), wxPoint(276, 30), wxSize(113, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_serie_o"));

	CK_avertirNouveau_pays = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_pays, wxT("Pays"), wxPoint(276, 54), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_pays"));

	CK_avertirNouveau_langue = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_langue, wxT("Langues"), wxPoint(276, 78), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_langue"));

	CK_avertirNouveau_traducteur = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_avertirNouveau_traducteur, wxT("Traducteurs"), wxPoint(276, 102), wxSize(97, 17), 0, wxDefaultValidator, wxT("CK_avertirNouveau_traducteur"));

	WxStaticLine2 = new wxStaticLine(WxNoteBookPage1, ID_WXSTATICLINE2, wxPoint(-4, 126), wxSize(422, -1), wxLI_HORIZONTAL);

	CK_use_splash_screen = new wxCheckBox(WxNoteBookPage1, ID_WX_CK_UseSplashScreen, wxT("Afficher l'�cran de d�marrage"), wxPoint(4, 150), wxSize(185, 17), 0, wxDefaultValidator, wxT("CK_use_splash_screen"));

	WxNoteBookPage2 = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE2, wxPoint(4, 26), wxSize(417, 235));
	WxNotebook1->AddPage(WxNoteBookPage2, wxT("Statistiques"));

	CK_useTopN = new wxCheckBox(WxNoteBookPage2, ID_WX_CK_UseTopN, wxT("Limiter l'affichage aux "), wxPoint(12, 14), wxSize(137, 17), 0, wxDefaultValidator, wxT("CK_useTopN"));

	ET_ValueTopN = new wxTextCtrl(WxNoteBookPage2, ID_WXEDIT1, wxT("ET_ValueTopN"), wxPoint(156, 13), wxSize(41, 19), 0, wxDefaultValidator, wxT("ET_ValueTopN"));

	WxStaticText1 = new wxStaticText(WxNoteBookPage2, ID_WXSTATICTEXT1, wxT("premiers r�sultats"), wxPoint(204, 13), wxDefaultSize, 0, wxT("WxStaticText1"));

	WxStaticLine1 = new wxStaticLine(WxNoteBookPage2, ID_WXSTATICLINE1, wxPoint(-4, 38), wxSize(422, -1), wxLI_HORIZONTAL);

	BN_OK = new wxButton(this, ID_WX_BNOK, wxT("OK"), wxPoint(80, 272), wxSize(75, 25), 0, wxDefaultValidator, wxT("BN_OK"));

	BN_CANCEL = new wxButton(this, ID_WX_BNCANCEL, wxT("Annuler"), wxPoint(248, 272), wxSize(75, 25), 0, wxDefaultValidator, wxT("BN_CANCEL"));

	SetTitle(wxT("Param�tres"));
	SetIcon(wxNullIcon);
	SetSize(8,8,442,334);
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
    // sauvegarder en base les param�tres de tous les onglets
	ParamManager* param = ParamManager::GetInstance("config");
	if (!param) {
        wxMessageBox ("instance de ParamManager non cr��e");
        return;
    }

    // Onglet G�n�ral
    param->Set("config", "INIT", "USE_SPLASH", CK_use_splash_screen->GetValue());

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

    // ligne STAT / USE_TOP_N
    BOOL useTopN = CK_useTopN->GetValue();
    long seuilTopN = 0;
    //if (useTopN) {
        wxString str2 = ET_ValueTopN->GetValue();
        sscanf(str2, "%ld", &seuilTopN);
    //}
    param->Set("config", "STAT", "USE_TOP_N", useTopN, seuilTopN);
        
    // fermer la fen�tre
	this->EndDialog(0);
	this->Destroy();
}

/*
 * BN_CANCELClick
 */
void ParametreDlg::BN_CANCELClick(wxCommandEvent& event)
{
    // fermer la fen�tre
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
	// initialiser en fonction des valeurs pr�sentes en base
	ParamManager* param = ParamManager::GetInstance("config");
	if (!param) {
        wxMessageBox ("instance de ParamManager non cr��e");
        return;
    }

    // onglet g�n�ral
    BOOL useSplashScreen = true;
    param->GetOrSet("config", "INIT", "USE_SPLASH", useSplashScreen);    
    CK_use_splash_screen->SetValue(useSplashScreen);
    
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
}
