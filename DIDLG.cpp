// DIDLG.cpp : implementation file
//

#include "stdafx.h"
#include "DigitalCollection.h"
#include "DIDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDIDLG dialog


CDIDLG::CDIDLG(CWnd* pParent /*=NULL*/)
	: CDialog(CDIDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDIDLG)
	//}}AFX_DATA_INIT
	for (int i=0;i<16;i++)
	{
		m_digital[i]=0;
	}
	bDISts[0] = 0;
	bDISts[1] = 0;
	bDISts[2] = 0;
	bDISts[3] = 0;
	bDISts[4] = 0;
	bDISts[5] = 0;
	bDISts[6] = 0;
	bDISts[7] = 0;
}


void CDIDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDIDLG)
	DDX_Control(pDX, IDC_BMP6, m_bmp6);
	DDX_Control(pDX, IDC_BMP9, m_bmp9);
	DDX_Control(pDX, IDC_BMP8, m_bmp8);
	DDX_Control(pDX, IDC_BMP7, m_bmp7);
	DDX_Control(pDX, IDC_BMP5, m_bmp5);
	DDX_Control(pDX, IDC_BMP4, m_bmp4);
	DDX_Control(pDX, IDC_BMP3, m_bmp3);
	DDX_Control(pDX, IDC_BMP2, m_bmp2);
	DDX_Control(pDX, IDC_BMP16, m_bmp16);
	DDX_Control(pDX, IDC_BMP15, m_bmp15);
	DDX_Control(pDX, IDC_BMP14, m_bmp14);
	DDX_Control(pDX, IDC_BMP13, m_bmp13);
	DDX_Control(pDX, IDC_BMP12, m_bmp12);
	DDX_Control(pDX, IDC_BMP11, m_bmp11);
	DDX_Control(pDX, IDC_BMP10, m_bmp10);
	DDX_Control(pDX, IDC_BMP, m_bmp);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDIDLG, CDialog)
	//{{AFX_MSG_MAP(CDIDLG)
	ON_WM_PAINT()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDIDLG message handlers

