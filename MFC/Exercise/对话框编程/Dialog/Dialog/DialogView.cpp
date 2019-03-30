
// DialogView.cpp : CDialogView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(IDM_DIALOG, &CDialogView::OnDialog)
END_MESSAGE_MAP()

// CDialogView ����/����

CDialogView::CDialogView()
{
	// TODO:  �ڴ˴���ӹ������

}

CDialogView::~CDialogView()
{
}

BOOL CDialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDialogView ����

void CDialogView::OnDraw(CDC* /*pDC*/)
{
	CDialogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CDialogView ��ӡ

BOOL CDialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CDialogView ���

#ifdef _DEBUG
void CDialogView::AssertValid() const
{
	CView::AssertValid();
}

void CDialogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDialogDoc* CDialogView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDialogDoc)));
	return (CDialogDoc*)m_pDocument;
}
#endif //_DEBUG


// CDialogView ��Ϣ�������


void CDialogView::OnDialog()
{
	// TODO:  �ڴ���������������
	//CTestDlg dlg;
	//dlg.DoModal();//����һ��ģ̬�Ի���

	CTestDlg *p_Dlg = new CTestDlg;
	p_Dlg->Create(IDD_DIALOG1, this);
	p_Dlg->ShowWindow(SW_SHOW);
}
