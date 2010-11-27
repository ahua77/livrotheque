#ifndef CURL_UTIL_H
#define CURL_UTIL_H

#include <wx/string.h>

class curl_util {
public:
    curl_util();
    ~curl_util();
    static curl_util* GetInstance()
    {
        if (!s_instance)
            new curl_util;
        return s_instance;
    }

    void SetProxy(bool prox_utilise, wxString prox_adresse, int prox_port, wxString prox_user, wxString prox_pass);
    void SetTimeout(long timeout) {m_timeout = timeout;}

    int GetFile(wxString url, const wxString& filename, const wxString& tempDir);
    
private:
    static curl_util* s_instance;

    bool m_prox_utilise;
    wxString m_prox_adresse;
    int m_prox_port;
    wxString m_prox_user;
    wxString m_prox_pass;
    
    long m_timeout;
};

#endif
