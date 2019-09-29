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
    TFILEITEM* pRoot = pDoc->GetRootItem();
    this->m_tDirDiffCtrl.SetItemCountEx(pRoot->GetTotal());

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

    //  移动窗口
    this->m_tDirDiffCtrl.MoveWindow(&rcClient);
}