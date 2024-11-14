/*
Author:
	Mehdi Mousavi

Email:
	mehdi_mousavi@hotmail.com
	webmaster@modemmania.com

Date of release:
	14th of April 2001

Description:
	The initial idea of doing this code has been put into my mind when my love asked me
	to go to a clinic in order to check out my heart. You know, doctors have got some
	sort of plotters that plots the information obtained from the heart on a piece of
	paper as a histogram. The idea has been dropped into my mind there!

Dedicated to:
	My love, Cindy

Copyright & disclaimer:
	Permission is granted to distribute *unmodified* version of this source code.
	You are entitled to use CHistogramCtrl for both commercial and/or educational
	purposes as far as you keep these comments intact. Please feel free to post
	any additions to the author.
*/

#include "stdafx.h"
//#include "histogram.h"
#include "HistogramCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHistogramCtrl

CHistogramCtrl::CHistogramCtrl()
{
	m_nFirstLinePos = 13;

	m_pMemDC = NULL;
	//m_pList = NULL;
	m_nLength = 0;
	m_uSpeed = IDLE;

	m_crBackGround = RGB(0, 0, 0);
	m_crGrids = RGB(0, 130, 66);

	SetPen(1, RGB(0, 255, 0));
	SetRange(0, 5);
}

CHistogramCtrl::~CHistogramCtrl()
{
	if(m_pMemDC)
		delete m_pMemDC;

	//if(m_pList)
		//delete m_pList;
}


BEGIN_MESSAGE_MAP(CHistogramCtrl, CWnd)
	//{{AFX_MSG_MAP(CHistogramCtrl)
	ON_WM_PAINT()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CHistogramCtrl message handlers


BOOL CHistogramCtrl::Create(DWORD dwStyle, const RECT &rect, CWnd *pParentWnd, UINT uID)
{
	//Postcondition:
	//	Creates a window within the "rect" region of the client screen
	//	Returns TRUE if the function creates the control successfully
	//	or FALSE if it fails.

	BOOL bRet = CWnd::CreateEx(WS_EX_CLIENTEDGE, 
								AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW),
								NULL,
								dwStyle,
								rect.left,
								rect.top,
								rect.right - rect.left,
								rect.bottom - rect.top,
								pParentWnd->GetSafeHwnd(),
								(HMENU)uID);

	if(!bRet)
		return FALSE;

	m_pMemDC = new CDC;
	if(!m_pMemDC)
		return FALSE;

	//m_pList = new CList<UINT, UINT&>;
	//if(!m_pList)
		//return FALSE;

	GetClientRect(m_rcClient);


	VERIFY(m_font.CreateFont(
		12,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_NORMAL,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		"宋体"));                 // lpszFacename

	if(!InvalidateCtrl())
		return FALSE;

	SetSpeed(CHistogramCtrl::NORMAL_SPEED);
	
	return TRUE;
}

void CHistogramCtrl::SetRange(UINT uLower, UINT uUpper)
{
	//ASSERT(uLower && uUpper && uLower < uUpper);
	//Postcondition:
	//	Sets the upper and lower (limits) range
	m_uUpper = uUpper;
	m_uLower = uLower;
	//m_uOffset = uLower - 1;
}

