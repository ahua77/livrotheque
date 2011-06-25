//---------------------------------------------------------------------------
//
// Name:        liste_champ.cpp
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

#ifdef __GNUG__
    #pragma implementation "liste_champ.cpp"
#endif

/* for compilers that support precompilation
   includes "wx/wx.h" */

#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif


#include "liste_champ.h"

////Header Include Start
////Header Include End

long liste_champ::s_nbInstances = 0;


//----------------------------------------------------------------------------
// liste_champ
//----------------------------------------------------------------------------

    ////Event Table Start
BEGIN_EVENT_TABLE(liste_champ,wxDialog)
	////Manual Code Start
	EVT_GRID_CMD_CELL_RIGHT_CLICK(ID_GRILLE_LISTE, liste_champ::OnGrilleClickDroit)
	////Manual Code End
	
	EVT_CLOSE(liste_champ::liste_champClose)
	EVT_MENU(ID_MNU_SUPPRIME_1008 , liste_champ::Mnusupprime1008Click)
	EVT_BUTTON(ID_WXBUTTON_INSERER,liste_champ::WxButton_insererClick)
	EVT_BUTTON(wxID_CANCEL,liste_champ::WxButton_okClick)
	EVT_GRID_CELL_LEFT_CLICK(liste_champ::grilleCellLeftClick)
	EVT_GRID_CELL_LEFT_DCLICK(liste_champ::grilleCellLeftDoubleClick)
	EVT_GRID_LABEL_LEFT_CLICK(liste_champ::grilleLabelLeftClick)
END_EVENT_TABLE()
    ////Event Table End



liste_champ::liste_champ( wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    s_nbInstances++;
    wxLogMessage("liste_champ::liste_champ() - nbInstances = %ld", s_nbInstances);

    modifie=false;
    nom_table=title;
    critere_tri = "upper(a.nom)";
    ordre_tri = "ASC";
    CreateGUIControls();
}

liste_champ::liste_champ( ma_base *pour_modif, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    s_nbInstances++;
    wxLogMessage("liste_champ::liste_champ() - nbInstances = %ld", s_nbInstances);

    modifie=false;
    la_belle=pour_modif;
    nom_table=title;
    critere_tri = "upper(a.nom)";
    ordre_tri = "ASC";
    CreateGUIControls();
}

liste_champ::~liste_champ()
{
    s_nbInstances--;
    wxLogMessage("liste_champ::~liste_champ() - nbInstances = %ld", s_nbInstances);

    SetReturnCode(modifie);
} 

void liste_champ::CreateGUIControls(void)
{
    ////GUI Items Creation Start

	WxBoxSizer_general = new wxBoxSizer(wxHORIZONTAL);
	this->SetSizer(WxBoxSizer_general);
	this->SetAutoLayout(true);

	WxBoxSizer_top = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer_general->Add(WxBoxSizer_top, 1, wxALIGN_CENTER | wxEXPAND | wxALL, 5);

	grille = new wxGrid(this, ID_GRILLE_LISTE, wxPoint(5, 5), wxSize(400, 300));
	grille->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	grille->SetDefaultColSize(50);
	grille->SetDefaultRowSize(25);
	grille->SetRowLabelSize(50);
	grille->SetColLabelSize(25);
	grille->CreateGrid(5,5,wxGrid::wxGridSelectRows);
	WxBoxSizer_top->Add(grille,1,wxALIGN_CENTER | wxEXPAND | wxALL,5);

	WxBoxSizer_button = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer_top->Add(WxBoxSizer_button, 0, wxALIGN_CENTER | wxALL, 5);

	WxButton_ok = new wxButton(this, wxID_CANCEL, wxT("OK"), wxPoint(5, 5), wxSize(80, 28), 0, wxDefaultValidator, wxT("WxButton_ok"));
	WxButton_ok->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxBoxSizer_button->Add(WxButton_ok,0,wxALIGN_CENTER | wxALL,5);

	WxButton_inserer = new wxButton(this, ID_WXBUTTON_INSERER, wxT("Inserer"), wxPoint(95, 5), wxSize(80, 28), 0, wxDefaultValidator, wxT("WxButton_inserer"));
	WxButton_inserer->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("MS Sans Serif")));
	WxBoxSizer_button->Add(WxButton_inserer,0,wxALIGN_CENTER | wxALL,5);

	WxPopupMenu_grille = new wxMenu(wxT(""));WxPopupMenu_grille->Append(ID_MNU_SUPPRIME_1008, wxT("Supprimer la ligne courante"), wxT(""), wxITEM_NORMAL);

	SetTitle(wxT("liste"));
	SetIcon(wxNullIcon);
	
	GetSizer()->Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
    ////GUI Items Creation End
	grille->SetSelectionMode(wxGrid::wxGridSelectRows);
    init_grille();
    this->SetTitle(nom_table);
}

