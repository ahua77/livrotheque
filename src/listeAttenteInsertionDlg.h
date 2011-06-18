///-----------------------------------------------------------------
///
/// @file      listeAttenteInsertionDlg.h
/// @author    cubbiste
/// Created:   12/06/2011 07:46:56
/// @section   DESCRIPTION
///            listeAttenteInsertionDlg class declaration
///
///------------------------------------------------------------------

#ifndef __LISTEATTENTEINSERTIONDLG_H__
#define __LISTEATTENTEINSERTIONDLG_H__

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
#include <wx/listctrl.h>
#include <wx/sizer.h>
////Header Include End

////Dialog Style Start
#undef listeAttenteInsertionDlg_STYLE
#define listeAttenteInsertionDlg_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class ma_base;

class listeAttenteInsertionDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		listeAttenteInsertionDlg(wxWindow *parent, ma_base* DB, wxWindowID id = 1, const wxString &title = wxT("Livres en attente d'insertion"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = listeAttenteInsertionDlg_STYLE);
		virtual ~listeAttenteInsertionDlg();
        wxArrayInt rowIdSelectionnes();
		void OnImporterListe(wxCommandEvent& event);
		void OnSupprimerLignesSelectionnees(wxCommandEvent& event);
		void OnImporterLigneSelectionnee(wxCommandEvent& event);
		void OnItemActivated(wxListEvent& event);
		void OnAjouterLigne(wxCommandEvent& event);
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *WxButton_fermer;
		wxButton *WxButton_supprimerLignesSelectionnees;
		wxButton *WxButton_ajouterLigne;
		wxButton *WxButton_insererLigneSelectionnee;
		wxButton *WxButton_importerListe;
		wxBoxSizer *m_sizerH_boutons;
		wxListCtrl *WxLC_livres;
		wxBoxSizer *m_sizerV_general;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXBTN_SUPPRIMER_LIGNES_SELECTIONNEES = 1007,
			ID_WXBTN_AJOUTER_LIGNE = 1009,
			ID_WXBTN_INSERER_LIGNE_SELECTIONNEE = 1005,
			ID_WXBTN_IMPORTER_LISTE = 1004,
			ID_WXLC_LIVRES = 1008,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
        void rafraichit();
        void editItem(long rowid);
		
	private:
        ma_base* m_db;
};

#endif
