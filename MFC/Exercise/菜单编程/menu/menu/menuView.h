
// menuView.h : CmenuView 类的接口
//

#pragma once


class CmenuView : public CView
{
protected: // 仅从序列化创建
	CmenuView();
	DECLARE_DYNCREATE(CmenuView)

// 特性
public:
	CmenuDoc* GetDocument() const;

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
	virtual ~CmenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTest();
};

#ifndef _DEBUG  // menuView.cpp 中的调试版本
inline CmenuDoc* CmenuView::GetDocument() const
   { return reinterpret_cast<CmenuDoc*>(m_pDocument); }
#endif

