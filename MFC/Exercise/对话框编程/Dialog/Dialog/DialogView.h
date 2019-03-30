
// DialogView.h : CDialogView ��Ľӿ�
//

#pragma once


class CDialogView : public CView
{
protected: // �������л�����
	CDialogView();
	DECLARE_DYNCREATE(CDialogView)

// ����
public:
	CDialogDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CDialogView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDialog();
};

#ifndef _DEBUG  // DialogView.cpp �еĵ��԰汾
inline CDialogDoc* CDialogView::GetDocument() const
   { return reinterpret_cast<CDialogDoc*>(m_pDocument); }
#endif

