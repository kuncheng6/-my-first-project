// DigitalCollection.h : main header file for the DIGITALCOLLECTION application
//

#if !defined(AFX_DIGITALCOLLECTION_H__79A95E5D_5B51_4934_8730_A5E74068746C__INCLUDED_)
#define AFX_DIGITALCOLLECTION_H__79A95E5D_5B51_4934_8730_A5E74068746C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDigitalCollectionApp:
// See DigitalCollection.cpp for the implementation of this class
//

class CDigitalCollectionApp : public CWinApp
{
public:
	CDigitalCollectionApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDigitalCollectionApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDigitalCollectionApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIGITALCOLLECTION_H__79A95E5D_5B51_4934_8730_A5E74068746C__INCLUDED_)
