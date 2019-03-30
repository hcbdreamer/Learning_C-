// TestDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Dialog.h"
#include "TestDlg.h"
#include "afxdialogex.h"
#include "Resource.h"


// CTestDlg �Ի���

IMPLEMENT_DYNAMIC(CTestDlg, CDialog)

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
	, m_blsCreate(FALSE)
	, m_num1(0)
	, m_num2(0)
	, m_num3(0)
{

}

CTestDlg::~CTestDlg()
{
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_num1);
	DDX_Text(pDX, IDC_EDIT2, m_num2);
	DDX_Text(pDX, IDC_EDIT3, m_num3);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
}


BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	//ON_BN_CLICKED(IDC_BUTTON1, &CTestDlg::OnBnClickedButton1)
	//ON_BN_CLICKED(IDC_BTN_ADD, &CTestDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_ADD, &CTestDlg::OnClickedBtnAdd)
	ON_STN_CLICKED(IDC_NUMBER1, &CTestDlg::OnClickedNumber1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &CTestDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTestDlg ��Ϣ�������


//void CTestDlg::OnBnClickedButton1()
//{
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//}




void CTestDlg::OnClickedBtnAdd()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//��̬������ť
	//1.ͨ�������ж��Ƿ񴴽�
	/*static BOOL bIsCreate = FALSE;
	//if (m_blsCreate == FALSE)
	if (bIsCreate==FALSE)
	{
		m_btn.Create("ά��", BS_DEFPUSHBUTTON| WS_VISIBLE | WS_CHILD, CRect(0, 0, 100, 100), this, 123);//����һ����ť
		//m_blsCreate = TRUE;
		bIsCreate = TRUE;
	}
	else
	{
		m_btn.DestroyWindow();
		//m_blsCreate = FALSE;
		bIsCreate = FALSE;
	}*/
	//2.ͨ����Button��������Ĵ��ھ���ж�
	/*if (!m_btn.m_hWnd)
	{
		m_btn.Create("ά��", BS_DEFPUSHBUTTON| WS_VISIBLE | WS_CHILD, CRect(0, 0, 100, 100), this, 123);
	}
	else
	{
		m_btn.DestroyWindow();
	}*/
	//���༭��1��ֵ���ϱ༭��2��ֵ����ʾ�ڱ༭��3��
	//��ʽ1
	/*int num1, num2, num3;
	char ch1[10], ch2[10], ch3[10];

	GetDlgItem(IDC_EDIT1)->GetWindowTextA(ch1, 10);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(ch2, 10);
	num1 = atoi(ch1);   //���ַ�ת��������
	num2 = atoi(ch2);
	num3 = num1 + num2; 
	_itoa_s(num3, ch3, 10); //��������ʮ����ת��Ϊ�ַ�
	GetDlgItem(IDC_EDIT3)->SetWindowTextA(ch3);*/
	//��ʽ2
	/*int num1, num2, num3;
	char ch1[10], ch2[10], ch3[10];
	GetDlgItemText(IDC_EDIT1, ch1, 10);
	GetDlgItemText(IDC_EDIT2, ch2, 10);  //ֱ��ȡ�ؼ��ı�����
	num1 = atoi(ch1);   //���ַ�ת��������
	num2 = atoi(ch2);
	num3 = num1 + num2; 
    _itoa_s(num3, ch3, 10); //��������ʮ����ת��Ϊ�ַ�
	SetDlgItemText(IDC_EDIT3, ch3);*/
	//��ʽ3
    /*int num1, num2, num3;
	num1=GetDlgItemInt(IDC_EDIT1);
	num2=GetDlgItemInt(IDC_EDIT2);
	num3 = num1 + num2;
	SetDlgItemInt(IDC_EDIT3, num3);*/
	//��ʽ4 ������Ա������ؼ������
	/*UpdateData();
	m_num3 = m_num1 + m_num2;//UpdateData(TRUE) == ���ؼ���ֵ��ֵ����Ա����;UpdateData(FALSE) == ����Ա������ֵ��ֵ���ؼ���
	UpdateData(FALSE);*/
	//��ʽ5�����ؼ�����
	/*int num1, num2, num3;
	char ch1[10], ch2[10], ch3[10];
	m_edit1.GetWindowTextA(ch1, 10);
	m_edit2.GetWindowTextA(ch2, 10);
	num1 = atoi(ch1);   //���ַ�ת��������
	num2 = atoi(ch2);
	num3 = num1 + num2;
	_itoa_s(num3, ch3, 10); //��������ʮ����ת��Ϊ�ַ�
	m_edit3.SetWindowTextA(ch3);*/
	//��ʽ6 ͨ��������Ϣ��ȡ�ı�����
	/*int num1, num2, num3;
	char ch1[10], ch2[10], ch3[10];

	//::SendMessage(GetDlgItem(IDC_EDIT1)->m_hWnd, WM_GETTEXT, 10, (LPARAM)ch1);
	//::SendMessage(m_edit1.m_hWnd, WM_GETTEXT, 10, (LPARAM)ch1);
	//GetDlgItem(IDC_EDIT1)->SendMessage(WM_GETTEXT, 10, (LPARAM)ch1);
	m_edit1.SendMessage(WM_GETTEXT, 10, (LPARAM)ch1);
	m_edit2.SendMessage(WM_GETTEXT, 10, (LPARAM)ch2);
	num1 = atoi(ch1);   //���ַ�ת��������
	num2 = atoi(ch2);
	num3 = num1 + num2;
	_itoa_s(num3, ch3, 10); //��������ʮ����ת��Ϊ�ַ�
	m_edit3.SendMessage(WM_SETTEXT, 0, (LPARAM)ch3);*/

	//��ʽ7��һ���Ի�����ӿؼ�������Ϣ
	int num1, num2, num3;
	char ch1[10], ch2[10], ch3[10];
	SendDlgItemMessage(IDC_EDIT1, WM_GETTEXT, 10, (LPARAM)ch1);
	SendDlgItemMessage(IDC_EDIT2, WM_GETTEXT, 10, (LPARAM)ch2);
	num1 = atoi(ch1);   //���ַ�ת��������
	num2 = atoi(ch2);
	num3 = num1 + num2;
	_itoa_s(num3, ch3, 10); //��������ʮ����ת��Ϊ�ַ�
	SendDlgItemMessage(IDC_EDIT3, WM_SETTEXT, 0, (LPARAM)ch3);
	//SendDlgItemMessage(IDC_EDIT3, EM_SETSEL, 1, 3);//���Ϳؼ���ѡ������Ϣ��1��3��Ϊ��ѡ��ʼλ��
	SendDlgItemMessage(IDC_EDIT3, EM_SETSEL, 0, -1);//����ѡ��ʼλ�ü�Ϊ0��-1����ѡ��������
	m_edit3.SetFocus();//����ѡ�Ľ��㼯�е���ѡ�ؼ�
}


