#ifndef _USB2832_DEVICE_
#define _USB2832_DEVICE_

#include<windows.h>
//***********************************************************
// 用于AD采集的参数结构
typedef struct _USB2832_PARA_AD
{
	LONG FirstChannel;      // 首通道,取值范围为[0, 31]
	LONG LastChannel;		// 末通道,取值范围为[0, 31]
	LONG InputRange;		// 量程选择
	LONG Gains;				// 增益控制字
	LONG GroundingMode;		// 接地方式（单端或双端选择）
} USB2832_PARA_AD, *PUSB2832_PARA_AD;

//***********************************************************
// AD硬件参数USB2832_PARA_AD中的InputRange量程所使用的选项
const long USB2832_INPUT_N10000_P10000mV= 0x00; // ±10000mV
const long USB2832_INPUT_N5000_P5000mV	= 0x01; // ±5000mV
const long USB2832_INPUT_N2500_P2500mV	= 0x02; // ±2500mV
const long USB2832_INPUT_0_P10000mV		= 0x03; // 0～10000mV

//***********************************************************
// AD参数USB2832_PARA_AD中的Gains使用的硬件增益选项
const long USB2832_GAINS_1MULT			= 0x00; // 1倍增益(使用AD8251放大器)
const long USB2832_GAINS_2MULT			= 0x01; // 2倍增益(使用AD8251放大器)
const long USB2832_GAINS_4MULT			= 0x02; // 4倍增益(使用AD8251放大器)
const long USB2832_GAINS_8MULT			= 0x03; // 8倍增益(使用AD8251放大器)

//***********************************************************
// AD参数(USB2832_PARA_AD)中的GroundingMode使用的模拟信号接地方式选项
const long USB2832_GNDMODE_SE			= 0x00;	// 单端方式(SE:Single end)
const long USB2832_GNDMODE_DI			= 0x01;	// 双端方式(DI:Differential)

//***********************************************************
// 用于计数器CNT的参数结构
// 硬件参数ControlMode控制字模式选项
const long USB2832_GATEMODE_POSITIVE_0	= 0x00;		// COUNTER:GATE高电平时计数，低电平时停止计数，计数时重新写入初值，按初值计数
													// 计数结束产生中断：写入初值开始计数时OUT开始为0，当计数到0时OUT为1

const long USB2832_GATEMODE_RISING_1	= 0x01;		// COUNTER:GATE上边沿触发计数，计数中出现GATE上升沿重新装入初值计数
													// 可编程单拍脉冲：当写入初值时OUT为1，当开始计数时OUT为0，当计数到0时OUT再次为1

const long USB2832_GATEMODE_POSITIVE_2	= 0x02;		// COUNTER:GATE高电平时计数，低电平时停止计数，计数时重新写入初值，按初值计数
													// 频率发生器：计数期间OUT为1，计数到0后输出一个周期的0，并重新装入计数值计数

const long USB2832_GATEMODE_POSITIVE_3	= 0x03;		// COUNTER:GATE高电平时计数，低电平时停止计数，计数时重新写入初值，按初值计数
													// 方波发生器：计数期间OUT为1，计数到0后输出一个周期的0，并重新装入计数值计数

const long USB2832_GATEMODE_POSITIVE_4	= 0x04;		// COUNTER:GATE高电平时计数，低电平时停止计数，计数时重新写入初值，按初值计数
													// 软件触发选通：写入初值OUT为1， 计数结束OUT输出一个周期低电平信号

const long USB2832_GATEMODE_RISING_5	= 0x05;		// COUNTER:GATE上边沿触发计数，计数中出现GATE上升沿重新装入初值计数
													// 硬件触发选通：写入初值OUT为1， 计数结束OUT输出一个周期低电平信号

//***********************************************************
// CreateFileObject中的Mode参数使用的文件操作方式控制字(可通过或指令实现多种方式并操作)
const long	USB2832_modeRead			= 0x0000;   // 只读文件方式
const long  USB2832_modeWrite			= 0x0001;   // 只写文件方式
const long 	USB2832_modeReadWrite		= 0x0002;   // 既读又写文件方式
const long  USB2832_modeCreate			= 0x1000;   // 如果文件不存可以创建该文件，如果存在，则重建此文件，并清0

