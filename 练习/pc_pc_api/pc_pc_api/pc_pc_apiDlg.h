
// pc_pc_apiDlg.h : 头文件
//

#pragma once
#if !defined(AFX_PC_PC_APIDLG_H__8BF2A52F_7EFE_4F7A_9D3E_28D85975C682__INCLUDED_)
#define AFX_PC_PC_APIDLG_H__8BF2A52F_7EFE_4F7A_9D3E_28D85975C682__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Cpc_pc_apiDlg 对话框
class Cpc_pc_apiDlg : public CDialogEx
{
// 构造
public:
	Cpc_pc_apiDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_PC_PC_API_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	CString m_strReceive;
	CString m_strSend;
	afx_msg void OnOk();
	afx_msg void OnCancel();

};
#endif // !defined(AFX_PC_PC_APIDLG_H__8BF2A52F_7EFE_4F7A_9D3E_28D85975C682__INCLUDED_)