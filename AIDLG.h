#if !defined(AFX_AIDLG_H__FA160D86_7383_4F6D_846A_54EB572B8F02__INCLUDED_)
#define AFX_AIDLG_H__FA160D86_7383_4F6D_846A_54EB572B8F02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AIDLG.h : header file
//
#include "USB2832.h"
#include "HistogramCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// CAIDLG dialog

class CAIDLG : public CDialog
{
// Construction
public:
	CAIDLG(CWnd* pParent = NULL);   // standard constructor
	CHistogramCtrl m_histctrl;
// Dialog Data
	//{{AFX_DATA(CAIDLG)
	enum { IDD = IDD_AI };
	CComboBox	m_cobox;
	CString	m_now;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAIDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAIDLG)
	afx_msg void OnCollection();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStop();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AIDLG_H__FA160D86_7383_4F6D_846A_54EB572B8F02__INCLUDED_)
