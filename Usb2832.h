#ifndef _USB2832_DEVICE_
#define _USB2832_DEVICE_

#include<windows.h>
//***********************************************************
// ����AD�ɼ��Ĳ����ṹ
typedef struct _USB2832_PARA_AD
{
	LONG FirstChannel;      // ��ͨ��,ȡֵ��ΧΪ[0, 31]
	LONG LastChannel;		// ĩͨ��,ȡֵ��ΧΪ[0, 31]
	LONG InputRange;		// ����ѡ��
	LONG Gains;				// ���������
	LONG GroundingMode;		// �ӵط�ʽ�����˻�˫��ѡ��
} USB2832_PARA_AD, *PUSB2832_PARA_AD;

//***********************************************************
// ADӲ������USB2832_PARA_AD�е�InputRange������ʹ�õ�ѡ��
const long USB2832_INPUT_N10000_P10000mV= 0x00; // ��10000mV
const long USB2832_INPUT_N5000_P5000mV	= 0x01; // ��5000mV
const long USB2832_INPUT_N2500_P2500mV	= 0x02; // ��2500mV
const long USB2832_INPUT_0_P10000mV		= 0x03; // 0��10000mV

//***********************************************************
// AD����USB2832_PARA_AD�е�Gainsʹ�õ�Ӳ������ѡ��
const long USB2832_GAINS_1MULT			= 0x00; // 1������(ʹ��AD8251�Ŵ���)
const long USB2832_GAINS_2MULT			= 0x01; // 2������(ʹ��AD8251�Ŵ���)
const long USB2832_GAINS_4MULT			= 0x02; // 4������(ʹ��AD8251�Ŵ���)
const long USB2832_GAINS_8MULT			= 0x03; // 8������(ʹ��AD8251�Ŵ���)

//***********************************************************
// AD����(USB2832_PARA_AD)�е�GroundingModeʹ�õ�ģ���źŽӵط�ʽѡ��
const long USB2832_GNDMODE_SE			= 0x00;	// ���˷�ʽ(SE:Single end)
const long USB2832_GNDMODE_DI			= 0x01;	// ˫�˷�ʽ(DI:Differential)

//***********************************************************
// ���ڼ�����CNT�Ĳ����ṹ
// Ӳ������ControlMode������ģʽѡ��
const long USB2832_GATEMODE_POSITIVE_0	= 0x00;		// COUNTER:GATE�ߵ�ƽʱ�������͵�ƽʱֹͣ����������ʱ����д���ֵ������ֵ����
													// �������������жϣ�д���ֵ��ʼ����ʱOUT��ʼΪ0����������0ʱOUTΪ1

const long USB2832_GATEMODE_RISING_1	= 0x01;		// COUNTER:GATE�ϱ��ش��������������г���GATE����������װ���ֵ����
													// �ɱ�̵������壺��д���ֵʱOUTΪ1������ʼ����ʱOUTΪ0����������0ʱOUT�ٴ�Ϊ1

const long USB2832_GATEMODE_POSITIVE_2	= 0x02;		// COUNTER:GATE�ߵ�ƽʱ�������͵�ƽʱֹͣ����������ʱ����д���ֵ������ֵ����
													// Ƶ�ʷ������������ڼ�OUTΪ1��������0�����һ�����ڵ�0��������װ�����ֵ����

const long USB2832_GATEMODE_POSITIVE_3	= 0x03;		// COUNTER:GATE�ߵ�ƽʱ�������͵�ƽʱֹͣ����������ʱ����д���ֵ������ֵ����
													// �����������������ڼ�OUTΪ1��������0�����һ�����ڵ�0��������װ�����ֵ����

const long USB2832_GATEMODE_POSITIVE_4	= 0x04;		// COUNTER:GATE�ߵ�ƽʱ�������͵�ƽʱֹͣ����������ʱ����д���ֵ������ֵ����
													// �������ѡͨ��д���ֵOUTΪ1�� ��������OUT���һ�����ڵ͵�ƽ�ź�

const long USB2832_GATEMODE_RISING_5	= 0x05;		// COUNTER:GATE�ϱ��ش��������������г���GATE����������װ���ֵ����
													// Ӳ������ѡͨ��д���ֵOUTΪ1�� ��������OUT���һ�����ڵ͵�ƽ�ź�

//***********************************************************
// CreateFileObject�е�Mode����ʹ�õ��ļ�������ʽ������(��ͨ����ָ��ʵ�ֶ��ַ�ʽ������)
const long	USB2832_modeRead			= 0x0000;   // ֻ���ļ���ʽ
const long  USB2832_modeWrite			= 0x0001;   // ֻд�ļ���ʽ
const long 	USB2832_modeReadWrite		= 0x0002;   // �ȶ���д�ļ���ʽ
const long  USB2832_modeCreate			= 0x1000;   // ����ļ�������Դ������ļ���������ڣ����ؽ����ļ�������0

