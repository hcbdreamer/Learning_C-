
// menu1View.cpp : Cmenu1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "menu1.h"
#endif

#include "menu1Doc.h"
#include "menu1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmenu1View

IMPLEMENT_DYNCREATE(Cmenu1View, CView)

BEGIN_MESSAGE_MAP(Cmenu1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()
ON_COMMAND(IDM_SHOW, &Cmenu1View::OnShow)
END_MESSAGE_MAP()

// Cmenu1View ����/����

Cmenu1View::Cmenu1View()
{
	// TODO:  �ڴ˴���ӹ������

}

Cmenu1View::~Cmenu1View()
{
}

BOOL Cmenu1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cmenu1View ����

void Cmenu1View::OnDraw(CDC* /*pDC*/)
{
	Cmenu1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cmenu1View ��ӡ

BOOL Cmenu1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cmenu1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cmenu1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// Cmenu1View ���

#ifdef _DEBUG
void Cmenu1View::AssertValid() const
{
	CView::AssertValid();
}

void Cmenu1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cmenu1Doc* Cmenu1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmenu1Doc)));
	return (Cmenu1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmenu1View ��Ϣ�������


//void Cmenu1View::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	CMenu menu;
//
//	CView::OnLButtonDown(nFlags, point);
//}


void Cmenu1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);

	CMenu *P_popmenu=menu.GetSubMenu(0);
	ClientToScreen(&point);
	//P_popmenu->TrackPopupMenu(TPM_LEFTBUTTON | TPM_RIGHTBUTTON, point.x, point.y,this );       //��view��������ʾ
	P_popmenu->TrackPopupMenu(TPM_LEFTBUTTON | TPM_RIGHTBUTTON, point.x, point.y,GetParent());   //��Mainframe��������ʾ
	CView::OnRButtonDown(nFlags, point);
}


void Cmenu1View::OnShow()
{
	// TODO:  �ڴ���������������
	MessageBox("View Show");//�Ӵ���ӵ�и����ȵ���Ӧ���ᣬ��view->cMainFrame˳��
}
