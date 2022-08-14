#include <Windows.h>
#include <iostream>


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParm, LPARAM lParm)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	default: ;
	}
	return DefWindowProc(hWnd, msg, wParm, lParm);
}


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	const auto pClassName = L"awesome3d";

	// Register window class
	WNDCLASSEXW wca = { 0 };
	wca.cbSize = sizeof(wca);
	wca.style = CS_OWNDC;
	wca.lpfnWndProc = WndProc;
	wca.cbClsExtra = 0;
	wca.cbWndExtra = 0;
	wca.hInstance = hInstance;
	wca.hIcon = nullptr;
	wca.hCursor = nullptr;
	wca.hbrBackground = nullptr;
	wca.lpszMenuName = nullptr;
	wca.hIconSm = nullptr;
	wca.lpszClassName = pClassName;
	RegisterClassExW(&wca);

	// Create window instance
	const HWND hwnd = CreateWindowExW(0, pClassName, L"Awesome Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, 200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr);
	ShowWindow(hwnd, nCmdShow);
	MSG msg;

	while (GetMessageW(&msg, hwnd, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
	return 0;
}