// Name:        mabase.cpp
// Author:      PE EPAILLARD
// Created:     10/27/2004 12:22:10 AM
//
//Copyright PE Epaillard, 10/27/2004 
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

#include <stdio.h>
#include <string.h>
#include "mabase.h"

ma_base::ma_base(void) {
    //db=NULL;
/*    nom_base[0]='\0';
    msg_erreur[0]='\0';*/
    
    nom_base="";
    ouvert=false;
//    wxMessageBox("ma_base::ma_base(void)");
}    
 
ma_base::ma_base(wxString nom) {
    //db=NULL;
/*    nom_base[0]='\0';
    msg_erreur[0]='\0';*/
    nom_base=nom;
    this->ouvrir(nom);
    //ouvert=true;
//    wxMessageBox("ma_base::ma_base("+nom+")");
}    

ma_base::~ma_base(void) {
    if (ouverte())
        fermer();
    // sqlite3_close(db);
//    wxMessageBox("ma_base::~ma_base("+nom_base+")");
}

void ma_base::get_erreur(wxString &erreur){
    erreur=msg_erreur;
}
    
wxString ma_base::get_version() {
    const char *version;
    
    version=sqlite3_libversion();
    return version;
}
int ma_base::ouvrir(wxString nom) {
    int rc;
//    char tempo[20000];
//    wxMessageBox("ma_base::ouvrir("+nom+")");
    nom_base=nom;
//    strncpy(tempo,(char *)nom.mb_str(), nom.Length());
    //strncpy(tempo,(char *)nom.utf8_str(), nom.Length());
    //tempo[nom.Length()]='\0';
        //wxMessageBox(tempo,"probleme", wxOK | wxICON_EXCLAMATION);
    //rc = sqlite3_open(tempo, &db);
//    const wxWX2MBbuf localFileName(nom.mb_str(wxConvLibc));
    //const wxMBConvUTF8 localFileName(nom.mb_str(wxConvLibc));
    //rc = sqlite3_open((const char*)localFileName, &db);
    rc = sqlite3_open(nom.utf8_str(), &db);
    //rc = sqlite3_open(nom.c_str(), &db);
    //tempo=nom.wc_str();
    
    /*for(int i=0;i<nom.Length();i++)
    {
        tempo[i] = nom.GetChar(i);
    }
    tempo[nom.Length()] = '\0';    
    rc = sqlite3_open(tempo, &db);*/
    if( rc != SQLITE_OK ){
        msg_erreur.Printf("%s", sqlite3_errmsg(db));
        sqlite3_close(db);
        return (-1);
    }
    ouvert=true;
    return 0; 
}     

void ma_base::fermer() {
//    wxMessageBox("ma_base::fermer("+nom_base+")");
    if (sqlite3_close(db) !=  SQLITE_OK)
        wxMessageBox("probleme lors de la fermeture de la base "+nom_base,"probleme", wxOK | wxICON_EXCLAMATION);
    ouvert = false;
}
    
int ma_base::exec_rapide(wxString query){
    sqlite3_stmt *monstate;
    const char *reste;
    int ret;
    int longu;
    char *tempo;

    if (ouvert==false) {
        msg_erreur.Printf("La base n'est pas ouverte");
        return -1;
    }
    
    longu=query.Length();
    tempo=(char*)malloc((longu*sizeof(char))+20);
    strncpy(tempo,(char *)query.mb_str(), query.Length());
    tempo[query.Length()]='\0';
    ret=sqlite3_prepare(db,tempo,-1,&monstate,&reste);
    ret=sqlite3_step(monstate);
    if (ret!=SQLITE_DONE && ret!=SQLITE_ROW) {
       ret=sqlite3_finalize(monstate);
       msg_erreur.Printf("%s",sqlite3_errmsg(db));
        wxMessageBox("probleme lors du exec_rapide sur la base "+nom_base + "("+query+")"+ sqlite3_errmsg(db),"probleme", wxOK | wxICON_EXCLAMATION);    
        free(tempo);
        return -1;
    }    
    ret=sqlite3_finalize(monstate);
    if (ret !=  SQLITE_OK)
        wxMessageBox("probleme lors du sqlite3_finalize sur la base "+nom_base + "("+query+")"+ sqlite3_errmsg(db),"probleme", wxOK | wxICON_EXCLAMATION);    
    free(tempo);
    return 0;
}    

int ma_base::transac_prepare(wxString query){
    int ret,longu;
    char *tempo;
    
    if (ouvert==false) {
        msg_erreur.Printf("%s","La base n'est pas ouverte");
        return -1;
    }
       
    longu=query.Length();
    tempo=(char*)malloc((longu*sizeof(char))+20);
    //tempo=(char *) query.GetData(); 
    strncpy(tempo,(char *)query.mb_str(), query.Length());
    tempo[query.Length()]='\0';
    ret=sqlite3_prepare(db,tempo,query.Length(),&proc_state,&proc_reste);

    if (ret!=SQLITE_OK) {
        msg_erreur.Printf("prepare: %s ("+query+")",sqlite3_errmsg(db));
        free (tempo);
        return -1;
    }
    free(tempo);
    return 0;
}    

int ma_base::transac_step(){
    int ret;

    if (ouvert==false) {
        msg_erreur.Printf("%s","La base n'est pas ouverte");
        return -1;
    }
        
    ret=sqlite3_step(proc_state);
    if (ret==SQLITE_ROW)
        return SQLITE_ROW;
    if (ret!=SQLITE_DONE ) {
        msg_erreur.Printf("transac_step : %s ",sqlite3_errmsg(db));
        return -1;
    }    
    return 0;
}    

