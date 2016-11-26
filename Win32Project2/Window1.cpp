#include "stdafx.h"
//#include "Win32Project2.h"
//
//#define MAX_LOADSTRING 100
//
//HINSTANCE hInst;                                // текущий экземпляр
//WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
//WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
//
//ATOM                MyRegisterWindow1(HINSTANCE hInstance);
//BOOL                InitInstance1(HINSTANCE, int);
//LRESULT CALLBACK    Window1Proc(HWND, UINT, WPARAM, LPARAM);
//
///*
//
//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//	_In_opt_ HINSTANCE hPrevInstance,
//	_In_ LPWSTR    lpCmdLine,
//	_In_ int       nCmdShow)
//{
//	UNREFERENCED_PARAMETER(hPrevInstance);
//	UNREFERENCED_PARAMETER(lpCmdLine);
//
//	// TODO: разместите код здесь.
//
//	// Инициализация глобальных строк
//	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
//	LoadStringW(hInstance, IDC_WIN32PROJECT2, szWindowClass, MAX_LOADSTRING);
//	MyRegisterWindow1(hInstance);
//
//	// Выполнить инициализацию приложения:
//	if (!InitInstance1(hInstance, nCmdShow))
//	{
//		return FALSE;
//	}
//
//	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT2));
//
//	MSG msg;
//
//	// Цикл основного сообщения:
//	while (GetMessage(&msg, nullptr, 0, 0))
//	{
//		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
//		{
//			TranslateMessage(&msg);
//			DispatchMessage(&msg);
//		}
//	}
//
//	return (int)msg.wParam;
//}
//*/
//ATOM MyRegisterWindow1(HINSTANCE hInstance)
//{
//	WNDCLASSEXW wcex;
//
//	wcex.cbSize = sizeof(WNDCLASSEX);
//
//	wcex.style = CS_HREDRAW | CS_VREDRAW;
//	wcex.lpfnWndProc = Window1Proc;
//	wcex.cbClsExtra = 0;
//	wcex.cbWndExtra = 0;
//	wcex.hInstance = hInstance;
//	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT2));
//	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
//	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WIN32PROJECT2);
//	wcex.lpszClassName = szWindowClass;
//	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
//
//	return RegisterClassExW(&wcex);
//}
//
//BOOL InitInstance1(HINSTANCE hInstance, int nCmdShow)
//{
//	hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной
//
//	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT, 0, 600, 400, nullptr, nullptr, hInstance, nullptr);
//
//	if (!hWnd)
//	{
//		return FALSE;
//	}
//
//	ShowWindow(hWnd, nCmdShow);
//	UpdateWindow(hWnd);
//
//	return TRUE;
//}
//
//
//
////
//LRESULT CALLBACK Window1Proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	static HWND NewMult, tmp;
//	static int number;
//	switch (message)
//	{
//	case WM_CREATE:
//	{
//
//		MessageBox(hWnd, (LPCWSTR)number, L"ok", MB_OK);
//	/*	NewMult = CreateWindow(
//			L"BUTTON", L"Добавить многочлен для работы", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 180, 300, 240, 30,
//			hWnd, (HMENU)A0_BUTTON, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
//*/
//	}
//	case WM_COMMAND:
//	{
//		if (LOWORD(wParam) == 1001)
//		{
//			MessageBox(hWnd, (LPCWSTR)number, L"kol-vo", MB_OK);
//		}
//		//break;
//		if (LOWORD(wParam) == 1000)
//		{
////			DialogBoxParam((HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDD_DIALOGBAR), 0, (DlgProc), 0);
//		}
//		//	break;
//		int wmId = LOWORD(wParam);
//		// Разобрать выбор в меню:
//		switch (wmId)
//		{
//		case IDM_EXIT:
//			DestroyWindow(hWnd);
//			break;
//		default:
//			return DefWindowProc(hWnd, message, wParam, lParam);
//		}
//	}
//	break;
//	case WM_PAINT:
//	{
//		PAINTSTRUCT ps;
//		HBITMAP hbitmap;
//		BITMAP bm;
//		HDC hDC;
//		HDC hMemDC;
//
//		hDC = BeginPaint(hWnd, &ps);
//		hMemDC = CreateCompatibleDC(hDC);
//		hbitmap = (HBITMAP)LoadImage(hInst, L"2.bmp", IMAGE_BITMAP, 600, 400, LR_LOADFROMFILE);
//		GetObject(hbitmap, sizeof(BITMAP), &bm);
//		SelectObject(hMemDC, hbitmap);
//		BitBlt(hDC, 0, 0, bm.bmWidth, bm.bmHeight, hMemDC, 0, 0, SRCCOPY);
//		DeleteDC(hMemDC);
//		ReleaseDC(hWnd, hDC);
//		DeleteObject(hbitmap);
//		EndPaint(hWnd, &ps);
//	}
//	break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	default:
//		return DefWindowProc(hWnd, message, wParam, lParam);
//	}
//	return 0;
//}
