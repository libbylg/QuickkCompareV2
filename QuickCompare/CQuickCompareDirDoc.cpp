// CQuickCompareDirDoc.cpp : 实现文件
//

#include "stdafx.h"
#include "CQuickCompareDirDoc.h"
#include "Utils.h"

// CQuickCompareDirDoc

IMPLEMENT_DYNCREATE(CQuickCompareDirDoc, CQuickCompareDoc)

CQuickCompareDirDoc::CQuickCompareDirDoc()
{
}

BOOL CQuickCompareDirDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

BOOL CQuickCompareDirDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
    //  对输入参数进行字符串分隔
    CString strDirs[2];
    CString strPathName = lpszPathName;
    int pos = strPathName.Find(_T(";"), 0);
    if (pos < 0) {
        strDirs[0] = lpszPathName;
    } else {
        strDirs[0] = strPathName.Left(pos).Trim();
        strDirs[1] = strPathName.Mid(pos +1).Trim();
    }

    //  生成 TFILEITEM
    for (int i = 0; i < 2; i++) {
        if (strDirs[i].IsEmpty()) {
            continue;
        }
        m_pRootItems[i] = new TFILEITEM(strDirs[i], TRUE);
    }

    for (int i = 0; i < 2; i++) {
        m_pRootItems[i]->ScanChilds(1);
    }

    return TRUE;
}

CQuickCompareDirDoc::~CQuickCompareDirDoc()
{
}


BEGIN_MESSAGE_MAP(CQuickCompareDirDoc, CQuickCompareDoc)
END_MESSAGE_MAP()


// CQuickCompareDirDoc 诊断

#ifdef _DEBUG
void CQuickCompareDirDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CQuickCompareDirDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CQuickCompareDirDoc 序列化

void CQuickCompareDirDoc::Serialize(CArchive& ar)
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


// CQuickCompareDirDoc 命令
