#include "curl_util.h"

#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>
#include <wx/filename.h>
#include <wx/file.h>
#include <wx/msgdlg.h>
#include <wx/log.h>

curl_util* curl_util::s_instance = NULL;

curl_util::curl_util()
{
    s_instance = this;
}

curl_util::~curl_util()
{
    s_instance = NULL;
}

void curl_util::SetProxy(bool prox_utilise, wxString prox_adresse, int prox_port, wxString prox_user, wxString prox_pass)
{
    wxLogMessage("curl_util::SetProxy(%d, %s, %d, %s, %s)", 
                  prox_utilise, prox_adresse.c_str(), prox_port, prox_user.c_str(), prox_pass.c_str());
    m_prox_utilise = prox_utilise;
    m_prox_adresse = prox_adresse;
    m_prox_port = prox_port;
    m_prox_user = prox_user;
    m_prox_pass = prox_pass;
}

wxString nouvelle_adresse;

size_t write_d(void *ptr,size_t size, size_t nmemb, void *stream)
{
   //int written = fwrite(ptr, size, nmemb, (FILE *)stream);
    wxString ret;
    ret.Printf("taille1=%d,taille2=%d,%s\n",size,nmemb,(char*)ptr);
       //wxMessageBox(ret,"test", wxOK | wxICON_EXCLAMATION);
    wxString donnee((char*)ptr);
    int written = ((wxFile*)stream)->Write(ptr,nmemb);
    //wxMessageBox(donnee,"test", wxOK | wxICON_EXCLAMATION);
    if(donnee.StartsWith("Location:")) {
        if (donnee.Mid(10).StartsWith("http://")) {
            nouvelle_adresse=donnee.Mid(10);
        } else {
            nouvelle_adresse=wxT("http://www.alapage.com")+donnee.Mid(10);
        //wxMessageBox(nouvelle_adresse,"POUET", wxOK | wxICON_EXCLAMATION);
        }
    }
    return written;
}

int curl_util::GetFile(wxString url, const wxString& filename, const wxString& tempDir)
{
  wxLogMessage("curl_util::GetFile() - param proxtt = {%d, %s, %d, %s, %s}",
                  m_prox_utilise, m_prox_adresse.c_str(), m_prox_port, m_prox_user.c_str(), m_prox_pass.c_str());
  CURL *curl_handle;
  wxString headerfilename = tempDir + wxFileName::GetPathSeparators() + wxT("head.html");
  wxFile* headerfile;
  wxFile* bodyfile;
  wxString tempo;
  int nouv_recherche=false;
  
  headerfile = new wxFile();
  bodyfile = new wxFile();
  nouvelle_adresse="";

  int posit_id=url.Find("?");
  if (posit_id != wxNOT_FOUND && posit_id>1) {
    url=url.Left(posit_id);
  }
  
  curl_global_init(CURL_GLOBAL_ALL);
  /* init the curl session */
  curl_handle = curl_easy_init();

  //  wxMessageBox(nom_fichier+ "\n" + url,"traitement de", wxOK | wxICON_EXCLAMATION);
  /* set URL to get */
  curl_easy_setopt(curl_handle, CURLOPT_URL, url.c_str());

  /* no progress meter please */
  curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1);
  curl_easy_setopt(curl_handle, CURLOPT_CONNECTTIMEOUT, 60);
  
  curl_easy_setopt(curl_handle,CURLOPT_VERBOSE,0); 
  /* shut up completely */
  
  /* send all data to this function  */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, &write_d);
  /* open the files */
  if (headerfile->Create(headerfilename.GetData(),true,wxS_DEFAULT) == false) {
    curl_easy_cleanup(curl_handle);
    wxMessageBox("Probleme ouverture fichier "+headerfilename,"fichier", wxOK | wxICON_EXCLAMATION);
    return -1;
  }
  
  if (bodyfile->Create(filename.GetData(),true,wxS_DEFAULT) == false) {
    curl_easy_cleanup(curl_handle); 
    wxMessageBox(wxT("Probleme ouverture fichier ") + filename,"fichier", wxOK | wxICON_EXCLAMATION);
    return -1;
  }
         //wxMessageBox(nom_fichier+"\n"+url,"Titre", wxOK | wxICON_EXCLAMATION);

  /* we want the headers to this file handle */
  curl_easy_setopt(curl_handle,   CURLOPT_WRITEDATA ,bodyfile);
  curl_easy_setopt(curl_handle,   CURLOPT_WRITEHEADER ,headerfile);
  
  /*
   * Notice here that if you want the actual data sent anywhere else but
   * stdout, you should consider using the CURLOPT_WRITEDATA option.  */
    if (m_prox_utilise == true) {
   // wxMessageBox(prox_adresse ,"PROXY!!!", wxOK | wxICON_EXCLAMATION);
        curl_easy_setopt(curl_handle,   CURLOPT_PROXYTYPE,CURLPROXY_HTTP);
        curl_easy_setopt(curl_handle,   CURLOPT_PROXY ,m_prox_adresse.GetData());
        curl_easy_setopt(curl_handle,   CURLOPT_PROXYPORT ,m_prox_port);
        tempo=m_prox_user+":"+m_prox_pass;
        curl_easy_setopt(curl_handle,   CURLOPT_PROXYUSERPWD,tempo.GetData());
    } else {
   // wxMessageBox( url," PAS PROXY!!!", wxOK | wxICON_EXCLAMATION);
        curl_easy_setopt(curl_handle,   CURLOPT_PROXY ,"");
    }
   // wxMessageBox("a4\n" + url,"traitement de", wxOK | wxICON_EXCLAMATION);
  /* get it! */
  curl_easy_perform(curl_handle);
  //  wxMessageBox("a5\n" + url,"traitement de", wxOK | wxICON_EXCLAMATION);
  
  if (bodyfile->Length()==0 && nouvelle_adresse.Len() > 0) {
      //   wxMessageBox(nom_fichier+"\n"+url,nouvelle_adresse, wxOK | wxICON_EXCLAMATION);
         nouv_recherche=true;
    }
  
  /* close the header file */
  bodyfile->Close();
  headerfile->Close();

  /* cleanup curl stuff */
  curl_easy_cleanup(curl_handle);
  if (nouv_recherche == true) {
        GetFile(nouvelle_adresse, filename, tempDir);
  }
         //wxMessageBox("fin",nouvelle_adresse, wxOK | wxICON_EXCLAMATION);
  return 0;
}
