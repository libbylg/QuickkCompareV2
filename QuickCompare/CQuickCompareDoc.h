#ifndef __CQuickCompareDoc_H_
#define __CQuickCompareDoc_H_


// QuickCompareDoc.h : CQuickCompareDoc ��Ľӿ�
//




class CQuickCompareDoc : public CDocument
{
protected: // �������л�����
	CQuickCompareDoc();
	DECLARE_DYNCREATE(CQuickCompareDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CQuickCompareDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};

#endif//__CQuickCompareDoc_H_
