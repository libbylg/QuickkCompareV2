
// QuickCompareView.cpp : CQuickCompareView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "CQuickCompareApp.h"
#endif

#include "CQuickCompareDoc.h"
#include "CQuickCompareView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CQuickCompareView

IMPLEMENT_DYNCREATE(CQuickCompareView, CView)

BEGIN_MESSAGE_MAP(CQuickCompareView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CQuickCompareView ����/����

CQuickCompareView::CQuickCompareView()
{
	// TODO:  �ڴ˴���ӹ������

}

CQuickCompareView::~CQuickCompareView()
{
}

BOOL CQuickCompareView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CQuickCompareView ����

void CQuickCompareView::OnDraw(CDC* /*pDC*/)
{
	CQuickCompareDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CQuickCompareView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CQuickCompareView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CQuickCompareView ���

#ifdef _DEBUG
void CQuickCompareView::AssertValid() const
{
	CView::AssertValid();
}

void CQuickCompareView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CQuickCompareDoc* CQuickCompareView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CQuickCompareDoc)));
	return (CQuickCompareDoc*)m_pDocument;
}
#endif //_DEBUG


// CQuickCompareView ��Ϣ�������
