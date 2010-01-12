///-----------------------------------------------------------------
///
/// @file      VerifNouveauGroupeDlg.cpp
/// @author    
/// Created:   26/12/2009 11:35:51
/// @section   DESCRIPTION
///            VerifNouveauGroupeDlg class implementation
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

#include "VerifNouveauGroupeDlg.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// VerifNouveauGroupeDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(VerifNouveauGroupeDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(VerifNouveauGroupeDlg::OnClose)
	EVT_INIT_DIALOG(VerifNouveauGroupeDlg::VerifNouveauGroupeDlgInitDialog)
	EVT_BUTTON(ID_WXBUTTON3,VerifNouveauGroupeDlg::BN_AnnulerClick)
	EVT_BUTTON(ID_WXBUTTON2,VerifNouveauGroupeDlg::BN_CreerClick)
	EVT_BUTTON(ID_WXBUTTON1,VerifNouveauGroupeDlg::BN_ChoisirClick)
END_EVENT_TABLE()
////Event Table End

VerifNouveauGroupeDlg::VerifNouveauGroupeDlg(wxWindow *parent, ma_base& pBase, 
                                             const wxString& valeur, const wxString& nom_table, const wxString& libelleGroupePluriel,
                                             wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style), mBaseLivre (pBase)
{
    mValeur = valeur;
    mNomTable = nom_table;
    
    mLibelleGroupePluriel = libelleGroupePluriel;
    if (mLibelleGroupePluriel == "") 
        mLibelleGroupePluriel = nom_table + "s";
    
    mOk = false;
    
	CreateGUIControls();
}

VerifNouveauGroupeDlg::~VerifNouveauGroupeDlg()
{
} 

void VerifNouveauGroupeDlg::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, wxT("(Vous pouvez modifier ce choix dans les param�tres de l'application)"), wxPoint(42, 218), wxDefaultSize, 0, wxT("WxStaticText3"));

	CK_ToujoursCreer = new wxCheckBox(this, ID_WXCHECKBOX1, wxT("Toujours cr�er les xxxxs sans poser la question."), wxPoint(24, 200), wxSize(385, 17), 0, wxDefaultValidator, wxT("CK_ToujoursCreer"));

	BN_Annuler = new wxButton(this, ID_WXBUTTON3, wxT("Annuler l'op�ration sur  le livre"), wxPoint(16, 147), wxSize(195, 25), 0, wxDefaultValidator, wxT("BN_Annuler"));
	BN_Annuler->Show(false);

	BN_Creer = new wxButton(this, ID_WXBUTTON2, wxT("Cr�er"), wxPoint(16, 109), wxSize(75, 25), 0, wxDefaultValidator, wxT("BN_Creer"));

	ET_nomGroupe = new wxTextCtrl(this, ID_WXEDIT1, wxT("ET_nomGroupe"), wxPoint(120, 112), wxSize(289, 19), 0, wxDefaultValidator, wxT("ET_nomGroupe"));

	BN_Choisir = new wxButton(this, ID_WXBUTTON1, wxT("Choisir"), wxPoint(16, 71), wxSize(75, 25), 0, wxDefaultValidator, wxT("BN_Choisir"));

	wxArrayString arrayStringFor_CB_listeGroupe;
	CB_listeGroupe = new wxComboBox(this, ID_WXCOMBOBOX1, wxT("Choisir un groupe"), wxPoint(120, 72), wxSize(289, 23), arrayStringFor_CB_listeGroupe, 0, wxDefaultValidator, wxT("CB_listeGroupe"));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, wxT("Voulez-vous s�lectionner un existant ou cr�er un nouveau ?"), wxPoint(16, 32), wxDefaultSize, 0, wxT("WxStaticText2"));

	ST_GroupeInconnu = new wxStaticText(this, ID_WXSTATICTEXT1, wxT("'xxx' est inconnu dans la liste des yyys."), wxPoint(16, 8), wxDefaultSize, 0, wxT("ST_GroupeInconnu"));

	SetTitle(wxT("D�tection d'un nouveau groupe"));
	SetIcon(wxNullIcon);
	SetSize(8,8,435,282);
	Center();
	
	////GUI Items Creation End
}

void VerifNouveauGroupeDlg::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * VerifNouveauGroupeDlgInitDialog
 */
void VerifNouveauGroupeDlg::VerifNouveauGroupeDlgInitDialog(wxInitDialogEvent& event)
{
    // wxMessageBox("VerifNouveauGroupeDlgInitDialog");
    
    // mettre � jour les libell�s
    ET_nomGroupe->SetValue(mValeur);
    ST_GroupeInconnu->SetLabel("'" + mValeur + "' est inconnu dans la liste des " + mLibelleGroupePluriel + ".");
    CK_ToujoursCreer->SetLabel("Toujours cr�er les " + mLibelleGroupePluriel + " sans poser la question.");
    
    // vider et remplir � partir de la base la liste de groupes
    while (!CB_listeGroupe->IsEmpty())
        CB_listeGroupe->Delete(0);
        
    // remplir les listes � partir de la base
	wxString query = "SELECT a.rowid, a.nom from " + mNomTable + " a order by a.nom ASC";
	wxString mess;
	int ret = mBaseLivre.transac_prepare(query);
	if (ret<0) {
        mBaseLivre.get_erreur(mess);
        mess=query+"\n"+mess;
        wxMessageBox("VerifNouveauGroupeDlgInitDialog "+mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        // baseLivre.fermer();
        return;
    }
    ret=SQLITE_ROW;
    ret=mBaseLivre.transac_step();
    int ii = 0;
    while(ret==SQLITE_ROW) {
        int id;
        wxString nom;
        int taille;
        mBaseLivre.get_value_int(0,id);
        mBaseLivre.get_value_char(1,nom,taille);
        CB_listeGroupe->AppendString(nom);
        CB_listeGroupe->SetClientData(ii, (void*)id);
        
        ii ++;
        ret=mBaseLivre.transac_step();
    }  
    mBaseLivre.transac_fin();
}

/*
 * BN_ChoisirClick
 */
void VerifNouveauGroupeDlg::BN_ChoisirClick(wxCommandEvent& event)
{
	mValeur = CB_listeGroupe->GetValue();
	mOk = true;
	this->EndDialog(0);
}

/*
 * BN_CreerClick
 */
void VerifNouveauGroupeDlg::BN_CreerClick(wxCommandEvent& event)
{
	mValeur = ET_nomGroupe->GetValue();
	mOk = true;
	this->EndDialog(0);
}

/*
 * BN_AnnulerClick
 */
void VerifNouveauGroupeDlg::BN_AnnulerClick(wxCommandEvent& event)
{
    mOk = false;
    this->EndDialog(1);
}
