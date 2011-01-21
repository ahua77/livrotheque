///-----------------------------------------------------------------
///
/// @file      exportAnalyseSeriesDlg.h
/// @author    Cubbiste
/// Created:   21/01/2011 05:46:02
/// @section   DESCRIPTION
///            exportAnalyseSeriesDlg class declaration
///
///------------------------------------------------------------------

#ifndef __EXPORTANALYSESERIESDLG_H__
#define __EXPORTANALYSESERIESDLG_H__

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
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
////Header Include End

////Dialog Style Start
#undef exportAnalyseSeriesDlg_STYLE
#define exportAnalyseSeriesDlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class exportAnalyseSeriesDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		exportAnalyseSeriesDlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Exporter l'analyse des séries"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = exportAnalyseSeriesDlg_STYLE);
		virtual ~exportAnalyseSeriesDlg();
		void WxBnParcourirClick(wxCommandEvent& event);
		void WxStdDialogButtonSizer1OkClick(wxCommandEvent& event);
		
		bool filtreManquants() const {return WxCK_filtreManquants->GetValue();}
		wxString exportFilename() const {return WxEdFilename->GetValue();}
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStdDialogButtonSizer *WxStdDialogButtonSizer1;
		wxButton *btnOK;
		wxButton *btnCANCEL;
		wxCheckBox *WxCK_filtreManquants;
		wxButton *WxBnParcourir;
		wxTextCtrl *WxEdFilename;
		wxStaticText *WxStaticText1;
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
			ID_WX_CK_FILTRE_MANQUANTS = 1002,
			ID_WX_BN_PARCOURIR = 1008,
			ID_WX_ED_FILENAME = 1007,
			ID_WXSTATICTEXT1 = 1006,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
        void InitValues();
};

#endif
