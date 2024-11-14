#if !defined(AFX_HISTOGRAMCTRL_H__A1446DDE_3456_47A9_BA8E_D4F048F3325A__INCLUDED_)
#define AFX_HISTOGRAMCTRL_H__A1446DDE_3456_47A9_BA8E_D4F048F3325A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HistogramCtrl.h : header file
//

#include "AfxTempl.h"
/////////////////////////////////////////////////////////////////////////////
// CHistogramCtrl window
#define  DATA_NUM 200
class CHistogramCtrl : public CWnd
{
// Construction
public:
	CHistogramCtrl();

// Attributes
public:
	typedef enum {LOW_SPEED = 3000, NORMAL_SPEED = 1000, HIGH_SPEED = 500, IDLE = 0} SPEED;

// Operations
public:
	BOOL Create(DWORD dwStyle, const RECT &rect, CWnd *pParentWnd, UINT uID);
	void SetRange(UINT uLower, UINT uUpper);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistogramCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL SetGridsColor(COLORREF cr);
	BOOL SetBkColor(COLORREF cr);
	BOOL Clear();
	void SetPen(int nWidth, COLORREF crColor);
	CHistogramCtrl::SPEED SetSpeed(CHistogramCtrl::SPEED uSpeed);
	void SetPos(float uPos);
	virtual ~CHistogramCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CHistogramCtrl)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	enum SPEED m_uSpeed;
	UINT m_yPos;
	UINT m_yPreviousPos;
	UINT m_uOffset;

	void DrawLine();
	BOOL InvalidateCtrl();
	UINT GetAverage();

	CDC *m_pMemDC;//CDC类定义的是设备上下文对象的类,CDC对象提供处理显示器或打印机等设备上下文的成员函数，以及处理与窗口客户区对应的显示上下文的成员。


	UINT m_uLower;
	UINT m_uUpper;
	CFont m_font;
	CRect m_rcClient;
	CPen m_colorPen;

	int m_nFirstLinePos;

	COLORREF m_crBackGround;
	COLORREF m_crGrids;

	//CList<UINT, UINT&> *m_pList;
	float m_nData[DATA_NUM];
	UINT m_nLength;//实际点的个数
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTOGRAMCTRL_H__A1446DDE_3456_47A9_BA8E_D4F048F3325A__INCLUDED_)
