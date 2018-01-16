
// MFCCSharpInteractionDlg.h : header file
//

#pragma once
#include "afxwin.h"

// Import the type library.
#import "..\CSharpDemoLibrary\bin\Debug\CSharpDemoLibrary.tlb" raw_interfaces_only

using namespace CSharpDemoLibrary;

// CMFCCSharpInteractionDlg dialog
class CMFCCSharpInteractionDlg : public CDialogEx
{
// Construction
public:
	CMFCCSharpInteractionDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCSHARPINTERACTION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

    IBaseInterface* pCalc = NULL; // Pointer to the C# class interface

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
    void InitializeCom();
	DECLARE_MESSAGE_MAP()
public:
    CButton radio_add;
    CButton radio_subtract;
    afx_msg void OnBnClickedButtonOperate();
    CEdit edit_operand1;
    CEdit edit_operand2;
    CEdit edit_result;
    afx_msg void OnBnClickedRadioAdd();
    afx_msg void OnBnClickedRadioSubtract();
    afx_msg void OnClose();
};