BOOL CHistogramCtrl::InvalidateCtrl()
{
	//Postcondition:
	//	Paints the entire client area of the control
	//	Returns TRUE if it's done successfuly or FALSE if it fails

	CClientDC dc(this);

	if(m_pMemDC->GetSafeHdc())
		return FALSE;

	if(!m_pMemDC->CreateCompatibleDC(&dc))
		return FALSE;

	CBitmap bmp;
	if(!bmp.CreateCompatibleBitmap(&dc, m_rcClient.Width(), m_rcClient.Height()))
		return FALSE;

	if(!m_pMemDC->SelectObject(bmp))
		return FALSE;

	Clear();

	return TRUE;
}
BOOL CHistogramCtrl::Clear()
{
	//Set the background color of the control
	CBrush bkBrush;
	if(!bkBrush.CreateSolidBrush(m_crBackGround))
		return FALSE;
	
	m_pMemDC->FillRect(m_rcClient, &bkBrush);
	
	//Select a specified pen to the device context to draw background lines
	CPen bkLinesPen;
	if(!bkLinesPen.CreatePen(PS_SOLID, 1, m_crGrids))
		return FALSE;
	
	if(!m_pMemDC->SelectObject(bkLinesPen))
		return FALSE;
	
	//Draw background lines
	int nGridX = 20;
	int nGridY = 6;
	double k1 = (m_rcClient.Width()-30) * 1.0/(nGridX-1);
	double k2 = (m_rcClient.Height()-30)*1.0/(nGridY - 1);
	for(register i = 0; i < nGridX  ; i++)//画竖线
	{
	    m_pMemDC->MoveTo(m_rcClient.left +20 + i * k1, m_rcClient.top+20);
		m_pMemDC->LineTo(m_rcClient.left +20 + i * k1, m_rcClient.top+20 +  m_rcClient.Height()-30);
	}
	
	for(register j = 0; j < nGridY; j++)//画横线
	{
		m_pMemDC->MoveTo(m_rcClient.left+20, j*k2 + m_rcClient.top + 20);
		m_pMemDC->LineTo(m_rcClient.left +20 + m_rcClient.Width() - 30, j*k2 + m_rcClient.top + 20);
	}

	//绘制坐标系
	
	//m_pMemDC->MoveTo(5,m_rcClient.bottom - 5);
	//m_pMemDC->LineTo(m_rcClient.Width()-5,m_rcClient.Height() - 5);

	
	//绘制Y轴坐标
	CString strX,strY;
	m_pMemDC->SetBkMode(TRANSPARENT);
	m_pMemDC->SetTextColor(RGB(0,255,0));//蓝色
	m_pMemDC->SelectObject(&m_font);
	for(i = 0; i <nGridY;i++)
	{
		strY.Format("%d",m_uUpper - (m_uUpper -m_uLower  ) * i/(nGridY-1));
		m_pMemDC->TextOut(5,m_rcClient.top + 20 +i * k2,strY);
	}
	strY = "V";
	m_pMemDC->TextOut(5,m_rcClient.top +5,strY);
	//m_yPreviousPos = m_yPos = m_rcClient.bottom + 1;
	
	InvalidateRect(m_rcClient);

	bkBrush.DeleteObject();
	bkLinesPen.DeleteObject();

}

void CHistogramCtrl::OnPaint() 
{
	CPaintDC dc(this);

	if(m_pMemDC->GetSafeHdc())
		dc.BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(), m_pMemDC, 0, 0, SRCCOPY);
}

void CHistogramCtrl::DrawLine()
{
	//Postcondition:
	//	Draws the histogram within the client area of the control
    Clear();
	if(!m_pMemDC->GetSafeHdc())
		return;
	

    //int nDataNum = 200;//总数据数
	double k1 = (m_rcClient.Width()-30)*1.0/(DATA_NUM-1);//每个点之间的间距
	//int nAcutalData = m_pList->GetCount();//实际的点个数
	m_pMemDC->SelectObject(m_colorPen);
	//POSITION p;
	//p = m_pList->GetTailPosition();
    double y ;
	for(register i = 0 ; i<m_nLength-1 ; i++){
        y = m_rcClient.top + 20 + (m_rcClient.Height() -30) * (1 - (m_nData[i]-m_uLower)*1.0 /(m_uUpper - m_uLower));
		m_pMemDC->MoveTo(m_rcClient.left +20 + i* k1, y);
		y = m_rcClient.top + 20 + (m_rcClient.Height() -30) * (1 -(m_nData[i+1]-m_uLower)*1.0 /(m_uUpper - m_uLower));
		m_pMemDC->LineTo(m_rcClient.left +20 + (i+1) * k1, y);
	}
	//m_pMemDC->MoveTo(m_rcClient.left + 20,m_rcClient.top + 20);
	//m_pMemDC->LineTo(m_rcClient.left + 20 + m_rcClient.Width() - 30, m_rcClient.top +20 + m_rcClient.Height() -30);
// 	UINT uAverage = GetAverage();
// 	TRACE("uAverage: %u\r\n", uAverage);
// 	if(uAverage)
// 		m_yPos = m_rcClient.bottom - (uAverage * m_rcClient.bottom / m_uUpper);
// 
// 	if(m_yPreviousPos == (unsigned)m_rcClient.bottom + 1)
// 		m_yPreviousPos = m_yPos;
		
	
	//m_yPreviousPos = m_yPos;
	Invalidate();
}

