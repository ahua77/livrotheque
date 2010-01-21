//---------------------------------------------------------------------------
//
// Name:        statistique.cpp
// Author:      Epaillard
// Created:     20/07/05 15:48:04
//
//Copyright  PE Epaillard, 20/07/05 
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

#include "statistique.h"

//Do not add custom headers.
//wx-dvcpp designer will remove them
////Header Include Start
////Header Include End

#include "ParamManager.h"
#include "ParametreDlg.h"

//----------------------------------------------------------------------------
// statistique
//----------------------------------------------------------------------------
     //Add Custom Events only in the appropriate Block.
    // Code added in  other places will be removed by wx-dvcpp 
    ////Event Table Start
BEGIN_EVENT_TABLE(statistique,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(statistique::statistiqueClose)
	EVT_SIZE(statistique::statistiqueSize)
	EVT_MENU(ID_MNU__IMPRIMER_1006, statistique::Mnuimprimer1006Click)
	EVT_MENU(ID_MNU_QUITTER_1002, statistique::Mnuquitter1002Click)
	EVT_MENU(ID_MNU_APER_UA_VANTIMPRESSION_1007, statistique::Mnuaperuavantimpression1007Click)
	EVT_MENU(ID_MNU_GENRE_1012, statistique::MnuGraph1013Click)
	EVT_MENU(ID_MNU_AUTEUR_1013, statistique::MnuGraph1013Click)
	EVT_MENU(ID_MNU_EDITEUR_1014, statistique::MnuGraph1013Click)
	EVT_MENU(ID_MNU_FORMAT_1015, statistique::MnuGraph1013Click)
	EVT_MENU(ID_MNU_ETAT_1016, statistique::MnuGraph1013Click)
	EVT_MENU(ID_MNU_LOCALISATION_1017, statistique::MnuGraph1013Click)
	EVT_MENU(ID_MNU_PAYS_1018, statistique::MnuGraph1013Click)
	EVT_MENU(ID_MNU_LANGUE_1019, statistique::MnuGraph1013Click)
	EVT_MENU(ID_MNU_TRADUCTEUR_1020, statistique::MnuGraph1013Click)
	EVT_MENU(ID_MNU_ARTISTE_1021, statistique::MnuGraph1013Click)
	EVT_MENU(ID_MNU_NOTES_1027, statistique::MnuGraph1013Click)
	EVT_MENU(ID_MNU_ANNEEDELECTURE_1024, statistique::MnuGraph1013Click)
	EVT_MENU(ID_MNU_MOIS_ANNEEDELECTURE_1025, statistique::MnuGraph1013Click)
	EVT_MENU(ID_MNU_ANNEEDACHAT_1022, statistique::MnuGraph1013Click)
	EVT_MENU(ID_MNU_MOISDACHAT_1023, statistique::MnuGraph1013Click)
	EVT_MENU(ID_MNU_BARRES_1009, statistique::MnuAffSwitch1009Click)
	EVT_MENU(ID_MNU_CAMEMBERT_1010, statistique::MnuAffSwitch1009Click)
	EVT_MENU(ID_MNU_BARRESCOMMENTEES_1026, statistique::MnuAffSwitch1009Click)
	EVT_MENU(ID_MNU_GESTIONDESCOULEURS_1005, statistique::Mnugestiondescouleurs1005Click)
	EVT_MENU(ID_MNU_PARAMETRER, statistique::parametrer)
END_EVENT_TABLE()
    ////Event Table End



statistique::statistique( wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxFrame( parent, id, title, position, size, style)
{
    CreateGUIControls();
}

statistique::~statistique()
{
    
} 

void statistique::CreateGUIControls(void)
{
    la_belle=NULL;
    BeauFrometon = new MonCamembert(this,ID_WXCAMEMBERT,this->GetClientAreaOrigin(),this->GetClientSize());
    //Do not add custom Code here
    //wx-devcpp designer will remove them.
    //Add the custom code before or after the Blocks
    ////GUI Items Creation Start

	SetTitle(wxT("Statistiques"));
	SetIcon(wxNullIcon);
	SetSize(8,8,362,296);
	Center();
	

	WxMenuBar_stat = new wxMenuBar();
	wxMenu *ID_MNU_FICHIER_1001_Mnu_Obj = new wxMenu(0);
	ID_MNU_FICHIER_1001_Mnu_Obj->Append(ID_MNU__IMPRIMER_1006, wxT("&Imprimer"), wxT(""), wxITEM_NORMAL);
	ID_MNU_FICHIER_1001_Mnu_Obj->Append(ID_MNU_QUITTER_1002, wxT("&Quitter"), wxT(""), wxITEM_NORMAL);
	ID_MNU_FICHIER_1001_Mnu_Obj->Append(ID_MNU_APER_UA_VANTIMPRESSION_1007, wxT("Aperçu  a&vant Impression"), wxT(""), wxITEM_NORMAL);
	WxMenuBar_stat->Append(ID_MNU_FICHIER_1001_Mnu_Obj, wxT("&Fichier"));
	
	wxMenu *ID_MNU__GRAPHIQUE_1011_Mnu_Obj = new wxMenu(0);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Append(ID_MNU_GENRE_1012, wxT("Genre"), wxT(""), wxITEM_RADIO);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Check(ID_MNU_GENRE_1012,true);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Append(ID_MNU_AUTEUR_1013, wxT("Auteur"), wxT(""), wxITEM_RADIO);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Check(ID_MNU_AUTEUR_1013,false);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Append(ID_MNU_EDITEUR_1014, wxT("Editeur"), wxT(""), wxITEM_RADIO);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Check(ID_MNU_EDITEUR_1014,false);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Append(ID_MNU_FORMAT_1015, wxT("Format"), wxT(""), wxITEM_RADIO);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Check(ID_MNU_FORMAT_1015,false);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Append(ID_MNU_ETAT_1016, wxT("Etat"), wxT(""), wxITEM_RADIO);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Check(ID_MNU_ETAT_1016,false);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Append(ID_MNU_LOCALISATION_1017, wxT("Localisation"), wxT(""), wxITEM_RADIO);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Check(ID_MNU_LOCALISATION_1017,false);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Append(ID_MNU_PAYS_1018, wxT("Pays"), wxT(""), wxITEM_RADIO);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Check(ID_MNU_PAYS_1018,false);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Append(ID_MNU_LANGUE_1019, wxT("Langue"), wxT(""), wxITEM_RADIO);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Check(ID_MNU_LANGUE_1019,false);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Append(ID_MNU_TRADUCTEUR_1020, wxT("Traducteur"), wxT(""), wxITEM_RADIO);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Check(ID_MNU_TRADUCTEUR_1020,false);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Append(ID_MNU_ARTISTE_1021, wxT("Artiste"), wxT(""), wxITEM_RADIO);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Check(ID_MNU_ARTISTE_1021,false);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Append(ID_MNU_NOTES_1027, wxT("Notes"), wxT(""), wxITEM_RADIO);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Check(ID_MNU_NOTES_1027,false);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Append(ID_MNU_ANNEEDELECTURE_1024, wxT("Année de lecture"), wxT(""), wxITEM_RADIO);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Check(ID_MNU_ANNEEDELECTURE_1024,false);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Append(ID_MNU_MOIS_ANNEEDELECTURE_1025, wxT("Mois/année de lecture"), wxT(""), wxITEM_RADIO);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Check(ID_MNU_MOIS_ANNEEDELECTURE_1025,false);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Append(ID_MNU_ANNEEDACHAT_1022, wxT("Année D'achat"), wxT(""), wxITEM_RADIO);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Check(ID_MNU_ANNEEDACHAT_1022,false);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Append(ID_MNU_MOISDACHAT_1023, wxT("Mois/année d'achat"), wxT(""), wxITEM_RADIO);
	ID_MNU__GRAPHIQUE_1011_Mnu_Obj->Check(ID_MNU_MOISDACHAT_1023,false);
	WxMenuBar_stat->Append(ID_MNU__GRAPHIQUE_1011_Mnu_Obj, wxT("&Graphique"));
	
	wxMenu *ID_MNU__AFFICHAGE_1008_Mnu_Obj = new wxMenu(0);
	ID_MNU__AFFICHAGE_1008_Mnu_Obj->Append(ID_MNU_BARRES_1009, wxT("&Barres"), wxT(""), wxITEM_RADIO);
	ID_MNU__AFFICHAGE_1008_Mnu_Obj->Check(ID_MNU_BARRES_1009,true);
	ID_MNU__AFFICHAGE_1008_Mnu_Obj->Append(ID_MNU_CAMEMBERT_1010, wxT("&Camembert"), wxT(""), wxITEM_RADIO);
	ID_MNU__AFFICHAGE_1008_Mnu_Obj->Check(ID_MNU_CAMEMBERT_1010,false);
	ID_MNU__AFFICHAGE_1008_Mnu_Obj->Append(ID_MNU_BARRESCOMMENTEES_1026, wxT("barres &commentées"), wxT(""), wxITEM_RADIO);
	ID_MNU__AFFICHAGE_1008_Mnu_Obj->Check(ID_MNU_BARRESCOMMENTEES_1026,false);
	WxMenuBar_stat->Append(ID_MNU__AFFICHAGE_1008_Mnu_Obj, wxT("&Affichage"));
	
	wxMenu *ID_MNU__OPTION_1004_Mnu_Obj = new wxMenu(0);
	ID_MNU__OPTION_1004_Mnu_Obj->Append(ID_MNU_GESTIONDESCOULEURS_1005, wxT("Gestion des &couleurs"), wxT(""), wxITEM_NORMAL);
	ID_MNU__OPTION_1004_Mnu_Obj->Append(ID_MNU_PARAMETRER, wxT("Paramètres"), wxT("Configuration générale de l'application"), wxITEM_NORMAL);
	WxMenuBar_stat->Append(ID_MNU__OPTION_1004_Mnu_Obj, wxT("&Option"));
	SetMenuBar(WxMenuBar_stat);
    ////GUI Items Creation End
    this->SetSize(30,30,800,600);
	//WxBoxSizer_top->Add(BeauFrometon,0,wxALIGN_CENTER_HORIZONTAL | wxALL,5);
    
    if (la_belle!=NULL)
        BeauFrometon->Dessiner();
    actualiser();
    //this->Refresh();

}

void statistique::statistiqueClose(wxCloseEvent& event)
{
    // --> Don't use Close with a Frame,
    // use Destroy instead.
    //Destroy();
    Hide();
}
 

/*
 * Mnuquitter1002Click
 */
void statistique::Mnuquitter1002Click(wxCommandEvent& event)
{
	// insert your code here
    Hide();
}

void statistique::parametrer(wxCommandEvent& event)
{
    ParametreDlg dlg(this, 1);
    dlg.ShowModal();
    actualiser();
}


void statistique::init_tableaux(wxString nom_table) {
//    int i,j;
    int ret;
    wxString mess;
    wxString query;
    wxString texte;
    wxArrayString liste_id;
    //int id;
    int taille;
    int val;

    BeauFrometon->Titre=titre;
    this->SetTitle(wxT("Statistique : ")+titre);

    if (la_belle == NULL)
        return;
    
    
    if(nom_table.StartsWith("date")) {
        gestion_date(nom_table);
        return;
    }else if(nom_table.StartsWith("note")) {
        gestion_note(nom_table);
        return;
    }
    BeauFrometon->aiNbre.Clear();
    BeauFrometon->asCommentaire.Clear();
    liste_id.Clear();
    
    ParamManager* param = ParamManager::GetInstance("config");
    BOOL useTopN = true;
    long seuil = 20;
    param->GetOrSet("config", "STAT", "USE_TOP_N", useTopN, seuil);
    query= "SELECT a.nom, count(l.rowid) nn from "+nom_table
          +" a, livre l where l.id_"+nom_table
          +" = a.rowid group by a.rowid order by nn desc";
    ret=la_belle->transac_prepare(query);
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
    }
    ret=la_belle->transac_step();
    int nbVal = 0;
    int totalHorsTop = 0;
    while(ret==SQLITE_ROW)
    {
       if (ret<0)
       {
          la_belle->get_erreur(mess);
          wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
       }
       else
       {
          nbVal++;
          if (!useTopN || nbVal <= seuil)
          {
              la_belle->get_value_char(0,texte,taille);
              BeauFrometon->asCommentaire.Add(texte);
              la_belle->get_value_int(1,val);
              BeauFrometon->aiNbre.Add(val);
          }
          else
          {
              la_belle->get_value_int(1,val);
              totalHorsTop += val;                
          }
          
       }    
       ret=la_belle->transac_step();
    }  
    if (totalHorsTop > 0)
    {
        BeauFrometon->asCommentaire.Add("[Autres]");
        BeauFrometon->aiNbre.Add(totalHorsTop);
    }
    la_belle->transac_fin();
}    

static int comparemois(const wxString& first, const wxString& second)
{
    wxString firsti,secondi;
    
    if (first == second)
        return 0;
    
    firsti=first.AfterFirst('/')+first.BeforeFirst('/');
    secondi=second.AfterFirst('/')+second.BeforeFirst('/');
    if(firsti>secondi) 
        return 1;
    if(firsti<secondi) 
        return -1;
    // pour enlever un warning
    return 0;
}

void statistique::gestion_note(wxString type_note) {
    wxString query, texte, mess;
    int ret, val, i;

    BeauFrometon->aiNbre.Clear();
    BeauFrometon->asCommentaire.Clear();

    for (i=0;i<=10;i++) {
        query.Printf("Select count(*) from livre where note='%d'",i);
        ret=la_belle->transac_prepare(query);
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }    
        ret=la_belle->transac_step();
        la_belle->get_value_int(0,val);
        mess.Printf("%d",i);
                //wxMessageBox(mess,"test", wxOK | wxICON_EXCLAMATION, this);
        BeauFrometon->asCommentaire.Add(mess);
        BeauFrometon->aiNbre.Add(val);
        la_belle->transac_fin();
    }
    
}
void statistique::gestion_date(wxString type_date) {
    wxString nom_champ, type_tri="Annee";
    wxString query, texte, mess;
    int ret, val, taille;
    int i, annee_cour=0;
    wxArrayString donnees;
    
    if (type_date == "date_achat_annee") {
        nom_champ="date_achat";
    } else if (type_date == "date_achat_mois") {
        nom_champ="date_achat";
        type_tri="mois";
    }else if (type_date == "date_lecture_annee") {
        nom_champ="date_lecture";
    } else if (type_date == "date_lecture_mois") {
        nom_champ="date_lecture";
        type_tri="mois";
    }
    if (type_tri == "mois") {
        wxDateTime madate;
        madate.SetToCurrent();
        annee_cour=(int)wxGetNumberFromUser( "Entrez l'année désirée\n Cancel pour les 12 derniers mois.\n 0 pour avoir toutes les données", "Année à afficher : ", "Choix de l'année",madate.GetYear(), 0, 3000, this);
    }

    BeauFrometon->aiNbre.Clear();
    BeauFrometon->asCommentaire.Clear();

    query="Select "+nom_champ+" from livre";
    ret=la_belle->transac_prepare(query);
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
    }
    ret=la_belle->transac_step();
    /* on récupère toutes les dates */
    while(ret==SQLITE_ROW) {
        if (ret<0) {
            la_belle->get_erreur(mess);
            wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
        }else {
            la_belle->get_value_char(0,texte,taille);
            if (type_tri == "mois")
                texte=texte.AfterFirst('/');
            else 
                texte=texte.AfterLast('/');
            if (texte.Len()>0) {
                mess.Printf("%d",annee_cour);
                if (type_tri != "mois" || annee_cour<=0 || mess==texte.AfterLast('/')) {
                    donnees.Add(texte);
                }
            }
        }    
          ret=la_belle->transac_step();
    }  
    la_belle->transac_fin();
    
    // on a récupéré les données maintenant on tri et on compte
    if (type_tri == "mois") {
        donnees.Sort(comparemois);
    } else
        donnees.Sort();
    i=-1;
    texte="";
    while (donnees.GetCount() !=0) {
        if (texte!=donnees[0]) {
            BeauFrometon->asCommentaire.Add(donnees[0]);
            BeauFrometon->aiNbre.Add(1);
            i++;
        } else {
            val=(BeauFrometon->aiNbre.Item(i)+1);
            BeauFrometon->aiNbre.RemoveAt(i);
            BeauFrometon->aiNbre.Add(val);
        }
        //mess.Printf("nbre comm:%d, nbre nbre :%d", BeauFrometon->asCommentaire.GetCount(), BeauFrometon->aiNbre.GetCount());
        //wxMessageBox(mess,"test", wxOK | wxICON_EXCLAMATION, this);
        
        texte=donnees[0];
        donnees.RemoveAt(0);
    }
    if (annee_cour ==-1) { //on ne garde que les 12 derniers
        i=BeauFrometon->asCommentaire.GetCount();
        BeauFrometon->asCommentaire.RemoveAt(0,i-12);
        BeauFrometon->aiNbre.RemoveAt(0,i-12);
    }
}
/*
 * statistiqueSize
 */
