
// MainFrm.cpp : CMainFrame ���ʵ��
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
	ID_SEPARATOR,           // ״̬��ָʾ��
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

	//��̬��Ӳ˵���

	/*CMenu menu;
	menu.CreateMenu();
	//GetMenu()->AppendMenu(MF_POPUP,(UINT)menu.m_hMenu,"HIT");  //AppendMenu():��ָ���Ĳ˵���������ʽ�˵����Ӳ˵����ݲ˵���ĩβ׷��һ���²˵���ĺ�����
	GetMenu()->InsertMenuA(3, MF_BYPOSITION | MF_POPUP, (UINT)menu.m_hMenu, "HIT"); //InsertMenu():��ָ��λ������²˵�
	menu.AppendMenuA(MF_STRING, IDM_HELLO, "hello");  //�ڵ���ʽ�˵�ĩβ����Ӳ˵���
	menu.AppendMenuA(MF_STRING, 112, "weixin");
	menu.AppendMenuA(MF_STRING, 113, "mybole");
	menu.Detach();
	/*GetMenu()->GetSubMenu(0)->AppendMenuA(MF_STRING, 114, "Welcome");
	GetMenu()->GetSubMenu(0)->InsertMenuA(ID_FILE_OPEN, MF_BYCOMMAND | MF_STRING, 115, "weixin");  //����˵���
	GetMenu()->DeleteMenu(2, MF_BYPOSITION);   //ɾ���˵�
	GetMenu()->GetSubMenu(2)->DeleteMenu(2, MF_BYPOSITION);*/
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
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
void CMainFrame::OnHello()
{
	MessageBox("Hello");
}

// CMainFrame ��Ϣ�������

