
// menu1View.h : Cmenu1View ��Ľӿ�
//

#pragma once


class Cmenu1View : public CView
{
protected: // �������л�����
	Cmenu1View();
	DECLARE_DYNCREATE(Cmenu1View)

// ����
public:
	Cmenu1Doc* GetDocument() const;

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
	virtual ~Cmenu1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnShow();
};

#ifndef _DEBUG  // menu1View.cpp �еĵ��԰汾
inline Cmenu1Doc* Cmenu1View::GetDocument() const
   { return reinterpret_cast<Cmenu1Doc*>(m_pDocument); }
#endif