//***********************************************************
// 驱动函数接口
#ifndef _USB2832_DRIVER_
#define DEVAPI __declspec(dllimport)
#else
#define DEVAPI __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C" {
#endif
	//######################## 常规通用函数 #################################
    HANDLE DEVAPI FAR PASCAL USB2832_CreateDevice(int DeviceLgcID = 0); // 创建设备对象(该函数使用系统内逻辑设备ID）
	int DEVAPI FAR PASCAL USB2832_GetDeviceCount(HANDLE hDevice);      // 取得USB2832在系统中的设备数量
	BOOL DEVAPI FAR PASCAL USB2832_GetDeviceCurrentID(HANDLE hDevice, PLONG DeviceLgcID, PLONG DevicePhysID); // 取得当前设备的逻辑ID号和物理ID号
	BOOL DEVAPI FAR PASCAL USB2832_ListDeviceDlg(void); // 用对话框列表系统当中的所有USB2832设备
	BOOL DEVAPI FAR PASCAL USB2832_ResetDevice(HANDLE hDevice);		 // 复位整个USB设备
    BOOL DEVAPI FAR PASCAL USB2832_ReleaseDevice(HANDLE hDevice);    // 释放设备

	//####################### AD数据读取函数 #################################
    BOOL DEVAPI FAR PASCAL USB2832_InitDeviceAD(				// 初始化设备,当返回TRUE后,设备即刻开始传输.
									HANDLE hDevice,				// 设备句柄,它应由CreateDevice函数创建
									PUSB2832_PARA_AD pADPara);  // 硬件参数, 它仅在此函数中决定硬件状态							

    BOOL DEVAPI FAR PASCAL USB2832_ReadDeviceAD(				// 初始化设备后，即可用此函数读取设备上的AD数据
									HANDLE hDevice,				// 设备句柄,它应由CreateDevice函数创建
									USHORT ADBuffer[],			// 将用于接受数据的用户缓冲区
									LONG nReadSizeWords,		// 读取AD数据的长度(字)  
									PLONG nRetSizeWords = NULL);// 实际返回数据的长度(字)

    BOOL DEVAPI FAR PASCAL USB2832_ReleaseDeviceAD(HANDLE hDevice); // 停止AD采集，释放AD对象所占资源

   	//################# AD的硬件参数操作函数 ########################	
	BOOL DEVAPI FAR PASCAL USB2832_SaveParaAD(HANDLE hDevice, PUSB2832_PARA_AD pADPara);  
    BOOL DEVAPI FAR PASCAL USB2832_LoadParaAD(HANDLE hDevice, PUSB2832_PARA_AD pADPara);
    BOOL DEVAPI FAR PASCAL USB2832_ResetParaAD(HANDLE hDevice, PUSB2832_PARA_AD pADPara); // 将AD采样参数恢复至出厂默认值

	//##################### 计数器控制函数 ##########################
    BOOL DEVAPI FAR PASCAL USB2832_SetDeviceCNT(				// 初始化计数器
									HANDLE	hDevice,			// 设备句柄
									ULONG	ContrlMode,			// 计数器控制模式
									ULONG	CNTVal,				// 计数初值
									ULONG	ulChannel);			// 通道选择[0-2]			

	BOOL DEVAPI FAR PASCAL USB2832_GetDeviceCNT(				// 取得各路计数器的当前计数值
									HANDLE	hDevice,			// 设备对象句柄,它由CreateDevice函数创建
									PULONG	pCNTVal,			// 返回计数值
									ULONG	ulChannel);			// 通道选择[0-2]
	
	//####################### 数字I/O输入输出函数 #################################
	BOOL DEVAPI FAR PASCAL USB2832_GetDeviceDI(					// 取得开关量状态     
									HANDLE hDevice,				// 设备句柄,它应由CreateDevice函数创建								        
									BYTE bDISts[8]);			// 开关输入状态(注意: 必须定义为8个字节元素的数组)

    BOOL DEVAPI FAR PASCAL USB2832_SetDeviceDO(					// 输出开关量状态
									HANDLE hDevice,				// 设备句柄,它应由CreateDevice函数创建								        
									BYTE bDOSts[8]);			// 开关输出状态(注意: 必须定义为8个字节元素的数组)

	//############################################################################
	BOOL DEVAPI FAR PASCAL USB2832_GetDevVersion(				// 获取设备固件及程序版本
									HANDLE hDevice,				// 设备对象句柄,它由CreateDevice函数创建
									PULONG pulFmwVersion,		// 固件版本
									PULONG pulDriverVersion);	// 驱动版本

   	//########################## 文件操作函数 ####################################
    HANDLE DEVAPI FAR PASCAL USB2832_CreateFileObject(			// 创建文件对象
									HANDLE hDevice,				// 设备句柄,它应由CreateDevice函数创建
									LPCTSTR strFileName,		// 路径及文件名
									int Mode);					// 文件操作方式

    BOOL DEVAPI FAR PASCAL USB2832_WriteFile(					// 保存用户空间中数据到磁盘文件
									HANDLE hFileObject,			// 文件句柄,它应由CreateFileObject函数创建
									PVOID pDataBuffer,			// 用户数据空间地址
									LONG nWriteSizeBytes);		// 缓冲区大小(字节)

    BOOL DEVAPI FAR PASCAL USB2832_ReadFile(					// 从磁盘文件中读取数据到用户空间
									HANDLE hFileObject,			// 文件句柄,它应由CreateFileObject函数创建
									PVOID pDataBuffer,			// 接受文件数据的用户内存缓冲区
									LONG OffsetBytes,			// 从文件前端开始的偏移位置
									LONG nReadSizeBytes);		// 从偏移位置开始读的字节数

	BOOL DEVAPI FAR PASCAL USB2832_SetFileOffset(				// 设置文件偏移指针
									HANDLE hFileObject,			// 文件句柄,它应由CreateFileObject函数创建
									LONG nOffsetBytes);			// 文件偏移位置（以字为单位）  

	ULONGLONG DEVAPI FAR PASCAL USB2832_GetFileLength(HANDLE hFileObject); // 取得指定文件长度（字节）

    BOOL DEVAPI FAR PASCAL USB2832_ReleaseFile(HANDLE hFileObject);
    LONGLONG DEVAPI FAR PASCAL USB2832_GetDiskFreeBytes(		// 获得指定盘符的磁盘空间(注意使用64位变量)
								   LPCTSTR strDiskName);		// 盘符名,如C盘为"C:\\", D盘为"D:\\"

	//############################ 线程操作函数 ################################
	HANDLE DEVAPI FAR PASCAL USB2832_CreateSystemEvent(void); 	// 创建内核系统事件对象
	BOOL DEVAPI FAR PASCAL USB2832_ReleaseSystemEvent(HANDLE hEvent); // 释放内核事件对象
	BOOL DEVAPI FAR PASCAL USB2832_CreateVBThread(HANDLE* hThread, LPTHREAD_START_ROUTINE RoutineAddr);
	BOOL DEVAPI FAR PASCAL USB2832_TerminateVBThread(HANDLE hThread);

	//################# 其他附加函数 ########################
	BOOL DEVAPI FAR PASCAL USB2832_kbhit(void); // 探测用户是否有击键动作(在控制台应用程序Console中且在非VC语言中)
	char DEVAPI FAR PASCAL USB2832_getch(void); // 等待并获取用户击键值(在控制台应用程序Console中有效)

	BOOL DEVAPI FAR PASCAL USB2832_SaveParaInt(HANDLE hDevice, LPCTSTR strParaName, int nValue); // 将整型数据保存到注册表中(Device-x\Others)
	UINT DEVAPI FAR PASCAL USB2832_LoadParaInt(HANDLE hDevice, LPCTSTR strParaName, int nDefaultVal); // 将整型数据从注册表中回读出来(Device-x\Others)
	BOOL DEVAPI FAR PASCAL USB2832_SaveParaString(HANDLE hDevice, LPCTSTR strParaName, LPCTSTR strParaVal); // 将字符串数据保存到注册表中(Device-x\Others)
	BOOL DEVAPI FAR PASCAL USB2832_LoadParaString(HANDLE hDevice, LPCTSTR strParaName, LPTSTR strParaVal, LPCTSTR strDefaultVal); // 将字符串数据从注册表中回读出来(Device-x\Others)

#ifdef __cplusplus
}
#endif

//#################### 辅助常量 #####################

const long USB2832_MAX_AD_CHANNELS = 16;

#ifndef _USB2832_FIFO_LENGTH_
#define _USB2832_FIFO_LENGTH_
// 本卡可以支持的各种FIFO存储器的长度(点)
const long FIFO_IDT7202_LENGTH				= 1024;
const long FIFO_IDT7203_LENGTH				= 2048;
const long FIFO_IDT7204_LENGTH				= 4096;
const long FIFO_IDT7205_LENGTH				= 8192;
const long FIFO_IDT7206_LENGTH				= 16384;
const long FIFO_IDT7207_LENGTH				= 32768;
#endif; // _USB2832_FIFO_LENGTH_

// 自动包含驱动函数导入库
#ifndef _USB2832_DRIVER_
	#pragma comment(lib, "USB2832.lib")
	#pragma message("======== Welcome to use our art company product!")
	#pragma message("======== Automatically linking with USB2832.dll...")
	#pragma message("======== Successfully linked with USB2832.dll")
#endif

#endif; // _USB2832_DEVICE_