void CHistogramCtrl::SetPos(float uPos)
{
	//uPos -= m_uOffset;
	//ASSERT(uPos <= m_uUpper && uPos >= m_uLower);
	if(uPos <= m_uUpper && uPos >= m_uLower){
	//Postcondition:
	//	Adds the specified point to a list, so that we
	//	would be able to draw the histogram within the
	//	specified intervals.
	//m_pList->AddHead(uPos);
	if(m_nLength < DATA_NUM)
		m_nData[m_nLength++] = uPos;
	else
	{
		for(int i =0;i<DATA_NUM;i++)
		{
			m_nData[i] = m_nData[i+1];
		}
		m_nData[DATA_NUM - 1] = uPos;
	}
	DrawLine();
	}
}



CHistogramCtrl::SPEED CHistogramCtrl::SetSpeed(enum SPEED uSpeed)
{
	enum SPEED oldSpeed = m_uSpeed;
	m_uSpeed = uSpeed;

	KillTimer(0);

	if(uSpeed != CHistogramCtrl::IDLE)
		SetTimer(0, m_uSpeed, NULL);

	return oldSpeed;
}

void CHistogramCtrl::SetPen(int nWidth, COLORREF crColor)
{
	m_colorPen.DeleteObject();
	m_colorPen.CreatePen(PS_SOLID, nWidth, crColor);
}

BOOL CHistogramCtrl::SetBkColor(COLORREF cr)
{
 	BOOL bRet = FALSE;
// 	enum SPEED oldSpeed = SetSpeed(CHistogramCtrl::IDLE);
// 
// 	m_crBackGround = cr;
// 
// 	CClientDC dc(this);
// 
// 	int oldPos = m_nFirstLinePos;
// 	m_nFirstLinePos = 13;
// 	if(m_pMemDC->DeleteDC())
// 		if(InvalidateCtrl())
// 			bRet = TRUE;
// 
// 	if(!bRet)
// 		m_nFirstLinePos = oldPos;
// 
// 	SetSpeed(oldSpeed);
// 
 	return bRet;
}

BOOL CHistogramCtrl::SetGridsColor(COLORREF cr)
{
 	BOOL bRet = FALSE;
// 	enum SPEED oldSpeed = SetSpeed(CHistogramCtrl::IDLE);
// 
// 	m_crGrids = cr;
// 
// 	CClientDC dc(this);
// 
// 	int oldPos = m_nFirstLinePos;
// 	m_nFirstLinePos = 13;
// 	if(m_pMemDC->DeleteDC())
// 		if(InvalidateCtrl())
// 			bRet = TRUE;
// 
// 	if(!bRet)
// 		m_nFirstLinePos = oldPos;
// 
// 	SetSpeed(oldSpeed);
// 
 	return bRet;
}

UINT CHistogramCtrl::GetAverage()
{
	UINT uCounter = 0, uSum = 0;
// 	while(!m_pList->IsEmpty())
// 	{
// 		uSum += m_pList->RemoveTail();
// 		uCounter++;
// 	}

	return uCounter ? uSum / uCounter : 0;
}