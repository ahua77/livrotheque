// Name:        myprintout.cpp
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

#include "myprintout.h" // class's header file

bool MyPrintout::OnPrintPage(int page)
{
    wxDC *dc = GetDC();
    if (dc)
    {
        dc->SetDeviceOrigin(0, 0);
        //dc->SetUserScale(1.0, 1.0);
        int ppiScreenX, ppiScreenY;
        GetPPIScreen(&ppiScreenX, &ppiScreenY);
        int ppiPrinterX, ppiPrinterY;
        GetPPIPrinter(&ppiPrinterX, &ppiPrinterY);
        
        // This scales the DC so that the printout roughly represents the
        // the screen scaling. The text point size _should_ be the right size
        // but in fact is too small for some reason. This is a detail that will
        // need to be addressed at some point but can be fudged for the
        // moment.
        float scaleX = (float)((float)ppiPrinterX/(float)ppiScreenX);
        float scaleY = (float)((float)ppiPrinterY/(float)ppiScreenY);
        
        // Now we have to check in case our real page size is reduced
        // (e.g. because we're drawing to a print preview memory DC)
        int pageWidth, pageHeight;
        int w, h;
        dc->GetSize(&w, &h);
        
//        wxString mess;
//        mess.Printf("%d,%d",w,h);
//        wxMessageBox(mess,"scale", wxOK | wxICON_EXCLAMATION);

        GetPageSizePixels(&pageWidth, &pageHeight);
    
        // If printer pageWidth == current DC width, then this doesn't
        // change. But w might be the preview bitmap width, so scale down.
        float overallScaleX = scaleX * (float)(w/(float)pageWidth);
        float overallScaleY = scaleY * (float)(h/(float)pageHeight);
        
        dc->SetUserScale(overallScaleX, overallScaleY);
        
        dc->SetTextForeground(*wxBLACK);
        dc->SetFont(wxFont(12,wxDECORATIVE,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL));
        
        wxString buf;
        buf.Printf("PAGE %d", page);
        
        int largeurFont,hauteurFont;
        dc->GetTextExtent(buf,&largeurFont,&hauteurFont);
        
        dc->DrawText(buf, 10, 10);
        //dc->SetDeviceOrigin(80*overallScaleX, (hauteurFont + 20)*overallScaleY);
        
        wxSize taille_tmp = myWindows->tailleDessin;
        
        wxString mess;
        mess.Printf("%d,%d",taille_tmp.x,taille_tmp.y);
        //wxMessageBox(mess,"scale", wxOK | wxICON_EXCLAMATION);

        myWindows->tailleDessin=wxSize((int)(w/overallScaleX), (int)(h/overallScaleY));
        
        if (page == 1)
            DrawPageOne(dc);
        
        //wxString mess;
        mess.Printf("%d,%d",myWindows->tailleDessin.x,myWindows->tailleDessin.y);
        //wxMessageBox(mess,"scale", wxOK | wxICON_EXCLAMATION);
        
        myWindows->tailleDessin = taille_tmp;
        myWindows->Refresh();
        
        return true;
    }
    else
        return false;
}

bool MyPrintout::OnBeginDocument(int startPage, int endPage)
{
    if (!wxPrintout::OnBeginDocument(startPage, endPage))
        return false;

    return true;
}

void MyPrintout::GetPageInfo(int *minPage, int *maxPage, int *selPageFrom, int *selPageTo)
{
    *minPage = 1;
    *maxPage = 1;
    *selPageFrom = 1;
    *selPageTo = 1;
}

bool MyPrintout::HasPage(int pageNum)
{
    return (pageNum == 1);
}

void MyPrintout::DrawPageOne(wxDC *dc)
{
    // You might use THIS code if you were scaling
    // graphics of known size to fit on the page.
    
    myWindows->DrawCercle(*dc);
    
}
