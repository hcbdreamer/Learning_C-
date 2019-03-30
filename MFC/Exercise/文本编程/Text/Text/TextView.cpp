
// TextView.cpp : CTextView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Text.h"
#endif

#include "TextDoc.h"
#include "TextView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTextView

IMPLEMENT_DYNCREATE(CTextView, CView)

BEGIN_MESSAGE_MAP(CTextView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTextView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CTextView ����/����

CTextView::CTextView()
{
	// TODO:  �ڴ˴���ӹ������

	m_strLine = _T("");
	m_ptOrigin = 0;
	m_nWidth = 0;
}

CTextView::~CTextView()
{
}

BOOL CTextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CTextView ����

void CTextView::OnDraw(CDC* pDC)
{
	CTextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString str("��������ҵ��ѧ");
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
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CTextView ��ӡ


void CTextView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CTextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CTextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}

void CTextView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTextView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTextView ���

#ifdef _DEBUG
void CTextView::AssertValid() const
{
	CView::AssertValid();
}

void CTextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTextDoc* CTextView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextDoc)));
	return (CTextDoc*)m_pDocument;
}
#endif //_DEBUG


// CTextView ��Ϣ�������


int CTextView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	CClientDC dc(this);
	TEXTMETRIC tm;            
	dc.GetTextMetrics(&tm);    //��ȡ��ǰ�豸���ַ�����
	//CBitmap bitmap;
	//bitmap.LoadBitmapW(IDB_BITMAP1);//����Ӱ������
	bitmap.LoadBitmap(310);
	CreateCaret(&bitmap);
	//CreateSolidCaret(tm.tmAveCharWidth/8, tm.tmHeight);
	ShowCaret();

	SetTimer(1, 100, NULL);//���ö�ʱ��
	return 0;
}


void CTextView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CFont font;
	font.CreatePointFont(300, _T("�����п�"), NULL);
	CFont *pOldfont=dc.SelectObject(&font);   //������ѡ���豸��������,ͬʱSelectObject����ԭ������ָ�����
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	if (0x0d==nChar)      //0x0dΪ���̻س�ASCII��,��Ϊ�س�����������ַ������¼�����һ��y����
	{
		m_strLine.Empty();
		m_ptOrigin.y += tm.tmHeight;
	}
	else if (0x08==nChar)     //0x08Ϊ�����˸�ASCII�룬��Ϊ�˸��Ƚ�����ɫ����Ϊ�ı���ɫ�����ı���������ȡ�ɣ���������leftȥ��һ���ַ�
	{
		COLORREF clr = dc.SetTextColor(dc.GetBkColor());
		dc.TextOut(m_ptOrigin.x, m_ptOrigin.y, m_strLine);
		m_strLine = m_strLine.Left(m_strLine.GetLength() - 1);
		dc.SetTextColor(clr);
	}
	else
	{
		m_strLine += (BYTE)nChar;//m_strLine+=(char)nChar
	}
	CSize sz = dc.GetTextExtent(m_strLine);//CSize�Ƕ�size�ṹ��ķ�װ

	CPoint pt;
	pt.x = m_ptOrigin.x + sz.cx;
	pt.y = m_ptOrigin.y;

	SetCaretPos(pt);
	dc.TextOut(m_ptOrigin.x, m_ptOrigin.y, m_strLine);

	dc.SelectObject(pOldfont);
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CTextView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCaretPos(point);
	m_strLine.Empty();
	m_ptOrigin = point;
	CView::OnLButtonDown(nFlags, point);
}


void CTextView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_nWidth += 5;

	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	CRect rect;
	rect.left = 0;
	rect.top = 200;
	rect.right = m_nWidth;
	rect.bottom = rect.top + tm.tmHeight;
	dc.SetTextColor(RGB(255, 0, 0));
	CString str;
	str.LoadStringA(IDS_HIT);
	dc.DrawText(str, rect, DT_LEFT);

	CSize sz = dc.GetTextExtent(str);
	if (m_nWidth > sz.cx)
	{
		m_nWidth = 0;
		dc.SetTextColor(RGB(0, 255, 0));
		dc.TextOutA(0, 200, str);
	}

	CView::OnTimer(nIDEvent);
}
