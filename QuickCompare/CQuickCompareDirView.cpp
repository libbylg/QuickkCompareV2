// CQuickCompareDirView.cpp : 实现文件
//

#include "stdafx.h"
#include "CQuickCompareDirView.h"
#include "CQuickCompareDirDoc.h"
#include "Utils.h"

#define DIFF_WIDTH  30
#define SPLT_WIDTH  3

// CQuickCompareDirView

IMPLEMENT_DYNCREATE(CQuickCompareDirView, CQuickCompareView)


// CQuickCompareDirView 消息处理程序
BEGIN_MESSAGE_MAP(CQuickCompareDirView, CQuickCompareView)
    ON_WM_CREATE()
    ON_WM_SIZE()
    ON_NOTIFY(LVN_GETDISPINFO, IDC_DIRLIST_LEFT, GetDisplayInfo)
    ON_NOTIFY(LVN_GETDISPINFO, IDC_DIRLIST_RIGHT, GetDisplayInfo)
END_MESSAGE_MAP()

CQuickCompareDirView::CQuickCompareDirView()
{
    printf("111");
}

CQuickCompareDirView::~CQuickCompareDirView()
{
}


void CQuickCompareDirView::GetDisplayInfo(NMHDR* pNMHDR, LRESULT* pResult)
{
    NMLVDISPINFO* pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);
    CQuickCompareDirDoc* pDoc = (CQuickCompareDirDoc*)this->GetDocument();

    //int iRootIndex = (IDC_DIRLIST_LEFT == pNMHDR->idFrom)?0:1;
    //TFILEITEM* pRootItem = pDoc->GetRootItem();
    //TFILEITEM* pDispItem = pRootItem->GetItem(pDispInfo->item.iItem);
    //pDispInfo->item.pszText = (LPTSTR)((LPCTSTR)(pDispItem->strName));
}


int CQuickCompareDirView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CQuickCompareView::OnCreate(lpCreateStruct) == -1) {
        return -1;
    }

    CRect rcRect;
    this->m_tDirDiffCtrl.Create(0, rcRect, this, 999);
    this->m_tDirDiffCtrl.InsertColumn(0, _T("名称"), LVCFMT_LEFT, 100);
    this->m_tDirDiffCtrl.InsertColumn(1, _T("大小"), LVCFMT_LEFT, 100);
    this->m_tDirDiffCtrl.InsertColumn(2, _T("修改时间"), LVCFMT_LEFT, 100);
    this->m_tDirDiffCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);

    return 0;
}


void CQuickCompareDirView::OnInitialUpdate()
{
    CQuickCompareView::OnInitialUpdate();

    CQuickCompareDirDoc* pDoc = (CQuickCompareDirDoc*)this->GetDocument();
    for (int i = 0; i < 2; i++) {
        TFILEITEM* pItem = pDoc->GetRootItem(i);
        DWORD dwTotal = pItem->GetTotal();
        this->m_pDirLists[i]->SetItemCountEx(dwTotal);
        this->m_pDirLists[i]->Invalidate();
    }

    this->Relayout();
}




void CQuickCompareDirView::OnSize(UINT nType, int cx, int cy)
{
    CQuickCompareView::OnSize(nType, cx, cy);
    this->Relayout();


}


void CQuickCompareDirView::Relayout()
{
    CRect rcClient;
    this->GetClientRect(&rcClient);
    int iListWidth = (rcClient.Width() - DIFF_WIDTH) / 2;
 
    CRect rcList[2];
    CRect rcSplt[2];
    CRect rcDiff;

    //
    rcList[0].left = 0;
    rcList[0].right = rcList[0].left + iListWidth;
    rcList[0].top = 0;
    rcList[0].bottom = rcClient.Height();

    //  
    rcSplt[0].left = rcList[0].right;
    rcSplt[0].right = rcSplt[0].left + SPLT_WIDTH;
    rcSplt[0].top = 0;
    rcSplt[0].bottom = rcClient.Height();

    
    //  
    rcDiff.left = rcSplt[0].right;
    rcDiff.right = rcDiff[0].left + DIFF_WIDTH;
    rcDiff.top = 0;
    rcDiff.bottom = rcClient.Height();

    //  
    rcSplt[1].left = rcDiff.right;
    rcSplt[1].right = rcDiff.right + SPLT_WIDTH;
    rcSplt[1].top = 0;
    rcSplt[1].bottom = rcClient.Height();

    //
    rcList[1].left = rcSplt[1].right;
    rcList[1].right = rcList[1].left + iListWidth;
    rcList[1].top = 0;
    rcList[1].bottom = rcClient.Height();
    
    //  移动窗口
    this->m_pDirDiffCtrl->MoveWindow(&rcDiff);
    this->m_pDirLists[0]->MoveWindow(&rcList[0]);
    this->m_pDirLists[1]->MoveWindow(&rcList[1]);
}