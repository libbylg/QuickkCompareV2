#ifndef __CQuickCompareFileDoc_H_
#define __CQuickCompareFileDoc_H_

#include "CQuickCompareDoc.h"

// CQuickCompareFileDoc 文档

class CQuickCompareFileDoc : public CQuickCompareDoc
{
	DECLARE_DYNCREATE(CQuickCompareFileDoc)

public:
	CQuickCompareFileDoc();
	virtual ~CQuickCompareFileDoc();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // 为文档 I/O 重写
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
