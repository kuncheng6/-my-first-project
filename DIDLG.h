#if !defined(AFX_DIDLG_H__9067C535_B8DE_4DDF_9FC6_647DA31DF487__INCLUDED_)
#define AFX_DIDLG_H__9067C535_B8DE_4DDF_9FC6_647DA31DF487__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DIDLG.h : header file
//
#include "USB2832.h"
/////////////////////////////////////////////////////////////////////////////
// CDIDLG dialog

class CDIDLG : public CDialog
{
// Construction
public:
	void Down();
	void On();
	int m_digital[16];
	BYTE bDISts[8];
	CDIDLG(CWnd* pParent = NULL);   // standard constructor
	
// Dialog Data
	//{{AFX_DATA(CDIDLG)
	enum { IDD = IDD_DI };
	CStatic	m_bmp6;
	CStatic	m_bmp9;
	CStatic	m_bmp8;
	CStatic	m_bmp7;
	CStatic	m_bmp5;
	CStatic	m_bmp4;
	CStatic	m_bmp3;
	CStatic	m_bmp2;
	CStatic	m_bmp16;
	CStatic	m_bmp15;
	CStatic	m_bmp14;
	CStatic	m_bmp13;
	CStatic	m_bmp12;
	CStatic	m_bmp11;
	CStatic	m_bmp10;
	CStatic	m_bmp;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDIDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDIDLG)
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIDLG_H__9067C535_B8DE_4DDF_9FC6_647DA31DF487__INCLUDED_)