void liste_champ::init_grille() {
    int i,j;
    int ret;
    wxString mess;
    wxString query;
    wxString texte;
    //int id;
    int taille;
    int nbcol, champ;

    int ir = grille->GetNumberRows();
    if (ir)
        grille->DeleteRows(0, ir);
    ir = grille->GetNumberCols();
    if (ir)
        grille->DeleteCols(0, ir);
        
    query= "SELECT a.rowid, a.nom, count(l.rowid) nn from "+nom_table
          +" a left outer join livre l on l.id_"+nom_table
          +" = a.rowid group by a.rowid order by "+critere_tri + " " + ordre_tri;

        
//    query= "SELECT rowid, nom FROM "+nom_table+" ORDER BY nom";
    ret=la_belle->transac_prepare(query);
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
    }
    ret=la_belle->transac_step();
    i=j=0;
    nbcol=la_belle->transac_nbcol(); 
    grille->InsertCols(0,nbcol);
    grille->SetColLabelValue(0,"id");
    grille->SetColLabelValue(1,"nom");
    grille->SetColLabelValue(2,"nb");
    while(ret==SQLITE_ROW) {

        grille->AppendRows();
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }else {
            for (champ=0; champ<nbcol;champ++) {
                la_belle->get_value_char(champ,texte,taille);
                if (champ == 0) 
                    grille->SetRowLabelValue(i,texte);
                grille->SetCellValue(i,champ,texte);
                grille->SetReadOnly( i, champ, true );
            }     
        }    
        i++;
        //j=0;
          ret=la_belle->transac_step();
    }  
    la_belle->transac_fin();
/*    
    for (i=0; i<grille->GetNumberRows() ; i++) {
        query="SELECT count(*) FROM livre where id_"+nom_table+"="+grille->GetRowLabelValue(i);
        ret=la_belle->transac_prepare(query);
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }    
        ret=la_belle->transac_step();
        la_belle->get_value_char(0,texte,taille);
        grille->SetCellValue(i,2,texte);
        grille->SetReadOnly( i, 2, true );
        la_belle->transac_fin();
    }
*/
    if (nom_table.CmpNoCase("auteur") == 0 || nom_table.CmpNoCase("artiste") == 0) {
        grille->AppendCols(1);
        grille->SetColLabelValue(3,"inverser");
        for (i=0; i<grille->GetNumberRows() ; i++) {
            grille->SetCellValue(i, 3, "Cliquez ici");
            grille->SetReadOnly( i, 3, true );
        }
    }

    grille->SetColLabelSize(15);
    grille->SetRowLabelSize(0);
//    grille->EnableEditing(false);
    grille->AutoSizeColumns(true);
    grille->AutoSizeRows(true);
    if (grille->GetNumberRows()>0) {
        grille->SelectRow(0);
    }    

}    

void liste_champ::liste_champClose(wxCloseEvent& event)
{
    // --> Don't use Close with a wxDialog,
    // use Destroy instead.
    Destroy();
}
 
/*
 * WxButton_okClick
 */
void liste_champ::WxButton_okClick(wxCommandEvent& event)
{
    // insert your code here
    Destroy();
    event.Skip();
}

/*
 * grilleCellLeftDoubleClick
 */
void liste_champ::grilleCellLeftDoubleClick(wxGridEvent& event)
{
    wxString id;
    int nb_ligne;
    
    nb_ligne=event.GetRow();
    id=grille->GetRowLabelValue(nb_ligne);
    nouv_autre* nouv = new nouv_autre(la_belle, id, this, -1, nom_table);
    nouv->ShowModal();
    init_grille();
	// insert your code here
	event.Skip();
}

/*
 * WxButton_insererClick
 */
void liste_champ::WxButton_insererClick(wxCommandEvent& event)
{
    nouv_autre* nouv = new nouv_autre(la_belle, "-1", this, -1, nom_table);
    nouv->ShowModal();
    init_grille();
	// insert your code here
	event.Skip();
}

