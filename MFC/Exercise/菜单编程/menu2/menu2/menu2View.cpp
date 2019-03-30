
// menu2View.cpp : Cmenu2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_COMMAND(IDM_PHONE1, &Cmenu2View::OnPhone1)
	ON_COMMAND(IDM_PHONE2, &Cmenu2View::OnPhone2)
	ON_COMMAND(IDM_PHONE3, &Cmenu2View::OnPhone3)
	ON_COMMAND(IDM_PHONE4, &Cmenu2View::OnPhone4)
END_MESSAGE_MAP()

// Cmenu2View ����/����

Cmenu2View::Cmenu2View()
{
	// TODO:  �ڴ˴���ӹ������

	m_nIndex = -1;
	m_strLine = "";
}

Cmenu2View::~Cmenu2View()
{
}

BOOL Cmenu2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cmenu2View ����

void Cmenu2View::OnDraw(CDC* /*pDC*/)
{
	Cmenu2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cmenu2View ��ӡ

BOOL Cmenu2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cmenu2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cmenu2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// Cmenu2View ���

#ifdef _DEBUG
void Cmenu2View::AssertValid() const
{
	CView::AssertValid();
}

void Cmenu2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cmenu2Doc* Cmenu2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmenu2Doc)));
	return (Cmenu2Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmenu2View ��Ϣ�������


void Cmenu2View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	if (0x0d == nChar)
	{
		if (0 == ++m_nIndex)
		{
			m_menu.CreatePopupMenu();
			GetParent()->GetMenu()->AppendMenuA(MF_POPUP, UINT(m_menu.m_hMenu), "PhoneBook");//view����û�в˵��������޷�����GetMenu().ֻ�ܸ����ָ��
			GetParent()->DrawMenuBar();
		}
		m_menu.AppendMenuA(MF_STRING,IDM_PHONE1+m_nIndex, m_strLine.Left(m_strLine.Find(' ')));
		m_strArray.Add(m_strLine);
		m_strLine.Empty();
		Invalidate();   //ʹ�������ڿͻ�����Ч
	}
	else
	{
		m_strLine += char(nChar); //������Ƶ��m_strLine+=nChar���뱨��
		dc.TextOutA(0, 0, m_strLine);
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void Cmenu2View::OnPhone1()
{
	// TODO:  �ڴ���������������
	CClientDC dc(this);
	dc.TextOutA(0, 0,m_strArray.GetAt(0));
}


void Cmenu2View::OnPhone2()
{
	// TODO:  �ڴ���������������
	CClientDC dc(this);
	dc.TextOutA(0, 0, m_strArray.GetAt(1));
}


void Cmenu2View::OnPhone3()
{
	// TODO:  �ڴ���������������
	CClientDC dc(this);
	dc.TextOutA(0, 0, m_strArray.GetAt(2));
}


void Cmenu2View::OnPhone4()
{
	// TODO:  �ڴ���������������
	CClientDC dc(this);
	dc.TextOutA(0, 0, m_strArray.GetAt(3));
}
