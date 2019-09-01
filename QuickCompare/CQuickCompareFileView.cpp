// CQuickCompareFileView.cpp : 实现文件
//

#include "stdafx.h"
#include "CQuickCompareFileView.h"


// CQuickCompareFileView

IMPLEMENT_DYNCREATE(CQuickCompareFileView, CQuickCompareView)

CQuickCompareFileView::CQuickCompareFileView()
{

}

CQuickCompareFileView::~CQuickCompareFileView()
{
}

BEGIN_MESSAGE_MAP(CQuickCompareFileView, CQuickCompareView)
END_MESSAGE_MAP()


// CQuickCompareFileView 绘图

void CQuickCompareFileView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO:  在此添加绘制代码
}


// CQuickCompareFileView 诊断

#ifdef _DEBUG
void CQuickCompareFileView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CQuickCompareFileView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CQuickCompareFileView 消息处理程序
