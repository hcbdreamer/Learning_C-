// WeiXinBtn.cpp : ʵ���ļ�
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



// CWeiXinBtn ��Ϣ�������




void CWeiXinBtn::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ShowWindow(SW_HIDE);
	m_pBtn->ShowWindow(SW_SHOW);
	CButton::OnMouseMove(nFlags, point);
}
