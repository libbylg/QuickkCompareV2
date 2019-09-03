#include "stdafx.h"
#include "CDirListCtrl.h"


CDirListCtrl::CDirListCtrl()
{
}


CDirListCtrl::~CDirListCtrl()
{
}

BOOL CDirListCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
    //dwStyle |= LVS_OWNERDRAWFIXED | LVS_REPORT | LVS_OWNERDATA;
    return CListCtrl::Create(dwStyle, rect, pParentWnd, nID);
}

DWORD CDirListCtrl::SetExtendedStyle( DWORD dwNewStyle )

{

      if ( dwNewStyle & LVS_EX_CHECKBOXES )

      {

            dwNewStyle &=~LVS_EX_CHECKBOXES;

            dwNewStyle &=~LVS_EX_GRIDLINES;

      }

      return __super::SetExtendedStyle(dwNewStyle);

}

void CDirListCtrl::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
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

    //CDC * pDC = CDC::FromHandle(lpDrawItemStruct->hDC);

    //CMemoryDC BufferDC(pDC, rcItem);

    ////获取属性

    //INT nItemID = lpDrawItemStruct->itemID;
    //INT nColumnCount = m_SkinHeaderCtrl.GetItemCount();

    ////绘画区域
    //CRect rcClipBox;
    //BufferDC.GetClipBox(&rcClipBox);

    ////设置环境
    //BufferDC.SetBkMode(TRANSPARENT);
    //BufferDC.SetTextColor(m_colNormalText);
    //BufferDC.SelectObject(GetCtrlFont());
    //BufferDC->FillSolidRect(&rcItem, m_colBack);

    ////绘画焦点
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


//绘画数据

VOID CDirListCtrl::DrawReportItem(CDC * pDC, INT nItem, CRect & rcSubItem, INT nColumnIndex)
{
    ////  获取文字
    //TCHAR szString[256] = TEXT("");
    //GetItemText(nItem, nColumnIndex, szString, CountArray(szString));

    ////  绘画文字
    //rcSubItem.left += 5;

    ////  绘制CheckButton
    //if (nColumnIndex == 0) {

    //    if ((m_pCheckImg != NULL && !m_pCheckImg->IsNull()) && (m_pUnCheckImg != NULL && !m_pUnCheckImg->IsNull())) {
    //        if (GetCheck(nItem)) {
    //            m_pCheckImg->DrawImage(pDC, rcSubItem.left + 2, rcSubItem.top + (rcSubItem.Height() - m_pCheckImg->GetHeight()) / 2);
    //        } else {
    //            m_pUnCheckImg->DrawImage(pDC, rcSubItem.left + 2, rcSubItem.top + (rcSubItem.Height() - m_pUnCheckImg->GetHeight()) / 2);
    //        }
    //        rcSubItem.left += (8 + m_pCheckImg->GetWidth());
    //    }

    //    CItemImgArray::iterator iter = m_ItemImgArray.begin();
    //    for (; iter != m_ItemImgArray.end(); ++iter) {
    //        if (iter->nItem == nItem) {
    //            CImageEx *pImage = iter->pImage;
    //            if (pImage != NULL && !pImage->IsNull()) {
    //                pImage->DrawImage(pDC, rcSubItem.left + 2, rcSubItem.top + (rcSubItem.Height() - pImage->GetHeight()) / 2);

    //                rcSubItem.left += (8 + pImage->GetWidth());
    //            }
    //            break;
    //        }
    //    }
    //}

    //pDC->DrawText(szString, lstrlen(szString), &rcSubItem, DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
    //return;
}