
// QuickkCompareView.cpp : CQuickkCompareView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CQuickkCompareView 构造/析构

CQuickkCompareView::CQuickkCompareView()
{
	// TODO:  在此处添加构造代码

}

CQuickkCompareView::~CQuickkCompareView()
{
}

BOOL CQuickkCompareView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CQuickkCompareView 绘制

void CQuickkCompareView::OnDraw(CDC* /*pDC*/)
{
	CQuickkCompareDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
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


// CQuickkCompareView 诊断

#ifdef _DEBUG
void CQuickkCompareView::AssertValid() const
{
	CView::AssertValid();
}

void CQuickkCompareView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CQuickkCompareDoc* CQuickkCompareView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CQuickkCompareDoc)));
	return (CQuickkCompareDoc*)m_pDocument;
}
#endif //_DEBUG


// CQuickkCompareView 消息处理程序
