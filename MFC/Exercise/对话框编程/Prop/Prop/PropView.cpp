
// PropView.cpp : CPropView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Prop.h"
#endif

#include "PropDoc.h"
#include "PropView.h"
#include "PropSheet.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPropView

IMPLEMENT_DYNCREATE(CPropView, CView)

BEGIN_MESSAGE_MAP(CPropView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_PROPERTYSHEET, &CPropView::OnPropertysheet)
END_MESSAGE_MAP()

// CPropView 构造/析构

CPropView::CPropView()
{
	// TODO:  在此处添加构造代码
	m_ioccupation = -1;
	m_strWorkAdr = "";
	memset(m_bLike, 0, sizeof(m_bLike));//布尔数组初始化
	m_strSalary = "";

}

CPropView::~CPropView()
{
}

BOOL CPropView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPropView 绘制

void CPropView::OnDraw(CDC* pDC)
{
	CPropDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CFont font;
	font.CreatePointFont(300, "华文行楷");

	CFont *pOldFont;
	pOldFont = pDC->SelectObject(&font);

	CString strTemp;
	strTemp = "你的职业：";

	switch (m_ioccupation)
	{
	case 0:
		strTemp += "程序员";
		break;
	case 1:
		strTemp += "系统工程师";
		break;
	case 2:
		strTemp += "项目经-理";
		break;
	default:
		break;
	}
	pDC->TextOutA(0, 0, strTemp);

	strTemp = "你的工作地点:";
	strTemp += m_strWorkAdr;

	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	pDC->TextOutA(0, tm.tmHeight, strTemp);

	strTemp = "你的兴趣爱好:";
	if (m_bLike[0])
	{
		strTemp += "足球 ";
	}
	if (m_bLike[1])
	{
		strTemp += "篮球 ";
	}
	if (m_bLike[2])
	{
		strTemp += "排球 ";
	}
	if (m_bLike[3])
	{
		strTemp += "游泳 ";
	}
	pDC->TextOutA(0, tm.tmHeight * 2, strTemp);

	strTemp = "你的薪资水平:";
	strTemp += m_strSalary;
	pDC->TextOutA(0, tm.tmHeight * 3, strTemp);

	pDC->SelectObject(pOldFont);


	// TODO:  在此处为本机数据添加绘制代码
}


// CPropView 打印

BOOL CPropView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CPropView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CPropView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CPropView 诊断

#ifdef _DEBUG
void CPropView::AssertValid() const
{
	CView::AssertValid();
}

void CPropView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPropDoc* CPropView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPropDoc)));
	return (CPropDoc*)m_pDocument;
}
#endif //_DEBUG


// CPropView 消息处理程序


void CPropView::OnPropertysheet()
{
	// TODO:  在此添加命令处理程序代码
	CPropSheet PropSheet("维新属性表单");
	PropSheet.SetWizardMode();
	if (ID_WIZFINISH == PropSheet.DoModal())
	{
		m_ioccupation = PropSheet.m_prop1.m_occupation;
		m_strWorkAdr = PropSheet.m_prop1.m_workAdr;
		m_bLike[0] = PropSheet.m_prop2.m_football;
		m_bLike[1] = PropSheet.m_prop2.m_basketball;
		m_bLike[2] = PropSheet.m_prop2.m_volleyball;
		m_bLike[3] = PropSheet.m_prop2.m_swim;
		m_strSalary = PropSheet.m_prop3.m_strSalary;
		Invalidate();  //让窗口无效，引起窗口重绘，然后在OnDraw中完成信息输出

	}
}
