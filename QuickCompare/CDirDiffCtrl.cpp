// CDirDiffCtrl.cpp : 实现文件
//

#include "stdafx.h"
#include "CDirDiffCtrl.h"

#define IDC_DIRLIST_LEFT    1000
#define IDC_DIRLIST_RIGHT   1001

#define RESERVE_WIDTH       22

// CQuickCompareDiffCtrl

IMPLEMENT_DYNAMIC(CDirDiffCtrl, CStatic)

static void DefaultGetDisplayDelegate(LPVOID pContext, NMHDR* pNMHDR, LRESULT* pResult)
{
    *pResult = 0;
}

CDirDiffCtrl::CDirDiffCtrl()
{
    this->m_tDelegateItems[0].pContext = NULL;
    this->m_tDelegateItems[0].pCall = DefaultGetDisplayDelegate;
    this->m_tDelegateItems[1].pContext = NULL;
    this->m_tDelegateItems[1].pCall = DefaultGetDisplayDelegate;
}

CDirDiffCtrl::~CDirDiffCtrl()
{
}


BEGIN_MESSAGE_MAP(CDirDiffCtrl, CStatic)
    ON_NOTIFY(LVN_GETDISPINFO, IDC_DIRLIST_LEFT, &CDirDiffCtrl::OnGetdispinfoList)
    ON_NOTIFY(LVN_GETDISPINFO, IDC_DIRLIST_RIGHT, &CDirDiffCtrl::OnGetdispinfoList)
    ON_WM_SIZE()
    ON_WM_PAINT()
END_MESSAGE_MAP()

void    CDirDiffCtrl::BindDelegate(INT iSide, LPVOID  pContext, LPVOID  pCall)
{
    ASSERT(pContext);
    ASSERT(pCall);
    m_tDelegateItems[iSide].pContext = pContext;
    m_tDelegateItems[iSide].pCall = pCall;
}

// CDirDiffCtrl 消息处理程序
//  Create a DiffCtrl
BOOL    CDirDiffCtrl::Create(DWORD dwStaticStyle, const CRect& rect, CWnd* pParent, UINT nID)
{
    ASSERT(pParent);

    //  创建标签对象自身
    BOOL bRet = CStatic::Create(_T(""), WS_CHILD | WS_VISIBLE | SS_CENTER, rect, pParent, nID);
    if (!bRet) {
        ASSERT(TRUE == bRet);
        return FALSE;
    }

    //  计算矩形宽度
    int iListWidth = (rect.Width() - RESERVE_WIDTH) / 2;

    //  列表的方位
    CRect rcList[2];
    rcList[0] = rect;
    rcList[0].right = rcList[0].left + iListWidth;

    rcList[1] = rect;
    rcList[1].left = rcList[1].right - iListWidth;

    //  创建左右两边的列表
    INT iIDs[] = {IDC_DIRLIST_LEFT, IDC_DIRLIST_RIGHT};
    for (int i = 0; i < 2; i++) {
        CListCtrl* pList = m_tDirLists + i;
        DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_EDITLABELS | LVS_SINGLESEL | LVS_SHOWSELALWAYS | LVS_OWNERDATA;
        BOOL bRet = pList->Create(dwStyle, rcList[i], this, iIDs[i]);
        if (!bRet) {
            ASSERT(TRUE == bRet);
            return FALSE;
        }
    }

    return TRUE;
}

int CDirDiffCtrl::InsertColumn(int nCol, LPCTSTR lpszColumnHeading, int nFormat, int nWidth, int nSubItem)
{
    int iRet = m_tDirLists[0].InsertColumn(nCol, lpszColumnHeading, nFormat, nWidth, nSubItem);
    if (iRet < 0) {
        ASSERT(iRet >= 0);
        return FALSE;
    }

    iRet = m_tDirLists[1].InsertColumn(nCol, lpszColumnHeading, nFormat, nWidth, nSubItem);
    if (iRet < 0) {
        ASSERT(iRet >= 0);
        return FALSE;
    }

    return iRet;
}

DWORD CDirDiffCtrl::SetExtendedStyle(_In_ DWORD dwNewStyle)
{
    DWORD dwRet = 0;
    dwRet = m_tDirLists[0].SetExtendedStyle(dwNewStyle);
    dwRet = m_tDirLists[1].SetExtendedStyle(dwNewStyle);
    return dwRet;
}


BOOL CDirDiffCtrl::SetItemCountEx(_In_ int iCount, _In_ DWORD dwFlags)
{
    BOOL bRet = m_tDirLists[0].SetItemCountEx(iCount, dwFlags);
    if (!bRet) {
        ASSERT(bRet >= 0);
        return FALSE;
    }

    bRet = m_tDirLists[1].SetItemCountEx(iCount, dwFlags);
    if (!bRet) {
        ASSERT(bRet);
        return FALSE;
    }

    return TRUE;
}


void CDirDiffCtrl::OnGetdispinfoList(NMHDR *pNMHDR, LRESULT *pResult)
{
    LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
    LV_ITEM* pItem = &(pDispInfo)->item;

    //  显示的哪一边
    int iSide = (IDC_DIRLIST_LEFT == pNMHDR->idFrom)?0:1;

    //  通过回调获得显示选项
    struct DelegateItem* pDelegate = m_tDelegateItems + iSide;
    GetDisplayDelegate GetDisplay = (GetDisplayDelegate)(pDelegate->pCall);
    GetDisplay(pDelegate->pContext, pNMHDR, pResult);
}

void CDirDiffCtrl::OnSize(UINT nType, int cx, int cy)
{
    CStatic::OnSize(nType, cy, cy);
    this->Relayout();
}

void CDirDiffCtrl::Relayout()
{
    CRect rect;
    this->GetClientRect(&rect);

    CRect rcList[2];
    int iListWidth = (rect.Width() - RESERVE_WIDTH) / 2;

    if (::IsWindow(this->m_tDirLists[0])) {
        rcList[0].left = rect.left;
        rcList[0].top = rect.top;
        rcList[0].right = rcList[0].left + iListWidth;
        rcList[0].bottom = rect.bottom;
        this->m_tDirLists[0].MoveWindow(&rcList[0]);
    }

    if (::IsWindow(this->m_tDirLists[1])) {
        rcList[1].right = rect.right;
        rcList[1].bottom = rect.bottom;
        rcList[1].left = rcList[1].right - iListWidth;
        rcList[1].top = rect.top;
        this->m_tDirLists[1].MoveWindow(&rcList[1]);
    }

    //  移动窗口
}


void CDirDiffCtrl::OnPaint()
{
    CWnd::OnPaint();
}

