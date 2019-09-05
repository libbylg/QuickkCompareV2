#ifndef __CQuickCompareDirView_H_
#define __CQuickCompareDirView_H_

#include "CQuickCompareView.h"
#include "SplitterControl.h"
#include "CDirDiffCtrl.h"
#include "CDirListCtrl.h"

// CQuickCompareDirView
#define IDC_DIRLIST_LEFT    1001
#define IDC_DIRLIST_RIGHT   1002
#define IDC_DIRDIFF         1003
class CQuickCompareDirView : public CQuickCompareView
{
	DECLARE_DYNCREATE(CQuickCompareDirView)

private:
    CDirListCtrl*     m_pDirLists[2];
    CDirDiffCtrl*     m_pDirDiffCtrl;

public:
	CQuickCompareDirView();
	virtual ~CQuickCompareDirView();
private:
    void Relayout();

protected:
	DECLARE_MESSAGE_MAP()
public:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    virtual void OnInitialUpdate();
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void GetDisplayInfo(NMHDR* pNMHDR, LRESULT* pResult);
};


#endif//__CQuickCompareDirView_H_
