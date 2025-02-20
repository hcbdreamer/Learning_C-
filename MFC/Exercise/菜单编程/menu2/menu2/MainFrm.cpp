
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "menu2.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(IDM_HELLO, OnHello)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
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

	//动态添加菜单项

	/*CMenu menu;
	menu.CreateMenu();
	//GetMenu()->AppendMenu(MF_POPUP,(UINT)menu.m_hMenu,"HIT");  //AppendMenu():在指定的菜单条、下拉式菜单、子菜单或快捷菜单的末尾追加一个新菜单项的函数。
	GetMenu()->InsertMenuA(3, MF_BYPOSITION | MF_POPUP, (UINT)menu.m_hMenu, "HIT"); //InsertMenu():在指定位置添加新菜单
	menu.AppendMenuA(MF_STRING, IDM_HELLO, "hello");  //在弹出式菜单末尾添加子菜单项
	menu.AppendMenuA(MF_STRING, 112, "weixin");
	menu.AppendMenuA(MF_STRING, 113, "mybole");
	menu.Detach();
	/*GetMenu()->GetSubMenu(0)->AppendMenuA(MF_STRING, 114, "Welcome");
	GetMenu()->GetSubMenu(0)->InsertMenuA(ID_FILE_OPEN, MF_BYCOMMAND | MF_STRING, 115, "weixin");  //插入菜单项
	GetMenu()->DeleteMenu(2, MF_BYPOSITION);   //删除菜单
	GetMenu()->GetSubMenu(2)->DeleteMenu(2, MF_BYPOSITION);*/
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

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
void CMainFrame::OnHello()
{
	MessageBox("Hello");
}

// CMainFrame 消息处理程序

