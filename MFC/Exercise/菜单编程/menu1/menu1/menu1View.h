
// menu1View.h : Cmenu1View 类的接口
//

#pragma once


class Cmenu1View : public CView
{
protected: // 仅从序列化创建
	Cmenu1View();
	DECLARE_DYNCREATE(Cmenu1View)

// 特性
public:
	Cmenu1Doc* GetDocument() const;

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
	virtual ~Cmenu1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnShow();
};

#ifndef _DEBUG  // menu1View.cpp 中的调试版本
inline Cmenu1Doc* Cmenu1View::GetDocument() const
   { return reinterpret_cast<Cmenu1Doc*>(m_pDocument); }
#endif

