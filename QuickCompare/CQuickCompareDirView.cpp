// CQuickCompareDirView.cpp : 实现文件
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



// CQuickCompareDirView 消息处理程序




int CQuickCompareDirView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CQuickCompareView::OnCreate(lpCreateStruct) == -1)
        return -1;

    // TODO:  在此添加您专用的创建代码

    return 0;
}
