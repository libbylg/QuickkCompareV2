// CQuickCompareDirView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CQuickCompareDirView.h"
#include "CQuickCompareDirDoc.h"
#include "Utils.h"

// CQuickCompareDirView

#define DIFF_WIDTH      30
#define SPLT_WIDTH      3

#define IDC_DIFF_CTRL   2000

static  void  CompareGetDisplayDelegate(LPVOID pContext, NMHDR* pNMHDR, LRESULT* pResult)
{
    struct CompareDelegateContext* pCompareContext = (struct CompareDelegateContext*)pContext;
    pCompareContext->pView->OnGetDisplayInfo(pCompareContext->nSide, pNMHDR, pResult);
}


IMPLEMENT_DYNCREATE(CQuickCompareDirView, CQuickCompareView)


// CQuickCompareDirView ��Ϣ�������
BEGIN_MESSAGE_MAP(CQuickCompareDirView, CQuickCompareView)
    ON_WM_CREATE()
    ON_WM_SIZE()
END_MESSAGE_MAP()

CQuickCompareDirView::CQuickCompareDirView()
{
}

CQuickCompareDirView::~CQuickCompareDirView()
{
}

int CQuickCompareDirView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CQuickCompareView::OnCreate(lpCreateStruct) == -1) {
        return -1;
    }

    //  ���������ͼ
    CRect rcRect;
    this->m_tDirDiffCtrl.Create(0, rcRect, this, IDC_DIFF_CTRL);
    this->m_tDirDiffCtrl.InsertColumn(0, _T("����"), LVCFMT_LEFT, 100);
    this->m_tDirDiffCtrl.InsertColumn(1, _T("��С"), LVCFMT_LEFT, 100);
    this->m_tDirDiffCtrl.InsertColumn(2, _T("�޸�ʱ��"), LVCFMT_LEFT, 100);
    this->m_tDirDiffCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);

    //  ��ί�ж���
    this->m_tDirDiffCtrl.BindDelegate(0, this->m_tDelegateContext + 0, CompareGetDisplayDelegate);
    this->m_tDirDiffCtrl.BindDelegate(1, this->m_tDelegateContext + 1, CompareGetDisplayDelegate);



    return 0;
}


void CQuickCompareDirView::OnInitialUpdate()
{
    CQuickCompareView::OnInitialUpdate();

    CQuickCompareDirDoc* pDoc = (CQuickCompareDirDoc*)this->GetDocument();
    CompareNode* pRoot = pDoc->GetRootItem();
    this->m_tDirDiffCtrl.SetItemCountEx(pRoot->GetTotal());
    
    this->m_tDelegateContext[0].pView = this;
    this->m_tDelegateContext[0].nSide = 0;

    this->m_tDelegateContext[1].pView = this;
    this->m_tDelegateContext[1].nSide = 1;

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

    //  �ƶ�����
    this->m_tDirDiffCtrl.MoveWindow(&rcClient);
}


void CQuickCompareDirView::OnGetDisplayInfo(INT nSide, NMHDR* pNMHDR, LRESULT* pResult)
{
    *pResult = 0;

    //  �����ʵ����
    LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
    LV_ITEM* pItem= &(pDispInfo)->item;

    //  ��ȡ�ĵ�����
    CQuickCompareDirDoc* pDoc = (CQuickCompareDirDoc*)(this->GetDocument());

    //  ��ȡ���ڵ�
    CompareNode* pRoot = pDoc->GetRootItem();

    //  ��ȡָ�������Ľڵ�
    CompareNode* pFileItem = pRoot->GetItem(pItem->iItem);

    //  �����Ҫ��ȡ�ı�
    if (pItem->mask & LVIF_TEXT) {
        _tcsncpy_s(pItem->pszText, pItem->cchTextMax, pFileItem->tDescs[nSide].strName, pFileItem->tDescs[nSide].strName.GetLength());
        return;
    }

    //  �����Ҫ��ȡ�ı�
    if (pItem->mask & LVIF_INDENT) {
        pItem->iIndent = (int)(pFileItem->dwLevel);
        return;
    }

    
}