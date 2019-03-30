
// textView.cpp : CtextView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "text.h"
#endif

#include "textDoc.h"
#include "textView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtextView

IMPLEMENT_DYNCREATE(CtextView, CView)

BEGIN_MESSAGE_MAP(CtextView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CtextView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CtextView 构造/析构

CtextView::CtextView()
	: m_strLine(_T(""))
	, m_ptOrigin2(0)
{
	// TODO:  在此处添加构造代码
	m_strLine = "";
	m_ptOrigin2 = 0;

}

CtextView::~CtextView()
{
}

BOOL CtextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CtextView 绘制

void CtextView::OnDraw(CDC* pDC)
{
	CtextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString str;
	str = "哈工大";
	pDC->TextOut(50, 50, str);
	CSize sz = pDC->GetTextExtent(str);
	str.LoadString(IDS_HIT);
	pDC->TextOut(0, 200, str);
	pDC->BeginPath();
	pDC->Rectangle(50, 50, 50 + sz.cx, 50 + sz.cy);
	pDC->EndPath();
	pDC->SelectClipPath(RGN_DIFF);
	for (int i = 0; i < 300; i += 10)
	{
		pDC->MoveTo(0, i);
		pDC->LineTo(300, i);
		pDC->MoveTo(i, 0);
		pDC->LineTo(i, 300);
	}
	// TODO:  在此处为本机数据添加绘制代码
}


// CtextView 打印


void CtextView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CtextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CtextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CtextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

void CtextView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CtextView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CtextView 诊断

#ifdef _DEBUG
void CtextView::AssertValid() const
{
	CView::AssertValid();
}

void CtextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtextDoc* CtextView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtextDoc)));
	return (CtextDoc*)m_pDocument;
}
#endif //_DEBUG


// CtextView 消息处理程序


int CtextView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	// TODO:  在此添加您专用的创建代码
	CreateSolidCaret(tm.tmAveCharWidth/8, tm.tmHeight);
	//CBitmap bitmap;
	//bitmap.LoadBitmap(IDB_BITMAP1);
	//CreateCaret(&bitmap);
	ShowCaret();
	//SetTimer(1, 100, NULL);
	return 0;
}


void CtextView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CFont font;
	font.CreatePointFont(300,"华文行楷",NULL);
	CFont *pOldFont = dc.SelectObject(&font);
	dc.SelectObject(&font);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	if (0x0d == nChar)
	{
		m_strLine.Empty();
		m_ptOrigin2.y += tm.tmHeight;
	}
	else if (0x08 == nChar)
	{
		COLORREF clr = dc.SetTextColor(dc.GetBkColor());
		dc.TextOut(m_ptOrigin2.x, m_ptOrigin2.y, m_strLine);
		m_strLine = m_strLine.Left(m_strLine.GetLength() - 1);
		dc.SetTextColor(clr);
	}
	else
	{
		m_strLine+=char(nChar);
	}
	CSize sz = dc.GetTextExtent(m_strLine);
	CPoint pt;
	pt.x = m_ptOrigin2.x+sz.cx;
	pt.y = m_ptOrigin2.y;
	SetCaretPos(pt);
	dc.TextOut(m_ptOrigin2.x, m_ptOrigin2.y, m_strLine);
	dc.SelectObject(pOldFont);

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CtextView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	SetCaretPos(point);
	m_strLine.Empty();
	m_ptOrigin2 = point;
	CView::OnLButtonDown(nFlags, point);
}
