
// lvhuandaDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "lvhuanda.h"
#include "lvhuandaDlg.h"
#include "afxdialogex.h"
#include "string.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ClvhuandaDlg 对话框




ClvhuandaDlg::ClvhuandaDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ClvhuandaDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ClvhuandaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, browser, brower);
}

BEGIN_MESSAGE_MAP(ClvhuandaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(read, &ClvhuandaDlg::OnBnClickedread)
END_MESSAGE_MAP()


// ClvhuandaDlg 消息处理程序

BOOL ClvhuandaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void ClvhuandaDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void ClvhuandaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR ClvhuandaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void ClvhuandaDlg::OnBnClickedread()
{
	//
	CFile gpx;
	gpx.Open(L"G:\\程序\\export.gpx", CFile::modeRead);
	//判断打开成功与否
	if (!gpx)
	{
		MessageBox(L"读取文件失败！");
		return;
	}
	else
	{
		MessageBox(L"成功读取！");
	
	}


	CFile html;
	html.Open(L"G:\\程序\\data.html", CFile::modeCreate | CFile::modeReadWrite);
	if (!html)
	{
		MessageBox(L"写入文件失败！");
		return;
	}
	else
	{
		MessageBox(L"成功创建html！");
	}



	CFile head;
	head.Open(L"G:\\程序\\head.txt", CFile::modeRead);
	int a;
	a = head.GetLength();
	char *Q;
	Q = new char[a + 1];
	Q[a] = 0;
	head.Read(Q, a);
	int i = a;
	int I = 0;
	CString lat, lon, file, data, time;
	int L = gpx.GetLength();
	char *E;
	E = new char[L + 1];
	E[L] = 0;
	gpx.Read(E, L);
	CString R;
	R = E;
	file = E;
	I = file.Find(L"trkpt", 0);
	CString D = L"new BMap.Point(";
	int C;
	C = D.GetLength();
	html.Write(Q, a);


	CFile csv;
	csv.Open(L"G:\\程序\\export.csv",CFile::modeCreate | CFile::modeReadWrite);
	while (I<(L - 94))//
	{
		html.Write("new BMap.Point(", C);
		lon = R.Mid(I + 27, 10);//lon 经度
		html.Write((char*)(_bstr_t)lon, 10);
		html.Write(L",", 1);
		lat = R.Mid(I + 11, 9);
		html.Write((char*)(_bstr_t)lat, 9);
		html.Write(")", 1);
		if (i != 4979)//
			html.Write(L",", 1);
		else
		{
			html.Write("\r\n", 1);
		}
	     csv.Write((char*)(_bstr_t)lon, 10);
		csv.Write(L",", 1);
		csv.Write((char*)(_bstr_t)lat, 9);
		csv.Write(L",", 1);
		data = R.Mid(I + 50, 10);
		csv.Write((char*)(_bstr_t)data, 10);
		csv.Write(L",", 1);
		time = R.Mid(I + 61, 8);	
		csv.Write((char*)(_bstr_t)time, 8);
		csv.Write(L",", 1);
		csv.Write(L"\r\n", 2);
		I = I + 94;
		i++;
	}
	

	CFile tail;
	tail.Open(L"G:\\程序\\tail.txt", CFile::modeRead);
	char *y;
	int Y = tail.GetLength();
	y = new char[Y + 1];
	y[Y] = 0;
	tail.Read(y, Y);
	html.Write(y, Y);
	brower.Navigate(L"G:\\程序\\data.html",NULL,NULL,NULL,NULL);
	gpx.Close();
	html.Close();
	head.Close();
	tail.Close();// TODO: 在此添加控件通知处理程序代码
}
