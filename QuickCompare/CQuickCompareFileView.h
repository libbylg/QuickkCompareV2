#ifndef __CQuickCompareFileView_H_
#define __CQuickCompareFileView_H_

#include "CQuickCompareView.h"

// CQuickCompareFileView ��ͼ

class CQuickCompareFileView : public CQuickCompareView
{
	DECLARE_DYNCREATE(CQuickCompareFileView)

protected:
	CQuickCompareFileView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CQuickCompareFileView();

public:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
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


