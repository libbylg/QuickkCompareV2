#ifndef __CQuickCompareFileDoc_H_
#define __CQuickCompareFileDoc_H_

#include "CQuickCompareDoc.h"

// CQuickCompareFileDoc �ĵ�

class CQuickCompareFileDoc : public CQuickCompareDoc
{
	DECLARE_DYNCREATE(CQuickCompareFileDoc)

public:
	CQuickCompareFileDoc();
	virtual ~CQuickCompareFileDoc();
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

	DECLARE_MESSAGE_MAP()
};

#endif//__CQuickCompareFileDoc_H_
