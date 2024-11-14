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
	
	HANDLE hDevice;         // �豸������
	int DeviceLgcID;        // �����豸ID��(�ɰ���JP1����)
	BOOL bReturn;           // �����ķ���ֵ
	int nReadSizeWords;     // ÿ�ζ�ȡAD���ݸ���
	LONG nRetWords;         // ʵ�ʶ�ȡ�����ݸ���
	int nChannelCount = 0;  // ����ͨ����
	WORD ADBuffer[32768];   // ����AD ���ݵĻ�����
	WORD ADData;
	float Volt;             // ��ADԭʼ����ת��Ϊ��ѹֵ
	int nRemainder = 0;


	USB2832_PARA_AD ADPara;                                       // ��ʼ��AD�Ĳ����ṹ
	ADPara.FirstChannel		= n;                                  // ��ͨ��0
	ADPara.LastChannel		= n;                                  // ĩͨ��3
	ADPara.InputRange		= 1;                                  // ����ѡ��
	ADPara.Gains			= USB2832_GAINS_1MULT;	              // ʹ��1������
	ADPara.GroundingMode	= USB2832_GNDMODE_SE;                 // ���˷�ʽ
	nChannelCount = ADPara.LastChannel - ADPara.FirstChannel + 1; // ����ͨ����

	DeviceLgcID = 0;                                              // �豸ID��, ����ϵͳ��ֻ��һ��USB2832�豸����DeviceLgcID=0;
	hDevice = USB2832_CreateDevice(DeviceLgcID);				  // �����豸����
	if(hDevice == INVALID_HANDLE_VALUE) 
	{ 
		printf("Create Device Error\n"); 
		return; 
	}

	bReturn = USB2832_InitDeviceAD(hDevice, &ADPara); // ��ʼ��AD
	if (!bReturn)
	{
		printf( "USB2832_InitDeviceAD Error\n" );
	}

	nReadSizeWords = 128;// ��ȡ���ݵĴ�С
	printf("��ȴ��������԰�������˳������벻Ҫֱ�ӹرմ���ǿ���˳�...\n");
	if(!USB2832_ReadDeviceAD(hDevice, ADBuffer, nReadSizeWords, &nRetWords)) // ��ȡADת������
	{
		printf("ReadDeviceAD Error...\n");
	}
	
	int nChannel = ADPara.FirstChannel;
	for (int Index=0; Index<4; Index++) // �ܹ���ʾ64�����AD����
	{
		ADData = ADBuffer[Index]&0x1FFF;
		

		Volt = (float)((10000.00/8192) * ADData - 5000.00); // ��AD����ת��Ϊ��ѹֵ
		if (nChannel==n)
		{
			m_now.Format("%8.2f",Volt);
			m_histctrl.SetPos(Volt*0.001);
			UpdateData(FALSE);
		}

		nChannel++;                                  // ͨ���ŵݼӣ�׼��������һ��ͨ��������
		if (nChannel>ADPara.LastChannel)             // ������㵽ĩͨ�����ٻص���ͨ��
		{
			printf("\n");                            // ����ʾ���λ���Ƶ���һ��
			nChannel = ADPara.FirstChannel;
		}
	}                                                // ������ݻ�����ʾ

	USB2832_ReleaseDeviceAD(hDevice); // �ͷ�AD��ֹͣAD����ת��
	USB2832_ReleaseDevice(hDevice);   // �ͷ��豸����	


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
