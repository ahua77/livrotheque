///-----------------------------------------------------------------
///
/// @file      exportAnalyseSeriesDlg.cpp
/// @author    Cubbiste
/// Created:   21/01/2011 05:46:02
/// @section   DESCRIPTION
///            exportAnalyseSeriesDlg class implementation
///
///------------------------------------------------------------------

#include "exportAnalyseSeriesDlg.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

#include <wx/filedlg.h>
#include <wx/stdpaths.h>

#include "ParamManager.h"

//----------------------------------------------------------------------------
// exportAnalyseSeriesDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(exportAnalyseSeriesDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(exportAnalyseSeriesDlg::OnClose)
	EVT_BUTTON(wxID_OK, exportAnalyseSeriesDlg::WxStdDialogButtonSizer1OkClick)
	EVT_BUTTON(ID_WX_BN_PARCOURIR,exportAnalyseSeriesDlg::WxBnParcourirClick)
END_EVENT_TABLE()
////Event Table End

exportAnalyseSeriesDlg::exportAnalyseSeriesDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
	InitValues();
}

exportAnalyseSeriesDlg::~exportAnalyseSeriesDlg()
{
} 

void exportAnalyseSeriesDlg::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxBoxSizer1 = new wxBoxSizer(wxVERTICAL);
	this->SetSizer(WxBoxSizer1);
	this->SetAutoLayout(true);

	WxBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer1->Add(WxBoxSizer2, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, wxT("Fichier d'export"), wxPoint(5, 5), wxDefaultSize, 0, wxT("WxStaticText1"));
	WxBoxSizer2->Add(WxStaticText1,0,wxALIGN_CENTER | wxALL,5);

	WxEdFilename = new wxTextCtrl(this, ID_WX_ED_FILENAME, wxT("WxEdFilename"), wxPoint(100, 5), wxSize(350, 19), 0, wxDefaultValidator, wxT("WxEdFilename"));
	WxBoxSizer2->Add(WxEdFilename,0,wxALIGN_CENTER | wxALL,5);

	WxBnParcourir = new wxButton(this, ID_WX_BN_PARCOURIR, wxT("..."), wxPoint(460, 5), wxSize(20, 18), 0, wxDefaultValidator, wxT("WxBnParcourir"));
	WxBoxSizer2->Add(WxBnParcourir,0,wxALIGN_CENTER | wxALL,5);

	WxCK_filtreManquants = new wxCheckBox(this, ID_WX_CK_FILTRE_MANQUANTS, wxT("Limiter l'export aux séries incomplètes"), wxPoint(107, 49), wxSize(280, 17), 0, wxDefaultValidator, wxT("WxCK_filtreManquants"));
	WxBoxSizer1->Add(WxCK_filtreManquants,0,wxALIGN_LEFT | wxEXPAND | wxALL,10);

	WxStdDialogButtonSizer1 = new wxStdDialogButtonSizer;
	btnOK = new wxButton( this, wxID_OK );
	WxStdDialogButtonSizer1->AddButton( btnOK );
	btnCANCEL = new wxButton( this, wxID_CANCEL );
	WxStdDialogButtonSizer1->AddButton( btnCANCEL );
	WxStdDialogButtonSizer1->Realize();
	WxBoxSizer1->Add(WxStdDialogButtonSizer1, 0, wxALIGN_CENTER | wxALL, 5);

	SetTitle(wxT("Exporter l'analyse des séries"));
	SetIcon(wxNullIcon);
	
	GetSizer()->Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
	
    btnOK->SetLabel("Exporter");
	btnCANCEL->SetLabel("Annuler");
}

/**
 * initialise le dlg à partir des valeurs stockées en base config
 */
void exportAnalyseSeriesDlg::InitValues()
{
    ParamManager* param = ParamManager::GetInstance("config");
    BOOL filtreManquants = false;
    wxString exportFilename = wxStandardPaths::Get().GetLocalDataDir();
    param->GetOrSet("config", "EXPORT_SERIES", "EXP_FILENAME", exportFilename);
    param->GetOrSet("config", "EXPORT_SERIES", "FILTRE_MANQUANTS", filtreManquants);
    
    WxCK_filtreManquants->SetValue(filtreManquants);
    WxEdFilename->SetValue(exportFilename);
}

void exportAnalyseSeriesDlg::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * WxBnParcourirClick
 */
void exportAnalyseSeriesDlg::WxBnParcourirClick(wxCommandEvent& event)
{
    wxFileDialog dlg (this, _("Choisir le fichier d'export"), "", WxEdFilename->GetValue(),
                      "fichiers csv (*.csv)|*.csv", wxFD_SAVE);

    if (dlg.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...
    
    WxEdFilename->SetValue(dlg.GetPath());
}

/*
 * WxStdDialogButtonSizer1OkClick
 */
void exportAnalyseSeriesDlg::WxStdDialogButtonSizer1OkClick(wxCommandEvent& event)
{
    // sauvegarder les valeurs en base config
    ParamManager* param = ParamManager::GetInstance("config");
    param->Set("config", "EXPORT_SERIES", "EXP_FILENAME", WxEdFilename->GetValue());
    param->Set("config", "EXPORT_SERIES", "FILTRE_MANQUANTS", WxCK_filtreManquants->GetValue());
    
    
    // fermer le dlg
    EndModal(wxID_OK);
}
