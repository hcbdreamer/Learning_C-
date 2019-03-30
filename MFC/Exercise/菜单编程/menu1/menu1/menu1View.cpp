
// menu1View.cpp : Cmenu1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()
ON_COMMAND(IDM_SHOW, &Cmenu1View::OnShow)
END_MESSAGE_MAP()

// Cmenu1View 构造/析构

Cmenu1View::Cmenu1View()
{
	// TODO:  在此处添加构造代码

}

Cmenu1View::~Cmenu1View()
{
}

BOOL Cmenu1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cmenu1View 绘制

void Cmenu1View::OnDraw(CDC* /*pDC*/)
{
	Cmenu1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// Cmenu1View 打印

BOOL Cmenu1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cmenu1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void Cmenu1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// Cmenu1View 诊断

#ifdef _DEBUG
void Cmenu1View::AssertValid() const
{
	CView::AssertValid();
}

void Cmenu1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cmenu1Doc* Cmenu1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmenu1Doc)));
	return (Cmenu1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmenu1View 消息处理程序


//void Cmenu1View::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO:  在此添加消息处理程序代码和/或调用默认值
//	CMenu menu;
//
//	CView::OnLButtonDown(nFlags, point);
//}


void Cmenu1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);

	CMenu *P_popmenu=menu.GetSubMenu(0);
	ClientToScreen(&point);
	//P_popmenu->TrackPopupMenu(TPM_LEFTBUTTON | TPM_RIGHTBUTTON, point.x, point.y,this );       //在view窗口中显示
	P_popmenu->TrackPopupMenu(TPM_LEFTBUTTON | TPM_RIGHTBUTTON, point.x, point.y,GetParent());   //在Mainframe窗口中显示
	CView::OnRButtonDown(nFlags, point);
}


void Cmenu1View::OnShow()
{
	// TODO:  在此添加命令处理程序代码
	MessageBox("View Show");//子窗口拥有更优先的响应机会，即view->cMainFrame顺序
}
