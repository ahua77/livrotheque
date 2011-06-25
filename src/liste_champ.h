//---------------------------------------------------------------------------
//
// Name:        liste_champ.h
// Author:      fougny
// Created:     31/01/05 11:04:00
//
//Copyright  PE Epaillard, 31/01/05
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
#ifndef __LISTE_CHAMP_HPP_
#define __LISTE_CHAMP_HPP_


#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif
#include "mabase.h"
#include "nouv_autre.h"



////Header Include Start
#include <wx/menu.h>
#include <wx/button.h>
#include <wx/grid.h>
#include <wx/sizer.h>
////Header Include End

#include <wx/dialog.h>

//Compatibility for 2.4.x code
#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif
#ifndef wxFIXED_MINSIZE
#define wxFIXED_MINSIZE 0
#endif

#ifdef THIS_DIALOG_STYLE
#undef THIS_DIALOG_STYLE
#endif
////Dialog Style Start
#undef THIS_DIALOG_STYLE
#define THIS_DIALOG_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxTHICK_FRAME | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class liste_champ : public wxDialog
{
public:
 enum {
////GUI Enum Control ID Start
			ID_MNU_SUPPRIME_1008 = 1008,
			
			ID_WXBUTTON_INSERER = 1007,
			ID_GRILLE_LISTE = 1004,
////GUI Enum Control ID End
ID_DUMMY_VALUE_ //Dont Delete this DummyValue
}; //End of Enum
    liste_champ( wxWindow *parent, wxWindowID id = 1, const wxString &title = _T("liste"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = THIS_DIALOG_STYLE);
    virtual ~liste_champ();
public:
  ////GUI Control Declaration Start
		wxMenu *WxPopupMenu_grille;
		wxButton *WxButton_inserer;
		wxButton *WxButton_ok;
		wxBoxSizer *WxBoxSizer_button;
		wxGrid *grille;
		wxBoxSizer *WxBoxSizer_top;
		wxBoxSizer *WxBoxSizer_general;
  ////GUI Control Declaration End
    wxString nom_table;
    ma_base *la_belle;
    int modifie;
private:
    DECLARE_EVENT_TABLE()

public:
    liste_champ( ma_base *pour_insere, wxWindow *parent, wxWindowID id = 1, const wxString &title = _T("liste"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = THIS_DIALOG_STYLE);
    void liste_champClose(wxCloseEvent& event);
    void CreateGUIControls(void);
	void WxButton_okClick(wxCommandEvent& event);
	void init_grille();
	void grilleCellLeftDoubleClick(wxGridEvent& event);
	void WxButton_insererClick(wxCommandEvent& event);
	void Mnusupprime1008Click(wxCommandEvent& event);
	void OnGrilleClickDroit( wxGridEvent& event );
	void grilleCellLeftClick(wxGridEvent& event);
    wxString inverse_texte (wxString texte);
		void grilleLabelLeftClick(wxGridEvent& event);

private:
    wxString critere_tri;
    wxString ordre_tri;
    static long s_nbInstances;
};


#endif




