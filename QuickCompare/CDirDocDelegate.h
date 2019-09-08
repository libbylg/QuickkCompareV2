#ifndef __CDirListDelegate_H_
#define __CDirListDelegate_H_


#include "IListDelegate.h"


class CDirListDelegate : public IListDelegate
{
public:
    CDirListDelegate();
    virtual void    GetDispInfo(CListCtrl* pListCtrl, NMHDR* pNMHDR, LRESULT* pResult) = 0;
    virtual void    DrawItem(CListCtrl* pListCtrl, LPDRAWITEMSTRUCT lpDrawItemStruct) = 0;
};

//DWORD       (*GetColumnCount)(void* ctx);
//void*       (*GetColumn)(void* ctx, DWORD dwIndex);
//DWORD       (*GetColumnState)(void* ctx, void* pColumn);
//CString&    (*GetColumnText)(void* ctx, void* pColumn, CString& strText);
//void*       (*GetColumnData)(void* ctx, void* pColumn);
//
//DWORD       (*GetItemCount)(void* ctx, void* pItem, DWORD dwState);
//void*       (*GetItem)(void* ctx, DWORD dwIndex);
//DWORD       (*GetItemState)(void* ctx, void* pItem);
//void*       (*GetItemData)(void* ctx, void* pItem);
//CString&    (*GetItemText)(void* ctx, void* pItem, DWORD dwColumn, CString& strText);

#endif//__CDirListDelegate_H_
