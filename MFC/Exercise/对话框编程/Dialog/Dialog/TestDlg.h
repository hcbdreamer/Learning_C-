#pragma once
#include "afxwin.h"


// CTestDlg �Ի���

class CTestDlg : public CDialog
{
	DECLARE_DYNAMIC(CTestDlg)

public:
	CTestDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTestDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1};
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedButton1();
//	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnClickedBtnAdd();
private:
	CButton m_btn;
	BOOL m_blsCreate=FALSE;
public:
	afx_msg void OnClickedNumber1();
private:
	int m_num1;
	int m_num2;
	int m_num3;
public:
	CEdit m_edit1;
	CEdit m_edit2;
	CEdit m_edit3;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
