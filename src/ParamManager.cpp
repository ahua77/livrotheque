///-----------------------------------------------------------------
///
/// @file      ParamManager.cpp
/// @author    cubbiste
/// Created:   12/12/2009 18:10:19
/// @section   DESCRIPTION
///            ParamManager class implementation
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
///
///------------------------------------------------------------------

#include "ParamManager.h"
#include <wx/log.h>

MapParamManager ParamManager::tabInstance;

ParamManager::ParamManager (ma_base& pBaseConfig, wxString cle) : baseConfig(pBaseConfig)
{
//    wxMessageBox("ParamManager::ParamManager");
    m_cle = cle;

    if (!baseConfig.ouverte()) {
        wxMessageBox("la base " + m_cle + " n'est pas ouverte");
    }
    
    if (tabInstance.find(cle) == tabInstance.end()) {
        tabInstance[cle] = this;
    } else {
        wxMessageBox("il existe déjà une instance de ParamManager pour la clé '" + cle + "'");
    }
}

ParamManager::~ParamManager()
{
    int retErase = tabInstance.erase(m_cle);
    if (retErase != 1) {
        wxMessageBox("ParamManager::~ParamManager() : instance '" + m_cle + "' non trouvée dans la map !!");
    }
}

ParamManager* ParamManager::GetInstance(wxString cle)
{
    ParamManager* ret = NULL;
    if (tabInstance.find(cle) != tabInstance.end())
        return tabInstance[cle];
    else
        return ret;
}

void ParamManager::GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                            wxString& val1)
{
    wxString dummyVal2;
    GetOrSet(tableParam, typeParam, nomParam, val1, dummyVal2);
}

void ParamManager::GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                            long& val1, long& val2)
{
    wxString str1, str2;
    str1.Printf("%ld", val1);
    str2.Printf("%ld", val2);
    GetOrSet(tableParam, typeParam, nomParam, str1, str2);
    str1.ToLong(&val1);
    str2.ToLong(&val2);
}

void ParamManager::GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                            BOOL& val1, long& val2)
{
    wxString str1 = "T", str2;
    if (!val1) str1 = "F";
    str2.Printf("%ld", val2);
    GetOrSet(tableParam, typeParam, nomParam, str1, str2);
    val1 = (str1 == "T");
    str2.ToLong(&val2);
}

void ParamManager::GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                            BOOL& val1, wxString& val2)
{
    wxString str1 = "T";
    if (!val1) str1 = "F";
    GetOrSet(tableParam, typeParam, nomParam, str1, val2);
    val1 = (str1 == "T");
}

void ParamManager::GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                            BOOL& val1)
{
    long dummyVal2=0;
    GetOrSet(tableParam, typeParam, nomParam, val1, dummyVal2);
}

void ParamManager::GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                            long& val1)
{
    long dummyVal2 = 0;
    GetOrSet(tableParam, typeParam, nomParam, val1, dummyVal2);
}

void ParamManager::GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                            wxString& val1, long& val2)
{
    wxString str2;
    str2.Printf("%ld", val2);
    GetOrSet(tableParam, typeParam, nomParam, val1, str2);
    str2.ToLong(&val2);
}

void ParamManager::GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                            wxString& val1, wxString& val2)
// pour le parametre (typeParam, nomParam) : 
//    - s'il est présent en base : retourne les valeurs lues dans val1, val2
//    - s'il est absent en base : le crée avec les valeurs val1 et val2
{
    if (!baseConfig.ouverte()) {
        wxMessageBox("ParamManager::GetOrSet() : la base config n'est pas ouverte");
    }

    if (!baseConfig.existe(tableParam)) {
        baseConfig.exec_rapide("CREATE TABLE " + tableParam + " (type_param TEXT , nom_param TEXT, val1 TEXT, val2 TEXT)");
    }

    wxString query = "select val1, val2 from " + tableParam + " where type_param='" + typeParam + "' and nom_param='" + nomParam + "'";
    int ret=baseConfig.transac_prepare(query);
    if (ret < 0) {
        wxString mess;
        baseConfig.get_erreur(mess);
        wxMessageBox("probleme avec la requete " + query + "\nmessage : " + mess);
    }
    if (ret >= 0) {
        ret = baseConfig.transac_step();
        if (ret == SQLITE_ROW) {
            // il ne doit y avoir qu'une ligne avec typeParam / nomParam --> on ne prend que la premiere trouvée
            int taille;
            baseConfig.get_value_char(0, val1, taille);
            baseConfig.get_value_char(1, val2, taille);
        } else {
            // la ligne typeParam / nomParam n'existe pas : on en profite pour l'insérer
            query = "insert into " + tableParam + " (type_param, nom_param, val1, val2) "
                    "values ('" + typeParam + "', '" + nomParam + "', '" + val1 + "', '" + val2 + "')";
            ret = baseConfig.exec_rapide(query);
            if (ret < 0) {
                wxMessageBox("probleme avec la requete " + query);
            }
        }
        baseConfig.transac_fin();
    }
}

