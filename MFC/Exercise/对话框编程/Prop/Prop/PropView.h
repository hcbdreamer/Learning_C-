
// PropView.h : CPropView ��Ľӿ�
//

#pragma once


class CPropView : public CView
{
protected: // �������л�����
	CPropView();
	DECLARE_DYNCREATE(CPropView)

// ����
public:
	CPropDoc* GetDocument() const;

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
	virtual ~CPropView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPropertysheet();
private:
	int m_ioccupation;
	CString m_strWorkAdr;
	BOOL m_bLike[4];
	CString  m_strSalary;
};

#ifndef _DEBUG  // PropView.cpp �еĵ��԰汾
inline CPropDoc* CPropView::GetDocument() const
   { return reinterpret_cast<CPropDoc*>(m_pDocument); }
#endif