void statistique::statistiqueSize(wxSizeEvent& event)
{
    dessiner();
}
void statistique::dessiner() {
    wxString mess;
    wxSize lataille;
    if (BeauFrometon->aiNbre.GetCount() == 0) {
        BeauFrometon->aiNbre.Add(1);
        BeauFrometon->asCommentaire.Add("aucune donnée");
    }
    if (BeauFrometon->aiNbre.GetCount() >0) {
       
        //BeauFrometon->Refresh();
        // insert your code here
        /*BeauFrometon->tailleDessin=this->GetClientSize();
        BeauFrometon->SetSize(this->GetClientSize());
        BeauFrometon->Dessiner();
        BeauFrometon->SetScrollbars(0,0,0,0);
        if (this->GetClientSize().GetHeight()<BeauFrometon->calc_hauteur_min()) {
            BeauFrometon->SetVirtualSize(lataille);
            BeauFrometon->SetScrollbars(0,10,0,(BeauFrometon->calc_hauteur_min()+9)/10);
            lataille=::wxSize(this->GetClientSize().GetWidth()-10,BeauFrometon->calc_hauteur_min()+1);
            BeauFrometon->tailleDessin=lataille;
        //mess.Printf("h min:%d", BeauFrometon->calc_hauteur_min());
        //wxMessageBox(mess,"test", wxOK | wxICON_EXCLAMATION, this)
        }*/
        BeauFrometon->tailleDessin=this->GetClientSize();
        BeauFrometon->Dessiner();

    }
}

