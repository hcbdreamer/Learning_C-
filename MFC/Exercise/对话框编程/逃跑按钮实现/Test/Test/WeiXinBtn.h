#pragma once


// CWeiXinBtn

class CWeiXinBtn : public CButton
{
	DECLARE_DYNAMIC(CWeiXinBtn)

public:
	CWeiXinBtn();
	virtual ~CWeiXinBtn();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CWeiXinBtn* m_pBtn;
};


