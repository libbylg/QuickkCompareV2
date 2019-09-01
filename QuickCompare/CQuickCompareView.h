#ifndef __CQuickCompareView_H_
#define __CQuickCompareView_H_

#include "CQuickCompareDoc.h"

class CQuickCompareView : public CView
{
protected: // �������л�����
	CQuickCompareView();
	DECLARE_DYNCREATE(CQuickCompareView)

// ����
public:
	CQuickCompareDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CQuickCompareView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // QuickCompareView.cpp �еĵ��԰汾
inline CQuickCompareDoc* CQuickCompareView::GetDocument() const
   { return reinterpret_cast<CQuickCompareDoc*>(m_pDocument); }
#endif

#endif//__CQuickCompareView_H_

