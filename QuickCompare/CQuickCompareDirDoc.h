#ifndef __CQuickCompareDirDoc_H_
#define __CQuickCompareDirDoc_H_

#include "CQuickCompareDoc.h"
#include "Utils.h"

// CQuickCompareDirDoc �ĵ�


class CQuickCompareDirDoc : public CQuickCompareDoc
{
	DECLARE_DYNCREATE(CQuickCompareDirDoc)

private:
    TFILEITEM   m_tRootItem;

public:
    TFILEITEM*  GetRootItem();

public:
	CQuickCompareDirDoc();
	virtual ~CQuickCompareDirDoc();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // Ϊ�ĵ� I/O ��д
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual BOOL OnNewDocument();
    virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);

	DECLARE_MESSAGE_MAP()
};

#endif//__CQuickCompareDirDoc_H_

