// CQuickCompareDirView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CQuickCompareDirView.h"


// CQuickCompareDirView

IMPLEMENT_DYNAMIC(CQuickCompareDirView, CQuickCompareView)

CQuickCompareDirView::CQuickCompareDirView()
{

}

CQuickCompareDirView::~CQuickCompareDirView()
{
}


BEGIN_MESSAGE_MAP(CQuickCompareDirView, CQuickCompareView)
    ON_WM_CREATE()
END_MESSAGE_MAP()



// CQuickCompareDirView ��Ϣ�������




int CQuickCompareDirView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CQuickCompareView::OnCreate(lpCreateStruct) == -1)
        return -1;

    // TODO:  �ڴ������ר�õĴ�������

    return 0;
}
