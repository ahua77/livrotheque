// Name:        divers.cpp
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
#include <stdlib.h>
#include <string.h>
#include "divers.h"
#include "affiche_image.h"

//IMPLEMENT_DYNAMIC_CLASS(ImageCanvas, wxScrolledWindow)
BEGIN_EVENT_TABLE(ImageCanvas, wxScrolledWindow)
  EVT_PAINT(ImageCanvas::OnPaint)
  EVT_LEFT_UP(ImageCanvas::OnLeftUp) 
END_EVENT_TABLE()


//#define TABLE_SUP 1
static char nom_token_livre[][TAILLE_TOKEN]={
            "titre", "id_auteur", "sous_titre", "id_serie", "no_serie", 
            "id_genre", "isbn", "id_editeur", "date_publication", "id_format", 
            "id_artiste", "prix", "recompense",
            "date_achat", "valeur", "reference", "nb_pages", "id_etat", 
            "id_localisation", "date_lecture", "note", "particularite",
            "titre_original", "sous_titre_o", "id_serie_o", "id_pays", "id_langue",
            "id_traducteur", "commentaire", "resume", 
            "date_entree", "date_maj", "image_face", "image_dos", "image_tranche",
            ""};

static char type_token_livre[][TAILLE_TOKEN]={
            "TEXT", "INTEGER_P" , "TEXT", "INTEGER", "INTEGER", 
            "INTEGER", "TEXT", "INTEGER", "DATE", "INTEGER", 
            "INTEGER_P", "REAL", "TEXT",
            "DATE", "TEXT", "TEXT", "INTEGER", "INTEGER", 
            "INTEGER", "DATE", "INTEGER", "TEXT",
            "TEXT", "TEXT", "INTEGER", "INTEGER", "INTEGER", 
            "INTEGER_P", "TEXT", "TEXT", 
            "DATE", "DATE", "BLOB", "BLOB", "BLOB",
            ""};
static wxString tables_sup[]={
            "CREATE INDEX ind_titre ON livre (titre)",
            "CREATE INDEX ind_auteur ON livre (id_auteur)",
            "INSERT INTO version (nover) VALUES ('0.5')",
            "CREATE TABLE version (nover TEXT)"
        };    

static wxString particularite_texte[]={
            "Acheté", "A acheter d'urgence", "A acheter peut être", "Emprunté", "Offert"};

/*static int taille_token[]={1, 500, 20, 20, 1,
            500, 1, 1, 50, 1,
            1, 1, 500, 1, 1, 
            20
        };  */

static char nom_token_personne[][TAILLE_TOKEN]={
            "nom", "date_naissance", "date_mort", "commentaire", "image_auteur",
            ""};

static char type_token_personne[][TAILLE_TOKEN]={
            "TEXT", "DATE", "DATE", "TEXT", "BLOB",
            ""};
livre::livre(){ 
    
    //ch_create=NULL;
    
    nom_table="livre";
    // compte le nombre de token
    nb_token=0;
    nb_gen_encourt=0;
    while (strlen(nom_token_livre[nb_token])>0)
        nb_token++;    
}    

livre::~livre(){
    /*if (ch_create!=NULL) {
        free(ch_create);
    }    */
}    

void  livre::gen_create_livre(wxString &ch_create) {
    int i; 
    wxString tempo;
//    char tempo[100];
    

    ch_create=("CREATE TABLE ");
    ch_create+=nom_table;
    ch_create+=" ( ";
    i=0;
    do { 
         if (i==0){
//             tempo.Printf("%s %s PRIMARY KEY, ", nom_token_livre[i],type_token_livre[i]);
             tempo.Printf("%s %s, ", nom_token_livre[i],type_token_livre[i]);
         }else if (strlen(nom_token_livre[i+1])==0){
             tempo.Printf("%s %s) ", nom_token_livre[i],type_token_livre[i]);
         }else{
             tempo.Printf("%s %s, ", nom_token_livre[i],type_token_livre[i]);
         }    
         ch_create+=tempo;
        i++;
    }while (strlen(nom_token_livre[i])>0);    
}    

