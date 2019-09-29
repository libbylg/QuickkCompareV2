#ifndef __CDirListCtrl_H_
#define __CDirListCtrl_H_


#include "afxcmn.h"



struct IListDelegate;
class CTreeListCtrl : public CListCtrl
{
public:
    CTreeListCtrl();
    virtual ~CTreeListCtrl();

    BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, struct IListDelegate* pDelegate);

public:
    virtual void DrawItem(_In_ LPDRAWITEMSTRUCT lpDrawItemStruct);
    DWORD SetExtendedStyle(DWORD dwNewStyle);

private:
    struct IListDelegate* m_pDelegate;
};

#endif//__CDirListCtrl_H_