void statistique::definir_base(ma_base *babase) {
    la_belle=babase;
    type_stat="genre";
    titre="Genre";
    load_typegraph();
    actualiser();
}

/*
 * Mnugestiondescouleurs1005Click
 */
void statistique::Mnugestiondescouleurs1005Click(wxCommandEvent& event)
{
	// insert your code here
//	GestionListeCouleur magest(this,BeauFrometon->listeCouleur, BeauFrometon->asCommentaire, BeauFrometon->LaFont, BeauFrometon->couleurTexte);
	GestionCoul magest(this,BeauFrometon);
	magest.ShowModal();
	dessiner();
}

/*
 * Mnuimprimer1006Click
 */
void statistique::Mnuimprimer1006Click(wxCommandEvent& event)
{
	// insert your code here
    wxPrintData *g_printData = new wxPrintData();
    wxPrintDialogData printDialogData(* g_printData);

    g_printData->SetOrientation(wxLANDSCAPE);
    wxPrinter printer(& printDialogData);
    MyPrintout printout(_T("Impression des statistiques"),BeauFrometon);
    if (!printer.Print(this, &printout, true /*prompt*/))
    {
        if (wxPrinter::GetLastError() == wxPRINTER_ERROR)
            wxMessageBox(_T("Problême lors de l'impression.\nVotre imprimante est peut-être mal configurée."), _T("Impression"), wxOK);
        else
            wxMessageBox(_T("Impression interrompue"), _T("Impression"), wxOK);
    }
    else
    {
        (*g_printData) = printer.GetPrintDialogData().GetPrintData();
    }
}

