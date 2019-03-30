
// pc_pc_api.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// Cpc_pc_apiApp: 
// 有关此类的实现，请参阅 pc_pc_api.cpp
//

class Cpc_pc_apiApp : public CWinApp
{
public:
	Cpc_pc_apiApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern Cpc_pc_apiApp theApp;