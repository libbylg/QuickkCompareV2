#ifndef __CQuickCompareDirView_H_
#define __CQuickCompareDirView_H_

#include "CQuickCompareView.h"
#include "SplitterControl.h"
#include "CDirDiffCtrl.h"

class CQuickCompareDirView;

struct CompareDelegateContext
{
    CQuickCompareDirDoc*    pDoc;
    CQuickCompareDirView*   pView;
    struct TFILEITEM*       pRoot;
    INT                     nSide;
};


// CQuickCompareDirView
class CQuickCompareDirView : public CQuickCompareView
{
	DECLARE_DYNCREATE(CQuickCompareDirView)

private:
    CDirDiffCtrl                    m_tDirDiffCtrl;
    struct CompareDelegateContext   m_tDelegateContext[2];

public:
	CQuickCompareDirView();
	virtual ~CQuickCompareDirView();
private:
    void Relayout();

protected:
	DECLARE_MESSAGE_MAP()
public:
    afx_msg int     OnCreate(LPCREATESTRUCT lpCreateStruct);
    virtual void    OnInitialUpdate();
    afx_msg void    OnSize(UINT nType, int cx, int cy);
    afx_msg void    OnGetDisplayInfo(INT nSide, NMHDR* pNMHDR, LRESULT* pResult);
};


#endif//__CQuickCompareDirView_H_