/*
 * Mnuaperuavantimpression1007Click
 */
void statistique::Mnuaperuavantimpression1007Click(wxCommandEvent& event)
{
	// insert your code here
    wxPrintData *g_printData;
    g_printData = new wxPrintData;
    wxSize taille=wxSize(700,600);
    wxSize taille_tmp;
    
     // Pass two printout objects: for preview, and possible printing.
     g_printData->SetOrientation(wxLANDSCAPE);
    wxPrintDialogData printDialogData(* g_printData);
    wxPrintPreview *preview = new wxPrintPreview(new MyPrintout("Prévisualiastion",BeauFrometon), new MyPrintout("Prévisualiastion",BeauFrometon), & printDialogData);
    if (!preview->Ok())
    {
        delete preview;
        wxMessageBox(_T("Probleme lors de la prévisualisation.\nVotre imprimante est peut-être mal configurée."), _T("Prévisualisation"), wxOK);
        return;
    }

    wxPreviewFrame *frame = new wxPreviewFrame(preview, this, _T("Aperçu avant impression"), wxDefaultPosition, taille);
    frame->Centre(wxBOTH);
    frame->Initialize();
    frame->Show();
    actualiser();
}

void statistique::actualiser() {
    init_tableaux(type_stat);
    //BeauFrometon->Dessiner();
    //this->Refresh();
    dessiner();

}

