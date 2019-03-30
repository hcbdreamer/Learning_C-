
// MainFrm.h : CMainFrame 类的接口
//

#pragma once

#define UM_PROGRESS WM_USER+1
class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
public:
	CStatusBar        m_wndStatusBar;
protected:  // 控件条嵌入成员
	CToolBar          m_wndToolBar;
	CToolBar		  m_newToolBar;
	CProgressCtrl     m_Progress;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT OnProgress(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()

private:
	HICON m_hIcons[3];
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnTest();
	afx_msg void OnViewNewtool();
	afx_msg void OnUpdateViewNewtool(CCmdUI *pCmdUI);
	afx_msg void OnPaint();
};


