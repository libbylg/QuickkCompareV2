
// CQuickCompareChildFrame.cpp : CQuickCompareChildFrame ���ʵ��
//

#include "stdafx.h"
#include "CQuickCompareApp.h"

#include "CQuickCompareChildFrame.h"

#include "CQuickCompareDirView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CQuickCompareChildFrame

IMPLEMENT_DYNCREATE(CQuickCompareChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CQuickCompareChildFrame, CMDIChildWndEx)
END_MESSAGE_MAP()

// CQuickCompareChildFrame ����/����

CQuickCompareChildFrame::CQuickCompareChildFrame()
{
	// TODO:  �ڴ���ӳ�Ա��ʼ������
}

CQuickCompareChildFrame::~CQuickCompareChildFrame()
{
}

BOOL CQuickCompareChildFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
//	return m_wndSplitter.Create(this,
//		2, 2,			// TODO:  ��������������
//		CSize(10, 10),	// TODO:  ������С�����С
//		pContext);

        m_pView = new CQuickCompareDirView();

    return TRUE;
}

BOOL CQuickCompareChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ��������ʽ
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CQuickCompareChildFrame ���

#ifdef _DEBUG
void CQuickCompareChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CQuickCompareChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// CQuickCompareChildFrame ��Ϣ�������
