#ifndef CREATEDLL_H
#define CREATEDLL_H

_declspec(dllexport) int add(int x, int y);/*_declspec(dllexport)����һ��������������˵�������Ҫ�ӱ�DLL����,��Ҫ�������á�*/
int add(int x, int y);  //��ͺ���
#endif