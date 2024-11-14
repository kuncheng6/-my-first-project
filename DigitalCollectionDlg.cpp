// DigitalCollectionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DigitalCollection.h"
#include "DigitalCollectionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDigitalCollectionDlg dialog

CDigitalCollectionDlg::CDigitalCollectionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDigitalCollectionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDigitalCollectionDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDigitalCollectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDigitalCollectionDlg)
	DDX_Control(pDX, IDC_TABTEST, m_tab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDigitalCollectionDlg, CDialog)
	//{{AFX_MSG_MAP(CDigitalCollectionDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TABTEST, OnSelchangeTabtest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDigitalCollectionDlg message handlers

BOOL CDigitalCollectionDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_tab.InsertItem(0,"AI"); 
	m_tab.InsertItem(1,"DI"); 
	m_tab.InsertItem(2,"DO"); 

	m_ai.Create(IDD_AI,GetDlgItem(IDC_TABTEST)); 
	m_di.Create(IDD_DI,GetDlgItem(IDC_TABTEST)); 
	m_do.Create(IDD_DO,GetDlgItem(IDC_TABTEST)); 

	CRect rs; 
	m_tab.GetClientRect(&rs); 
	//调整子对话框在父窗口中的位置 
	rs.top+=20; 
	rs.bottom-=1; 
	rs.left+=1; 
	rs.right-=2; 
	
	//设置子对话框尺寸并移动到指定位置 
	m_ai.MoveWindow(&rs); 
	m_di.MoveWindow(&rs); 
	m_do.MoveWindow(&rs); 

	
	m_ai.ShowWindow(true); 
	m_di.ShowWindow(false); 
	m_do.ShowWindow(false); 
	
	//设置默认的选项卡 
	m_tab.SetCurSel(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDigitalCollectionDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDigitalCollectionDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDigitalCollectionDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDigitalCollectionDlg::OnSelchangeTabtest(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int CurSel = m_tab.GetCurSel(); 
	switch(CurSel) 
	{ 
	case 0: 
		m_ai.ShowWindow(true); 
		m_di.ShowWindow(false); 
		m_do.ShowWindow(false); 
		m_di.Down();
		break; 
	case 1: 
		m_ai.ShowWindow(false); 
		m_di.ShowWindow(true); 
		m_do.ShowWindow(false);
		m_di.On();
		break; 
	case 2: 
		m_ai.ShowWindow(false); 
		m_di.ShowWindow(false); 
		m_do.ShowWindow(true); 
		m_di.Down();
		break; 
	default: 
		; 
	}     
	

	*pResult = 0;
}
