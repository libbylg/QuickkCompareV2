#ifndef __CDirListCtrl_H_
#define __CDirListCtrl_H_


#include "afxcmn.h"


class CDirListCtrl : public CListCtrl
{
public:
    CDirListCtrl();
    virtual ~CDirListCtrl();

    BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
public:
    virtual void DrawItem(_In_ LPDRAWITEMSTRUCT lpDrawItemStruct);
    DWORD SetExtendedStyle(DWORD dwNewStyle);

private:
    VOID DrawReportItem(CDC * pDC, INT nItem, CRect & rcSubItem, INT nColumnIndex);
};

#endif//__CDirListCtrl_H_
