///-----------------------------------------------------------------
///
/// @file      VerifNouveauGroupeDlg.h
/// @author    
/// Created:   26/12/2009 11:35:51
/// @section   DESCRIPTION
///            VerifNouveauGroupeDlg class declaration
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

#ifndef __VERIFNOUVEAUGROUPEDLG_H__
#define __VERIFNOUVEAUGROUPEDLG_H__

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
#include <wx/checkbox.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/stattext.h>
////Header Include End

#include "mabase.h"


////Dialog Style Start
#undef VerifNouveauGroupeDlg_STYLE
#define VerifNouveauGroupeDlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class VerifNouveauGroupeDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		VerifNouveauGroupeDlg(wxWindow *parent, ma_base& pBase, 
                              const wxString& valeur, const wxString& nom_table, const wxString& libelleGroupePluriel,
                              wxWindowID id = 1, const wxString &title = wxT("VerifNouveauGroupeDlg"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = VerifNouveauGroupeDlg_STYLE);
		virtual ~VerifNouveauGroupeDlg();
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStaticText *WxStaticText3;
		wxCheckBox *CK_ToujoursCreer;
		wxButton *BN_Annuler;
		wxButton *BN_Creer;
		wxTextCtrl *ET_nomGroupe;
		wxButton *BN_Choisir;
		wxComboBox *CB_listeGroupe;
		wxStaticText *WxStaticText2;
		wxStaticText *ST_GroupeInconnu;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXSTATICTEXT3 = 1010,
			ID_WXCHECKBOX1 = 1009,
			ID_WXBUTTON3 = 1008,
			ID_WXBUTTON2 = 1007,
			ID_WXEDIT1 = 1006,
			ID_WXBUTTON1 = 1005,
			ID_WXCOMBOBOX1 = 1004,
			ID_WXSTATICTEXT2 = 1003,
			ID_WXSTATICTEXT1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};

    public:
        wxString valeur() const {return mValeur;}
        BOOL ok() const {return mOk;}
        BOOL toujoursCreer() const {return (CK_ToujoursCreer->GetValue() == true);}
		void VerifNouveauGroupeDlgInitDialog(wxInitDialogEvent& event);
		void BN_ChoisirClick(wxCommandEvent& event);
		void BN_CreerClick(wxCommandEvent& event);
		void BN_AnnulerClick(wxCommandEvent& event);
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		
	private:
        ma_base& mBaseLivre;
        wxString mNomTable;
        wxString mLibelleGroupePluriel;
        wxString mValeur;
        BOOL mOk;
        static long s_nbInstances;
};

#endif