/* generation de la création des tables de la base
  la chaine sql de création est retournée dans ch_create
  nb contient le nombre de tables restant à generer,
    pour lancer la création nb doit être négatif
    si a l'appel nb est négatif la création reprend au début
    */
int livre::gen_create_tout(wxString &ch_create, int &nb) {
    int i=0, j=0;
    wxString tempo;
    wxString mess;
    char *c_tempo;
    int nb_tables_sup;
    
   nb_tables_sup= WXSIZEOF(tables_sup);

    if (nb == -1) {
        // on compte le nombre de table à générer
        nb_gen_encourt=0;
        i=0;
        do {
            // toutes les tables à générer correspondent à un id dans la table livre
            if (strncmp(nom_token_livre[i],"id_",3) == 0) {
                nb_gen_encourt++;
            }
            i++;
        } while (strlen(nom_token_livre[i])>0);    
        nb_gen_encourt+= nb_tables_sup;
        nb=nb_gen_encourt;
        // on crée d'abord la table livre (qui n'est pas comptée au dessus)
        gen_create_livre(ch_create);
        return nb;
    } else {
        if (nb_gen_encourt == 0)
            return 0;
        nb=nb_gen_encourt;
    }    
    
   if(nb>nb_tables_sup)
   {
    i=0;
    j=0;
    while (i!=(nb-nb_tables_sup)) {
        if (strncmp(nom_token_livre[j],"id_",3) == 0)
            i++;
            
        j++;
   }    
   j--;
    c_tempo=type_token_livre[j]+(strlen(type_token_livre[j])-2);
    if (strcmp(c_tempo,"_P") == 0) { // une table contenant des données sur des gens
        ch_create.Printf("CREATE TABLE %s ( ",nom_token_livre[j]+3);
        i=0;
        do { 
             if (i==0){
                 tempo.Printf("%s %s PRIMARY KEY, ", nom_token_personne[i],type_token_personne[i]);
             }else if (strlen(nom_token_personne[i+1])==0){
                 tempo.Printf("%s %s) ", nom_token_personne[i],type_token_personne[i]);
             }else{
                 tempo.Printf("%s %s, ", nom_token_personne[i],type_token_personne[i]);
             }    
             ch_create+=tempo;
            i++;
        }while (strlen(nom_token_personne[i])>0);    
        
    } else {
        ch_create.Printf("CREATE TABLE %s (nom TEXT PRIMARY KEY, commentaire TEXT)",nom_token_livre[j]+3);
    }   
}    
        if (nb<=nb_tables_sup && nb_gen_encourt>0) {
            ch_create=tables_sup[nb_gen_encourt-1];
        }    
        nb_gen_encourt--;
        nb--;
        return nb;    
}   
 
void livre::select_image(wxString id, wxString &query, int &nb_img)
{
    int i;
    
    query="SELECT ";
    nb_img=0;
    for(i=0;i<nb_token;i++) {
        if (strncmp(nom_token_livre[i],"image_",6) == 0) {
           query+=nom_token_livre[i] ;
           query+=", ";
           nb_img++;
       }    
    }    
    query.Truncate(query.Length()-2);
    query+=" FROM livre WHERE rowid=";
    query+=id;
}    

int livre::select_tout(char *query){
return 0;
}

int livre::n_token(){
    return nb_token;
}    

wxString livre::get_nom_token(int n_token) {
    wxString texte;
    if (n_token < nb_token) 
        texte.Printf("%s",nom_token_livre[n_token]);
    else
        texte="";
        
    return texte;
}    

wxString livre::get_label_particularite(int n_token) {
    wxString texte;
    if (n_token < PARTICULARITE_NB) 
        return particularite_texte[n_token];
    else
        texte="";
        
    return texte;
}    

wxString livre::Get_token_type(wxString nom_t) {
    int i;
    wxString texte;
    
    for (i=0;i<nb_token;i++) {
        texte.Printf("%s",nom_token_livre[i]);
        if (texte==nom_t) {
            texte.Printf("%s",type_token_livre[i]);
            return texte;
        }    
    }
    texte="";
    return texte;    
}    
wxString gettempdir(){
    wxString tempdir;
    bool tt;
    
    tt=wxGetEnv("TEMP", &tempdir);
    if (tt=false) {
        //wxMessageBox("Pas de répertoire temporaire défini, j'utilise le repertoire courant (bien fait pour vous)","probleme", wxOK | wxICON_EXCLAMATION, this);
        tempdir=".";
    }
    
    if (!wxDirExists(tempdir)) {
        tempdir = ".";
    }
    
    tempdir = tempdir + "\\tmp_livro";
    if (!wxDirExists(tempdir)) {
        wxMkDir(tempdir);
    }

    return tempdir;
}    

