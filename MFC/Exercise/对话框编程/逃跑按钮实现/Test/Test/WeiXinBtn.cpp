// WeiXinBtn.cpp : 实现文件
//

#include "stdafx.h"
#include "Test.h"
#include "WeiXinBtn.h"


// CWeiXinBtn

IMPLEMENT_DYNAMIC(CWeiXinBtn, CButton)

CWeiXinBtn::CWeiXinBtn()
: m_pBtn(NULL)
{

}

CWeiXinBtn::~CWeiXinBtn()
{
}


BEGIN_MESSAGE_MAP(CWeiXinBtn, CButton)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CWeiXinBtn 消息处理程序




void CWeiXinBtn::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	ShowWindow(SW_HIDE);
	m_pBtn->ShowWindow(SW_SHOW);
	CButton::OnMouseMove(nFlags, point);
}