void CTestDlg::OnClickedNumber1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str;
	if (GetDlgItem(IDC_NUMBER1)->GetWindowText(str), str == "Number1:")            //GetDlgItem:ȡ�öԻ�������Ӧ�ؼ���ָ��
	{
		GetDlgItem(IDC_NUMBER1)->SetWindowTextA("��ֵ1��");
	}
	else
	{
		GetDlgItem(IDC_NUMBER1)->SetWindowTextA("Number1:");
	}
}


void CTestDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str;
	if (GetDlgItemText(IDC_BUTTON2, str), str == "����<<")
	{
		SetDlgItemText(IDC_BUTTON2, "��չ>>");
	}
	else
	{
		SetDlgItemText(IDC_BUTTON2, "����<<");
	}
	static CRect rectLarge;
	static CRect rectSmall;
	if (rectLarge.IsRectNull())
	{   
		CRect rectSeparator;
		GetWindowRect(&rectLarge);
		GetDlgItem(IDC_SEPARATOR)->GetWindowRect(&rectSeparator);
		rectSmall.left = rectLarge.left;
		rectSmall.top = rectLarge.top;
		rectSmall.right = rectLarge.right;
		rectSmall.bottom = rectSeparator.bottom;

	}
	if (str == "����<<")
	{
		SetWindowPos(NULL, 0, 0, rectSmall.Width(), rectSmall.Height(), SWP_NOMOVE | SWP_NOZORDER);
	}
	else
	{
		SetWindowPos(NULL, 0, 0, rectLarge.Width(), rectLarge.Height(), SWP_NOMOVE | SWP_NOZORDER);
	}

}


void CTestDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialog::OnOK();
	//GetDlgItem(IDC_EDIT1)->GetNextWindow()->SetFocus();//ֻ����IDC_EDIT1���´�һ��
	//GetFocus()->GetNextWindow()->SetFocus();//���ݵ����һ�����ڣ��޷���ȡ����һ�����ڵ�
	GetNextDlgTabItem(GetFocus())->SetFocus();

}



BOOL CTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