void gestion_quote(wxString &chaine) {
    
    chaine.Replace("'", "''", true);    
}

wxString gestion_quote2(const wxString& chaine) 
{
    wxString tmp = chaine;
    gestion_quote(tmp);
    return tmp;
}

void resize_image(wxString nom_fichier,int larg,int haut,wxString nom_fichier_arrivee) {
    int largeur_img,hauteur_img;
    float multi; 
    wxImage tempo;
    //wxImage tempo2;
    
    tempo.LoadFile(nom_fichier);
    multi=0.0;
    largeur_img=tempo.GetWidth();
    hauteur_img=tempo.GetHeight();
    if (larg<0)
        larg=largeur_img+1;
    if (haut<0)
        haut=hauteur_img+1;
    if (largeur_img>larg) {
        multi=(float)larg/(float)largeur_img;
        largeur_img=(int)(multi*(float)largeur_img);
        hauteur_img=(int)(multi*(float)hauteur_img);
    }
    if (hauteur_img>haut) {
        multi=(float)haut/(float)hauteur_img;
        largeur_img=(int)(multi*(float)largeur_img);
        hauteur_img=(int)(multi*(float)hauteur_img);
    }
    tempo.Rescale(largeur_img, hauteur_img);
    if (nom_fichier_arrivee == "")
        nom_fichier_arrivee=nom_fichier;
    tempo.SaveFile(nom_fichier_arrivee);
}    
void ImageCanvas::OnLeftUp( wxMouseEvent &event ) {
    if(charge==true && cliquable == true) {
        affiche_image *mon_image;
    
        //wxMessageBox("test","probleme", wxOK | wxICON_EXCLAMATION, this);
        mon_image=new affiche_image(image_s,this);
        mon_image->ShowModal();
    }
}

void ImageCanvas::rempli_canvas() {
    int largeur_obj,hauteur_obj;
    int largeur_img,hauteur_img;
    float multi; 
    wxBitmap *affiche;
    wxImage tempo;

    this->GetSize(&largeur_obj,&hauteur_obj);
    multi=0.0;
    largeur_img=image_s.GetWidth();
    hauteur_img=image_s.GetHeight();
    
    if (largeur_img==largeur_obj && hauteur_img == hauteur_obj) {
        m_bmp = new wxBitmap(image_s, -1);
    } else {
        if (largeur_img>largeur_obj) {
            multi=(float)largeur_obj/(float)largeur_img;
            largeur_img=(int)(multi*(float)largeur_img);
            hauteur_img=(int)(multi*(float)hauteur_img);
        }
        if (hauteur_img>hauteur_obj) {
            multi=(float)hauteur_obj/(float)hauteur_img;
            largeur_img=(int)(multi*(float)largeur_img);
            hauteur_img=(int)(multi*(float)hauteur_img);
        }
        tempo=image_s.Scale(largeur_img, hauteur_img);
        affiche=new wxBitmap(tempo, -1);
        m_bmp = new wxBitmap (*affiche);
    }
    charge=true;
    //init(*affiche);        
    Refresh();
}

bool DnDFile::OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames)
{
    chemin=filenames[0];
    wxMessageBox(chemin,"ondropFile", wxOK | wxICON_EXCLAMATION, NULL);
    return true;
}