void CDIDLG::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here

	CBitmap bmp; 
	bmp.LoadBitmap(IDB_BITMAP1); 
	CBitmap bmp2;
	bmp2.LoadBitmap(IDB_BITMAP2);

	if (bDISts[0]==0)
	{
		m_bmp.SetBitmap((HBITMAP)bmp); //IDC_PICÊÇÍ¼Æ¬¿òID
	}else
	{
		m_bmp.SetBitmap((HBITMAP)bmp2); //IDC_PICÊÇÍ¼Æ¬¿òID
	}

	if (bDISts[1]==0)
	{
		m_bmp2.SetBitmap((HBITMAP)bmp); //IDC_PICÊÇÍ¼Æ¬¿òID
	}else
	{
		m_bmp2.SetBitmap((HBITMAP)bmp2); //IDC_PICÊÇÍ¼Æ¬¿òID
	}

	if (bDISts[2]==0)
	{
		m_bmp3.SetBitmap((HBITMAP)bmp); //IDC_PICÊÇÍ¼Æ¬¿òID
	}else
	{
		m_bmp3.SetBitmap((HBITMAP)bmp2); //IDC_PICÊÇÍ¼Æ¬¿òID
	}

	if (bDISts[3]==0)
	{
		m_bmp4.SetBitmap((HBITMAP)bmp); //IDC_PICÊÇÍ¼Æ¬¿òID
	}else
	{
		m_bmp4.SetBitmap((HBITMAP)bmp2); //IDC_PICÊÇÍ¼Æ¬¿òID
	}

	if (bDISts[4]==0)
	{
		m_bmp5.SetBitmap((HBITMAP)bmp); //IDC_PICÊÇÍ¼Æ¬¿òID
	}else
	{
		m_bmp5.SetBitmap((HBITMAP)bmp2); //IDC_PICÊÇÍ¼Æ¬¿òID
	}

	if (bDISts[5]==0)
	{
		m_bmp6.SetBitmap((HBITMAP)bmp); //IDC_PICÊÇÍ¼Æ¬¿òID
	}else
	{
		m_bmp6.SetBitmap((HBITMAP)bmp2); //IDC_PICÊÇÍ¼Æ¬¿òID
	}

	if (bDISts[6]==0)
	{
		m_bmp7.SetBitmap((HBITMAP)bmp); //IDC_PICÊÇÍ¼Æ¬¿òID
	}else
	{
		m_bmp7.SetBitmap((HBITMAP)bmp2); //IDC_PICÊÇÍ¼Æ¬¿òID
	}
	if (bDISts[7]==0)
	{
		m_bmp8.SetBitmap((HBITMAP)bmp); //IDC_PICÊÇÍ¼Æ¬¿òID
	}else
	{
		m_bmp8.SetBitmap((HBITMAP)bmp2); //IDC_PICÊÇÍ¼Æ¬¿òID
	}
	if (m_digital[8]==0)
	{
		m_bmp9.SetBitmap((HBITMAP)bmp); //IDC_PICÊÇÍ¼Æ¬¿òID
	}else
	{
		m_bmp9.SetBitmap((HBITMAP)bmp2); //IDC_PICÊÇÍ¼Æ¬¿òID
	}
	if (m_digital[9]==0)
	{
		m_bmp10.SetBitmap((HBITMAP)bmp); //IDC_PICÊÇÍ¼Æ¬¿òID
	}else
	{
		m_bmp10.SetBitmap((HBITMAP)bmp2); //IDC_PICÊÇÍ¼Æ¬¿òID
	}
	if (m_digital[10]==0)
	{
		m_bmp11.SetBitmap((HBITMAP)bmp); //IDC_PICÊÇÍ¼Æ¬¿òID
	}else
	{
		m_bmp11.SetBitmap((HBITMAP)bmp2); //IDC_PICÊÇÍ¼Æ¬¿òID
	}
	if (m_digital[11]==0)
	{
		m_bmp12.SetBitmap((HBITMAP)bmp); //IDC_PICÊÇÍ¼Æ¬¿òID
	}else
	{
		m_bmp12.SetBitmap((HBITMAP)bmp2); //IDC_PICÊÇÍ¼Æ¬¿òID
	}
	if (m_digital[12]==0)
	{
		m_bmp13.SetBitmap((HBITMAP)bmp); //IDC_PICÊÇÍ¼Æ¬¿òID
	}else
	{
		m_bmp13.SetBitmap((HBITMAP)bmp2); //IDC_PICÊÇÍ¼Æ¬¿òID
	}
	if (m_digital[13]==0)
	{
		m_bmp14.SetBitmap((HBITMAP)bmp); //IDC_PICÊÇÍ¼Æ¬¿òID
	}else
	{
		m_bmp14.SetBitmap((HBITMAP)bmp2); //IDC_PICÊÇÍ¼Æ¬¿òID
	}
	if (m_digital[14]==0)
	{
		m_bmp15.SetBitmap((HBITMAP)bmp); //IDC_PICÊÇÍ¼Æ¬¿òID
	}else
	{
		m_bmp15.SetBitmap((HBITMAP)bmp2); //IDC_PICÊÇÍ¼Æ¬¿òID
	}
	if (m_digital[15]==0)
	{
		m_bmp16.SetBitmap((HBITMAP)bmp); //IDC_PICÊÇÍ¼Æ¬¿òID
	}else
	{
		m_bmp16.SetBitmap((HBITMAP)bmp2); //IDC_PICÊÇÍ¼Æ¬¿òID
	}
	bmp.Detach(); 
//	InvalidateRect( rcPic ); 
	// Do not call CDialog::OnPaint() for painting messages
}

void CDIDLG::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	HANDLE hDevice;
	int DeviceLgcID = 0; 
	hDevice = USB2832_CreateDevice(DeviceLgcID);
	if(hDevice == INVALID_HANDLE_VALUE)
	{
		//MessageBox("Create Device Error...\n");
		KillTimer(1);
	}
	if(!USB2832_GetDeviceDI(hDevice, bDISts)) // ¿ª¹ØÁ¿ÊäÈë
	{
		//MessageBox("USB2832_GetDeviceDI...\n");
		KillTimer(1);
	}
	Invalidate(TRUE);
	CDialog::OnTimer(nIDEvent);
}

BOOL CDIDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDIDLG::On()
{
	SetTimer(1,100,NULL);
}

void CDIDLG::Down()
{
	KillTimer(1);
}
