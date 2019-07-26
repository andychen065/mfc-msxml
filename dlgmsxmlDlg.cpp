// dlgmsxmlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "dlgmsxml.h"
#include "dlgmsxmlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#import "msxml6.dll"
using namespace MSXML2;
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
// CDlgmsxmlDlg dialog

CDlgmsxmlDlg::CDlgmsxmlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgmsxmlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgmsxmlDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDlgmsxmlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgmsxmlDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgmsxmlDlg, CDialog)
	//{{AFX_MSG_MAP(CDlgmsxmlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgmsxmlDlg message handlers

BOOL CDlgmsxmlDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDlgmsxmlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDlgmsxmlDlg::OnPaint() 
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
HCURSOR CDlgmsxmlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDlgmsxmlDlg::OnBnClickedOk() 
{
	AfxMessageBox("start");
	//首先初始化COM   
	HRESULT hr;  
	hr = CoInitialize(NULL);   
	//AfxMessageBox("2222");
	if( hr != S_OK )  
	{  
		return;  
	}
	//AfxMessageBox("3333");
	//创建Document对象   
	MSXML2::IXMLDOMDocumentPtr pDoc;  
	hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument)); 
	if( FAILED(hr) )  
	{  
		return;  
	}  
	//AfxMessageBox("4444");
	if( FALSE == pDoc->load(_bstr_t("book.xml")) )  
	{
		return; 
	}
	//AfxMessageBox("555");
	//选择内容的根节点   
	MSXML2::IXMLDOMElementPtr pElem = NULL;  
	pElem = pDoc->selectSingleNode("catalog");  
	//AfxMessageBox("666");
	if(pElem==NULL)  
	{
		return;
	}
	unsigned int nBookNum = pElem->childNodes->length;  
	if( nBookNum == 0)  
	{
		return;
	}
 //AfxMessageBox("7777");
	for(int i=0; i < nBookNum; i++)  
	{  
		//AfxMessageBox("888");
		MSXML2::IXMLDOMNodePtr pBookNode = pElem->childNodes->item[i];  
		if(pBookNode==NULL)  
		{
			return;
		}
		//读取book节点的id属性   
		MSXML2::IXMLDOMNodePtr pId = pBookNode->attributes->getNamedItem("id");
		AfxMessageBox(pId->text);
		//读取book节点下author子节点   
		MSXML2::IXMLDOMNodePtr pAuthorNode = pBookNode->selectSingleNode("author"); 
		
		if(pAuthorNode==NULL)  
		{  
			;
		}  
		else  
		{  
			AfxMessageBox(pAuthorNode->text); 
		}   
		//AfxMessageBox("9999");
	}
}
