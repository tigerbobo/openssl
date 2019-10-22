
// openssl_testDlg.h : header file
//

#pragma once


// Copenssl_testDlg dialog
class Copenssl_testDlg : public CDialogEx
{
// Construction
public:
	Copenssl_testDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPENSSL_TEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBEnc();
	afx_msg void OnBnClickedBDec();
	CString m_input;
	CString m_output;
	int m_mode;
};
