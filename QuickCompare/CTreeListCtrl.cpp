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
    //变量定义

    //CRect rcItem = lpDrawItemStruct->rcItem;
    //
    //CDC * pDC = CDC::FromHandle(lpDrawItemStruct->hDC);

    //CMemoryDC BufferDC(pDC, rcItem);

    //获取属性
    //INT nItemID = lpDrawItemStruct->itemID;
    //INT nColumnCount = this->GetHeaderCtrl()->GetItemCount();

    //绘画区域
    //CRect rcClipBox;
    //BufferDC.GetClipBox(&rcClipBox);

    ////设置环境
    //BufferDC.SetBkMode(TRANSPARENT);
    //BufferDC.SetTextColor(m_colNormalText);
    //BufferDC.SelectObject(GetCtrlFont());
    //pDC->FillSolidRect(&rcItem, RGB(120,250,110));

    //绘画焦点
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

    ////绘画子项
    //for (INT i = 0; i<nColumnCount; i++) {
    //    //获取位置
    //    CRect rcSubItem;
    //    GetSubItemRect(nItemID, i, LVIR_BOUNDS, rcSubItem);

    //    //绘画判断
    //    if (rcSubItem.left>rcClipBox.right) break;
    //    if (rcSubItem.right < rcClipBox.left) continue;
    //    //绘画数据
    //    DrawReportItem(&BufferDC, nItemID, rcSubItem, i);

    //}

    return;
}