//***********************************************************
// ���������ӿ�
#ifndef _USB2832_DRIVER_
#define DEVAPI __declspec(dllimport)
#else
#define DEVAPI __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C" {
#endif
	//######################## ����ͨ�ú��� #################################
    HANDLE DEVAPI FAR PASCAL USB2832_CreateDevice(int DeviceLgcID = 0); // �����豸����(�ú���ʹ��ϵͳ���߼��豸ID��
	int DEVAPI FAR PASCAL USB2832_GetDeviceCount(HANDLE hDevice);      // ȡ��USB2832��ϵͳ�е��豸����
	BOOL DEVAPI FAR PASCAL USB2832_GetDeviceCurrentID(HANDLE hDevice, PLONG DeviceLgcID, PLONG DevicePhysID); // ȡ�õ�ǰ�豸���߼�ID�ź�����ID��
	BOOL DEVAPI FAR PASCAL USB2832_ListDeviceDlg(void); // �öԻ����б�ϵͳ���е�����USB2832�豸
	BOOL DEVAPI FAR PASCAL USB2832_ResetDevice(HANDLE hDevice);		 // ��λ����USB�豸
    BOOL DEVAPI FAR PASCAL USB2832_ReleaseDevice(HANDLE hDevice);    // �ͷ��豸

	//####################### AD���ݶ�ȡ���� #################################
    BOOL DEVAPI FAR PASCAL USB2832_InitDeviceAD(				// ��ʼ���豸,������TRUE��,�豸���̿�ʼ����.
									HANDLE hDevice,				// �豸���,��Ӧ��CreateDevice��������
									PUSB2832_PARA_AD pADPara);  // Ӳ������, �����ڴ˺����о���Ӳ��״̬							

    BOOL DEVAPI FAR PASCAL USB2832_ReadDeviceAD(				// ��ʼ���豸�󣬼����ô˺�����ȡ�豸�ϵ�AD����
									HANDLE hDevice,				// �豸���,��Ӧ��CreateDevice��������
									USHORT ADBuffer[],			// �����ڽ������ݵ��û�������
									LONG nReadSizeWords,		// ��ȡAD���ݵĳ���(��)  
									PLONG nRetSizeWords = NULL);// ʵ�ʷ������ݵĳ���(��)

    BOOL DEVAPI FAR PASCAL USB2832_ReleaseDeviceAD(HANDLE hDevice); // ֹͣAD�ɼ����ͷ�AD������ռ��Դ

   	//################# AD��Ӳ�������������� ########################	
	BOOL DEVAPI FAR PASCAL USB2832_SaveParaAD(HANDLE hDevice, PUSB2832_PARA_AD pADPara);  
    BOOL DEVAPI FAR PASCAL USB2832_LoadParaAD(HANDLE hDevice, PUSB2832_PARA_AD pADPara);
    BOOL DEVAPI FAR PASCAL USB2832_ResetParaAD(HANDLE hDevice, PUSB2832_PARA_AD pADPara); // ��AD���������ָ�������Ĭ��ֵ

	//##################### ���������ƺ��� ##########################
    BOOL DEVAPI FAR PASCAL USB2832_SetDeviceCNT(				// ��ʼ��������
									HANDLE	hDevice,			// �豸���
									ULONG	ContrlMode,			// ����������ģʽ
									ULONG	CNTVal,				// ������ֵ
									ULONG	ulChannel);			// ͨ��ѡ��[0-2]			

	BOOL DEVAPI FAR PASCAL USB2832_GetDeviceCNT(				// ȡ�ø�·�������ĵ�ǰ����ֵ
									HANDLE	hDevice,			// �豸������,����CreateDevice��������
									PULONG	pCNTVal,			// ���ؼ���ֵ
									ULONG	ulChannel);			// ͨ��ѡ��[0-2]
	
	//####################### ����I/O����������� #################################
	BOOL DEVAPI FAR PASCAL USB2832_GetDeviceDI(					// ȡ�ÿ�����״̬     
									HANDLE hDevice,				// �豸���,��Ӧ��CreateDevice��������								        
									BYTE bDISts[8]);			// ��������״̬(ע��: ���붨��Ϊ8���ֽ�Ԫ�ص�����)

    BOOL DEVAPI FAR PASCAL USB2832_SetDeviceDO(					// ���������״̬
									HANDLE hDevice,				// �豸���,��Ӧ��CreateDevice��������								        
									BYTE bDOSts[8]);			// �������״̬(ע��: ���붨��Ϊ8���ֽ�Ԫ�ص�����)

	//############################################################################
	BOOL DEVAPI FAR PASCAL USB2832_GetDevVersion(				// ��ȡ�豸�̼�������汾
									HANDLE hDevice,				// �豸������,����CreateDevice��������
									PULONG pulFmwVersion,		// �̼��汾
									PULONG pulDriverVersion);	// �����汾

   	//########################## �ļ��������� ####################################
    HANDLE DEVAPI FAR PASCAL USB2832_CreateFileObject(			// �����ļ�����
									HANDLE hDevice,				// �豸���,��Ӧ��CreateDevice��������
									LPCTSTR strFileName,		// ·�����ļ���
									int Mode);					// �ļ�������ʽ

    BOOL DEVAPI FAR PASCAL USB2832_WriteFile(					// �����û��ռ������ݵ������ļ�
									HANDLE hFileObject,			// �ļ����,��Ӧ��CreateFileObject��������
									PVOID pDataBuffer,			// �û����ݿռ��ַ
									LONG nWriteSizeBytes);		// ��������С(�ֽ�)

    BOOL DEVAPI FAR PASCAL USB2832_ReadFile(					// �Ӵ����ļ��ж�ȡ���ݵ��û��ռ�
									HANDLE hFileObject,			// �ļ����,��Ӧ��CreateFileObject��������
									PVOID pDataBuffer,			// �����ļ����ݵ��û��ڴ滺����
									LONG OffsetBytes,			// ���ļ�ǰ�˿�ʼ��ƫ��λ��
									LONG nReadSizeBytes);		// ��ƫ��λ�ÿ�ʼ�����ֽ���

	BOOL DEVAPI FAR PASCAL USB2832_SetFileOffset(				// �����ļ�ƫ��ָ��
									HANDLE hFileObject,			// �ļ����,��Ӧ��CreateFileObject��������
									LONG nOffsetBytes);			// �ļ�ƫ��λ�ã�����Ϊ��λ��  

	ULONGLONG DEVAPI FAR PASCAL USB2832_GetFileLength(HANDLE hFileObject); // ȡ��ָ���ļ����ȣ��ֽڣ�

    BOOL DEVAPI FAR PASCAL USB2832_ReleaseFile(HANDLE hFileObject);
    LONGLONG DEVAPI FAR PASCAL USB2832_GetDiskFreeBytes(		// ���ָ���̷��Ĵ��̿ռ�(ע��ʹ��64λ����)
								   LPCTSTR strDiskName);		// �̷���,��C��Ϊ"C:\\", D��Ϊ"D:\\"

	//############################ �̲߳������� ################################
	HANDLE DEVAPI FAR PASCAL USB2832_CreateSystemEvent(void); 	// �����ں�ϵͳ�¼�����
	BOOL DEVAPI FAR PASCAL USB2832_ReleaseSystemEvent(HANDLE hEvent); // �ͷ��ں��¼�����
	BOOL DEVAPI FAR PASCAL USB2832_CreateVBThread(HANDLE* hThread, LPTHREAD_START_ROUTINE RoutineAddr);
	BOOL DEVAPI FAR PASCAL USB2832_TerminateVBThread(HANDLE hThread);

	//################# �������Ӻ��� ########################
	BOOL DEVAPI FAR PASCAL USB2832_kbhit(void); // ̽���û��Ƿ��л�������(�ڿ���̨Ӧ�ó���Console�����ڷ�VC������)
	char DEVAPI FAR PASCAL USB2832_getch(void); // �ȴ�����ȡ�û�����ֵ(�ڿ���̨Ӧ�ó���Console����Ч)

	BOOL DEVAPI FAR PASCAL USB2832_SaveParaInt(HANDLE hDevice, LPCTSTR strParaName, int nValue); // ���������ݱ��浽ע�����(Device-x\Others)
	UINT DEVAPI FAR PASCAL USB2832_LoadParaInt(HANDLE hDevice, LPCTSTR strParaName, int nDefaultVal); // ���������ݴ�ע����лض�����(Device-x\Others)
	BOOL DEVAPI FAR PASCAL USB2832_SaveParaString(HANDLE hDevice, LPCTSTR strParaName, LPCTSTR strParaVal); // ���ַ������ݱ��浽ע�����(Device-x\Others)
	BOOL DEVAPI FAR PASCAL USB2832_LoadParaString(HANDLE hDevice, LPCTSTR strParaName, LPTSTR strParaVal, LPCTSTR strDefaultVal); // ���ַ������ݴ�ע����лض�����(Device-x\Others)

#ifdef __cplusplus
}
#endif

//#################### �������� #####################

const long USB2832_MAX_AD_CHANNELS = 16;

#ifndef _USB2832_FIFO_LENGTH_
#define _USB2832_FIFO_LENGTH_
// ��������֧�ֵĸ���FIFO�洢���ĳ���(��)
const long FIFO_IDT7202_LENGTH				= 1024;
const long FIFO_IDT7203_LENGTH				= 2048;
const long FIFO_IDT7204_LENGTH				= 4096;
const long FIFO_IDT7205_LENGTH				= 8192;
const long FIFO_IDT7206_LENGTH				= 16384;
const long FIFO_IDT7207_LENGTH				= 32768;
#endif; // _USB2832_FIFO_LENGTH_

// �Զ������������������
#ifndef _USB2832_DRIVER_
	#pragma comment(lib, "USB2832.lib")
	#pragma message("======== Welcome to use our art company product!")
	#pragma message("======== Automatically linking with USB2832.dll...")
	#pragma message("======== Successfully linked with USB2832.dll")
#endif

#endif; // _USB2832_DEVICE_