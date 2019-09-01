
// QuickkCompareView.cpp : CQuickkCompareView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "QuickkCompare.h"
#endif

#include "QuickkCompareDoc.h"
#include "QuickkCompareView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CQuickkCompareView

IMPLEMENT_DYNCREATE(CQuickkCompareView, CView)

BEGIN_MESSAGE_MAP(CQuickkCompareView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CQuickkCompareView ����/����

CQuickkCompareView::CQuickkCompareView()
{
	// TODO:  �ڴ˴���ӹ������

}

CQuickkCompareView::~CQuickkCompareView()
{
}

BOOL CQuickkCompareView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CQuickkCompareView ����

void CQuickkCompareView::OnDraw(CDC* /*pDC*/)
{
	CQuickkCompareDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CQuickkCompareView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CQuickkCompareView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CQuickkCompareView ���

#ifdef _DEBUG
void CQuickkCompareView::AssertValid() const
{
	CView::AssertValid();
}

void CQuickkCompareView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CQuickkCompareDoc* CQuickkCompareView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CQuickkCompareDoc)));
	return (CQuickkCompareDoc*)m_pDocument;
}
#endif //_DEBUG


// CQuickkCompareView ��Ϣ�������
