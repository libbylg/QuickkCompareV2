#ifndef __CQuickCompareDirView_H_
#define __CQuickCompareDirView_H_

#include "CQuickCompareView.h"
#include "SplitterControl.h"

// CQuickCompareDirView

class CQuickCompareDirView : public CQuickCompareView
{
	DECLARE_DYNAMIC(CQuickCompareDirView)

private:
    CSplitterControl* m_pSplitter;
    CListCtrl*        m_pDirLists[2];

public:
	CQuickCompareDirView();
	virtual ~CQuickCompareDirView();

protected:
	DECLARE_MESSAGE_MAP()
};


#endif//__CQuickCompareDirView_H_
