
// menuView.cpp : CmenuView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "menu.h"
#endif

#include "menuDoc.h"
#include "menuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmenuView

IMPLEMENT_DYNCREATE(CmenuView, CView)

BEGIN_MESSAGE_MAP(CmenuView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CmenuView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(IDM_TEST, &CmenuView::OnTest)
END_MESSAGE_MAP()

// CmenuView 构造/析构

CmenuView::CmenuView()
{
	// TODO:  在此处添加构造代码

}

CmenuView::~CmenuView()
{
}

BOOL CmenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CmenuView 绘制

void CmenuView::OnDraw(CDC* /*pDC*/)
{
	CmenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CmenuView 打印


void CmenuView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CmenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CmenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CmenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CmenuView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CmenuView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CmenuView 诊断

#ifdef _DEBUG
void CmenuView::AssertValid() const
{
	CView::AssertValid();
}

void CmenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmenuDoc* CmenuView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmenuDoc)));
	return (CmenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CmenuView 消息处理程序


void CmenuView::OnTest()
{
	// TODO:  在此添加命令处理程序代码
	MessageBox("View clicked!");
}
