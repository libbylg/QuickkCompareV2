#ifndef __CQuickCompareFileView_H_
#define __CQuickCompareFileView_H_

#include "CQuickCompareView.h"

// CQuickCompareFileView 视图

class CQuickCompareFileView : public CQuickCompareView
{
	DECLARE_DYNCREATE(CQuickCompareFileView)

protected:
	CQuickCompareFileView();           // 动态创建所使用的受保护的构造函数
	virtual ~CQuickCompareFileView();

public:
	virtual void OnDraw(CDC* pDC);      // 重写以绘制该视图
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


#endif//__CQuickCompareFileView_H_