int ma_base::transac_fin(){
    int ret;

    if (ouvert==false) {
        msg_erreur.Printf("%s","La base n'est pas ouverte");
        return -1;
    }
        
    ret=sqlite3_finalize(proc_state);

    if (ret!=SQLITE_OK) {
        msg_erreur.Printf("%s",sqlite3_errmsg(db));
        wxMessageBox("probleme lors du sqlite3_finalize (transac_fin) sur la base "+nom_base + " " + sqlite3_errmsg(db),"probleme", wxOK | wxICON_EXCLAMATION);    
        return -1;
    }
    return 0;
}    

int ma_base::transac_blob(int nblob, wxFile *donnee){
    char *tempo;
    int ret;
    
    if (ouvert==false) {
        msg_erreur.Printf("%s","La base n'est pas ouverte");
        return -1;
    }
    tempo=(char*)malloc(donnee->Length()+1);
    ret=donnee->Read(tempo, donnee->Length());
    if (ret ==0) {
        msg_erreur="Rien d'écrit";
        free(tempo);
        return -1;
    }    
    ret=sqlite3_bind_blob(proc_state,nblob,tempo,donnee->Length(), SQLITE_TRANSIENT);
    free(tempo);
    return ret;
}    

int ma_base::get_value_int(int numcol, int &val){
    int nb_col;
    
    if (ouvert==false) {
        msg_erreur.Printf("%s","La base n'est pas ouverte");
        return -1;
    }
    nb_col=sqlite3_column_count(proc_state);
    if (numcol>=nb_col) {
       msg_erreur.Printf("%s","numero de colonne trop grand");
       return -1;
    }
    val=sqlite3_column_int(proc_state, numcol);
    return 0;
}    

int ma_base::get_value_blob(int numcol, wxFile *val, int &size){
    bool ret_taille=false;
    int nb_col;
    char *chaine;
    
    if (ouvert==false) {
        msg_erreur.Printf("%s","La base n'est pas ouverte");
        return -1;
    }
    nb_col=sqlite3_column_count(proc_state);
    if (numcol>=nb_col) {
       msg_erreur.Printf("%s","numero de colonne trop grand");
       return -1;
    }
    if (size == -1) {
        ret_taille=true;
    } 
    size=sqlite3_column_bytes(proc_state, numcol);
    if (size>0) {   
        chaine=(char *)sqlite3_column_blob(proc_state, numcol);
        val->Write(chaine,size);
        val->Close();
    }    
    return 0;
}    

int ma_base::get_value_char(int numcol, wxString &val, int &size){
    bool ret_taille=false;
    int nb_col;
    const unsigned char *chaine;
    
    if (ouvert==false) {
        msg_erreur.Printf("%s","La base n'est pas ouverte");
        return -1;
    }
    nb_col=sqlite3_column_count(proc_state);
    if (numcol>=nb_col) {
       msg_erreur.Printf("%s","numero de colonne trop grand");
       return -1;
    }
    if (size == -1) {
        ret_taille=true;
    } 
    size=sqlite3_column_bytes(proc_state, numcol);
    if (size>0) {   
        chaine=sqlite3_column_text(proc_state, numcol);
        val.Printf("%s",chaine);
    } else
        val="";    
    return 0;
}    

long ma_base::last_insert(){
    return (long) sqlite3_last_insert_rowid(db);
}    
int ma_base::get_nom_col(int i, wxString &nom_col) {
    const char *nom;
    
    nom=sqlite3_column_name(proc_state, i);
    nom_col.Printf("%s",nom);
    return 0;
}    

int ma_base::transac_nbligne(){
    int nb;
    
    if (ouvert==false) {
        msg_erreur.Printf("%s","La base n'est pas ouverte");
        return 0;
    }
    nb=sqlite3_column_count(proc_state);
    return nb;
}    

int ma_base::transac_nbcol(){
    int nb;
    
    if (ouvert==false) {
        msg_erreur.Printf("%s","La base n'est pas ouverte");
        return 0;
    }
    nb=sqlite3_column_count(proc_state);
    return nb;
}    

bool ma_base::ouverte(){
    return ouvert;
}    

bool ma_base::existe(wxString nomtable){
    int ret;
    int res;
    wxString mess;
    wxString query="select count(*) from sqlite_master where type='table' and name='"+nomtable+"'";
    ret=transac_prepare(query);
    if (ret<0) {
        get_erreur(mess);
        wxMessageBox(mess,"probleme", wxOK | wxICON_EXCLAMATION, NULL);
    }
    ret=transac_step();
    
    if(ret==SQLITE_ROW) {
        get_value_int(0,res);
    }  
    transac_fin();
    return (res>0);
}

wxString ma_base::get_nombase() {
    return nom_base;
}

int ma_base::get_value_int_rapide(wxString query, int& val)
// récupération d'un unique résultat de type int à partir d'une requête SELECT
// si le SELECT retourne une ou plusieurs lignes : le premier est pris (non déterministe), la méthode retourne 1
// si le SELECT ne retourne aucune ligne : la méthode retourne 0
// en cas d'erreur sur la base de donnée : la méthode retourne -1
{
    int ret=transac_prepare(query);
    if (ret<0) {
        return -1;
    }

    ret=transac_step();
    if (ret<0) {
        return -1;
    }

    if (ret == SQLITE_ROW) {
        ret=get_value_int(0,val);
        if (ret<0) {
            transac_fin();
            return -1;
        }
        transac_fin();
        return 1;
    } else {
        transac_fin();
        return 0;
    }
}
