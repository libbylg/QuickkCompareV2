// CQuickCompareDirDoc.cpp : 实现文件
//

#include "stdafx.h"
#include "CQuickCompareDirDoc.h"
#include "Utils.h"
//#include "IListDelegate.h"
//
//class CDirListDelegate : public IListDelegate
//{
//public:
//    CompareNode* m_pRoot;
//
//public:
//    CDirListDelegate(CompareNode* pRoot);
//    virtual void    GetDispInfo(CListCtrl* pListCtrl, NMHDR* pNMHDR, LRESULT* pResult);
//    virtual void    DrawItem(CListCtrl* pListCtrl, LPDRAWITEMSTRUCT lpDrawItemStruct);
//};
//
//CDirListDelegate::CDirListDelegate(CompareNode* pRoot)
//{
//    m_pRoot = pRoot;
//}
//
//void    CDirListDelegate::GetDispInfo(CListCtrl* pListCtrl, NMHDR* pNMHDR, LRESULT* pResult)
//{
//    NMLVDISPINFO *pDispInfo = reinterpret_cast<NMLVDISPINFO *>(pNMHDR);
//    LVITEM *pItem = &(pDispInfo)->item;
//    //（1）LVIF_TEXT   必须填充 pszText
//    m_pRoot->GetItem(pItem->iItem);
//    //（2）LVIF_IMAGE  必须填充 iImage 
//    //（3）LVIF_INDENT 必须填充 iIndent
//    //（4）LVIF_PARAM  必须填充 lParam 
//    //（5）LVIF_STATE  必须填充 state
//}
//
//void    CDirListDelegate::DrawItem(CListCtrl* pListCtrl, LPDRAWITEMSTRUCT lpDrawItemStruct)
//{
//}

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
    //  对输入参数进行字符串分隔
    CString strDirs[2];
    CString strPathName = lpszPathName;
    int pos = strPathName.Find(_T(";"), 0);
    if (pos < 0) {
        strDirs[0] = CPathUtils::DirName(lpszPathName);
    } else {
        strDirs[0] = CPathUtils::DirName(strPathName.Left(pos).Trim());
        strDirs[1] = CPathUtils::DirName(strPathName.Mid(pos +1).Trim());
    }

    //  生成 CompareNode
    for (int i = 0; i < 2; i++) {
        m_tRootItem.tDescs[i].strName = strDirs[i];
        m_tRootItem.dwFlag |= ITEMFLAG_DIR;
    }

    for (int i = 0; i < 2; i++) {
        if (m_tRootItem.tDescs[i].strName.IsEmpty()) {
            continue;
        }
        m_tRootItem.ScanChilds(1, i);
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

CompareNode*  CQuickCompareDirDoc::GetRootItem()
{
    return &(this->m_tRootItem);
}

// CQuickCompareDirDoc 命令
