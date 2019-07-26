// dlgmsxmlDlg.h : header file
//

#if !defined(AFX_DLGMSXMLDLG_H__9CEB3BF3_1FD5_4ABD_950F_ECCC397F374D__INCLUDED_)
#define AFX_DLGMSXMLDLG_H__9CEB3BF3_1FD5_4ABD_950F_ECCC397F374D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDlgmsxmlDlg dialog

class CDlgmsxmlDlg : public CDialog
{
// Construction
public:
	CDlgmsxmlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgmsxmlDlg)
	enum { IDD = IDD_DLGMSXML_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgmsxmlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDlgmsxmlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMSXMLDLG_H__9CEB3BF3_1FD5_4ABD_950F_ECCC397F374D__INCLUDED_)
