
// CQuickCompareChildFrame.h : CQuickCompareChildFrame ��Ľӿ�
//

#pragma once

class CQuickCompareChildFrame : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CQuickCompareChildFrame)
public:
	CQuickCompareChildFrame();

// ����
protected:
	CSplitterWndEx m_wndSplitter;
public:

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
