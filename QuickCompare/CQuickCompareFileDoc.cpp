// CQuickCompareFileDoc.cpp : ʵ���ļ�
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


// CQuickCompareFileDoc ���

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
// CQuickCompareFileDoc ���л�

void CQuickCompareFileDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  �ڴ���Ӵ洢����
	}
	else
	{
		// TODO:  �ڴ���Ӽ��ش���
	}
}
#endif


// CQuickCompareFileDoc ����
