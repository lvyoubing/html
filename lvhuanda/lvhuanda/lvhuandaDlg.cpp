
// lvhuandaDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "lvhuanda.h"
#include "lvhuandaDlg.h"
#include "afxdialogex.h"
#include "string.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// ClvhuandaDlg �Ի���




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


// ClvhuandaDlg ��Ϣ�������

BOOL ClvhuandaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void ClvhuandaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR ClvhuandaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void ClvhuandaDlg::OnBnClickedread()
{
	//
	CFile gpx;
	gpx.Open(L"G:\\����\\export.gpx", CFile::modeRead);
	//�жϴ򿪳ɹ����
	if (!gpx)
	{
		MessageBox(L"��ȡ�ļ�ʧ�ܣ�");
		return;
	}
	else
	{
		MessageBox(L"�ɹ���ȡ��");
	
	}


	CFile html;
	html.Open(L"G:\\����\\data.html", CFile::modeCreate | CFile::modeReadWrite);
	if (!html)
	{
		MessageBox(L"д���ļ�ʧ�ܣ�");
		return;
	}
	else
	{
		MessageBox(L"�ɹ�����html��");
	}



	CFile head;
	head.Open(L"G:\\����\\head.txt", CFile::modeRead);
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
	csv.Open(L"G:\\����\\export.csv",CFile::modeCreate | CFile::modeReadWrite);
	while (I<(L - 94))//
	{
		html.Write("new BMap.Point(", C);
		lon = R.Mid(I + 27, 10);//lon ����
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
	tail.Open(L"G:\\����\\tail.txt", CFile::modeRead);
	char *y;
	int Y = tail.GetLength();
	y = new char[Y + 1];
	y[Y] = 0;
	tail.Read(y, Y);
	html.Write(y, Y);
	brower.Navigate(L"G:\\����\\data.html",NULL,NULL,NULL,NULL);
	gpx.Close();
	html.Close();
	head.Close();
	tail.Close();// TODO: �ڴ���ӿؼ�֪ͨ����������
}
