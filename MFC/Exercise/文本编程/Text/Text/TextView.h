
// TextView.h : CTextView ��Ľӿ�
//

#pragma once


class CTextView : public CView
{
protected: // �������л�����
	CTextView();
	DECLARE_DYNCREATE(CTextView)

// ����
public:
	CTextDoc* GetDocument() const;

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
	virtual ~CTextView();
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
private:
	CString m_strLine;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	CPoint m_ptOrigin;
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	int m_nWidth;
};

#ifndef _DEBUG  // TextView.cpp �еĵ��԰汾
inline CTextDoc* CTextView::GetDocument() const
   { return reinterpret_cast<CTextDoc*>(m_pDocument); }
#endif

