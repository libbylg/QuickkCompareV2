
// CQuickCompareChildFrame.cpp : CQuickCompareChildFrame 类的实现
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

// CQuickCompareChildFrame 构造/析构

CQuickCompareChildFrame::CQuickCompareChildFrame()
{
	// TODO:  在此添加成员初始化代码
}

CQuickCompareChildFrame::~CQuickCompareChildFrame()
{
}

BOOL CQuickCompareChildFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
//	return m_wndSplitter.Create(this,
//		2, 2,			// TODO:  调整行数和列数
//		CSize(10, 10),	// TODO:  调整最小窗格大小
//		pContext);

        m_pView = new CQuickCompareDirView();

    return TRUE;
}

BOOL CQuickCompareChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改 CREATESTRUCT cs 来修改窗口类或样式
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CQuickCompareChildFrame 诊断

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

// CQuickCompareChildFrame 消息处理程序