/*
 * MnuAffSwitch1009Click
 */
void statistique::MnuAffSwitch1009Click(wxCommandEvent& event)
{
    wxString message;
	// insert your code here
	if(event.GetId() == ID_MNU_BARRES_1009) {
        graph_encour=MonCamembert::Rectangle;
    } else if (event.GetId() == ID_MNU_CAMEMBERT_1010) {
        graph_encour = MonCamembert::Cercle;
    } else if (event.GetId() == ID_MNU_BARRESCOMMENTEES_1026) {
        graph_encour = MonCamembert::RectangleBas;
    }
    BeauFrometon->typeGraph = graph_encour;
    sauve_typegraph();
    //BeauFrometon->Dessiner();
    dessiner();
}

void statistique::sauve_typegraph() {
    wxString query;
    wxString mess;
    if (la_belle->existe("config_stat") != true ) {
        //wxMessageBox("existe pas", _T("test"), wxOK);
        query="CREATE TABLE config_stat (type_param TEXT , nom_param TEXT, val1 TEXT, val2 TEXT)";
        la_belle->exec_rapide(query);
    }
    query="DELETE FROM config_stat where type_param='type_graph' AND nom_param='"+type_stat+"'";
    la_belle->exec_rapide(query);
    mess.Printf("%d",graph_encour);
    query="INSERT INTO config_stat (type_param, nom_param, val1) VALUES ('type_graph', '"+type_stat+"', '"+mess+"')";
    la_belle->exec_rapide(query);
}

