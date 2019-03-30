
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once

#define UM_PROGRESS WM_USER+1
class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
public:
	CStatusBar        m_wndStatusBar;
protected:  // �ؼ���Ƕ���Ա
	CToolBar          m_wndToolBar;
	CToolBar		  m_newToolBar;
	CProgressCtrl     m_Progress;

// ���ɵ���Ϣӳ�亯��
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