wxDragResult DnDFile::OnData(wxCoord x, wxCoord y, wxDragResult def) {
    wxBitmap clourd;
    //wxString mess;
    
//    wxMessageBox(chemin,"repouet", wxOK | wxICON_EXCLAMATION, NULL);
    if ( !GetData() ) {
        wxMessageBox("pas marché","rerepouet", wxOK | wxICON_EXCLAMATION, NULL);
        return wxDragNone;
    }
    //mess.Printf("width:%d heigth:%d",clourd.GetWidth(),clourd.GetHeight());
    clourd=((wxBitmapDataObject *)m_dataObject)->GetBitmap();
    moncanvas->init(clourd.ConvertToImage());
    //wxMessageBox(mess,"rererepouet", wxOK | wxICON_EXCLAMATION, NULL);
        //OnDropURL(x, y, ((wxTextDataObject *)m_dataObject)->GetURL());

    return def;
}

// Vire les blancs en début et fin de chaîne (vu que wxWidget merdouille des qu'il y a des accents)
// et en plus je vire tous les espaces en double dans la chaine
wxString string_nettoie(wxString lachaine) {
    int i=0;
    while (lachaine[i] == ' ')
        i++;
    lachaine=lachaine.Mid(i);
    i=lachaine.Len()-1;
    while (lachaine[i] == ' ')
        i--;
    lachaine=lachaine.Left(i+1);
    while (lachaine.Replace("  "," ") > 0);
    
    return lachaine;
}

