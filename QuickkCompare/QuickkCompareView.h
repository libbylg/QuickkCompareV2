
// QuickkCompareView.h : CQuickkCompareView ��Ľӿ�
//

#pragma once


class CQuickkCompareView : public CView
{
protected: // �������л�����
	CQuickkCompareView();
	DECLARE_DYNCREATE(CQuickkCompareView)

// ����
public:
	CQuickkCompareDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CQuickkCompareView();
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

#ifndef _DEBUG  // QuickkCompareView.cpp �еĵ��԰汾
inline CQuickkCompareDoc* CQuickkCompareView::GetDocument() const
   { return reinterpret_cast<CQuickkCompareDoc*>(m_pDocument); }
#endif

