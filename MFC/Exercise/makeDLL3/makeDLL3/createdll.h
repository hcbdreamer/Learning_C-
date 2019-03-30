#ifdef DLL2_API
#else
#define DLL2_API /*extern "C"*/ _declspec(dllimport)  //定义一个宏
#endif

DLL2_API int add(int a, int b);
class /*DLL2_API*/ Point
{
public:
	DLL2_API void output(int x, int y);
	void test();
};