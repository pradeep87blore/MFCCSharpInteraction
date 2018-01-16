
// MFCCSharpInteractionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCCSharpInteraction.h"
#include "MFCCSharpInteractionDlg.h"
#include "afxdialogex.h"
#include <memory>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CAboutDlg dialog used for App About


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCCSharpInteractionDlg dialog


CMFCCSharpInteractionDlg::CMFCCSharpInteractionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCCSHARPINTERACTION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCSharpInteractionDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_RADIO_ADD, radio_add);
    DDX_Control(pDX, IDC_RADIO_ADD2, radio_subtract);
    DDX_Control(pDX, IDC_EDIT_OPERAND_1, edit_operand1);
    DDX_Control(pDX, IDC_EDIT_OPERAND_2, edit_operand2);
    DDX_Control(pDX, IDC_EDIT_RESULT, edit_result);
}

BEGIN_MESSAGE_MAP(CMFCCSharpInteractionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_OPERATE, &CMFCCSharpInteractionDlg::OnBnClickedButtonOperate)
    ON_BN_CLICKED(IDC_RADIO_ADD, &CMFCCSharpInteractionDlg::OnBnClickedRadioAdd)
    ON_BN_CLICKED(IDC_RADIO_SUBTRACT, &CMFCCSharpInteractionDlg::OnBnClickedRadioSubtract)
    ON_WM_CLOSE()
END_MESSAGE_MAP()


// CMFCCSharpInteractionDlg message handlers

// Initialize the COM DLL and get a handle to the C# class
void CMFCCSharpInteractionDlg::InitializeCom()
{
    HRESULT hr = CoInitialize(NULL);
    
    hr = CoCreateInstance(__uuidof(ManagedCalculator), NULL,
        CLSCTX_INPROC_SERVER, __uuidof(IBaseInterface), (void**)&pCalc);

    // If the initalization failed, set this to nullptr so that we avoid using this later
    if (hr != S_OK)
    {
        pCalc = nullptr;
    }
}

BOOL CMFCCSharpInteractionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
    InitializeCom();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCCSharpInteractionDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCCSharpInteractionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCCSharpInteractionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// Use the loaded DLL to perform some basic operations
void CMFCCSharpInteractionDlg::OnBnClickedButtonOperate()
{
    if (pCalc == nullptr)
    {
        MessageBox(L"Could not connect to the COM C# class, check the code", L"COM class init failed", MB_OK);
        return;
    }

    int iOperand1 = 0, iOperand2 = 0;
    long result = 0;
    
    CString sTemp = L"";

    edit_operand1.GetWindowTextW(sTemp);
    iOperand1 = _ttoi(sTemp);

    edit_operand2.GetWindowTextW(sTemp);
    iOperand2 = _ttoi(sTemp);

    if(radio_add.GetCheck() == TRUE)
        pCalc->Add(iOperand1, iOperand2, &result);
    else if (radio_subtract.GetCheck() == TRUE)
        pCalc->Subtract(iOperand1, iOperand2, &result);
    else
    {
        MessageBoxW(L"Please select one of the operations", L"Incomplete data", MB_OK);
        return;
    }

    sTemp.Format(L"%ld", result);
    edit_result.SetWindowTextW(sTemp);
}

// There is a better way to ensure only one radio button is selected (by using groups).
// For now, using this since it was a known method.
void CMFCCSharpInteractionDlg::OnBnClickedRadioAdd()
{
    // Uncheck the other option
    radio_subtract.SetCheck(FALSE);
}

// There is a better way to ensure only one radio button is selected (by using groups).
// For now, using this since it was a known method.
void CMFCCSharpInteractionDlg::OnBnClickedRadioSubtract()
{
    // Uncheck the other option
    radio_add.SetCheck(FALSE);
}


void CMFCCSharpInteractionDlg::OnClose()
{
    // TODO: Add your message handler code here and/or call default
    CoUninitialize(); // Unload the loaded COM objects

    CDialogEx::OnClose();
}