void liste_champ::OnGrilleClickDroit( wxGridEvent& event ) {
    int nrow;
    
    nrow=event.GetRow();
    grille->SelectRow(nrow);

    PopupMenu(WxPopupMenu_grille);
}

/*
 * Mnusupprime1008Click
 */
void liste_champ::Mnusupprime1008Click(wxCommandEvent& event)
{
    wxString nb_enr, id, mess;
    wxString query;
    wxArrayInt cell_select;
    int ret;
    
    cell_select=grille->GetSelectedRows(); 
    if (cell_select.GetCount()>0) {
        nb_enr=grille->GetCellValue(cell_select[0],2);
        id=grille->GetCellValue(cell_select[0],0);
        if (nb_enr != "0") {
            mess="Vous ne pouvez pas supprimer cette ligne :\n il y a "+nb_enr+" livres qui en dépendent";
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        } else {
            ret=wxMessageBox("Etes vous sur de vouloir effacer cette ligne?? \n(Attention cet effacement est DEFINITIF!)","Question", wxYES_NO|wxNO_DEFAULT | wxICON_EXCLAMATION, this);
            if (ret == wxYES) {
                query="DELETE FROM "+nom_table +" WHERE rowid="+id;
                ret=la_belle->exec_rapide(query);
                if (ret<0) {
                    la_belle->get_erreur(mess);
                    wxMessageBox(query+"\n"+mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
                }
                init_grille();
            }    
        }    
    }    
	// insert your code here
	event.Skip();
}


/*
 * grilleCellLeftClick
 */
void liste_champ::grilleCellLeftClick(wxGridEvent& event)
{
	// insert your code here
	int numcol, numrow, taille,ret;
	if ((numcol=event.GetCol()) == 3) {
        wxString query, texte, texte_inverse;
        numrow=event.GetRow();
        query= "SELECT nom FROM "+nom_table+" Where rowid="+grille->GetCellValue(numrow,0);
        //wxMessageBox(query,"probleme", wxOK | wxICON_EXCLAMATION, this);
        ret=la_belle->transac_prepare(query);
        if (ret<0) {
            la_belle->get_erreur(texte);
            wxMessageBox(query+"\n"+texte,"probleme", wxOK | wxICON_EXCLAMATION, this);
            event.Skip();
            return;
        }
        ret=la_belle->transac_step();
        la_belle->get_value_char(0,texte,taille);
        la_belle->transac_fin();
        texte_inverse=inverse_texte(texte);
        ret=wxMessageBox("voulez vous inverser nom/prénom pour "+texte+"\n le nouveau nom sera : "+texte_inverse,"inversion", wxYES_NO | wxICON_QUESTION , this);
        if (ret == wxYES) {
            query="UPDATE "+nom_table+" set nom='"+texte_inverse+"' where rowid="+grille->GetCellValue(numrow,0);
            ret=la_belle->exec_rapide(query);
            if (ret<0) {
                la_belle->get_erreur(texte);
                wxMessageBox(query+"\n"+texte,"probleme", wxOK | wxICON_EXCLAMATION, this);
            } else {
                modifie=true;
                init_grille();
            }
            //wxMessageBox("INVERSION","probleme", wxOK | wxICON_EXCLAMATION, this);
       }
    }
	event.Skip();

}
wxString liste_champ::inverse_texte (wxString texte) {
    wxString fin_ch=texte.AfterLast(' ');
    wxString debut_ch=texte.BeforeLast(' ');
    return (fin_ch+wxT(" ")+debut_ch);

}

/*
 * grilleLabelLeftClick
 */
void liste_champ::grilleLabelLeftClick(wxGridEvent& event)
{
	// clic sur un label : trier par cette colonne et réafficher
    BOOL changeSens = false;
	if (event.GetCol() == 2) {
       changeSens = (critere_tri == "nn");
	   critere_tri = "nn";
    } else if (event.GetCol() == 1) {
       changeSens = (critere_tri == "upper(a.nom)");
	   critere_tri = "upper(a.nom)";
    } else if (event.GetCol() == 0) {
       changeSens = (critere_tri == "a.rowid");
	   critere_tri = "a.rowid";
    }
    
    if (changeSens) {
        if (ordre_tri == "ASC")
           ordre_tri = "DESC";
        else
           ordre_tri = "ASC";
    }
	   
	
	init_grille();
}
