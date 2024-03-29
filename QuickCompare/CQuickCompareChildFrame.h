#ifndef __CQuickCompareChildFrame_H_
#define __CQuickCompareChildFrame_H_


// CQuickCompareChildFrame.h : CQuickCompareChildFrame 类的接口
//
class CQuickCompareView;

class CQuickCompareChildFrame : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CQuickCompareChildFrame)
public:
	CQuickCompareChildFrame();

// 特性
protected:
	CSplitterWndEx m_wndSplitter;

// 操作
public:

// 重写
public:
	//virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CQuickCompareChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};


#endif//__CQuickCompareChildFrame_H_

