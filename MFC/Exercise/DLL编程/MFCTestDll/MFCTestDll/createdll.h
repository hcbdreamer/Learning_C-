#ifdef DLL2_API
#else
#define DLL2_API _declspec(dllimport)  //定义一个宏
#endif

DLL2_API int add(int a, int b);
class DLL2_API Point
{
public:
	void output(int x, int y);
};