///-----------------------------------------------------------------
///
/// @file      ParamManager.h
/// @author    
/// Created:   12/12/2009 18:10:19
/// @section   DESCRIPTION
///            ParamManager class declaration
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
//*
///
///------------------------------------------------------------------

#ifndef __PARAMMANAGER_H__
#define __PARAMMANAGER_H__

#include "mabase.h"

class ParamManager;
WX_DECLARE_STRING_HASH_MAP( ParamManager*, MapParamManager );

class ParamManager {
public:
    ParamManager(ma_base& pBaseConfig, wxString cle);
    ~ParamManager();

    static ParamManager* GetInstance(wxString cle);
    
    void GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  wxString& val1, wxString& val2);
    void GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  wxString& val1);
    void GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  long& val1, long& val2);
    void GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  long& val1);
    void GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  BOOL& val1, long& val2);
    void GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  BOOL& val1);
    void GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  BOOL& val1, wxString& val2);
    void GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  wxString& val1, long& val2);
                  
    void Set     (const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  wxString val1, wxString val2="");
    void Set     (const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  BOOL val1);
    void Set     (const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  BOOL val1, long val2);                  
    void Set     (const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  long val1, long val2=0);
    void Set     (const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  BOOL val1, wxString val2);
    void Set     (const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  wxString val1, long val2);
                  
private:
    static MapParamManager tabInstance;  // toutes les instances créées, associées à une chaine de caractère utilisée comme clé
    ma_base& baseConfig;
    wxString m_cle;                 // la clé utilisée dans la map tabInstance
    
};



#endif
