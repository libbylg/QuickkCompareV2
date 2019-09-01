#ifndef __CQuickCompareDirDoc_H_
#define __CQuickCompareDirDoc_H_

#include "CQuickCompareDoc.h"

// CQuickCompareDirDoc �ĵ�

struct TFILEITEM;


class CQuickCompareDirDoc : public CQuickCompareDoc
{
	DECLARE_DYNCREATE(CQuickCompareDirDoc)

private:
    TFILEITEM*   m_pRootItems[2];

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

