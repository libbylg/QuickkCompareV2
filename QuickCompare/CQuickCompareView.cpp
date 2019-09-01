
// QuickCompareView.cpp : CQuickCompareView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CQuickCompareView 构造/析构

CQuickCompareView::CQuickCompareView()
{
	// TODO:  在此处添加构造代码

}

CQuickCompareView::~CQuickCompareView()
{
}

BOOL CQuickCompareView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CQuickCompareView 绘制

void CQuickCompareView::OnDraw(CDC* /*pDC*/)
{
	CQuickCompareDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
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


// CQuickCompareView 诊断

#ifdef _DEBUG
void CQuickCompareView::AssertValid() const
{
	CView::AssertValid();
}

void CQuickCompareView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CQuickCompareDoc* CQuickCompareView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CQuickCompareDoc)));
	return (CQuickCompareDoc*)m_pDocument;
}
#endif //_DEBUG


// CQuickCompareView 消息处理程序
