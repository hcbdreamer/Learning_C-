#include<iostream>
#pragma comment(lib,"makeDLL.lib")

_declspec(dllimport) int add(int x, int y); //_declspec(dllimport)����һ�����뺯������˵��������Ǵӱ��DLL����,��Ҫ�á�

int main()
{
	std::cout << "2 + 3 = " << add(2, 3) << std::endl;

	std::cin.get();
	return 0;
}