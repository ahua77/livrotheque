///-----------------------------------------------------------------
///
/// @file      FusionDlg.h
/// @author    
/// Created:   10/12/2009 00:38:40
/// @section   DESCRIPTION
///            FusionDlg class declaration
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

#ifndef __FUSIONDLG_H__
#define __FUSIONDLG_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/button.h>
#include <wx/listbox.h>
#include <wx/statline.h>
#include <wx/combobox.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
////Header Include End

#include "mabase.h"

////Dialog Style Start
#undef FusionDlg_STYLE
#define FusionDlg_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxSTAY_ON_TOP | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class FusionDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		FusionDlg(wxWindow *parent, ma_base& p_baseLivre, wxString table = "", long itemId = -1, wxWindowID id = 1, const wxString &title = wxT("Fusion"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = FusionDlg_STYLE);
		virtual ~FusionDlg();
		void FusionDlgInitDialog(wxInitDialogEvent& event);
		void CB_listeGroupes1Selected(wxCommandEvent& event );
		void CB_listeGroupes2Selected(wxCommandEvent& event );
		void BN_AnnulerClick(wxCommandEvent& event);
		void CB_typeGroupeSelected(wxCommandEvent& event );
		void BN_FusionnerClick(wxCommandEvent& event);
		void CB_typeTriSelected(wxCommandEvent& event );
		void m_btn_permuterClick(wxCommandEvent& event);
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxBoxSizer *WxBoxSizer12;
		wxButton *BN_Annuler;
		wxButton *BN_Fusionner;
		wxBoxSizer *WxBoxSizer11;
		wxBoxSizer *WxBoxSizer10;
		wxListBox *LB_listeLivres2;
		wxBoxSizer *WxBoxSizer9;
		wxComboBox *CB_listeGroupes2;
		wxStaticText *WxStaticText2;
		wxBoxSizer *WxBoxSizer7;
		wxBoxSizer *WxBoxSizer6;
		wxButton *m_btn_permuter;
		wxListBox *LB_listeLivres1;
		wxBoxSizer *WxBoxSizer8;
		wxComboBox *CB_listeGroupes1;
		wxStaticText *WxStaticText1;
		wxBoxSizer *WxBoxSizer5;
		wxBoxSizer *WxBoxSizer4;
		wxBoxSizer *WxBoxSizer3;
		wxStaticLine *WxStaticLine1;
		wxComboBox *CB_typeTri;
		wxStaticText *WxStaticText4;
		wxComboBox *CB_typeGroupe;
		wxStaticText *WxStaticText3;
		wxBoxSizer *WxBoxSizer2;
		wxBoxSizer *WxBoxSizer1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXBUTTON2 = 1008,
			ID_WXBUTTON1 = 1007,
			ID_WXLISTBOX2 = 1010,
			ID_WXCOMBOBOX2 = 1002,
			ID_WXSTATICTEXT2 = 1004,
			ID_WXBN_PERMUTER = 1029,
			ID_WXLISTBOX1 = 1009,
			ID_WXCOMBOBOX1 = 1001,
			ID_WXSTATICTEXT1 = 1003,
			ID_WXSTATICLINE1 = 1011,
			ID_CB_TYPE_TRI = 1015,
			ID_WXSTATICTEXT4 = 1030,
			ID_CB_TYPE_GROUPE = 1012,
			ID_WXSTATICTEXT3 = 1013,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();

        void remplirListeLivres(wxListBox* listeLivres, int idGroupe);
        void InitListeGroupes();

        ma_base& baseLivre;
    
        static long s_nbInstances;

        long m_itemId;
        wxString m_table;
};

#endif
