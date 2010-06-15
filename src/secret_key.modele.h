// Name:        secret_key.h
// Author:      PE EPAILLARD
// Created:     07/09/2009 12:22:10 AM
//
//Copyright PE Epaillard, 07/09/2009
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

#ifndef __SECRET_KEY_HPP_
#define __SECRET_KEY_HPP_

#include <stdio.h>
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif
#include <wx/string.h>
#include "hmac_sha2.h"
#include "base64.hpp"


class sk
{
    private:
    public:
        sk(){            }
        ~sk() {}
        static wxString encrypt_string(wxString chaine) {
            wxString sc="*** saisir ici la clé ***";;
            
            unsigned char mac[SHA256_DIGEST_SIZE];
            hmac_sha256((unsigned char*)sc.c_str(), sc.Len(),(unsigned char*) chaine.c_str(),
                   chaine.Len(), mac, SHA256_DIGEST_SIZE);
                   
            // encodage en b64
            std::string ch((const char*)mac,SHA256_DIGEST_SIZE);
            std::string recup_enc=Base64::encode(ch);
            //wxGetTextFromUser("Base64","Base64",recup_enc.c_str());
            
            return recup_enc;
        }
        
        static wxString creer_adresse(wxString adresse, wxString parametres) {
            // encodage des parametres
            parametres.Replace(":", "%3A");
            parametres.Replace(",", "%2C");

            
            wxString adresse_a_encoder="GET\n"+adresse+"\n/onca/xml\n"+parametres;
            wxString signature=encrypt_string(adresse_a_encoder);
            //encodage de la signature
            signature.Replace("+", "%2B");
            signature.Replace("=", "%3D");
            wxString adresse_finale="http://"+adresse+"/onca/xml?"+parametres+"&Signature="+signature;
            
            return adresse_finale;
        }
};

#endif
