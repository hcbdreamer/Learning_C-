
// menuView.h : CmenuView ��Ľӿ�
//

#pragma once


class CmenuView : public CView
{
protected: // �������л�����
	CmenuView();
	DECLARE_DYNCREATE(CmenuView)

// ����
public:
	CmenuDoc* GetDocument() const;

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
	virtual ~CmenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTest();
};

#ifndef _DEBUG  // menuView.cpp �еĵ��԰汾
inline CmenuDoc* CmenuView::GetDocument() const
   { return reinterpret_cast<CmenuDoc*>(m_pDocument); }
#endif

