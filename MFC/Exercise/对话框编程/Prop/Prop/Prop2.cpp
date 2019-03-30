// Prop2.cpp : 实现文件
//

#include "stdafx.h"
#include "Prop.h"
#include "Prop2.h"
#include "afxdialogex.h"


// CProp2 对话框

IMPLEMENT_DYNAMIC(CProp2, CPropertyPage)

CProp2::CProp2()
	: CPropertyPage(CProp2::IDD)
	, m_football(FALSE)
	, m_basketball(FALSE)
	, m_volleyball(FALSE)
	, m_swim(FALSE)
{

}

CProp2::~CProp2()
{
}

void CProp2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, m_football);
	DDX_Check(pDX, IDC_CHECK2, m_basketball);
	DDX_Check(pDX, IDC_CHECK3, m_volleyball);
	DDX_Check(pDX, IDC_CHECK4, m_swim);
}


BEGIN_MESSAGE_MAP(CProp2, CPropertyPage)
END_MESSAGE_MAP()


// CProp2 消息处理程序


//BOOL CProp2::OnSetActive()
//{
//	// TODO:  在此添加专用代码和/或调用基类
//
//	return CPropertyPage::OnSetActive();
//}


BOOL CProp2::OnSetActive()
{
	// TODO:  在此添加专用代码和/或调用基类
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_NEXT|PSWIZB_BACK);
	return CPropertyPage::OnSetActive();
}


LRESULT CProp2::OnWizardNext()
{
	// TODO:  在此添加专用代码和/或调用基类
	UpdateData();
	if (m_football || m_basketball || m_volleyball || m_swim)
	{
       return CPropertyPage::OnWizardNext();
	}
	else
	{
		MessageBox("请选择你的兴趣爱好!");
		return -1;
	}
	
}
