///-----------------------------------------------------------------
///
/// @file      VersionDlg.h
/// @author    Cubbiste
/// Created:   10/11/2010 20:44:26
/// @section   DESCRIPTION
///            VersionDlg class declaration
///
///------------------------------------------------------------------

#ifndef __VERSIONDLG_H__
#define __VERSIONDLG_H__

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
#include <wx/hyperlink.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
////Header Include End

////Dialog Style Start
#undef VersionDlg_STYLE
#define VersionDlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class VersionXml;

class VersionDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		VersionDlg(wxWindow *parent, VersionXml& version, wxWindowID id = 1, const wxString &title = wxT("Vérification de la version"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = VersionDlg_STYLE);
		virtual ~VersionDlg();
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStdDialogButtonSizer *WxStdDialogButtonSizer1;
		wxButton *btnOK;
		wxTextCtrl *WxMemo2;
		wxTextCtrl *WxMemo1;
		wxHyperlinkCtrl *WxHyperLinkCtrl1;
		wxStaticText *WxStaticText4;
		wxBoxSizer *WxBoxSizer2;
		wxStaticText *WxStaticText3;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
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
			ID_WXMEMO2 = 1007,
			ID_WXMEMO1 = 1006,
			ID_WXHYPERLINKCTRL1 = 1011,
			ID_WXSTATICTEXT4 = 1010,
			ID_WXSTATICTEXT3 = 1004,
			ID_WXSTATICTEXT2 = 1003,
			ID_WXSTATICTEXT1 = 1002,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
        VersionXml& m_version;
};

#endif
