
// DialogView.cpp : CDialogView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Dialog.h"
#endif

#include "DialogDoc.h"
#include "DialogView.h"

#include "TestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDialogView

IMPLEMENT_DYNCREATE(CDialogView, CView)

BEGIN_MESSAGE_MAP(CDialogView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_DIALOG, &CDialogView::OnDialog)
END_MESSAGE_MAP()

// CDialogView 构造/析构

CDialogView::CDialogView()
{
	// TODO:  在此处添加构造代码

}

CDialogView::~CDialogView()
{
}

BOOL CDialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDialogView 绘制

void CDialogView::OnDraw(CDC* /*pDC*/)
{
	CDialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CDialogView 打印

BOOL CDialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CDialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CDialogView 诊断

#ifdef _DEBUG
void CDialogView::AssertValid() const
{
	CView::AssertValid();
}

void CDialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDialogDoc* CDialogView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDialogDoc)));
	return (CDialogDoc*)m_pDocument;
}
#endif //_DEBUG


// CDialogView 消息处理程序


void CDialogView::OnDialog()
{
	// TODO:  在此添加命令处理程序代码
	//CTestDlg dlg;
	//dlg.DoModal();//产生一个模态对话框

	CTestDlg *p_Dlg = new CTestDlg;
	p_Dlg->Create(IDD_DIALOG1, this);
	p_Dlg->ShowWindow(SW_SHOW);
}
