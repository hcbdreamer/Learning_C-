
// menu2View.h : Cmenu2View ��Ľӿ�
//

#pragma once


class Cmenu2View : public CView
{
protected: // �������л�����
	Cmenu2View();
	DECLARE_DYNCREATE(Cmenu2View)

// ����
public:
	Cmenu2Doc* GetDocument() const;

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
	virtual ~Cmenu2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
private:
	int m_nIndex;
	CMenu m_menu;
	CString m_strLine;
public:
//	CStringArray m_strArray;
	afx_msg void OnPhone1();
	afx_msg void OnPhone2();
	afx_msg void OnPhone3();
	afx_msg void OnPhone4();
	CStringArray m_strArray;
};

#ifndef _DEBUG  // menu2View.cpp �еĵ��԰汾
inline Cmenu2Doc* Cmenu2View::GetDocument() const
   { return reinterpret_cast<Cmenu2Doc*>(m_pDocument); }
#endif

