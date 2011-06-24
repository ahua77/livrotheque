#ifndef __TREEITEMDATALONG_H__
#define __TREEITEMDATALONG_H__

#include <wx/treectrl.h>

class treeItemDataLong : public wxTreeItemData
{
public:
    treeItemDataLong(long val) {m_val = val;}
    long val() const {return m_val;}
private:
    long m_val;
};

#endif // __TREEITEMDATALONG_H__
