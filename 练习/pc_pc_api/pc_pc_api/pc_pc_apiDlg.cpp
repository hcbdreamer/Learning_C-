
// pc_pc_apiDlg.cpp : 实现文件
//
#include "stdafx.h"
#include "pc_pc_api.h"
#include "pc_pc_apiDlg.h"
//#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



const CM_RECEIVE = WM_USER + 100;
OVERLAPPED tOverLaped = { 0 };
OVERLAPPED wOverLaped = { 0 };
OVERLAPPED rOverLaped = { 0 };
BOOL IsFun = TRUE;
BOOL IsStop = FALSE;

DWORD ThreadFunction(LPVOID pParam)
{
	DWORD dwEvtMask, dwResult;
	tOverLaped.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	while (IsFun)
	{
		WaitCommEvent(((Cpc_pc_apiDlg*)AfxGetMainWnd())->hCom, &dwEvtMask, &tOverLaped);
		dwResult = WaitForDebugEvent(tOverLaped.hEvent, 100);
		switch (dwResult)
		{
		case WAIT_OBJECT_0:
			switch (dwEvtMask)
			{
			case EV_RXCHAR:
			{
				if (IsStop)
				{
					IsStop = FALSE;
				::PostMessage(AfxGetMainWnd()->m_hWnd, CM_RECEIVE, 0, (LPARAM)EV_RXCHAR);

				}
				break;
			}
			}
		}
		break;
	}
	return 0;

}
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


// Cpc_pc_apiDlg 对话框



Cpc_pc_apiDlg::Cpc_pc_apiDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cpc_pc_apiDlg::IDD, pParent)
	, m_strReceive(_T(""))
	, m_strSend(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cpc_pc_apiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_receive, m_strReceive);
	DDX_Control(pDX, IDC_send, m_strSend);
}

BEGIN_MESSAGE_MAP(Cpc_pc_apiDlg, CDialogEx)
		ON_WM_SYSCOMMAND()
			ON_WM_PAINT()
			ON_MESSAGE(CM_RECEIVE, OnRecieveData)
		ON_WM_QUERYDRAGICON()
			//ON_BN_CLICKED(IDC_BUTTON1, &Cpc_pc_apiDlg::OnBnClickedButton1)
			ON_BN_CLICKED(IDOK, &Cpc_pc_apiDlg::OnBnClickedOk)
			ON_NOTIFY(BCN_DROPDOWN, IDOK, &Cpc_pc_apiDlg::OnOk)
			ON_BN_CLICKED(IDCANCEL, &Cpc_pc_apiDlg::OnCancel)
END_MESSAGE_MAP()


// Cpc_pc_apiDlg 消息处理程序

BOOL Cpc_pc_apiDlg::OnInitDialog()
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	CSeriesPort();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cpc_pc_apiDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cpc_pc_apiDlg::OnPaint()
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
HCURSOR Cpc_pc_apiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void Cpc_pc_apiDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void Cpc_pc_apiDlg::OnOk()
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	m_strReceive = m_strSend;
	DWORD res;
	DWORD factdata = 0;
	wOverLaped.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);//创建一个事件对象
	IsStop = FALSE;
	if (WriteFile(hCom, m_strSend, m_strSend.GetLength(), &factdata, &wOverLaped))//开始发送数据
	{
		IsStop = TRUE;
	}
	else
	{
		res = WaitForSingleObject(wOverLaped.hEvent, 5000); //延时5秒,等待数据发送
		if (WAIT_OBJECT_0 == res)//如果事件处于有信号状态,表示发送完成
		{
			IsStop = TRUE;
		}
		else
			IsStop = FALSE;
		Sleep(1000); //延时1000毫秒钟		
	}
	
}


void Cpc_pc_apiDlg::OnCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CloseHandle(hCom);
	CDialogEx::OnCancel();
}

void CPc_pc_apiDlg::CSeriesPort()//配置并打开串口
{
	hCom = CreateFile("COM1",  //打开串口1
		GENERIC_READ | GENERIC_WRITE, //允许读和写操作
		0,  //独占方式
		NULL,
		OPEN_EXISTING, //打开一个存在的串口
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, //异步方式打开
		NULL
		);
	if (hCom == INVALID_HANDLE_VALUE)
	{
		MessageBox("端口打开失败.");
		return;
	}

	SetupComm(hCom, 1024, 1024); //设置发送和接收缓冲区大小
	//设置串口信息
	DCB dcb;
	GetCommState(hCom, &dcb);
	dcb.BaudRate = 9600;
	dcb.fBinary = TRUE;
	dcb.fParity = TRUE;
	dcb.ByteSize = 8;
	dcb.Parity = ODDPARITY;
	dcb.StopBits = ONESTOPBIT;
	if (!SetCommState(hCom, &dcb))
	{
		MessageBox("掩码设置失败.", "提示");
		return;
	}

	if (!SetCommMask(hCom, EV_RXCHAR | EV_TXEMPTY))
	{
		MessageBox("掩码设置失败.", "提示");
		return;
	}
	DWORD param;
	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadFunction, &param, 0, &dwThreadID);
	if (hThread == INVALID_HANDLE_VALUE)
	{
		MessageBox("线程创建失败.", "提示", 64);
		return;
	}
	IsFun = TRUE;
}
//自定义消息处理函数,用于接收消息
void CPc_pc_apiDlg::OnRecieveData(WPARAM wParam, LPARAM lParam)
{
	DWORD res, factbyte;
	memset(DataBuffer, 0, 1024); //初始化数据缓冲区
	COMSTAT rst;
	ClearCommError(hCom, &res, &rst);//清空串口错误标志,记录当前通信状态
	rOverLaped.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL); //创建一个事件对象
	if (ReadFile(hCom, DataBuffer, rst.cbInQue, &factbyte, &rOverLaped))  //读取数据到缓冲区中
	{
		DataBuffer[rst.cbInQue] = 0;
		IsStop = FALSE;
	}
	else
	{
		res = WaitForSingleObject(rOverLaped.hEvent, 5000);
	}
	IsStop = FALSE;
	m_strReceive += DataBuffer;
	UpdateData(false);
}