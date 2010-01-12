// Name:        mabase.h
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

