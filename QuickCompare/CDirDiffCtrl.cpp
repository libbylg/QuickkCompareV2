// CDirDiffCtrl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CDirDiffCtrl.h"


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



// CDirDiffCtrl ��Ϣ�������
//  Create a DiffCtrl
BOOL    CDirDiffCtrl::Create(DWORD dwStaticStyle, const CRect& rect, CWnd* pParent, UINT nID)
{
    return CStatic::Create(_T(""), WS_CHILD | WS_VISIBLE | SS_CENTER, rect, pParent, nID);
}


