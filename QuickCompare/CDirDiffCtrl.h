#ifndef __CDirDiffCtrl_H_
#define __CDirDiffCtrl_H_

#include "Delegate.h"

struct DelegateItem
{
    LPVOID  pContext;
    LPVOID  pCall;
};

typedef     void(*GetDisplayDelegate)(LPVOID pContext, NMHDR* pNMHDR, LRESULT* pResult);

class CDirDiffCtrl : public CStatic
{
	DECLARE_DYNAMIC(CDirDiffCtrl)

private:
    CListCtrl       m_tDirLists[2];
    DelegateItem    m_tDelegateItems[2];
    CImageList      m_tImageList;

public:
	CDirDiffCtrl();
	virtual ~CDirDiffCtrl();

    //  Create a DiffCtrl
    BOOL    Create(DWORD dwStaticStyle, const CRect& rect, CWnd* pParent, UINT nID);
    void    BindDelegate(INT iSide, LPVOID  pContext, LPVOID  pCall);
    int     InsertColumn(_In_ int nCol, _In_z_ LPCTSTR lpszColumnHeading, _In_ int nFormat = LVCFMT_LEFT, _In_ int nWidth = -1, _In_ int nSubItem = -1);
    DWORD   SetExtendedStyle(_In_ DWORD dwNewStyle);
    
    // Updates expected item count for a virtual control.
    BOOL SetItemCountEx(_In_ int iCount, _In_ DWORD dwFlags = LVSICF_NOINVALIDATEALL);

    void Relayout();

protected:
	DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnGetdispinfoList(NMHDR *pNMHDR, LRESULT *pResult);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnPaint();
};


#endif//__CDirDiffCtrl_H_
