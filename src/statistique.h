//---------------------------------------------------------------------------
//
// Name:        statistique.h
// Author:      Epaillard
// Created:     20/07/05 15:48:04
//
//Copyright  PE Epaillard, 20/07/05 
//
//Fougny@gmail.com
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
//---------------------------------------------------------------------------
#ifndef __STATISTIQUE_HPP_
#define __STATISTIQUE_HPP_

// For compilers that support precompilation, includes "wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
// Include your minimal set of headers here, or wx.h
#include <wx/wx.h>
#endif

//Do not add custom headers.
//wx-dvcpp designer will remove them
////Header Include Start
#include <wx/menu.h>
////Header Include End
#include <wx/frame.h>
#include <wx/numdlg.h>
#include <wx/datetime.h>

#include "mabase.h"
#include "moncamembert.h"
#include "myprintout.h"

////Dialog Style Start
#undef THIS_DIALOG_STYLE
#define THIS_DIALOG_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMAXIMIZE_BOX | wxCLOSE_BOX | wxFRAME_NO_TASKBAR
////Dialog Style End

class statistique : public wxFrame
{
private:
    DECLARE_EVENT_TABLE()
public:
    statistique( wxWindow *parent, wxWindowID id = 1, const wxString &title = _T("Statistiques"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = THIS_DIALOG_STYLE);
    virtual ~statistique();
    MonCamembert *BeauFrometon;
    ma_base *la_belle;
    wxString type_stat;
    MonCamembert::myTypeGraph graph_encour;
    wxString titre;
    
public:

  //Do not add custom Control Declarations here.
  //wx-devcpp will remove them. Try adding the custom code 
  //after the block.
  ////GUI Control Declaration Start
		wxMenuBar *WxMenuBar_stat;
  ////GUI Control Declaration End

public:
    //Note: if you receive any error with these enums, then you need to
    //change your old form code that are based on the #define control ids.
    //#defines may replace a numeric value for the enums names.
    //Try copy pasting the below block in your old Form header Files.
	enum {
////GUI Enum Control ID Start
			ID_MNU_FICHIER_1001 = 1001,
			ID_MNU__IMPRIMER_1006 = 1006,
			ID_MNU_QUITTER_1002 = 1002,
			ID_MNU_APER_UA_VANTIMPRESSION_1007 = 1007,
			ID_MNU__GRAPHIQUE_1011 = 1011,
			ID_MNU_GENRE_1012 = 1012,
			ID_MNU_AUTEUR_1013 = 1013,
			ID_MNU_EDITEUR_1014 = 1014,
			ID_MNU_FORMAT_1015 = 1015,
			ID_MNU_ETAT_1016 = 1016,
			ID_MNU_LOCALISATION_1017 = 1017,
			ID_MNU_PAYS_1018 = 1018,
			ID_MNU_LANGUE_1019 = 1019,
			ID_MNU_TRADUCTEUR_1020 = 1020,
			ID_MNU_ARTISTE_1021 = 1021,
			ID_MNU_NOTES_1027 = 1027,
			ID_MNU_ANNEEDELECTURE_1024 = 1024,
			ID_MNU_MOIS_ANNEEDELECTURE_1025 = 1025,
			ID_MNU_ANNEEDACHAT_1022 = 1022,
			ID_MNU_MOISDACHAT_1023 = 1023,
			ID_MNU__AFFICHAGE_1008 = 1008,
			ID_MNU_BARRES_1009 = 1009,
			ID_MNU_CAMEMBERT_1010 = 1010,
			ID_MNU_BARRESCOMMENTEES_1026 = 1026,
			ID_MNU__OPTION_1004 = 1004,
			ID_MNU_GESTIONDESCOULEURS_1005 = 1005,
			
////GUI Enum Control ID End
ID_WXCAMEMBERT = 2500,
   ID_DUMMY_VALUE_ //Dont Delete this DummyValue
   }; //End of Enum
private:
    void init_tableaux(wxString nom_table);
    void gestion_date(wxString nom_table);
    void gestion_note(wxString type_note);
public:
    void dessiner();
    void actualiser();
    void statistiqueClose(wxCloseEvent& event);
    void CreateGUIControls(void);
	void Mnuquitter1002Click(wxCommandEvent& event);
	void statistiqueSize(wxSizeEvent& event);
	void definir_base(ma_base *babase);
	void sauve_typegraph();
	void load_typegraph();
	void Mnugestiondescouleurs1005Click(wxCommandEvent& event);
	void Mnuimprimer1006Click(wxCommandEvent& event);
	void Mnuaperuavantimpression1007Click(wxCommandEvent& event);
	void MnuAffSwitch1009Click(wxCommandEvent& event);
	void MnuGraph1013Click(wxCommandEvent& event);
//int comparemois(const wxString& first, const wxString& second);

};


#endif
 
 
 
 
