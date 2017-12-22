
// offlinePasswordGeneratorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "offlinePasswordGenerator.h"
#include "offlinePasswordGeneratorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CofflinePasswordGeneratorDlg dialog



CofflinePasswordGeneratorDlg::CofflinePasswordGeneratorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_OFFLINEPASSWORDGENERATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CofflinePasswordGeneratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CofflinePasswordGeneratorDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(btnGenerate, &CofflinePasswordGeneratorDlg::OnBnClickedbtngenerate)
	ON_BN_CLICKED(IDCANCEL, &CofflinePasswordGeneratorDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CofflinePasswordGeneratorDlg message handlers

BOOL CofflinePasswordGeneratorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	GetDlgItem(txtPasswordLength)->SetWindowTextW((LPCWSTR)L"8");
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CofflinePasswordGeneratorDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CofflinePasswordGeneratorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CString generateRandomPassword(INT length) {

	char* characters[] = {
		"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
		, "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
		, "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"
	};

	int arrSize = sizeof(characters) / sizeof(characters[0]);
	CString result = (LPCWSTR)L"";
	for (int i = 0; i <= length -1; i++) {
		int randomKey = rand() % arrSize;
		CString randomCharacter = (LPCWSTR)characters[randomKey];
		result = result + randomCharacter;
	}
	return result;
}


void CofflinePasswordGeneratorDlg::OnBnClickedbtngenerate()
{
	CString strLength;
	GetDlgItem(txtPasswordLength)->GetWindowTextW(strLength);
	int intLength = _ttoi(strLength);
	GetDlgItem(txtGeneratedPassword)->SetWindowTextW(generateRandomPassword(intLength));
}


void CofflinePasswordGeneratorDlg::OnBnClickedCancel()
{
	CDialog::OnCancel();
}
