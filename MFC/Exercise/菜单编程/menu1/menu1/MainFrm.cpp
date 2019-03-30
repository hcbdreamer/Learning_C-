
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "menu1.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_TEST, &CMainFrame::OnTest)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, &CMainFrame::OnUpdateEditCut)
	ON_UPDATE_COMMAND_UI(ID_FILE_NEW, &CMainFrame::OnUpdateFileNew)
//	ON_UPDATE_COMMAND_UI(IDR_MENU1, &CMainFrame::OnUpdateIdrMenu1)
ON_COMMAND(IDM_SHOW, &CMainFrame::OnShow)
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

	//m_bAutoMenuEnable = FALSE;
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
m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));

// TODO:  如果不需要可停靠工具栏，则删除这三行
m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
EnableDocking(CBRS_ALIGN_ANY);
DockControlBar(&m_wndToolBar);

//GetMenu()->GetSubMenu(0)->CheckMenuItem(0, MF_BYPOSITION | MF_CHECKED);
//创建菜单标识、缺省菜单以及图形标记菜单
/*CMenu *pMenu = GetMenu();
pMenu->GetSubMenu(0)->CheckMenuItem(ID_FILE_NEW,MF_BYCOMMAND|MF_CHECKED);  //用ID创建菜单标识
pMenu->GetSubMenu(0)->SetDefaultItem(1, TRUE);  //设置缺省菜单
//CBitmap bitmap;

CString str;
str.Format(_T("x=%d,y=%d"), GetSystemMetrics(SM_CXMENUCHECK), GetSystemMetrics(SM_CYMENUCHECK));//将内容按一定的格式化放到str对象中,
//GetSystemMetrics()取出系统图形标记的宽度和高度
MessageBox(str);
m_bitmap.LoadBitmapW(IDB_BITMAP1);    //加载位图
GetMenu()->GetSubMenu(0)->SetMenuItemBitmaps(0, MF_BYPOSITION, &m_bitmap, &m_bitmap);  //创建图形标记菜单*/

//设置某一菜单项变灰失效
/*CMenu *pMenu = GetMenu();
CMenu *subMenu = pMenu->GetSubMenu(0);
subMenu->EnableMenuItem(1, MF_BYPOSITION | MF_DISABLED | MF_GRAYED);*/

//更换菜单
SetMenu(NULL);//取消原菜单
CMenu menu;
menu.LoadMenu(IDR_MAINFRAME);
SetMenu(&menu);
menu.Detach();
return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CFrameWnd::PreCreateWindow(cs))
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


// CMainFrame 消息处理程序



void CMainFrame::OnTest()
{
	// TODO:  在此添加命令处理程序代码
	MessageBox(_T("MainFrame Clicked!"));
}


void CMainFrame::OnUpdateEditCut(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable();
}


void CMainFrame::OnUpdateFileNew(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	/*if (ID_FILE_NEW == pCmdUI->m_nID)
	{
		pCmdUI->Enable(FALSE);
	}*/
	if (0 == pCmdUI->m_nIndex)
	{
		pCmdUI->Enable(FALSE);
	}
	
}


//void CMainFrame::OnUpdateIdrMenu1(CCmdUI *pCmdUI)
//{
//	// TODO:  在此添加命令更新用户界面处理程序代码
//}


void CMainFrame::OnShow()
{
	// TODO:  在此添加命令处理程序代码
	MessageBox("MainFrame Show");
}
