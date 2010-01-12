// Name:        mabase.h
// Author:      PE EPAILLARD
// Created:     10/27/2004 12:22:10 AM
//
//Copyright PE Epaillard, 10/27/2004 
//
//Fougny@gmail.com
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
//---------------------------------------------------------------------------
#ifndef __MABASE_HPP_
#define __MABASE_HPP_

/*#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif*/

#include "sqlite3.h"
#include <wx/string.h>
#include <wx/file.h>
#include <wx/mstream.h>
#include <wx/msgdlg.h>
class ma_base
{
private:
    sqlite3 *db;
    //char msg_erreur[500];
    //char nom_base[1000];
    bool ouvert;
    wxString msg_erreur;
    wxString nom_base;
    sqlite3_stmt *proc_state;
    const char *proc_reste;

public:
    ma_base(void);
    ma_base(wxString nom);
    ~ma_base(void); 
    int ouvrir(wxString nom);
    void fermer();
    void get_erreur(wxString &erreur);
    int exec_rapide(wxString query);
    int get_value_int_rapide(wxString query, int& val);
    int transac_prepare(wxString query);
    int transac_step();
    int transac_blob(int nblob, wxFile *donnee);
    int transac_fin();
    int transac_nbligne();
    int transac_nbcol();
    int get_value_int(int numcol, int &val);
    int get_value_char(int numcol, wxString &val,int &size);
    int get_value_blob(int numcol, wxFile *val, int &size);
    bool ouverte();
    int get_nom_col(int i, wxString &nom_col);
    long last_insert();
    bool existe(wxString nomtable);
    wxString get_nombase();
    wxString ma_base::get_version();
};
    


#endif

