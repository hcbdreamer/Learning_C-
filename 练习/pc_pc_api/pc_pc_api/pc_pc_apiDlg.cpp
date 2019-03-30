
// pc_pc_apiDlg.cpp : ʵ���ļ�
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


// Cpc_pc_apiDlg �Ի���



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


// Cpc_pc_apiDlg ��Ϣ�������

BOOL Cpc_pc_apiDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	CSeriesPort();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Cpc_pc_apiDlg::OnPaint()
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
HCURSOR Cpc_pc_apiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void Cpc_pc_apiDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void Cpc_pc_apiDlg::OnOk()
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	m_strReceive = m_strSend;
	DWORD res;
	DWORD factdata = 0;
	wOverLaped.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);//����һ���¼�����
	IsStop = FALSE;
	if (WriteFile(hCom, m_strSend, m_strSend.GetLength(), &factdata, &wOverLaped))//��ʼ��������
	{
		IsStop = TRUE;
	}
	else
	{
		res = WaitForSingleObject(wOverLaped.hEvent, 5000); //��ʱ5��,�ȴ����ݷ���
		if (WAIT_OBJECT_0 == res)//����¼��������ź�״̬,��ʾ�������
		{
			IsStop = TRUE;
		}
		else
			IsStop = FALSE;
		Sleep(1000); //��ʱ1000������		
	}
	
}


void Cpc_pc_apiDlg::OnCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CloseHandle(hCom);
	CDialogEx::OnCancel();
}

void CPc_pc_apiDlg::CSeriesPort()//���ò��򿪴���
{
	hCom = CreateFile("COM1",  //�򿪴���1
		GENERIC_READ | GENERIC_WRITE, //�������д����
		0,  //��ռ��ʽ
		NULL,
		OPEN_EXISTING, //��һ�����ڵĴ���
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, //�첽��ʽ��
		NULL
		);
	if (hCom == INVALID_HANDLE_VALUE)
	{
		MessageBox("�˿ڴ�ʧ��.");
		return;
	}

	SetupComm(hCom, 1024, 1024); //���÷��ͺͽ��ջ�������С
	//���ô�����Ϣ
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
		MessageBox("��������ʧ��.", "��ʾ");
		return;
	}

	if (!SetCommMask(hCom, EV_RXCHAR | EV_TXEMPTY))
	{
		MessageBox("��������ʧ��.", "��ʾ");
		return;
	}
	DWORD param;
	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadFunction, &param, 0, &dwThreadID);
	if (hThread == INVALID_HANDLE_VALUE)
	{
		MessageBox("�̴߳���ʧ��.", "��ʾ", 64);
		return;
	}
	IsFun = TRUE;
}
//�Զ�����Ϣ������,���ڽ�����Ϣ
void CPc_pc_apiDlg::OnRecieveData(WPARAM wParam, LPARAM lParam)
{
	DWORD res, factbyte;
	memset(DataBuffer, 0, 1024); //��ʼ�����ݻ�����
	COMSTAT rst;
	ClearCommError(hCom, &res, &rst);//��մ��ڴ����־,��¼��ǰͨ��״̬
	rOverLaped.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL); //����һ���¼�����
	if (ReadFile(hCom, DataBuffer, rst.cbInQue, &factbyte, &rOverLaped))  //��ȡ���ݵ���������
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