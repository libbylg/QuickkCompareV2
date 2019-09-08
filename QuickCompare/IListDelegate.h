#ifndef __IListDelegate_H_
#define __IListDelegate_H_

#include "afxcmn.h"

struct IListDelegate
{
    virtual void    GetDispInfo(CListCtrl* pListCtrl, NMHDR* pNMHDR, LRESULT* pResult) = 0;
    virtual void    DrawItem(CListCtrl* pListCtrl, LPDRAWITEMSTRUCT lpDrawItemStruct) = 0;
};

#endif//__IListDelegate_H_


