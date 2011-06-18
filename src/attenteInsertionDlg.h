///-----------------------------------------------------------------
///
/// @file      attenteInsertionDlg.h
/// @author    cubbiste
/// Created:   16/06/2011 22:45:25
/// @section   DESCRIPTION
///            attenteInsertionDlg class declaration
///
///------------------------------------------------------------------

#ifndef __ATTENTEINSERTIONDLG_H__
#define __ATTENTEINSERTIONDLG_H__

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
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
////Header Include End

////Dialog Style Start
#undef attenteInsertionDlg_STYLE
#define attenteInsertionDlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class attenteInsertion;

class attenteInsertionDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		attenteInsertionDlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("livre en attente d'insertion"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = attenteInsertionDlg_STYLE);
		virtual ~attenteInsertionDlg();
		
		void initDialog(attenteInsertion* item);
		void updateItem(attenteInsertion* item);
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStdDialogButtonSizer *WxStdDialogButtonSizer1;
		wxButton *btnOK;
		wxButton *btnCANCEL;
		wxTextCtrl *m_ET_commentaire;
		wxStaticText *WxStaticText4;
		wxTextCtrl *m_ET_auteur;
		wxStaticText *WxStaticText3;
		wxTextCtrl *m_ET_titre;
		wxStaticText *WxStaticText2;
		wxTextCtrl *m_ET_isbn;
		wxStaticText *WxStaticText1;
		wxFlexGridSizer *WxFlexGridSizer1;
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
			ID_WX_ET_COMMENTAIRE = 1015,
			ID_WXSTATICTEXT4 = 1012,
			ID_WX_ET_AUTEUR = 1014,
			ID_WXSTATICTEXT3 = 1011,
			ID_WX_ET_TITRE = 1013,
			ID_WXSTATICTEXT2 = 1010,
			ID_WX_ET_ISBN = 1009,
			ID_WXSTATICTEXT1 = 1008,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
