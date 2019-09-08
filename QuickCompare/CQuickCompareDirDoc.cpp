// CQuickCompareDirDoc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CQuickCompareDirDoc.h"
#include "Utils.h"


class CDirListDelegate : public IListDelegate
{
public:
    CDirListDelegate();
    virtual void    GetDispInfo(CListCtrl* pListCtrl, NMHDR* pNMHDR, LRESULT* pResult) = 0;
    virtual void    DrawItem(CListCtrl* pListCtrl, LPDRAWITEMSTRUCT lpDrawItemStruct) = 0;
};

//DWORD       (*GetColumnCount)(void* ctx);
//void*       (*GetColumn)(void* ctx, DWORD dwIndex);
//DWORD       (*GetColumnState)(void* ctx, void* pColumn);
//CString&    (*GetColumnText)(void* ctx, void* pColumn, CString& strText);
//void*       (*GetColumnData)(void* ctx, void* pColumn);
//
//DWORD       (*GetItemCount)(void* ctx, void* pItem, DWORD dwState);
//void*       (*GetItem)(void* ctx, DWORD dwIndex);
//DWORD       (*GetItemState)(void* ctx, void* pItem);
//void*       (*GetItemData)(void* ctx, void* pItem);
//CString&    (*GetItemText)(void* ctx, void* pItem, DWORD dwColumn, CString& strText);

// CQuickCompareDirDoc

IMPLEMENT_DYNCREATE(CQuickCompareDirDoc, CQuickCompareDoc)

CQuickCompareDirDoc::CQuickCompareDirDoc()
{
}

BOOL CQuickCompareDirDoc::OnNewDocument()
{
    if (!CDocument::OnNewDocument()) {
        return FALSE;
    }
	return TRUE;
}

BOOL CQuickCompareDirDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
    //  ��������������ַ����ָ�
    CString strDirs[2];
    CString strPathName = lpszPathName;
    int pos = strPathName.Find(_T(";"), 0);
    if (pos < 0) {
        strDirs[0] = CPathUtils::DirName(lpszPathName);
    } else {
        strDirs[0] = CPathUtils::DirName(strPathName.Left(pos).Trim());
        strDirs[1] = CPathUtils::DirName(strPathName.Mid(pos +1).Trim());
    }

    //  ���� TFILEITEM
    for (int i = 0; i < 2; i++) {
        m_pRootItems[i].strName = strDirs[i];
        m_pRootItems[i].dwFlag |= ITEMFLAG_DIR;
    }

    for (int i = 0; i < 2; i++) {
        if (m_pRootItems[i].strName.IsEmpty()) {
            continue;
        }
        m_pRootItems[i].ScanChilds(1);
    }

    return TRUE;
}

CQuickCompareDirDoc::~CQuickCompareDirDoc()
{
}


BEGIN_MESSAGE_MAP(CQuickCompareDirDoc, CQuickCompareDoc)
END_MESSAGE_MAP()


// CQuickCompareDirDoc ���

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
// CQuickCompareDirDoc ���л�

void CQuickCompareDirDoc::Serialize(CArchive& ar)
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

TFILEITEM*  CQuickCompareDirDoc::GetRootItem(int index)
{
    return this->m_pRootItems + index;
}

// CQuickCompareDirDoc ����
