#ifndef __CQuickCompareApp_H_
#define __CQuickCompareApp_H_


// QuickCompare.h : QuickCompare Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CQuickCompareApp:
// �йش����ʵ�֣������ QuickCompare.cpp
//

class CQuickCompareApp : public CWinAppEx
{
public:
    CQuickCompareApp();


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
    afx_msg void OnFileNew();
    afx_msg void OnFileOpen();
};

extern CQuickCompareApp theApp;

#endif//__CQuickCompareApp_H_

