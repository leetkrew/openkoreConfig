
// offlinePasswordGeneratorDlg.h : header file
//

#pragma once


// CofflinePasswordGeneratorDlg dialog
class CofflinePasswordGeneratorDlg : public CDialog
{
// Construction
public:
	CofflinePasswordGeneratorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OFFLINEPASSWORDGENERATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedbtngenerate();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedbtncopy();
};
