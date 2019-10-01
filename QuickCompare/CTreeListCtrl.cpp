#include "stdafx.h"
#include "CTreeListCtrl.h"
#include "CMemoryDC.h"
#include "Delegate.h"


CTreeListCtrl::CTreeListCtrl()
{
}


CTreeListCtrl::~CTreeListCtrl()
{
}

BOOL CTreeListCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, struct IListDelegate* pDelegate)
{
    ASSERT(NULL != pDelegate);
    this->m_pDelegate = pDelegate;
    //dwStyle |= LVS_OWNERDRAWFIXED | LVS_REPORT | LVS_OWNERDATA;
    dwStyle |= (LVS_REPORT | LVS_OWNERDATA | LVS_OWNERDRAWFIXED);
    return CListCtrl::Create(dwStyle, rect, pParentWnd, nID);
}

DWORD CTreeListCtrl::SetExtendedStyle(DWORD dwNewStyle)
{

    //if (dwNewStyle & LVS_EX_CHECKBOXES) {
    //    dwNewStyle &= ~LVS_EX_CHECKBOXES;
    //    dwNewStyle &= ~LVS_EX_GRIDLINES;
    //}

    return __super::SetExtendedStyle(dwNewStyle);
}

void CTreeListCtrl::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    this->m_pDelegate->DrawItem(this, lpDrawItemStruct);
    //    typedef struct tagDRAWITEMSTRUCT {
    //    UINT        CtlType;
    //    UINT        CtlID;
    //    UINT        itemID;
    //    UINT        itemAction;
    //    UINT        itemState;
    //    HWND        hwndItem;
    //    HDC         hDC;
    //    RECT        rcItem;
    //    ULONG_PTR   itemData;
    //} DRAWITEMSTRUCT, NEAR *PDRAWITEMSTRUCT, FAR *LPDRAWITEMSTRUCT;
    //��������

    //CRect rcItem = lpDrawItemStruct->rcItem;
    //
    //CDC * pDC = CDC::FromHandle(lpDrawItemStruct->hDC);

    //CMemoryDC BufferDC(pDC, rcItem);

    //��ȡ����
    //INT nItemID = lpDrawItemStruct->itemID;
    //INT nColumnCount = this->GetHeaderCtrl()->GetItemCount();

    //�滭����
    //CRect rcClipBox;
    //BufferDC.GetClipBox(&rcClipBox);

    ////���û���
    //BufferDC.SetBkMode(TRANSPARENT);
    //BufferDC.SetTextColor(m_colNormalText);
    //BufferDC.SelectObject(GetCtrlFont());
    //pDC->FillSolidRect(&rcItem, RGB(120,250,110));

    //�滭����
    //if (lpDrawItemStruct->itemState&ODS_SELECTED) {
    //    if (m_pSelectImg != NULL && !m_pSelectImg->IsNull()) {
    //        m_pSelectImg->Draw(&BufferDC, rcItem);
    //    }
    //}

    //else if (m_uActiveItem == nItemID) {

    //    if (m_pHovenImg != NULL && !m_pHovenImg->IsNull()) {
    //        m_pHovenImg->Draw(&BufferDC, rcItem);
    //    }
    //}

    ////�滭����
    //for (INT i = 0; i<nColumnCount; i++) {
    //    //��ȡλ��
    //    CRect rcSubItem;
    //    GetSubItemRect(nItemID, i, LVIR_BOUNDS, rcSubItem);

    //    //�滭�ж�
    //    if (rcSubItem.left>rcClipBox.right) break;
    //    if (rcSubItem.right < rcClipBox.left) continue;
    //    //�滭����
    //    DrawReportItem(&BufferDC, nItemID, rcSubItem, i);

    //}

    return;
}

