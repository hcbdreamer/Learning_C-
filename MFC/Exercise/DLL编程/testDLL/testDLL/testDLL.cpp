#include<iostream>
#pragma comment(lib,"makeDLL.lib")

_declspec(dllimport) int add(int x, int y); //_declspec(dllimport)声明一个导入函数，是说这个函数是从别的DLL导入,我要用。

int main()
{
	std::cout << "2 + 3 = " << add(2, 3) << std::endl;

	std::cin.get();
	return 0;
}