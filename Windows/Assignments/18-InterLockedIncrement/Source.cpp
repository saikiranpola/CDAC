#include<iostream>
#include<windows.h>
using namespace std;
#define MAX 64
long g_x = 0;
DWORD WINAPI ThreadFunction(LPVOID lpParam);
int main()
{	
	HANDLE hThread1, hThread2;
	for (int i = 0; i < MAX && g_x != 1; i++)
	{
		g_x = 0;
		DWORD dwThreadId, dwThreadId1;
		hThread1 = CreateThread(NULL, 0, ThreadFunction, NULL, 0, &dwThreadId);
		Sleep(1000);
		cout << "After Thread 1 - " << g_x << " ";
		hThread2 = CreateThread(NULL, 0, ThreadFunction, NULL, 0, &dwThreadId1);
		Sleep(1000);
		cout << "After Thread 2 - " << g_x << endl;
		CloseHandle(hThread1);
		CloseHandle(hThread2);
	}
	if (g_x == 1)
	{
		cout << "Thread Inconsistency" << endl;
	}
	system("pause");
}
DWORD WINAPI ThreadFunction(LPVOID lpParam)
{
	InterlockedExchangeAdd(&g_x,1);  
	return 0;
}