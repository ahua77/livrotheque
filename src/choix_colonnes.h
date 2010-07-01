//---------------------------------------------------------------------------
//
// Name:        choix_colonnes.h
// Author:      
// Created:     12/01/05 12:55:25
//
//Copyright  PE Epaillard, 12/01/05 
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
#ifndef __CHOIX_COLONNES_HPP_
#define __CHOIX_COLONNES_HPP_


#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif
#include <wx/splitter.h>
#include <wx/listbox.h>



////Header Include Start
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/listbox.h>
#include <wx/splitter.h>
////Header Include End

#include <wx/dialog.h>

//Compatibility for 2.4.x code
#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif
#ifndef wxFIXED_MINSIZE
#define wxFIXED_MINSIZE 0
#endif

#define ID_SPLITTERWINDOW_GAUCHE 10009
#define ID_LISTBOX_CHOIX 10010
#define ID_SPLITTERWINDOW_DROIT 10011
#define ID_PANEL_BOUTON 10012
#define ID_LISTBOX_CHOISIS 10013
#define ID_BUTTON_OK 10014
#define ID_BUTTON_ANNULER 10015
#define ID_BUTTON_AJOUTE 10016
#define ID_BUTTON_ENLEVE 10017
#define ID_LISTBOX2 10013

//WX_DEFINE_ARRAY(int, ArrayOfInt);

#ifdef THIS_DIALOG_STYLE
#undef THIS_DIALOG_STYLE
#endif

////Dialog Style Start
#undef THIS_DIALOG_STYLE
#define THIS_DIALOG_STYLE wxCAPTION
////Dialog Style End

class choix_colonnes : public wxDialog
{
public:
 enum {
////GUI Enum Control ID Start
			ID_ITEMLISTBOX_CHOISIS = 1015,
			ID_WXBITMAPBUTTON_BAS = 1012,
			ID_WXBITMAPBUTTON_HAUT = 1011,
			ID_WXBITMAPBUTTON1 = 1010,
			ID_WXBUTTON_ENLEVE = 1008,
			ID_WXBUTTON_ANNULER = 1007,
			ID_WXBUTTON_OK = 1006,
			ID_ITEMPANEL_BOUTON = 1004,
			ID_ITEMSPLITTERWINDOW_DROIT = 1003,
			ID_ITEMLISTBOX_CHOIX = 1002,
			ID_ITEMSPLITTERWINDOW_GAUCHE = 1001,
////GUI Enum Control ID End
ID_DUMMY_VALUE_ //Dont Delete this DummyValue
}; //End of Enum
    choix_colonnes( wxWindow *parent, wxWindowID id = 1, const wxString &title = _T("choix_colonnes"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxRESIZE_BORDER );
    virtual ~choix_colonnes();
public: 
  ////GUI Control Declaration Start
		wxListBox *itemListBox_choisis;
		wxBitmapButton *WxBitmapButton_bas;
		wxBitmapButton *WxBitmapButton_haut;
		wxBitmapButton *WxBitmapButton1;
		wxBitmapButton *wxButton_enleve;
		wxButton *wxButton_annuler;
		wxButton *wxButton_OK;
		wxPanel *itemPanel_bouton;
		wxSplitterWindow *itemSplitterWindow_droit;
		wxListBox *itemListBox_choix;
		wxSplitterWindow *itemSplitterWindow_gauche;
  ////GUI Control Declaration End
  
  //wxSplitterWindow* itemSplitterWindow_gauche;
  //wxListBox* itemListBox_choix;
  //wxSplitterWindow* itemSplitterWindow_droit;
  //wxListBox* itemListBox_choisis;
  //wxPanel* itemPanel_bouton;
  //wxButton* wxButton_OK ;
  //wxButton* wxButton_annuler;
  //wxButton* wxButton_ajoute;
  //wxButton* wxButton_enleve;
  //
  wxArrayString liste_choix;
  wxArrayInt *liste_choisis;
  wxArrayString *liste_choisis_nom;
private:
    DECLARE_EVENT_TABLE()

public:
    choix_colonnes( wxArrayString &l_choix, wxArrayInt *l_choisis, wxArrayString *l_choisis_nom, wxWindow *parent, wxWindowID id = 1, const wxString &title = _T("choix_colonnes"),
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxRESIZE_BORDER );
    void choix_colonnesClose(wxCloseEvent& event);
    void CreateGUIControls(void);
	void WxButton_annulClick(wxCommandEvent& event);
	void WxButton_okClick(wxCommandEvent& event);
	void WxButton_ajouteClick(wxCommandEvent& event);
	void WxButton_enleveClick(wxCommandEvent& event);
	void Wxlist_ajouteClick( wxCommandEvent &event ) ;
	void init_listbox();
	void ajouteClick();
	void WxBitmapButton_hautClick(wxCommandEvent& event);
    void choix_colonnes::deplace_choisi(bool haut);
		void WxBitmapButton_basClick(wxCommandEvent& event);

private:    
    static long s_nbInstances;
};


#endif
 
 
 
 
