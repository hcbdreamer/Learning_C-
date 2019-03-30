
// menuView.cpp : CmenuView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CmenuView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(IDM_TEST, &CmenuView::OnTest)
END_MESSAGE_MAP()

// CmenuView ����/����

CmenuView::CmenuView()
{
	// TODO:  �ڴ˴���ӹ������

}

CmenuView::~CmenuView()
{
}

BOOL CmenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CmenuView ����

void CmenuView::OnDraw(CDC* /*pDC*/)
{
	CmenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CmenuView ��ӡ


void CmenuView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CmenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CmenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CmenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
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


// CmenuView ���

#ifdef _DEBUG
void CmenuView::AssertValid() const
{
	CView::AssertValid();
}

void CmenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmenuDoc* CmenuView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmenuDoc)));
	return (CmenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CmenuView ��Ϣ�������


void CmenuView::OnTest()
{
	// TODO:  �ڴ���������������
	MessageBox("View clicked!");
}
