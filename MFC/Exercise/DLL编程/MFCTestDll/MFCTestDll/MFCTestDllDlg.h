
// MFCTestDllDlg.h : ͷ�ļ�
//

#pragma once


// CMFCTestDllDlg �Ի���
class CMFCTestDllDlg : public CDialogEx
{
// ����
public:
	CMFCTestDllDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCTESTDLL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAdd();
//	afx_msg void OnBnClickedBtnOut();
	afx_msg void OnBnClickedBtnOut();
};
