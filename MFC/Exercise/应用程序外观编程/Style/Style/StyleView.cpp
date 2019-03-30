
// StyleView.cpp : CStyleView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Style.h"
#endif

#include"MainFrm.h"
#include "StyleDoc.h"
#include "StyleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStyleView

IMPLEMENT_DYNCREATE(CStyleView, CView)

BEGIN_MESSAGE_MAP(CStyleView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CStyleView ����/����

CStyleView::CStyleView()
{
	// TODO:  �ڴ˴���ӹ������

}

CStyleView::~CStyleView()
{
}

BOOL CStyleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	//cs.lpszClass = "HIT";
	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, LoadCursor(NULL,IDC_CROSS), (HBRUSH)GetStockObject(BLACK_BRUSH), 0);
	return CView::PreCreateWindow(cs);
}

// CStyleView ����

void CStyleView::OnDraw(CDC* /*pDC*/)
{
	CStyleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CStyleView ��ӡ

BOOL CStyleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CStyleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CStyleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CStyleView ���

#ifdef _DEBUG
void CStyleView::AssertValid() const
{
	CView::AssertValid();
}

void CStyleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStyleDoc* CStyleView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStyleDoc)));
	return (CStyleDoc*)m_pDocument;
}
#endif //_DEBUG


// CStyleView ��Ϣ�������


int CStyleView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	//SetClassLong(m_hWnd, GCL_HBRBACKGROUND, (LONG)GetStockObject(BLACK_BRUSH));
	//SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(NULL, IDC_HELP));
	return 0;
}


void CStyleView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str;
	str.Format("x=%d,y=%d", point.x, point.y); 
	//((CMainFrame*)GetParent())->m_wndStatusBar.SetWindowTextA(str);
	//((CMainFrame*)GetParent())->SetMessageText(str);
    //((CMainFrame*)GetParent())->GetMessageBar()->SetWindowTextA(str);
	//((CMainFrame*)GetParent())->m_wndStatusBar.SetPaneText(0, str);
	((CMainFrame*)GetParent())->GetDescendantWindow(AFX_IDW_STATUS_BAR)->SetWindowTextA(str);
	CView::OnMouseMove(nFlags, point);
}
