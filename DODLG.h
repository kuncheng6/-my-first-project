#if !defined(AFX_DODLG_H__C542C67C_77DF_414C_89C9_9FEDB3C9E694__INCLUDED_)
#define AFX_DODLG_H__C542C67C_77DF_414C_89C9_9FEDB3C9E694__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DODLG.h : header file
//
#include "USB2832.h"
/////////////////////////////////////////////////////////////////////////////
// CDODLG dialog

class CDODLG : public CDialog
{
// Construction
public:
	static BYTE s_t0;
	static BYTE s_t1;
	static BYTE s_t2;
	static BYTE s_t3;
	static BYTE s_t4;
	static BYTE s_t5;
	static BYTE s_t6;
	static BYTE s_t7;
	static BYTE s_t8;
	static int s_t9;
	static int s_t10;
	static int s_t11;
	static int s_t12;
	static int s_t13;
	static int s_t14;
	static int s_t15;
public:
	CDODLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDODLG)
	enum { IDD = IDD_DO };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDODLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDODLG)
	afx_msg void OnT0();
	afx_msg void OnT1();
	afx_msg void OnT2();
	afx_msg void OnT3();
	afx_msg void OnT4();
	afx_msg void OnT5();
	afx_msg void OnT6();
	afx_msg void OnT7();
	afx_msg void OnT8();
	afx_msg void OnT9();
	afx_msg void OnT10();
	afx_msg void OnT11();
	afx_msg void OnT12();
	afx_msg void OnT13();
	afx_msg void OnT14();
	afx_msg void OnT15();
	afx_msg void OnDout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DODLG_H__C542C67C_77DF_414C_89C9_9FEDB3C9E694__INCLUDED_)