void statistique::load_typegraph() {
    wxString query;
    wxString mess;
    int ret, taille;
    long graphique;
    
    if (la_belle->existe("config_stat") != TRUE ) {
        return;
    }
    query="SELECT val1 FROM config_stat where type_param='type_graph' AND nom_param='"+type_stat+"'";
    ret=la_belle->transac_prepare(query);
    if (ret<0) {
        la_belle->get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, this);
    }

    ret=la_belle->transac_step();

    //BeauFrometon->typeGraph = MonCamembert::Rectangle;
    if (ret==SQLITE_ROW) {
        la_belle->get_value_char(0,mess,taille);
        mess.ToLong(&graphique);
        BeauFrometon->typeGraph = (MonCamembert::myTypeGraph) graphique;
        if (BeauFrometon->typeGraph == MonCamembert::Rectangle)
            WxMenuBar_stat->Check(ID_MNU_BARRES_1009, true);
        else if (BeauFrometon->typeGraph == MonCamembert::Cercle)
            WxMenuBar_stat->Check(ID_MNU_CAMEMBERT_1010, true);
        else if (BeauFrometon->typeGraph == MonCamembert::RectangleBas)
            WxMenuBar_stat->Check(ID_MNU_BARRESCOMMENTEES_1026, true);
    }  
    la_belle->transac_fin();
}

