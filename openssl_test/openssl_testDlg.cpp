
// openssl_testDlg.cpp : implementation file
//

#include "stdafx.h"
#include "openssl_test.h"
#include "openssl_testDlg.h"
#include "afxdialogex.h"

#include <memory>

#include "openssl\OpenSSL.h"

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


// Copenssl_testDlg dialog



Copenssl_testDlg::Copenssl_testDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_OPENSSL_TEST_DIALOG, pParent)
	, m_input(_T(""))
	, m_output(_T(""))
	, m_mode(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Copenssl_testDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_E_IN, m_input);
	DDX_Text(pDX, IDC_E_OUT, m_output);
	DDX_Radio(pDX, IDC_R_ECB, m_mode);
}

BEGIN_MESSAGE_MAP(Copenssl_testDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_B_ENC, &Copenssl_testDlg::OnBnClickedBEnc)
	ON_BN_CLICKED(IDC_B_DEC, &Copenssl_testDlg::OnBnClickedBDec)
END_MESSAGE_MAP()


// Copenssl_testDlg message handlers

BOOL Copenssl_testDlg::OnInitDialog()
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Copenssl_testDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Copenssl_testDlg::OnPaint()
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
HCURSOR Copenssl_testDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Copenssl_testDlg::OnBnClickedBEnc()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	char *output;
	CStringA input(m_input);
	std::shared_ptr<char> ptr;
	unsigned char key[24], ivec[8];

	memset(key, 1, sizeof(key));
	memset(ivec, 0, sizeof(ivec));

	COpenSSL::openssl_des3(input.GetBuffer(), DES_ENCRYPT, m_mode, key, ivec, &output);
	ptr.reset(output);

	m_output = output;
	UpdateData(FALSE);
}


void Copenssl_testDlg::OnBnClickedBDec()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	char *output;
	CStringA input(m_input);
	std::shared_ptr<char> ptr;
	unsigned char key[24], ivec[8];

	memset(key, 1, sizeof(key));
	memset(ivec, 0, sizeof(ivec));

	COpenSSL::openssl_des3(input.GetBuffer(), DES_DECRYPT, m_mode, key, ivec, &output);
	ptr.reset(output);

	m_output = output;
	UpdateData(FALSE);
}
