// CQuickCompareFileDoc.cpp : 实现文件
//

#include "stdafx.h"
#include "CQuickCompareFileDoc.h"


// CQuickCompareFileDoc

IMPLEMENT_DYNCREATE(CQuickCompareFileDoc, CQuickCompareDoc)

CQuickCompareFileDoc::CQuickCompareFileDoc()
{
}

BOOL CQuickCompareFileDoc::OnNewDocument()
{
	if (!CQuickCompareDoc::OnNewDocument())
		return FALSE;
	return TRUE;
}

CQuickCompareFileDoc::~CQuickCompareFileDoc()
{
}


BEGIN_MESSAGE_MAP(CQuickCompareFileDoc, CQuickCompareDoc)
END_MESSAGE_MAP()


// CQuickCompareFileDoc 诊断

#ifdef _DEBUG
void CQuickCompareFileDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CQuickCompareFileDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CQuickCompareFileDoc 序列化

void CQuickCompareFileDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  在此添加存储代码
	}
	else
	{
		// TODO:  在此添加加载代码
	}
}
#endif


// CQuickCompareFileDoc 命令
