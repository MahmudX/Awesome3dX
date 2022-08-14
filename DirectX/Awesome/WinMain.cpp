#include <Windows.h>
#include <iostream>


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParm, LPARAM lParm)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69);
		break;
	default:
		break;
	}
	return DefWindowProc(hWnd, msg, wParm, lParm);
}


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	const auto pClassName = L"awesome3d";

	// Register window class
	WNDCLASSEXW wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.hIconSm = nullptr;
	wc.lpszClassName = pClassName;
	RegisterClassExW(&wc);

	// Create window instance
	const HWND hWnd = CreateWindowExW(0, pClassName, L"Awesome Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, 200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr);
	ShowWindow(hWnd, nCmdShow);
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessageW(&msg, hWnd, 0, 0)) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
	if (gResult == -1)
		return -1;
	return msg.wParam;
}