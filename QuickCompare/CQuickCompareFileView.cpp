// CQuickCompareFileView.cpp : ʵ���ļ�
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


// CQuickCompareFileView ��ͼ

void CQuickCompareFileView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO:  �ڴ���ӻ��ƴ���
}


// CQuickCompareFileView ���

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


// CQuickCompareFileView ��Ϣ�������
