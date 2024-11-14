// DODLG.cpp : implementation file
//

#include "stdafx.h"
#include "DigitalCollection.h"
#include "DODLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDODLG dialog


CDODLG::CDODLG(CWnd* pParent /*=NULL*/)
	: CDialog(CDODLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDODLG)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDODLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDODLG)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDODLG, CDialog)
	//{{AFX_MSG_MAP(CDODLG)
	ON_BN_CLICKED(IDC_T0, OnT0)
	ON_BN_CLICKED(IDC_T1, OnT1)
	ON_BN_CLICKED(IDC_T2, OnT2)
	ON_BN_CLICKED(IDC_T3, OnT3)
	ON_BN_CLICKED(IDC_T4, OnT4)
	ON_BN_CLICKED(IDC_T5, OnT5)
	ON_BN_CLICKED(IDC_T6, OnT6)
	ON_BN_CLICKED(IDC_T7, OnT7)
	ON_BN_CLICKED(IDC_T8, OnT8)
	ON_BN_CLICKED(IDC_T9, OnT9)
	ON_BN_CLICKED(IDC_T10, OnT10)
	ON_BN_CLICKED(IDC_T11, OnT11)
	ON_BN_CLICKED(IDC_T12, OnT12)
	ON_BN_CLICKED(IDC_T13, OnT13)
	ON_BN_CLICKED(IDC_T14, OnT14)
	ON_BN_CLICKED(IDC_T15, OnT15)
	ON_BN_CLICKED(IDC_DOUT, OnDout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDODLG message handlers

BYTE CDODLG::s_t0=0;
BYTE CDODLG::s_t1=0;
BYTE CDODLG::s_t2=0;
BYTE CDODLG::s_t3=0;
BYTE CDODLG::s_t4=0;
BYTE CDODLG::s_t5=0;
BYTE CDODLG::s_t6=0;
BYTE CDODLG::s_t7=0;
BYTE CDODLG::s_t8=0;
int  CDODLG::s_t9=0;
int  CDODLG::s_t10=0;
int  CDODLG::s_t11=0;
int  CDODLG::s_t12=0;
int  CDODLG::s_t13=0;
int  CDODLG::s_t14=0;
int  CDODLG::s_t15=0;

void CDODLG::OnT0() 
{
	// TODO: Add your control notification handler code here
	s_t0++;
	if (s_t0>1)
	{
		s_t0=0;
	}
	CWnd* pWnd = GetDlgItem(IDC_T0); 
	if (s_t0==1)
	{ 
		pWnd->SetWindowText(_T("1"));
	}
	else
	{
		pWnd->SetWindowText(_T("0"));
	}
	OnDout(); 
}

void CDODLG::OnT1() 
{
	// TODO: Add your control notification handler code here
	s_t1++;
	if (s_t1>1)
	{
		s_t1=0;
	}
	CWnd* pWnd = GetDlgItem(IDC_T1); 
	if (s_t1==1)
	{ 
		pWnd->SetWindowText(_T("1"));
	}
	else
	{
		pWnd->SetWindowText(_T("0"));
	}
	OnDout(); 
}

void CDODLG::OnT2() 
{
	// TODO: Add your control notification handler code here
	s_t2++;
	if (s_t2>1)
	{
		s_t2=0;
	}
	CWnd* pWnd = GetDlgItem(IDC_T2); 
	if (s_t2==1)
	{ 
		pWnd->SetWindowText(_T("1"));
	}
	else
	{
		pWnd->SetWindowText(_T("0"));
	}
	OnDout(); 
}

void CDODLG::OnT3() 
{
	s_t3++;
	if (s_t3>1)
	{
		s_t3=0;
	}
	CWnd* pWnd = GetDlgItem(IDC_T3); 
	if (s_t3==1)
	{ 
		pWnd->SetWindowText(_T("1"));
	}
	else
	{
		pWnd->SetWindowText(_T("0"));
	}
	OnDout(); 
}

void CDODLG::OnT4() 
{
	s_t4++;
	if (s_t4>1)
	{
		s_t4=0;
	}
	CWnd* pWnd = GetDlgItem(IDC_T4); 
	if (s_t4==1)
	{ 
		pWnd->SetWindowText(_T("1"));
	}
	else
	{
		pWnd->SetWindowText(_T("0"));
	}	
	OnDout();
}

void CDODLG::OnT5() 
{
	s_t5++;
	if (s_t5>1)
	{
		s_t5=0;
	}
	CWnd* pWnd = GetDlgItem(IDC_T5); 
	if (s_t5==1)
	{ 
		pWnd->SetWindowText(_T("1"));
	}
	else
	{
		pWnd->SetWindowText(_T("0"));
	}
	OnDout();
}

void CDODLG::OnT6() 
{
	s_t6++;
	if (s_t6>1)
	{
		s_t6=0;
	}
	CWnd* pWnd = GetDlgItem(IDC_T6); 
	if (s_t6==1)
	{ 
		pWnd->SetWindowText(_T("1"));
	}
	else
	{
		pWnd->SetWindowText(_T("0"));
	}
	OnDout();
}

void CDODLG::OnT7() 
{
	s_t7++;
	if (s_t7>1)
	{
		s_t7=0;
	}
	CWnd* pWnd = GetDlgItem(IDC_T7); 
	if (s_t7==1)
	{ 
		pWnd->SetWindowText(_T("1"));
	}
	else
	{
		pWnd->SetWindowText(_T("0"));
	}
	OnDout();
}

void CDODLG::OnT8() 
{
	s_t8++;
	if (s_t8>1)
	{
		s_t8=0;
	}
	CWnd* pWnd = GetDlgItem(IDC_T8); 
	if (s_t8==1)
	{ 
		pWnd->SetWindowText(_T("1"));
	}
	else
	{
		pWnd->SetWindowText(_T("0"));
	}		
}

void CDODLG::OnT9() 
{
	s_t9++;
	if (s_t9>1)
	{
		s_t9=0;
	}
	CWnd* pWnd = GetDlgItem(IDC_T9); 
	if (s_t9==1)
	{ 
		pWnd->SetWindowText(_T("1"));
	}
	else
	{
		pWnd->SetWindowText(_T("0"));
	}		
}

void CDODLG::OnT10() 
{
	s_t10++;
	if (s_t10>1)
	{
		s_t10=0;
	}
	CWnd* pWnd = GetDlgItem(IDC_T10); 
	if (s_t10==1)
	{ 
		pWnd->SetWindowText(_T("1"));
	}
	else
	{
		pWnd->SetWindowText(_T("0"));
	}		
}

void CDODLG::OnT11() 
{
	s_t11++;
	if (s_t11>1)
	{
		s_t11=0;
	}
	CWnd* pWnd = GetDlgItem(IDC_T11); 
	if (s_t11==1)
	{ 
		pWnd->SetWindowText(_T("1"));
	}
	else
	{
		pWnd->SetWindowText(_T("0"));
	}		
}

void CDODLG::OnT12() 
{
	s_t12++;
	if (s_t12>1)
	{
		s_t12=0;
	}
	CWnd* pWnd = GetDlgItem(IDC_T12); 
	if (s_t12==1)
	{ 
		pWnd->SetWindowText(_T("1"));
	}
	else
	{
		pWnd->SetWindowText(_T("0"));
	}		
}

void CDODLG::OnT13() 
{
	s_t13++;
	if (s_t13>1)
	{
		s_t13=0;
	}
	CWnd* pWnd = GetDlgItem(IDC_T13); 
	if (s_t13==1)
	{ 
		pWnd->SetWindowText(_T("1"));
	}
	else
	{
		pWnd->SetWindowText(_T("0"));
	}		
}

void CDODLG::OnT14() 
{
	s_t14++;
	if (s_t14>1)
	{
		s_t14=0;
	}
	CWnd* pWnd = GetDlgItem(IDC_T14); 
	if (s_t14==1)
	{ 
		pWnd->SetWindowText(_T("1"));
	}
	else
	{
		pWnd->SetWindowText(_T("0"));
	}		
}

void CDODLG::OnT15() 
{
	s_t15++;
	if (s_t15>1)
	{
		s_t15=0;
	}
	CWnd* pWnd = GetDlgItem(IDC_T15); 
	if (s_t15==1)
	{ 
		pWnd->SetWindowText(_T("1"));
	}
	else
	{
		pWnd->SetWindowText(_T("0"));
	}		
}

void CDODLG::OnDout() 
{
	BYTE bDOSts[8];
	
	HANDLE hDevice;
	int DeviceLgcID = 0; 
	hDevice = USB2832_CreateDevice(DeviceLgcID);
	if(hDevice == INVALID_HANDLE_VALUE)
	{
		MessageBox("Create Device Error...\n");
		return;
	}
	bDOSts[0] = s_t0;
	bDOSts[1] = s_t1;
	bDOSts[2] = s_t2;
	bDOSts[3] = s_t3;
	bDOSts[4] = s_t4;
	bDOSts[5] = s_t5;
	bDOSts[6] = s_t6;
	bDOSts[7] = s_t7;

	if(!USB2832_SetDeviceDO(hDevice, bDOSts)) // 开关量输出
	{
		MessageBox("SetDeviceDO Error...\n");
		return;
	}
}
