
// pc_pc_api.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cpc_pc_apiApp: 
// �йش����ʵ�֣������ pc_pc_api.cpp
//

class Cpc_pc_apiApp : public CWinApp
{
public:
	Cpc_pc_apiApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cpc_pc_apiApp theApp;