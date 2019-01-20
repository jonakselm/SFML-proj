#include "pch.h"
#include <Windows.h>
#include "App.hpp"


int main()
{
	//Console Window
	HWND hWnd = GetConsoleWindow();
#ifdef DEBUG
	ShowWindow(hWnd, SW_SHOW);
#else
	ShowWindow(hWnd, SW_HIDE);
#endif // DEBUG

	App app;
	app.run();

	return 0;
}
