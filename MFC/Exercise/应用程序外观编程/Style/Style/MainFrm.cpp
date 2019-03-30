
// MainFrm.cpp : CMainFrame 类的实现
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
	
	ID_SEPARATOR,           // 状态行指示器
    IDS_TIMER,
	IDS_PROGRESS,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO:  在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

extern CStyleApp theAPP;  //声明这个变量是在外部的源文件中定义的
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO:  如果不需要可停靠工具栏，则删除这三行
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
	SetTimer(1, 1000, NULL);//设定1000ms的定时器

	if (!m_newToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_RIGHT | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_newToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	m_newToolBar.EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_newToolBar);
	//状态栏

	CTime t = CTime::GetCurrentTime();//获取当前时间
	CString str = t.Format("%H:%M:%S");
	CClientDC dc(this);
	CSize sz = dc.GetTextExtent(str);
	int index = 0;
	index = m_wndStatusBar.CommandToIndex(IDS_TIMER);//获得时钟栏在状态指示器数组中的位置
	m_wndStatusBar.SetPaneInfo(index, IDS_TIMER, SBPS_NORMAL, sz.cx);
	m_wndStatusBar.SetPaneText(index,str);

	//创建进度栏
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
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	//cs.cx = 300;   //修改窗口大小
	//cs.cy = 200;
	//cs.style &= ~FWS_ADDTOTITLE;
	//cs.style = WS_OVERLAPPEDWINDOW;

	//cs.lpszName =_T("HIT");   //修改窗口名称
	//方式一 重新注册窗口改变光标图标和背景
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
	//方式二 用全局函数
	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, 0, 0, LoadIcon(NULL, IDI_WARNING));
	return TRUE;
}

// CMainFrame 诊断

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


// CMainFrame 消息处理程序



void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	static int index=1;
	SetClassLong(m_hWnd, GCL_HICON, LONG(m_hIcons[index]));
	index = ++index % 3;

	CTime t = CTime::GetCurrentTime();//获取当前时间
	CString str = t.Format("%H:%M:%S");
	CClientDC dc(this);
	CSize sz = dc.GetTextExtent(str);
	//index = m_wndStatusBar.CommandToIndex(IDS_TIMER);//获得时钟栏在状态指示器数组中的位置
	m_wndStatusBar.SetPaneInfo(1, IDS_TIMER, SBPS_NORMAL, sz.cx);
	m_wndStatusBar.SetPaneText(1, str);

	m_Progress.StepIt();//进度栏按一定步长移动
	CFrameWnd::OnTimer(nIDEvent);
}


void CMainFrame::OnTest()
{
	// TODO:  在此添加命令处理程序代码
	MessageBox("Test");
}


void CMainFrame::OnViewNewtool()
{
	// TODO:  在此添加命令处理程序代码
	//方式一 显示工具栏
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
	//方式二 显示工具栏
	ShowControlBar(&m_newToolBar, !m_newToolBar.IsWindowVisible(), FALSE);
}


void CMainFrame::OnUpdateViewNewtool(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
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
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CFrameWnd::OnPaint()
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
