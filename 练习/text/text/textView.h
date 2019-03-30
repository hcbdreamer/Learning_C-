
// textView.h : CtextView ��Ľӿ�
//

#pragma once
#include "atltypes.h"


class CtextView : public CView
{
protected: // �������л�����
	CtextView();
	DECLARE_DYNCREATE(CtextView)

// ����
public:
	CtextDoc* GetDocument() const;

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
	virtual ~CtextView();
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
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
private:
	CBitmap bitmap;
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	CString m_strLine;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CPoint m_ptOrigin2;
};

#ifndef _DEBUG  // textView.cpp �еĵ��԰汾
inline CtextDoc* CtextView::GetDocument() const
   { return reinterpret_cast<CtextDoc*>(m_pDocument); }
#endif