/* fonction de conversion des quotes uniquement pour les arbres de la génération HTML
par le format HTML */
void convert_quote(wxString &texte) {
    texte.Replace(wxT("´"),wxT("&acute;")); // accent aigu
    texte.Replace(wxT("\""),wxT("&quot;")); // guillemet double
}
/* fonction de conversion des caracteres spéciaux en machins gérés
par le format HTML */
void convert_html(wxString &texte) {
    texte.Replace(wxT("Á"),wxT("&Aacute;")); // a accent aigu majuscule
    texte.Replace(wxT("á"),wxT("&aacute;")); // a accent aigu minuscule
    texte.Replace(wxT("Â"),wxT("&Acirc;")); // a accent circonflexe majuscule
    texte.Replace(wxT("â"),wxT("&acirc;")); // a accent circonflexe minuscule
    texte.Replace(wxT("À"),wxT("&Agrave;")); // a accent grave majuscule
    texte.Replace(wxT("à"),wxT("&agrave;")); // a accent grave minuscule
    texte.Replace(wxT("Å"),wxT("&Aring;")); // a anneau majuscule
    texte.Replace(wxT("å"),wxT("&aring;")); // a rond minuscule
    texte.Replace(wxT("Ã"),wxT("&Atilde;")); // a tilde majuscule
    texte.Replace(wxT("ã"),wxT("&atilde;")); // a tilde minuscule
    texte.Replace(wxT("Ä"),wxT("&Auml;")); // a tréma majuscule
    texte.Replace(wxT("ä"),wxT("&auml;")); // a tréma minuscule
    texte.Replace(wxT("´"),wxT("&acute;")); // accent aigu
    texte.Replace(wxT("Æ"),wxT("&AElig;")); // ae majuscule
    texte.Replace(wxT("æ"),wxT("&aelig;")); // ae minuscule
    texte.Replace(wxT("¦"),wxT("&brvbar;")); // barre verticale interrompue
    texte.Replace(wxT("Ç"),wxT("&Ccedil;")); // c cédille majuscule
    texte.Replace(wxT("ç"),wxT("&ccedil;")); // c cédille minuscule
    texte.Replace(wxT("¸"),wxT("&cedil;")); // cédille
    texte.Replace(wxT("»"),wxT("&raquo;")); // chevron droit ou guillemet droit
    texte.Replace(wxT("«"),wxT("&laquo;")); // chevron gauche ou guillemet gauche
    texte.Replace(wxT("©"),wxT("&copy;")); // copyright
    texte.Replace(wxT("²"),wxT("&sup2;")); // deux exposant
    texte.Replace(wxT("É"),wxT("&Eacute;")); // e accent aigu majuscule
    texte.Replace(wxT("é"),wxT("&eacute;")); // e accent aigu minuscule
    texte.Replace(wxT("Ê"),wxT("&Ecirc;")); // e accent circonflexe majuscule
    texte.Replace(wxT("ê"),wxT("&ecirc;")); // e accent circonflexe minuscule
    texte.Replace(wxT("È"),wxT("&Egrave;")); // e accent grave majuscule
    texte.Replace(wxT("è"),wxT("&egrave;")); // e accent grave minuscule
    texte.Replace(wxT("Ë"),wxT("&Euml;")); // e tréma majuscule
    texte.Replace(wxT("ë"),wxT("&euml;")); // e tréma minuscule
    //texte.Replace(wxT(""),wxT("nbsp; e")); //space insécable
    //texte.Replace(wxT("&"),wxT("&amp;")); // et commercial
    texte.Replace(wxT("Ð"),wxT("&ETH;")); // eth islandais majuscule
    texte.Replace(wxT("ð"),wxT("&eth;")); // eth islandais minuscule
    texte.Replace(wxT("¡"),wxT("&iexcl;")); // exclamation inversée
    texte.Replace(wxT("¾"),wxT("&frac34;")); // fraction trois quarts
    texte.Replace(wxT("½"),wxT("&frac12;")); // fraction un demi
    texte.Replace(wxT("¼"),wxT("&frac14;")); // fraction un quart
    //texte.Replace(wxT("\""),wxT("&quot;")); // guillemet double
    texte.Replace(wxT("Í"),wxT("&Iacute;")); // i accent aigu majuscule
    texte.Replace(wxT("í"),wxT("&iacute;")); // i accent aigu minuscule
    texte.Replace(wxT("Î"),wxT("&Icirc;")); // i accent circonflexe majuscule
    texte.Replace(wxT("î"),wxT("&icirc;")); // i accent circonflexe minuscule
    texte.Replace(wxT("Ì"),wxT("&Igrave;")); // i accent grave majuscule
    texte.Replace(wxT("ì"),wxT("&igrave;")); // i accent grave minuscule
    texte.Replace(wxT("Ï"),wxT("&Iuml;")); // i tréma majuscule
    texte.Replace(wxT("ï"),wxT("&iuml;")); // i tréma minuscule
    //texte.Replace(wxT("<"),wxT("&lt;")); // inférieur à
    texte.Replace(wxT("¯"),wxT("&macr;")); // macron
    texte.Replace(wxT("®"),wxT("&reg;")); // marque déposée
    texte.Replace(wxT("Ñ"),wxT("&Ntilde;")); // n tilde majuscule
    texte.Replace(wxT("ñ"),wxT("&ntilde;")); // n tilde minuscule
    texte.Replace(wxT("Ó"),wxT("&Oacute;")); // o accent aigu majuscule
    texte.Replace(wxT("ó"),wxT("&oacute;")); // o accent aigu minuscule
    texte.Replace(wxT("Ô"),wxT("&Ocirc;")); // o accent circonflexe majuscule
    texte.Replace(wxT("ô"),wxT("&ocirc;")); // o accent circonflexe minuscule
    texte.Replace(wxT("Ò"),wxT("&Ograve;")); // o accent grave majuscule
    texte.Replace(wxT("ò"),wxT("&ograve;")); // o accent grave minuscule
    texte.Replace(wxT("Ø"),wxT("&Oslash;")); // o barré majuscule
    texte.Replace(wxT("ø"),wxT("&oslash;")); // o barré minuscule
    texte.Replace(wxT("Õ"),wxT("&Otilde;")); // o tilde majuscule
    texte.Replace(wxT("õ"),wxT("&otilde;")); // o tilde minuscule
    texte.Replace(wxT("Ö"),wxT("&Ouml;")); // o tréma majuscule
    texte.Replace(wxT("ö"),wxT("&ouml;")); // o tréma minuscule
    texte.Replace(wxT("ª"),wxT("&ordf;")); // ordinal féminin
    texte.Replace(wxT("º"),wxT("&ordm;")); // ordinal masculin
    texte.Replace(wxT("±"),wxT("&plusmn;")); // plus ou moins
    texte.Replace(wxT("¿"),wxT("&iquest;")); // point d'interrogation inversé
    texte.Replace(wxT("·"),wxT("&middot;")); // point milieu
    texte.Replace(wxT("ß"),wxT("&szlig;")); // s allemand
    texte.Replace(wxT("°"),wxT("&deg;")); // signe degrés
    texte.Replace(wxT("÷"),wxT("&divide;")); // signe division
    texte.Replace(wxT("µ"),wxT("&micro;")); // signe micro
    texte.Replace(wxT("×"),wxT("&times;")); // signe multiplication
    texte.Replace(wxT("¬"),wxT("&not;")); // signe non
    texte.Replace(wxT("¶"),wxT("&para;")); // signe paragraphe
    texte.Replace(wxT("§"),wxT("&sect;")); // signe section
    texte.Replace(wxT("¥"),wxT("&yen;")); // signe yen
    //texte.Replace(wxT(">"),wxT("&gt;")); // supérieur à
    texte.Replace(wxT("¢"),wxT("&cent;")); // symbole centime
    texte.Replace(wxT("£"),wxT("&pound;")); // symbole livre
    texte.Replace(wxT("¤"),wxT("&curren;")); // symbole monétaire
    texte.Replace(wxT("Þ"),wxT("&THORN;")); // thorn islandais majuscule
    texte.Replace(wxT("þ"),wxT("&thorn;")); // thorn islandais minuscule
    texte.Replace(wxT("¨"),wxT("&uml;")); // tréma
    texte.Replace(wxT("³"),wxT("&sup3;")); // trois exposant
    texte.Replace(wxT("Ú"),wxT("&Uacute;")); // u accent aigu majuscule
    texte.Replace(wxT("ú"),wxT("&uacute;")); // u accent aigu minuscule
    texte.Replace(wxT("Û"),wxT("&Ucirc;")); // u accent circonflexe majuscule
    texte.Replace(wxT("û"),wxT("&ucirc;")); // u accent circonflexe minuscule
    texte.Replace(wxT("Ù"),wxT("&Ugrave;")); // u accent grave majuscule
    texte.Replace(wxT("ù"),wxT("&ugrave;")); // u accent grave minuscule
    texte.Replace(wxT("Ü"),wxT("&Uuml;")); // u tréma majuscule
    texte.Replace(wxT("ü"),wxT("&uuml;")); // u tréma minuscule
    texte.Replace(wxT("¹"),wxT("&sup1;")); // un exposant
    texte.Replace(wxT("Ý"),wxT("&Yacute;")); // y accent aigu majuscule
    texte.Replace(wxT("ý"),wxT("&yacute;")); // y accent aigu minuscule
    texte.Replace(wxT("ÿ"),wxT("&yuml;")); // y tréma minuscule     
}
void convert_html_total(wxString &texte) {
    texte.Replace(wxT("Á"),wxT("&Aacute;")); // a accent aigu majuscule
    texte.Replace(wxT("á"),wxT("&aacute;")); // a accent aigu minuscule
    texte.Replace(wxT("Â"),wxT("&Acirc;")); // a accent circonflexe majuscule
    texte.Replace(wxT("â"),wxT("&acirc;")); // a accent circonflexe minuscule
    texte.Replace(wxT("À"),wxT("&Agrave;")); // a accent grave majuscule
    texte.Replace(wxT("à"),wxT("&agrave;")); // a accent grave minuscule
    texte.Replace(wxT("Å"),wxT("&Aring;")); // a anneau majuscule
    texte.Replace(wxT("å"),wxT("&aring;")); // a rond minuscule
    texte.Replace(wxT("Ã"),wxT("&Atilde;")); // a tilde majuscule
    texte.Replace(wxT("ã"),wxT("&atilde;")); // a tilde minuscule
    texte.Replace(wxT("Ä"),wxT("&Auml;")); // a tréma majuscule
    texte.Replace(wxT("ä"),wxT("&auml;")); // a tréma minuscule
    texte.Replace(wxT("´"),wxT("&acute;")); // accent aigu
    texte.Replace(wxT("Æ"),wxT("&AElig;")); // ae majuscule
    texte.Replace(wxT("æ"),wxT("&aelig;")); // ae minuscule
    texte.Replace(wxT("¦"),wxT("&brvbar;")); // barre verticale interrompue
    texte.Replace(wxT("Ç"),wxT("&Ccedil;")); // c cédille majuscule
    texte.Replace(wxT("ç"),wxT("&ccedil;")); // c cédille minuscule
    texte.Replace(wxT("¸"),wxT("&cedil;")); // cédille
    texte.Replace(wxT("»"),wxT("&raquo;")); // chevron droit ou guillemet droit
    texte.Replace(wxT("«"),wxT("&laquo;")); // chevron gauche ou guillemet gauche
    texte.Replace(wxT("©"),wxT("&copy;")); // copyright
    texte.Replace(wxT("²"),wxT("&sup2;")); // deux exposant
    texte.Replace(wxT("É"),wxT("&Eacute;")); // e accent aigu majuscule
    texte.Replace(wxT("é"),wxT("&eacute;")); // e accent aigu minuscule
    texte.Replace(wxT("Ê"),wxT("&Ecirc;")); // e accent circonflexe majuscule
    texte.Replace(wxT("ê"),wxT("&ecirc;")); // e accent circonflexe minuscule
    texte.Replace(wxT("È"),wxT("&Egrave;")); // e accent grave majuscule
    texte.Replace(wxT("è"),wxT("&egrave;")); // e accent grave minuscule
    texte.Replace(wxT("Ë"),wxT("&Euml;")); // e tréma majuscule
    texte.Replace(wxT("ë"),wxT("&euml;")); // e tréma minuscule
    //texte.Replace(wxT(""),wxT("nbsp; e")); //space insécable
    texte.Replace(wxT("&"),wxT("&amp;")); // et commercial
    texte.Replace(wxT("Ð"),wxT("&ETH;")); // eth islandais majuscule
    texte.Replace(wxT("ð"),wxT("&eth;")); // eth islandais minuscule
    texte.Replace(wxT("¡"),wxT("&iexcl;")); // exclamation inversée
    texte.Replace(wxT("¾"),wxT("&frac34;")); // fraction trois quarts
    texte.Replace(wxT("½"),wxT("&frac12;")); // fraction un demi
    texte.Replace(wxT("¼"),wxT("&frac14;")); // fraction un quart
    texte.Replace(wxT("\""),wxT("&quot;")); // guillemet double
    texte.Replace(wxT("Í"),wxT("&Iacute;")); // i accent aigu majuscule
    texte.Replace(wxT("í"),wxT("&iacute;")); // i accent aigu minuscule
    texte.Replace(wxT("Î"),wxT("&Icirc;")); // i accent circonflexe majuscule
    texte.Replace(wxT("î"),wxT("&icirc;")); // i accent circonflexe minuscule
    texte.Replace(wxT("Ì"),wxT("&Igrave;")); // i accent grave majuscule
    texte.Replace(wxT("ì"),wxT("&igrave;")); // i accent grave minuscule
    texte.Replace(wxT("Ï"),wxT("&Iuml;")); // i tréma majuscule
    texte.Replace(wxT("ï"),wxT("&iuml;")); // i tréma minuscule
    texte.Replace(wxT("<"),wxT("&lt;")); // inférieur à
    texte.Replace(wxT("¯"),wxT("&macr;")); // macron
    texte.Replace(wxT("®"),wxT("&reg;")); // marque déposée
    texte.Replace(wxT("Ñ"),wxT("&Ntilde;")); // n tilde majuscule
    texte.Replace(wxT("ñ"),wxT("&ntilde;")); // n tilde minuscule
    texte.Replace(wxT("Ó"),wxT("&Oacute;")); // o accent aigu majuscule
    texte.Replace(wxT("ó"),wxT("&oacute;")); // o accent aigu minuscule
    texte.Replace(wxT("Ô"),wxT("&Ocirc;")); // o accent circonflexe majuscule
    texte.Replace(wxT("ô"),wxT("&ocirc;")); // o accent circonflexe minuscule
    texte.Replace(wxT("Ò"),wxT("&Ograve;")); // o accent grave majuscule
    texte.Replace(wxT("ò"),wxT("&ograve;")); // o accent grave minuscule
    texte.Replace(wxT("Ø"),wxT("&Oslash;")); // o barré majuscule
    texte.Replace(wxT("ø"),wxT("&oslash;")); // o barré minuscule
    texte.Replace(wxT("Õ"),wxT("&Otilde;")); // o tilde majuscule
    texte.Replace(wxT("õ"),wxT("&otilde;")); // o tilde minuscule
    texte.Replace(wxT("Ö"),wxT("&Ouml;")); // o tréma majuscule
    texte.Replace(wxT("ö"),wxT("&ouml;")); // o tréma minuscule
    texte.Replace(wxT("ª"),wxT("&ordf;")); // ordinal féminin
    texte.Replace(wxT("º"),wxT("&ordm;")); // ordinal masculin
    texte.Replace(wxT("±"),wxT("&plusmn;")); // plus ou moins
    texte.Replace(wxT("¿"),wxT("&iquest;")); // point d'interrogation inversé
    texte.Replace(wxT("·"),wxT("&middot;")); // point milieu
    texte.Replace(wxT("ß"),wxT("&szlig;")); // s allemand
    texte.Replace(wxT("°"),wxT("&deg;")); // signe degrés
    texte.Replace(wxT("÷"),wxT("&divide;")); // signe division
    texte.Replace(wxT("µ"),wxT("&micro;")); // signe micro
    texte.Replace(wxT("×"),wxT("&times;")); // signe multiplication
    texte.Replace(wxT("¬"),wxT("&not;")); // signe non
    texte.Replace(wxT("¶"),wxT("&para;")); // signe paragraphe
    texte.Replace(wxT("§"),wxT("&sect;")); // signe section
    texte.Replace(wxT("¥"),wxT("&yen;")); // signe yen
    texte.Replace(wxT(">"),wxT("&gt;")); // supérieur à
    texte.Replace(wxT("¢"),wxT("&cent;")); // symbole centime
    texte.Replace(wxT("£"),wxT("&pound;")); // symbole livre
    texte.Replace(wxT("¤"),wxT("&curren;")); // symbole monétaire
    texte.Replace(wxT("Þ"),wxT("&THORN;")); // thorn islandais majuscule
    texte.Replace(wxT("þ"),wxT("&thorn;")); // thorn islandais minuscule
    texte.Replace(wxT("¨"),wxT("&uml;")); // tréma
    texte.Replace(wxT("³"),wxT("&sup3;")); // trois exposant
    texte.Replace(wxT("Ú"),wxT("&Uacute;")); // u accent aigu majuscule
    texte.Replace(wxT("ú"),wxT("&uacute;")); // u accent aigu minuscule
    texte.Replace(wxT("Û"),wxT("&Ucirc;")); // u accent circonflexe majuscule
    texte.Replace(wxT("û"),wxT("&ucirc;")); // u accent circonflexe minuscule
    texte.Replace(wxT("Ù"),wxT("&Ugrave;")); // u accent grave majuscule
    texte.Replace(wxT("ù"),wxT("&ugrave;")); // u accent grave minuscule
    texte.Replace(wxT("Ü"),wxT("&Uuml;")); // u tréma majuscule
    texte.Replace(wxT("ü"),wxT("&uuml;")); // u tréma minuscule
    texte.Replace(wxT("¹"),wxT("&sup1;")); // un exposant
    texte.Replace(wxT("Ý"),wxT("&Yacute;")); // y accent aigu majuscule
    texte.Replace(wxT("ý"),wxT("&yacute;")); // y accent aigu minuscule
    texte.Replace(wxT("ÿ"),wxT("&yuml;")); // y tréma minuscule
}
int tri_sans_accent(void *foo, int len, const void * data1, int len2, const void *data2)
{
    wxString accent = "ÀÁÂÃÄÅàáâãäåÒÓÔÕÖØòóôõöøÈÉÊËèéêëÌÍÎÏìíîïÙÚÛÜùúûüÿÑñÇç";
    wxString sansAccent = "AAAAAAAAAAAAOOOOOOOOOOOOEEEEEEEEIIIIIIIIUUUUUUUUYNNCC";

    wxString wxdata1=wxString((const char *)data1,len);
    wxString wxdata2=wxString((const char *)data2,len2);
    
    for(int i=0; i<accent.Length(); i++)
    {
        // Remplacement de l'accent par son équivalent sans accent dans la chaîne de caractères
        wxdata1.Replace(accent.Mid(i,1), sansAccent.Mid(i,1));
        wxdata2.Replace(accent.Mid(i,1), sansAccent.Mid(i,1));
    }
    
	return wxdata1.compare(wxdata2);
}

