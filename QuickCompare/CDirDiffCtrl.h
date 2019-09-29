#ifndef __CDirDiffCtrl_H_
#define __CDirDiffCtrl_H_


// CQuickCompareDiffCtrl

class CDirDiffCtrl : public CStatic
{
	DECLARE_DYNAMIC(CDirDiffCtrl)

private:
    CListCtrl m_tDirLists[2];

public:
	CDirDiffCtrl();
	virtual ~CDirDiffCtrl();

    //  Create a DiffCtrl
    BOOL    Create(DWORD dwStaticStyle, const CRect& rect, CWnd* pParent, UINT nID);
    int     InsertColumn(_In_ int nCol, _In_z_ LPCTSTR lpszColumnHeading, _In_ int nFormat = LVCFMT_LEFT, _In_ int nWidth = -1, _In_ int nSubItem = -1);
    DWORD   SetExtendedStyle(_In_ DWORD dwNewStyle);
    
    // Updates expected item count for a virtual control.
    BOOL SetItemCountEx(_In_ int iCount, _In_ DWORD dwFlags = LVSICF_NOINVALIDATEALL);

protected:
	DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnGetdispinfoList(NMHDR *pNMHDR, LRESULT *pResult);
};


#endif//__CDirDiffCtrl_H_
