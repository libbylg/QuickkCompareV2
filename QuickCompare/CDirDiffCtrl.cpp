// CDirDiffCtrl.cpp : 实现文件
//

#include "stdafx.h"
#include "CDirDiffCtrl.h"

#define IDC_DIRLIST_LEFT    1000
#define IDC_DIRLIST_RIGHT   1001

#define RESERVE_WIDTH       22

// CQuickCompareDiffCtrl

IMPLEMENT_DYNAMIC(CDirDiffCtrl, CStatic)

CDirDiffCtrl::CDirDiffCtrl()
{

}

CDirDiffCtrl::~CDirDiffCtrl()
{
}


BEGIN_MESSAGE_MAP(CDirDiffCtrl, CStatic)
END_MESSAGE_MAP()



// CDirDiffCtrl 消息处理程序
//  Create a DiffCtrl
BOOL    CDirDiffCtrl::Create(DWORD dwStaticStyle, const CRect& rect, CWnd* pParent, UINT nID)
{
    BOOL bRet = CStatic::Create(_T(""), WS_CHILD | WS_VISIBLE | SS_CENTER, rect, pParent, nID);
    if (!bRet) {
        ASSERT(TRUE == bRet);
        return FALSE;
    }

    int iListWidth = (rect.Width() - RESERVE_WIDTH) / 2;
    CRect rcList[2];
    rcList[0].left = rect.left;
    rcList[0].top = rect.top;
    rcList[0].right = rcList[0].left + iListWidth;
    rcList[0].bottom = rect.bottom;

    rcList[1].right = rect.right;
    rcList[1].bottom = rect.bottom;
    rcList[1].left = rcList[1].right - iListWidth;
    rcList[1].top = rect.top;

        // TODO:  在此添加您专用的创建代码
    INT iIDs[] = {IDC_DIRLIST_LEFT, IDC_DIRLIST_RIGHT};
    for (int i = 0; i < 2; i++) {
        CListCtrl* pList = m_tDirLists + i;
        DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_EDITLABELS | LVS_SINGLESEL | LVS_SHOWSELALWAYS;
        BOOL bRet = pList->Create(dwStyle, rcList[i], this, iIDs[i]);
        if (!bRet) {
            ASSERT(TRUE == bRet);
            return FALSE;
        }
        pList->InsertColumn(0, _T("名称"), LVCFMT_LEFT, 100);
        pList->InsertColumn(1, _T("大小"), LVCFMT_LEFT, 100);
        pList->InsertColumn(2, _T("修改时间"), LVCFMT_LEFT, 100);
        pList->SetExtendedStyle(LVS_EX_FULLROWSELECT);
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

