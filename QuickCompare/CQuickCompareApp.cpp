
// QuickCompare.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "CQuickCompareApp.h"
#include "CQuickCompareMainFrame.h"

#include "CQuickCompareChildFrame.h"
#include "CQuickCompareDirDoc.h"
#include "CQuickCompareDirView.h"
#include "CQuickCompareFileDoc.h"
#include "CQuickCompareFileView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CQuickCompareApp

BEGIN_MESSAGE_MAP(CQuickCompareApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CQuickCompareApp::OnAppAbout)
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
END_MESSAGE_MAP()


// CQuickCompareApp ����

CQuickCompareApp::CQuickCompareApp()
{
	m_bHiColorIcons = TRUE;

	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// ���Ӧ�ó��������ù�����������ʱ֧��(/clr)�����ģ���: 
	//     1) �����д˸������ã�������������������֧�ֲ�������������
	//     2) ��������Ŀ�У������밴������˳���� System.Windows.Forms ������á�
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO:  ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("QuickCompare.AppID.NoVersion"));

	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CQuickCompareApp ����

CQuickCompareApp theApp;


// CQuickCompareApp ��ʼ��

BOOL CQuickCompareApp::InitInstance()
{
    // ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
    // ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
    //����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
    INITCOMMONCONTROLSEX InitCtrls;
    InitCtrls.dwSize = sizeof(InitCtrls);
    // ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
    // �����ؼ��ࡣ
    InitCtrls.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&InitCtrls);

    CWinAppEx::InitInstance();

    if (!AfxSocketInit()) {
        AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
        return FALSE;
    }

    // ��ʼ�� OLE ��
    if (!AfxOleInit()) {
        AfxMessageBox(IDP_OLE_INIT_FAILED);
        return FALSE;
    }

    AfxEnableControlContainer();

    EnableTaskbarInteraction();

    // ʹ�� RichEdit �ؼ���Ҫ  AfxInitRichEdit2()	
    // AfxInitRichEdit2();

    // ��׼��ʼ��
    // ���δʹ����Щ���ܲ�ϣ����С
    // ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
    // ����Ҫ���ض���ʼ������
    // �������ڴ洢���õ�ע�����
    // TODO:  Ӧ�ʵ��޸ĸ��ַ�����
    // �����޸�Ϊ��˾����֯��
    SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
    LoadStdProfileSettings(16);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)


    InitContextMenuManager();

    InitKeyboardManager();

    InitTooltipManager();
    CMFCToolTipInfo ttParams;
    ttParams.m_bVislManagerTheme = TRUE;
    theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
        RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

    // ע��Ӧ�ó�����ĵ�ģ�塣  �ĵ�ģ��
    // �������ĵ�����ܴ��ں���ͼ֮�������
    CMultiDocTemplate* pDocTemplate;
    pDocTemplate = new CMultiDocTemplate(IDR_QuickCompareTYPE,
        RUNTIME_CLASS(CQuickCompareDoc),
        RUNTIME_CLASS(CQuickCompareChildFrame), // �Զ��� MDI �ӿ��
        RUNTIME_CLASS(CQuickCompareDirView)
        //RUNTIME_CLASS(CQuickCompareView)
        //RUNTIME_CLASS(CEditView)
        );
    if (!pDocTemplate) {
        return FALSE;
    }
    AddDocTemplate(pDocTemplate);

    // ������ MDI ��ܴ���
    CQuickCompareMainFrame* pMainFrame = new CQuickCompareMainFrame;
    if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME)) {
        delete pMainFrame;
        return FALSE;
    }
    m_pMainWnd = pMainFrame;

    // �������к�׺ʱ�ŵ��� DragAcceptFiles
    //  �� MDI Ӧ�ó����У���Ӧ������ m_pMainWnd ֮����������
    // ������/��
    m_pMainWnd->DragAcceptFiles();

    // ������׼ shell ���DDE�����ļ�������������
    CCommandLineInfo cmdInfo;
    ParseCommandLine(cmdInfo);

    // ���á�DDE ִ�С�
    EnableShellOpen();
    RegisterShellFileTypes(TRUE);


    // ��������������ָ�������  ���
    // �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
    if (!ProcessShellCommand(cmdInfo)) {
        return FALSE;
    }
    // �������ѳ�ʼ���������ʾ����������и���
    pMainFrame->ShowWindow(SW_SHOWMAXIMIZED);
    pMainFrame->UpdateWindow();

    return TRUE;
}

int CQuickCompareApp::ExitInstance()
{
	//TODO:  �����������ӵĸ�����Դ
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CQuickCompareApp ��Ϣ�������


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// �������жԻ����Ӧ�ó�������
void CQuickCompareApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CQuickCompareApp �Զ������/���淽��

void CQuickCompareApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CQuickCompareApp::LoadCustomState()
{
}

void CQuickCompareApp::SaveCustomState()
{
}

// CQuickCompareApp ��Ϣ�������





void CQuickCompareApp::OnFileNew()
{
    // TODO:  �ڴ���������������
}



void CQuickCompareApp::OnFileOpen()
{
    /*
	CFileDialog dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL, NULL, 0);

	CString title;

	CString strFilter;
	CString strDefault;

	// append the "*.*" all files filter
	CString allFilter;
	VERIFY(allFilter.LoadString(AFX_IDS_ALLFILTER));
	strFilter += allFilter;
	strFilter += (TCHAR)'\0';   // next string please
	strFilter += _T("*.*");
	strFilter += (TCHAR)'\0';   // last string
	dlgFile.m_ofn.nMaxCustFilter++;

	dlgFile.m_ofn.lpstrFilter = strFilter;
	dlgFile.m_ofn.lpstrTitle = title;
	dlgFile.m_ofn.lpstrFile = fileName.GetBuffer(_MAX_PATH);
    

	INT_PTR nResult = dlgFile.DoModal();
	fileName.ReleaseBuffer();
    */

    this->OpenDocumentFile(_T("F:\\dev\\github.com\\libbylg\\QuickkCompareV2\\1.qc"));

	return;
}

