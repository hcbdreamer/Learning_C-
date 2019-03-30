
// menu2View.cpp : Cmenu2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "menu2.h"
#endif

#include "menu2Doc.h"
#include "menu2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmenu2View

IMPLEMENT_DYNCREATE(Cmenu2View, CView)

BEGIN_MESSAGE_MAP(Cmenu2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_COMMAND(IDM_PHONE1, &Cmenu2View::OnPhone1)
	ON_COMMAND(IDM_PHONE2, &Cmenu2View::OnPhone2)
	ON_COMMAND(IDM_PHONE3, &Cmenu2View::OnPhone3)
	ON_COMMAND(IDM_PHONE4, &Cmenu2View::OnPhone4)
END_MESSAGE_MAP()

// Cmenu2View 构造/析构

Cmenu2View::Cmenu2View()
{
	// TODO:  在此处添加构造代码

	m_nIndex = -1;
	m_strLine = "";
}

Cmenu2View::~Cmenu2View()
{
}

BOOL Cmenu2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cmenu2View 绘制

void Cmenu2View::OnDraw(CDC* /*pDC*/)
{
	Cmenu2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// Cmenu2View 打印

BOOL Cmenu2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cmenu2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void Cmenu2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// Cmenu2View 诊断

#ifdef _DEBUG
void Cmenu2View::AssertValid() const
{
	CView::AssertValid();
}

void Cmenu2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cmenu2Doc* Cmenu2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmenu2Doc)));
	return (Cmenu2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmenu2View 消息处理程序


void Cmenu2View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	if (0x0d == nChar)
	{
		if (0 == ++m_nIndex)
		{
			m_menu.CreatePopupMenu();
			GetParent()->GetMenu()->AppendMenuA(MF_POPUP, UINT(m_menu.m_hMenu), "PhoneBook");//view类中没有菜单，所以无法调用GetMenu().只能父类的指针
			GetParent()->DrawMenuBar();
		}
		m_menu.AppendMenuA(MF_STRING,IDM_PHONE1+m_nIndex, m_strLine.Left(m_strLine.Find(' ')));
		m_strArray.Add(m_strLine);
		m_strLine.Empty();
		Invalidate();   //使整个窗口客户区无效
	}
	else
	{
		m_strLine += char(nChar); //孙鑫视频里m_strLine+=nChar编译报错
		dc.TextOutA(0, 0, m_strLine);
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void Cmenu2View::OnPhone1()
{
	// TODO:  在此添加命令处理程序代码
	CClientDC dc(this);
	dc.TextOutA(0, 0,m_strArray.GetAt(0));
}


void Cmenu2View::OnPhone2()
{
	// TODO:  在此添加命令处理程序代码
	CClientDC dc(this);
	dc.TextOutA(0, 0, m_strArray.GetAt(1));
}


void Cmenu2View::OnPhone3()
{
	// TODO:  在此添加命令处理程序代码
	CClientDC dc(this);
	dc.TextOutA(0, 0, m_strArray.GetAt(2));
}


void Cmenu2View::OnPhone4()
{
	// TODO:  在此添加命令处理程序代码
	CClientDC dc(this);
	dc.TextOutA(0, 0, m_strArray.GetAt(3));
}
