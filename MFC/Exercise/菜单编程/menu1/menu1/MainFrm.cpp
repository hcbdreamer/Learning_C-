
// MainFrm.cpp : CMainFrame ���ʵ��
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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{

	//m_bAutoMenuEnable = FALSE;
	// TODO:  �ڴ���ӳ�Ա��ʼ������
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
	TRACE0("δ�ܴ���������\n");
	return -1;      // δ�ܴ���
}

if (!m_wndStatusBar.Create(this))
{
	TRACE0("δ�ܴ���״̬��\n");
	return -1;      // δ�ܴ���
}
m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));

// TODO:  �������Ҫ��ͣ������������ɾ��������
m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
EnableDocking(CBRS_ALIGN_ANY);
DockControlBar(&m_wndToolBar);

//GetMenu()->GetSubMenu(0)->CheckMenuItem(0, MF_BYPOSITION | MF_CHECKED);
//�����˵���ʶ��ȱʡ�˵��Լ�ͼ�α�ǲ˵�
/*CMenu *pMenu = GetMenu();
pMenu->GetSubMenu(0)->CheckMenuItem(ID_FILE_NEW,MF_BYCOMMAND|MF_CHECKED);  //��ID�����˵���ʶ
pMenu->GetSubMenu(0)->SetDefaultItem(1, TRUE);  //����ȱʡ�˵�
//CBitmap bitmap;

CString str;
str.Format(_T("x=%d,y=%d"), GetSystemMetrics(SM_CXMENUCHECK), GetSystemMetrics(SM_CYMENUCHECK));//�����ݰ�һ���ĸ�ʽ���ŵ�str������,
//GetSystemMetrics()ȡ��ϵͳͼ�α�ǵĿ�Ⱥ͸߶�
MessageBox(str);
m_bitmap.LoadBitmapW(IDB_BITMAP1);    //����λͼ
GetMenu()->GetSubMenu(0)->SetMenuItemBitmaps(0, MF_BYPOSITION, &m_bitmap, &m_bitmap);  //����ͼ�α�ǲ˵�*/

//����ĳһ�˵�����ʧЧ
/*CMenu *pMenu = GetMenu();
CMenu *subMenu = pMenu->GetSubMenu(0);
subMenu->EnableMenuItem(1, MF_BYPOSITION | MF_DISABLED | MF_GRAYED);*/

//�����˵�
SetMenu(NULL);//ȡ��ԭ�˵�
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
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

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



void CMainFrame::OnTest()
{
	// TODO:  �ڴ���������������
	MessageBox(_T("MainFrame Clicked!"));
}


void CMainFrame::OnUpdateEditCut(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->Enable();
}


void CMainFrame::OnUpdateFileNew(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
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
//	// TODO:  �ڴ������������û����洦��������
//}


void CMainFrame::OnShow()
{
	// TODO:  �ڴ���������������
	MessageBox("MainFrame Show");
}
