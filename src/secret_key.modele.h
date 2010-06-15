// Name:        secret_key.h
// Author:      PE EPAILLARD
// Created:     07/09/2009 12:22:10 AM
//
//Copyright PE Epaillard, 07/09/2009
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
            wxString sc="*** saisir ici la cl� ***";;
            
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
