#ifndef __CQuickCompareChildFrame_H_
#define __CQuickCompareChildFrame_H_


// CQuickCompareChildFrame.h : CQuickCompareChildFrame ��Ľӿ�
//
class CQuickCompareView;

class CQuickCompareChildFrame : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CQuickCompareChildFrame)
public:
	CQuickCompareChildFrame();

// ����
protected:
	CSplitterWndEx m_wndSplitter;

public:
    CQuickCompareView* m_pView;

// ����
public:

// ��д
public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CQuickCompareChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


#endif//__CQuickCompareChildFrame_H_

