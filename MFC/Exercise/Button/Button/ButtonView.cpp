
// ButtonView.cpp : CButtonView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Button.h"
#endif

#include "ButtonDoc.h"
#include "ButtonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CButtonView

IMPLEMENT_DYNCREATE(CButtonView, CView)

BEGIN_MESSAGE_MAP(CButtonView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CButtonView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CButtonView ����/����

CButtonView::CButtonView()
{
	// TODO:  �ڴ˴���ӹ������
	m_ptOrigin = 0;
}

CButtonView::~CButtonView()
{
}

BOOL CButtonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CButtonView ����

void CButtonView::OnDraw(CDC* /*pDC*/)
{
	CButtonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CButtonView ��ӡ


void CButtonView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CButtonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CButtonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CButtonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}

void CButtonView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CButtonView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CButtonView ���

#ifdef _DEBUG
void CButtonView::AssertValid() const
{
	CView::AssertValid();
}

void CButtonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CButtonDoc* CButtonView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CButtonDoc)));
	return (CButtonDoc*)m_pDocument;
}
#endif //_DEBUG


// CButtonView ��Ϣ�������


void CButtonView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//MessageBox(_T("HIT"));
	//MessageBox("HIT");
	m_ptOrigin = point;
	CView::OnLButtonDown(nFlags, point);
}


void CButtonView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	/*HDC hdc;
	hdc = ::GetDC(m_hWnd);
	MoveToEx(hdc, m_ptOrigin.x, m_ptOrigin.y, NULL);
	LineTo(hdc, point.x, point.y);
	::ReleaseDC(m_hWnd, hdc);*/
	/*CDC *pDC = GetDC();
	pDC->MoveTo(m_ptOrigin);
	pDC->LineTo(point);
	ReleaseDC(pDC);*/
	//CClientDC dc(GetParent());
	/*CClientDC dc(this);
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(point);*/
	/*CWindowDC dc(GetDesktopWindow());
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(point);*/
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	CClientDC dc(this);
	CPen *pOldPen = dc.SelectObject(&pen);
	dc.MoveTo(m_ptOrigin);
	dc.LineTo(point);
	dc.SelectObject(pOldPen);
	CView::OnLButtonUp(nFlags, point);
}
