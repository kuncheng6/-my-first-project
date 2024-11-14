// DigitalCollectionDlg.h : header file
//

#if !defined(AFX_DIGITALCOLLECTIONDLG_H__178A9789_CE3A_483E_ACE1_3A6CFBC5CDBA__INCLUDED_)
#define AFX_DIGITALCOLLECTIONDLG_H__178A9789_CE3A_483E_ACE1_3A6CFBC5CDBA__INCLUDED_

#include "AIDLG.h"	// Added by ClassView
#include "DIDLG.h"
#include "DODLG.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDigitalCollectionDlg dialog

class CDigitalCollectionDlg : public CDialog
{
// Construction
public:

	CAIDLG m_ai;
	CDIDLG m_di;
	CDODLG m_do;
	CDigitalCollectionDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDigitalCollectionDlg)
	enum { IDD = IDD_DIGITALCOLLECTION_DIALOG };
	CTabCtrl	m_tab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDigitalCollectionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDigitalCollectionDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTabtest(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIGITALCOLLECTIONDLG_H__178A9789_CE3A_483E_ACE1_3A6CFBC5CDBA__INCLUDED_)
