
// QuickkCompare.h : QuickkCompare Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CQuickkCompareApp:
// �йش����ʵ�֣������ QuickkCompare.cpp
//

class CQuickkCompareApp : public CWinAppEx
{
public:
	CQuickkCompareApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CQuickkCompareApp theApp;
