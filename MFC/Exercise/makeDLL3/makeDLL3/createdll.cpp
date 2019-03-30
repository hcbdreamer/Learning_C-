#define DLL2_API /*extern "C"*/ _declspec(dllexport)
#include"createdll.h"
#include<Windows.h>
#include<stdio.h>
int add(int a, int b)
{
	return a + b;
}

void Point::output(int x, int y)
{
	HWND hwnd = GetForegroundWindow();
	HDC hdc = GetDC(hwnd);
	char buf[22];
	memset(buf, 0, 22);
	sprintf_s(buf, "x=%d,y=%d", x, y);  //将格式化数据写入字符串中
	TextOut(hdc, 0, 0, (LPCWSTR)buf, strlen(buf));
	ReleaseDC(hwnd, hdc);
}

void Point::test()
{

}