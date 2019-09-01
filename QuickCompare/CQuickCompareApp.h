#ifndef __CQuickCompareApp_H_
#define __CQuickCompareApp_H_


// QuickCompare.h : QuickCompare 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CQuickCompareApp:
// 有关此类的实现，请参阅 QuickCompare.cpp
//

class CQuickCompareApp : public CWinAppEx
{
public:
    CQuickCompareApp();


    // 重写
public:
    virtual BOOL InitInstance();
    virtual int ExitInstance();

    // 实现
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

