
// PropView.cpp : CPropView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_PROPERTYSHEET, &CPropView::OnPropertysheet)
END_MESSAGE_MAP()

// CPropView ����/����

CPropView::CPropView()
{
	// TODO:  �ڴ˴���ӹ������
	m_ioccupation = -1;
	m_strWorkAdr = "";
	memset(m_bLike, 0, sizeof(m_bLike));//���������ʼ��
	m_strSalary = "";

}

CPropView::~CPropView()
{
}

BOOL CPropView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CPropView ����

void CPropView::OnDraw(CDC* pDC)
{
	CPropDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CFont font;
	font.CreatePointFont(300, "�����п�");

	CFont *pOldFont;
	pOldFont = pDC->SelectObject(&font);

	CString strTemp;
	strTemp = "���ְҵ��";

	switch (m_ioccupation)
	{
	case 0:
		strTemp += "����Ա";
		break;
	case 1:
		strTemp += "ϵͳ����ʦ";
		break;
	case 2:
		strTemp += "��Ŀ��-��";
		break;
	default:
		break;
	}
	pDC->TextOutA(0, 0, strTemp);

	strTemp = "��Ĺ����ص�:";
	strTemp += m_strWorkAdr;

	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	pDC->TextOutA(0, tm.tmHeight, strTemp);

	strTemp = "�����Ȥ����:";
	if (m_bLike[0])
	{
		strTemp += "���� ";
	}
	if (m_bLike[1])
	{
		strTemp += "���� ";
	}
	if (m_bLike[2])
	{
		strTemp += "���� ";
	}
	if (m_bLike[3])
	{
		strTemp += "��Ӿ ";
	}
	pDC->TextOutA(0, tm.tmHeight * 2, strTemp);

	strTemp = "���н��ˮƽ:";
	strTemp += m_strSalary;
	pDC->TextOutA(0, tm.tmHeight * 3, strTemp);

	pDC->SelectObject(pOldFont);


	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CPropView ��ӡ

BOOL CPropView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CPropView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CPropView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CPropView ���

#ifdef _DEBUG
void CPropView::AssertValid() const
{
	CView::AssertValid();
}

void CPropView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPropDoc* CPropView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPropDoc)));
	return (CPropDoc*)m_pDocument;
}
#endif //_DEBUG


// CPropView ��Ϣ�������


void CPropView::OnPropertysheet()
{
	// TODO:  �ڴ���������������
	CPropSheet PropSheet("ά�����Ա�");
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
		Invalidate();  //�ô�����Ч�����𴰿��ػ棬Ȼ����OnDraw�������Ϣ���

	}
}