void ParamManager::Set(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                            BOOL val1)
{
    wxString str1 = "T";
    if (!val1) str1 = "F";
    Set (tableParam, typeParam, nomParam, str1);
}

void ParamManager::Set(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                            BOOL val1, wxString val2)
{
    wxString str1 = "T";
    if (!val1) str1 = "F";
    Set (tableParam, typeParam, nomParam, str1, val2);
}

void ParamManager::Set(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                            BOOL val1, long val2)
{
    wxString str1 = "T";
    if (!val1) str1 = "F";
    wxString str2;
    str2.Printf("%ld", val2);
    Set (tableParam, typeParam, nomParam, str1, str2);
}

void ParamManager::Set(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                       long val1, long val2)
{
    wxString str1, str2;
    str1.Printf("%ld", val1);
    str2.Printf("%ld", val2);
    Set(tableParam, typeParam, nomParam, str1, str2);
}

void ParamManager::Set(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                       wxString val1, long val2)
{
    wxString str2;
    str2.Printf("%ld", val2);
    Set(tableParam, typeParam, nomParam, val1, str2);
}

void ParamManager::Set(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                            wxString val1, wxString val2)
// pour le parametre (typeParam, nomParam) : 
//    - s'il est présent en base : met à jour avec val1 et val2 (update)
//    - s'il est absent en base : le crée avec les valeurs val1 et val2 (insert)
{
    if (!baseConfig.ouverte()) {
        wxMessageBox("ParamManager::Set() : la base config n'est pas ouverte");
    }
    
    if (!baseConfig.existe(tableParam)) {
        baseConfig.exec_rapide("CREATE TABLE " + tableParam + " (type_param TEXT , nom_param TEXT, val1 TEXT, val2 TEXT)");
    }

    wxString query = "select val1, val2 from " + tableParam + " where type_param='" + typeParam + "' and nom_param='" + nomParam + "'";
    int ret=baseConfig.transac_prepare(query);
    if (ret < 0) {
        wxString mess;
        baseConfig.get_erreur(mess);
        wxMessageBox("probleme avec la requete " + query + "\nmessage : " + mess);
    }
    if (ret >= 0) {
        ret = baseConfig.transac_step();
        if (ret == SQLITE_ROW) {
            // il ne doit y avoir qu'une ligne avec typeParam / nomParam --> on ne prend que la premiere trouvée
            wxString val1_avant, val2_avant;
            int size1, size2;
            baseConfig.get_value_char(0, val1_avant, size1);
            baseConfig.get_value_char(1, val2_avant, size2);
            // la lecture en base est beaucoup plus rapide que l'écriture : on commence par récupérer les valeurs courantes, et on
            // ne les remplace que si elles ont effectivement été modifiées
            if (val1 != val1_avant || val2 != val2_avant) {
                query = "update " + tableParam + " set val1 = '" + val1 + "', val2 = '" + val2 + "'"
                        " where type_param='" + typeParam + "' and nom_param='" + nomParam + "'";
                wxLogMessage(query);
                ret = baseConfig.exec_rapide(query);
                if (ret < 0) {
                    wxMessageBox("probleme avec la requete " + query);
                }
            } else {
                wxLogMessage("pas de changement pour %s/%s : ('%s', '%s')", tableParam.c_str(), nomParam.c_str(), val1.c_str(), val2.c_str());
            }
        } else {
            // la ligne typeParam / nomParam n'existe pas : on en profite pour l'insérer
            query = "insert into " + tableParam + " (type_param, nom_param, val1, val2) "
                    "values ('" + typeParam + "', '" + nomParam + "', '" + val1 + "', '" + val2 + "')";
            ret = baseConfig.exec_rapide(query);
            if (ret < 0) {
                wxMessageBox("probleme avec la requete " + query);
            }
        }
        baseConfig.transac_fin();
    }
}
