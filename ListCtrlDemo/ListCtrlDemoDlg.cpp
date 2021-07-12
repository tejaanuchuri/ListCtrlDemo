
// ListCtrlDemoDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ListCtrlDemo.h"
#include "ListCtrlDemoDlg.h"
#include "afxdialogex.h"


#include "odbcinst.h"
#include "afxdb.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CListCtrlDemoDlg dialog



CListCtrlDemoDlg::CListCtrlDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LISTCTRLDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DATA, m_list);
}

BEGIN_MESSAGE_MAP(CListCtrlDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CListCtrlDemoDlg message handlers

BOOL CListCtrlDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	ListView_SetExtendedListViewStyle(m_list, LVS_EX_GRIDLINES);
	m_list.InsertColumn(
		0,              // Rank/order of item
		L"ID",          // Caption for this header
		LVCFMT_LEFT,    // Relative position of items under header
		100);           // Width of items under header

	m_list.InsertColumn(1, L"Name", LVCFMT_CENTER, 80);
	m_list.InsertColumn(2, L"Age", LVCFMT_LEFT, 100);
	m_list.InsertColumn(3, L"Address", LVCFMT_LEFT, 80);

	int nItem;

	nItem = m_list.InsertItem(0, L"1");
	m_list.SetItemText(nItem, 1, L"Mark");
	m_list.SetItemText(nItem, 2, L"45");
	m_list.SetItemText(nItem, 3, L"Address 1");

	nItem = m_list.InsertItem(0, L"2");
	m_list.SetItemText(nItem, 1, L"Allan");
	m_list.SetItemText(nItem, 2, L"29");
	m_list.SetItemText(nItem, 3, L"Address 2");

	nItem = m_list.InsertItem(0, L"3");
	m_list.SetItemText(nItem, 1, L"Ajay");
	m_list.SetItemText(nItem, 2, L"37");
	m_list.SetItemText(nItem, 3, L"Address 3");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CListCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CListCtrlDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CListCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

