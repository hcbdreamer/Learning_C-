#include<iostream>
#include<Windows.h>
#include<process.h>
using namespace std;
HANDLE _hThread[5];
LONG APIENTRY MainWndProc(HWND hWnd, UINT message, UINT wParam, LONG lParam)
{
	DWORD ThreadID[5];
	int i;
	static DWORD ThreadArg[5] = { HIGHEST_THREAD, ABOVE_AVE_THREAD, NORMAL_THREAD, BELOW_AVE_THREAD, LOWEST_THREAD };
	for (i = 0; i < 5; i++)
		_hThread[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc, &ThreadArg[i], Create_SUSPENDED, &ThreadID[i]);
	SetThreadPriority(_hThread[0], THREAD_PRIORITY_HIGHEST);
	SetThreadPriority(_hThread[1], THREAD_PRIORITY_ABOVE_NORMAL);
	SetThreadPriority(_hThread[2], THREAD_PRIORITY_NORMAL);
	SetThreadPriority(_hThread[3], THREAD_PRIORITY_BELOW_NORMAL);
	SetThreadPriority(_hThread[4], THREAD_PRIORITY_LOWEST);
}

UINT _uDelayType = NODELAY;
VOID ThreadProc(DWORD *ThreadArg)
{
	RECT rect;
	HDC hDC;
	HANDLE hBrush, hOldBrush;
	DWORD dwThreadHits = 0;
	int iThreadNo, i;
	do
	{
		dwThreadHits++;
		Rectangle(hDC, *(ThreadArg), rect.bottom - (dwThreadHits / 10), *(ThreadArg)+0x40, rect.bottom);
		if (_uDelayType == SLEEPDELAY)
			Sleep(10);
		else if (_uDelayType == FORLOOPDELAY);
		for (i = 0; i < 30000; i++);
	} while (dwThreadHits < 1000);
}