/*
 * MnuGraph1013Click
 */
void statistique::MnuGraph1013Click(wxCommandEvent& event)
{
    //wxMessageBox("toto", _T("Impression"), wxOK);

	// insert your code here
	if(event.GetId() == ID_MNU_GENRE_1012) {
        titre="Genre";
        type_stat="genre";
    } else if (event.GetId() == ID_MNU_AUTEUR_1013) {
        titre="Auteur";
        type_stat="auteur";
    } else if (event.GetId() == ID_MNU_EDITEUR_1014) {
        titre="Editeur";
        type_stat="editeur";
    } else if (event.GetId() == ID_MNU_FORMAT_1015) {
        titre="Format";
        type_stat="format";
    } else if (event.GetId() == ID_MNU_ETAT_1016) {
        titre="Etat";
        type_stat="etat";
    } else if (event.GetId() == ID_MNU_LOCALISATION_1017) {
        titre="Localisation";
        type_stat="localisation";
    } else if (event.GetId() == ID_MNU_PAYS_1018) {
        titre="Pays";
        type_stat="pays";
    } else if (event.GetId() == ID_MNU_LANGUE_1019) {
        titre="Langue";
        type_stat="langue";
    } else if (event.GetId() == ID_MNU_TRADUCTEUR_1020) {
        titre="Traducteur";
        type_stat="traducteur";
    } else if (event.GetId() == ID_MNU_ARTISTE_1021) {
        titre="Artiste";
        type_stat="artiste";
    } else if (event.GetId() == ID_MNU_ANNEEDACHAT_1022) {
        titre="Année d'achat";
        type_stat="date_achat_annee";
    } else if (event.GetId() == ID_MNU_NOTES_1027) {
        titre="Notes";
        type_stat="note";
    } else if (event.GetId() == ID_MNU_MOISDACHAT_1023) {
        titre="Mois/annee d'achat";
        type_stat="date_achat_mois";
    } else if (event.GetId() == ID_MNU_ANNEEDELECTURE_1024) {
        titre="Année de lecture";
        type_stat="date_lecture_annee";
    } else if (event.GetId() == ID_MNU_MOIS_ANNEEDELECTURE_1025) {
        titre="Mois/Année de lecture";
        type_stat="date_lecture_mois";
    }
    load_typegraph();
    //BeauFrometon->Dessiner();
    actualiser();
}
