

#define DLL2_API _declspec(dllexport)
#include"createdll.h"
#include<Windows.h>
#include<stdio.h>
int add(int a, int b)
{
	return a + b;
}