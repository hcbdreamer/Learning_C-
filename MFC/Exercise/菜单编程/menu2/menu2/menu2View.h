
// menu2View.h : Cmenu2View 类的接口
//

#pragma once


class Cmenu2View : public CView
{
protected: // 仅从序列化创建
	Cmenu2View();
	DECLARE_DYNCREATE(Cmenu2View)

// 特性
public:
	Cmenu2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Cmenu2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // menu2View.cpp 中的调试版本
inline Cmenu2Doc* Cmenu2View::GetDocument() const
   { return reinterpret_cast<Cmenu2Doc*>(m_pDocument); }
#endif

