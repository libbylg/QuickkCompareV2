#ifndef __CDirDiffCtrl_H_
#define __CDirDiffCtrl_H_


// CQuickCompareDiffCtrl

class CDirDiffCtrl : public CStatic
{
	DECLARE_DYNAMIC(CDirDiffCtrl)

public:
	CDirDiffCtrl();
	virtual ~CDirDiffCtrl();

    //  Create a DiffCtrl
    BOOL    Create(DWORD dwStaticStyle, const CRect& rect, CWnd* pParent, UINT nID);

protected:
	DECLARE_MESSAGE_MAP()
};


#endif//__CDirDiffCtrl_H_
