
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "Style.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_COMMAND(IDM_TEST, &CMainFrame::OnTest)
	ON_COMMAND(IDM_VIEW_NEWTOOL, &CMainFrame::OnViewNewtool)
	ON_UPDATE_COMMAND_UI(IDM_VIEW_NEWTOOL, &CMainFrame::OnUpdateViewNewtool)
	ON_MESSAGE(UM_PROGRESS,&CMainFrame::OnProgress)
	ON_WM_PAINT()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	
	ID_SEPARATOR,           // ״̬��ָʾ��
    IDS_TIMER,
	IDS_PROGRESS,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO:  �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

extern CStyleApp theAPP;  //����������������ⲿ��Դ�ļ��ж����
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO:  �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	//SetWindowLong(m_hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);
	//SetWindowLong(m_hWnd, GWL_STYLE, GetWindowLong(m_hWnd, GWL_STYLE)&~WS_MAXIMIZEBOX);
	//SetClassLong(m_hWnd, GCL_HICON, (LONG)LoadIcon(NULL, IDI_ERROR));
	m_hIcons[0] = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	m_hIcons[1] = LoadIcon(theApp.m_hInstance, MAKEINTRESOURCE(IDI_ICON2));
	m_hIcons[2] = LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON3));

	SetClassLong(m_hWnd, GCL_HICON, (LONG)m_hIcons[0]);
	SetTimer(1, 1000, NULL);//�趨1000ms�Ķ�ʱ��

	if (!m_newToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_RIGHT | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_newToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	m_newToolBar.EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_newToolBar);
	//״̬��

	CTime t = CTime::GetCurrentTime();//��ȡ��ǰʱ��
	CString str = t.Format("%H:%M:%S");
	CClientDC dc(this);
	CSize sz = dc.GetTextExtent(str);
	int index = 0;
	index = m_wndStatusBar.CommandToIndex(IDS_TIMER);//���ʱ������״ָ̬ʾ�������е�λ��
	m_wndStatusBar.SetPaneInfo(index, IDS_TIMER, SBPS_NORMAL, sz.cx);
	m_wndStatusBar.SetPaneText(index,str);

	//����������
	/*CRect rect;
	m_wndStatusBar.GetItemRect(2, &rect);
	//m_Progress.Create(WS_CHILD | WS_VISIBLE|PBS_VERTICAL, CRect(100, 100, 200, 120), this, 123);
	m_Progress.Create(WS_CHILD | WS_VISIBLE, rect, &m_wndStatusBar, 123);
	m_Progress.SetPos(50);*/
	//PostMessage(UM_PROGRESS);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	//cs.cx = 300;   //�޸Ĵ��ڴ�С
	//cs.cy = 200;
	//cs.style &= ~FWS_ADDTOTITLE;
	//cs.style = WS_OVERLAPPEDWINDOW;

	//cs.lpszName =_T("HIT");   //�޸Ĵ�������
	//��ʽһ ����ע�ᴰ�ڸı���ͼ��ͱ���
	/*WNDCLASS wndcls;
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndcls.hCursor = LoadCursor(NULL, IDC_HELP);
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR);
	wndcls.hInstance = AfxGetInstanceHandle();
	wndcls.lpfnWndProc = ::DefWindowProcA;
	wndcls.lpszClassName = "HIT";
	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndcls);
	cs.lpszClass = "HIT";*/
	//��ʽ�� ��ȫ�ֺ���
	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, 0, 0, LoadIcon(NULL, IDI_WARNING));
	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������



void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	static int index=1;
	SetClassLong(m_hWnd, GCL_HICON, LONG(m_hIcons[index]));
	index = ++index % 3;

	CTime t = CTime::GetCurrentTime();//��ȡ��ǰʱ��
	CString str = t.Format("%H:%M:%S");
	CClientDC dc(this);
	CSize sz = dc.GetTextExtent(str);
	//index = m_wndStatusBar.CommandToIndex(IDS_TIMER);//���ʱ������״ָ̬ʾ�������е�λ��
	m_wndStatusBar.SetPaneInfo(1, IDS_TIMER, SBPS_NORMAL, sz.cx);
	m_wndStatusBar.SetPaneText(1, str);

	m_Progress.StepIt();//��������һ�������ƶ�
	CFrameWnd::OnTimer(nIDEvent);
}


void CMainFrame::OnTest()
{
	// TODO:  �ڴ���������������
	MessageBox("Test");
}


void CMainFrame::OnViewNewtool()
{
	// TODO:  �ڴ���������������
	//��ʽһ ��ʾ������
	/*if (m_newToolBar.IsWindowVisible())
	{
		m_newToolBar.ShowWindow(SW_HIDE);
	}
	else
	{
		m_newToolBar.ShowWindow(SW_SHOW);
	}
	RecalcLayout();
	DockControlBar(&m_newToolBar);*/
	//��ʽ�� ��ʾ������
	ShowControlBar(&m_newToolBar, !m_newToolBar.IsWindowVisible(), FALSE);
}


void CMainFrame::OnUpdateViewNewtool(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_newToolBar.IsWindowVisible());
}


LRESULT CMainFrame::OnProgress(WPARAM,LPARAM)
{
	CRect rect;
	m_wndStatusBar.GetItemRect(2, &rect);
	//m_Progress.Create(WS_CHILD | WS_VISIBLE|PBS_VERTICAL, CRect(100, 100, 200, 120), this, 123);
	m_Progress.Create(WS_CHILD | WS_VISIBLE, rect, &m_wndStatusBar, 123);
	m_Progress.SetPos(50);
	return 0;
}

void CMainFrame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CFrameWnd::OnPaint()
    CRect rect;
	m_wndStatusBar.GetItemRect(2, &rect);
	//m_Progress.Create(WS_CHILD | WS_VISIBLE|PBS_VERTICAL, CRect(100, 100, 200, 120), this, 123);
	if (!m_Progress.m_hWnd)
	{
		m_Progress.Create(WS_CHILD | WS_VISIBLE, rect, &m_wndStatusBar, 123);
	}
	else
		m_Progress.MoveWindow(rect);
	m_Progress.SetPos(50);
}
