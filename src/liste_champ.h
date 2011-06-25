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




