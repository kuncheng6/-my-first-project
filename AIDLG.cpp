// AIDLG.cpp : implementation file
//

#include "stdafx.h"
#include "DigitalCollection.h"
#include "AIDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAIDLG dialog


CAIDLG::CAIDLG(CWnd* pParent /*=NULL*/)
	: CDialog(CAIDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAIDLG)
	m_now = _T("");
	//}}AFX_DATA_INIT
}


void CAIDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAIDLG)
	DDX_Control(pDX, IDC_COMBO1, m_cobox);
	DDX_Text(pDX, IDC_EDIT1, m_now);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAIDLG, CDialog)
	//{{AFX_MSG_MAP(CAIDLG)
	ON_BN_CLICKED(IDC_COLLECTION, OnCollection)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_STOP, OnStop)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAIDLG message handlers


void CAIDLG::OnCollection() 
{
	// TODO: Add your control notification handler code here
	SetTimer(1,100,NULL);
	
}

void CAIDLG::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	int n = m_cobox.GetCurSel();
	
	HANDLE hDevice;         // 设备对象句柄
	int DeviceLgcID;        // 物理设备ID号(由板上JP1决定)
	BOOL bReturn;           // 函数的返回值
	int nReadSizeWords;     // 每次读取AD数据个数
	LONG nRetWords;         // 实际读取的数据个数
	int nChannelCount = 0;  // 采样通道数
	WORD ADBuffer[32768];   // 接收AD 数据的缓冲区
	WORD ADData;
	float Volt;             // 将AD原始数据转换为电压值
	int nRemainder = 0;


	USB2832_PARA_AD ADPara;                                       // 初始化AD的参数结构
	ADPara.FirstChannel		= n;                                  // 首通道0
	ADPara.LastChannel		= n;                                  // 末通道3
	ADPara.InputRange		= 1;                                  // 量程选择
	ADPara.Gains			= USB2832_GAINS_1MULT;	              // 使用1倍增益
	ADPara.GroundingMode	= USB2832_GNDMODE_SE;                 // 单端方式
	nChannelCount = ADPara.LastChannel - ADPara.FirstChannel + 1; // 采样通道数

	DeviceLgcID = 0;                                              // 设备ID号, 假设系统中只有一个USB2832设备，即DeviceLgcID=0;
	hDevice = USB2832_CreateDevice(DeviceLgcID);				  // 创建设备对象
	if(hDevice == INVALID_HANDLE_VALUE) 
	{ 
		printf("Create Device Error\n"); 
		return; 
	}

	bReturn = USB2832_InitDeviceAD(hDevice, &ADPara); // 初始化AD
	if (!bReturn)
	{
		printf( "USB2832_InitDeviceAD Error\n" );
	}

	nReadSizeWords = 128;// 读取数据的大小
	printf("请等待，您可以按任意键退出，但请不要直接关闭窗口强制退出...\n");
	if(!USB2832_ReadDeviceAD(hDevice, ADBuffer, nReadSizeWords, &nRetWords)) // 读取AD转换数据
	{
		printf("ReadDeviceAD Error...\n");
	}
	
	int nChannel = ADPara.FirstChannel;
	for (int Index=0; Index<4; Index++) // 总共显示64个点的AD数据
	{
		ADData = ADBuffer[Index]&0x1FFF;
		

		Volt = (float)((10000.00/8192) * ADData - 5000.00); // 将AD数据转换为电压值
		if (nChannel==n)
		{
			m_now.Format("%8.2f",Volt);
			m_histctrl.SetPos(Volt*0.001);
			UpdateData(FALSE);
		}

		nChannel++;                                  // 通道号递加，准备换算下一个通道的数据
		if (nChannel>ADPara.LastChannel)             // 如果换算到末通道，再回到首通道
		{
			printf("\n");                            // 将显示光标位置移到下一项
			nChannel = ADPara.FirstChannel;
		}
	}                                                // 多点数据换算显示

	USB2832_ReleaseDeviceAD(hDevice); // 释放AD，停止AD数据转换
	USB2832_ReleaseDevice(hDevice);   // 释放设备对象	


	CDialog::OnTimer(nIDEvent);
}



void CAIDLG::OnStop() 
{
	// TODO: Add your control notification handler code here
	KillTimer(1);
}

BOOL CAIDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CRect rect;
	GetDlgItem(IDC_STATIC_HIST)->GetWindowRect(rect);
	ScreenToClient(rect);
	m_histctrl.Create(WS_VISIBLE | WS_CHILD | WS_TABSTOP, rect, this, 1000);
	//m_ctrlHistogram.SetRange(1, 120);
	m_histctrl.SetSpeed(CHistogramCtrl::HIGH_SPEED);
	//m_histctrl.SetRange(0,5);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
