// TestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Dialog.h"
#include "TestDlg.h"
#include "afxdialogex.h"
#include "Resource.h"


// CTestDlg 对话框

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


// CTestDlg 消息处理程序


//void CTestDlg::OnBnClickedButton1()
//{
//	// TODO:  在此添加控件通知处理程序代码
//}




void CTestDlg::OnClickedBtnAdd()
{
	// TODO:  在此添加控件通知处理程序代码
	//动态创建按钮
	//1.通过变量判断是否创建
	/*static BOOL bIsCreate = FALSE;
	//if (m_blsCreate == FALSE)
	if (bIsCreate==FALSE)
	{
		m_btn.Create("维新", BS_DEFPUSHBUTTON| WS_VISIBLE | WS_CHILD, CRect(0, 0, 100, 100), this, 123);//创建一个按钮
		//m_blsCreate = TRUE;
		bIsCreate = TRUE;
	}
	else
	{
		m_btn.DestroyWindow();
		//m_blsCreate = FALSE;
		bIsCreate = FALSE;
	}*/
	//2.通过与Button对象关联的窗口句柄判断
	/*if (!m_btn.m_hWnd)
	{
		m_btn.Create("维新", BS_DEFPUSHBUTTON| WS_VISIBLE | WS_CHILD, CRect(0, 0, 100, 100), this, 123);
	}
	else
	{
		m_btn.DestroyWindow();
	}*/
	//将编辑框1的值加上编辑框2的值，显示在编辑框3中
	//方式1
	/*int num1, num2, num3;
	char ch1[10], ch2[10], ch3[10];

	GetDlgItem(IDC_EDIT1)->GetWindowTextA(ch1, 10);
	GetDlgItem(IDC_EDIT2)->GetWindowTextA(ch2, 10);
	num1 = atoi(ch1);   //将字符转换成数字
	num2 = atoi(ch2);
	num3 = num1 + num2; 
	_itoa_s(num3, ch3, 10); //将数字以十进制转换为字符
	GetDlgItem(IDC_EDIT3)->SetWindowTextA(ch3);*/
	//方式2
	/*int num1, num2, num3;
	char ch1[10], ch2[10], ch3[10];
	GetDlgItemText(IDC_EDIT1, ch1, 10);
	GetDlgItemText(IDC_EDIT2, ch2, 10);  //直接取控件文本内容
	num1 = atoi(ch1);   //将字符转换成数字
	num2 = atoi(ch2);
	num3 = num1 + num2; 
    _itoa_s(num3, ch3, 10); //将数字以十进制转换为字符
	SetDlgItemText(IDC_EDIT3, ch3);*/
	//方式3
    /*int num1, num2, num3;
	num1=GetDlgItemInt(IDC_EDIT1);
	num2=GetDlgItemInt(IDC_EDIT2);
	num3 = num1 + num2;
	SetDlgItemInt(IDC_EDIT3, num3);*/
	//方式4 创建成员变量与控件相关联
	/*UpdateData();
	m_num3 = m_num1 + m_num2;//UpdateData(TRUE) == 将控件的值赋值给成员变量;UpdateData(FALSE) == 将成员变量的值赋值给控件。
	UpdateData(FALSE);*/
	//方式5创建控件变量
	/*int num1, num2, num3;
	char ch1[10], ch2[10], ch3[10];
	m_edit1.GetWindowTextA(ch1, 10);
	m_edit2.GetWindowTextA(ch2, 10);
	num1 = atoi(ch1);   //将字符转换成数字
	num2 = atoi(ch2);
	num3 = num1 + num2;
	_itoa_s(num3, ch3, 10); //将数字以十进制转换为字符
	m_edit3.SetWindowTextA(ch3);*/
	//方式6 通过发送消息获取文本内容
	/*int num1, num2, num3;
	char ch1[10], ch2[10], ch3[10];

	//::SendMessage(GetDlgItem(IDC_EDIT1)->m_hWnd, WM_GETTEXT, 10, (LPARAM)ch1);
	//::SendMessage(m_edit1.m_hWnd, WM_GETTEXT, 10, (LPARAM)ch1);
	//GetDlgItem(IDC_EDIT1)->SendMessage(WM_GETTEXT, 10, (LPARAM)ch1);
	m_edit1.SendMessage(WM_GETTEXT, 10, (LPARAM)ch1);
	m_edit2.SendMessage(WM_GETTEXT, 10, (LPARAM)ch2);
	num1 = atoi(ch1);   //将字符转换成数字
	num2 = atoi(ch2);
	num3 = num1 + num2;
	_itoa_s(num3, ch3, 10); //将数字以十进制转换为字符
	m_edit3.SendMessage(WM_SETTEXT, 0, (LPARAM)ch3);*/

	//方式7给一个对话框的子控件发送消息
	int num1, num2, num3;
	char ch1[10], ch2[10], ch3[10];
	SendDlgItemMessage(IDC_EDIT1, WM_GETTEXT, 10, (LPARAM)ch1);
	SendDlgItemMessage(IDC_EDIT2, WM_GETTEXT, 10, (LPARAM)ch2);
	num1 = atoi(ch1);   //将字符转换成数字
	num2 = atoi(ch2);
	num3 = num1 + num2;
	_itoa_s(num3, ch3, 10); //将数字以十进制转换为字符
	SendDlgItemMessage(IDC_EDIT3, WM_SETTEXT, 0, (LPARAM)ch3);
	//SendDlgItemMessage(IDC_EDIT3, EM_SETSEL, 1, 3);//发送控件复选内容消息，1，3，为复选起始位置
	SendDlgItemMessage(IDC_EDIT3, EM_SETSEL, 0, -1);//若复选起始位置记为0，-1，则复选所有内容
	m_edit3.SetFocus();//将复选的焦点集中到所选控件
}


void CTestDlg::OnClickedNumber1()
{
	// TODO:  在此添加控件通知处理程序代码
	CString str;
	if (GetDlgItem(IDC_NUMBER1)->GetWindowText(str), str == "Number1:")            //GetDlgItem:取得对话框上相应控件的指针
	{
		GetDlgItem(IDC_NUMBER1)->SetWindowTextA("数值1：");
	}
	else
	{
		GetDlgItem(IDC_NUMBER1)->SetWindowTextA("Number1:");
	}
}


void CTestDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	CString str;
	if (GetDlgItemText(IDC_BUTTON2, str), str == "收缩<<")
	{
		SetDlgItemText(IDC_BUTTON2, "扩展>>");
	}
	else
	{
		SetDlgItemText(IDC_BUTTON2, "收缩<<");
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
	if (str == "收缩<<")
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
	// TODO:  在此添加控件通知处理程序代码
	//CDialog::OnOK();
	//GetDlgItem(IDC_EDIT1)->GetNextWindow()->SetFocus();//只能由IDC_EDIT1往下传一个
	//GetFocus()->GetNextWindow()->SetFocus();//传递到最后一个窗口，无法获取到下一个窗口的
	GetNextDlgTabItem(GetFocus())->SetFocus();

}



BOOL CTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
