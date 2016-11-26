// Win32Project2.cpp: определяет точку входа для приложения.
#include <windows.h>
#include "stdafx.h"
#include "Win32Project2.h"
#include <iostream>
#include "Classes\Multinomial.h"
#include <strsafe.h>

#define MAX_LOADSTRING 100
#define A0_BUTTON 1000
#define Label_1 2002

#define result 2001
#define addfirst 1000
#define addsecond 1000
#define back 2004
#define exit 2005
#define Label_addfirst 2006
#define Label_addsecond 2006
#define Label_choose 2006
#define Label_result 2006

#define IDC_GRPBUTTONS	3000
#define ID_RADIOBTN1	3001
#define ID_RADIOBTN2	3002
#define ID_RADIOBTN3 	3003
#define ID_RADIOBTN4	 3004

#define ID_EDITRESULT1	4001
#define ID_COMBO1 5001
#define ID_COMBO2 5002
#define ID_FIRSTCHILD	100
#define ID_SECONDCHILD	101
#define ID_THIRDCHILD	102

#define ID_32770 32770
#define ID_32771 32771
#define ID_32772 32772

// Глобальные переменные:
HINSTANCE hInst;
TCHAR WinName[] = _T("MainFrame");
TCHAR ChildName[] = _T("Арифметические операции");
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
static int number = 0;
HWND clr_butns[100];
HWND clr_labels[100];
vector<Multinomial> multy;
int ItemCombo1 = 0, ItemCombo2 = 0;
static HWND back1, result1, exit1, addFirst1, addSecond1,
Label_addfirst1, Label_addsecond1, Label_choose1, Label_result1,
radio1, radio2, radio3, radio4,
editresult1, combo1, combo2;

// Отправить объявления функций, включенных в этот модуль кода:
ATOM               MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK ChildProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//vector<string> multToString();
//bool findMulty(Multinomial);
//void addToVector(Multinomial);

INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine, _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: разместите код здесь.

	// Инициализация глобальных строк
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WIN32PROJECT2, szWindowClass, MAX_LOADSTRING);

	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT2));

	MSG msg;

	// Цикл основного сообщения:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT2));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WIN32PROJECT2);
	wcex.lpszClassName = WinName;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	if (!RegisterClassExW(&wcex)) return -1;

	WNDCLASSEXW wch;
	wch.cbSize = sizeof(WNDCLASSEXW);
	wch.hInstance = hInstance;
	wch.lpszClassName = ChildName;
	wch.lpfnWndProc = ChildProc;
	wch.style = CS_HREDRAW | CS_VREDRAW;
	wch.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT2));
	wch.hCursor = LoadCursor(NULL, IDC_ARROW);
	wch.lpszMenuName = NULL;
	wch.cbClsExtra = 0;
	wch.cbWndExtra = 0;
	wch.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wch.hIconSm = LoadIcon(wch.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	if (!RegisterClassExW(&wch)) return -2;

}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

	HWND hWnd = CreateWindowW(WinName, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 600, 400, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

// для значений коэффициентов
BOOL CALLBACK DlgProcKof(HWND hwnd, UINT Message,
	WPARAM wparam, LPARAM lparam)
{

	switch (Message) {

	case WM_INITDIALOG:
	{
		int  IDS_BTNS[MAX_LOADSTRING];
		for (int j = 0; j < number; j++) { //+1
			IDS_BTNS[j] = 1010 + j;
		}

		int i = 2;
		int x, y, sx = 45, sy = 20, cnt = 0;
		x = 20;
		y = 35;
		int p = 0;
		for (i = 0; i < number + 1; ++i) {

			clr_labels[i] = CreateWindow(L"static", L"ST_U", WS_CHILD | WS_VISIBLE | WS_TABSTOP,
				x, y, sx, sy, hwnd, (HMENU)Label_1, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);

			// какой-то капец про склейку 
			TCHAR pszDest[30];
			LPCTSTR pszFormat = TEXT("%s %d");
			TCHAR* pscText = TEXT("x^");
			HRESULT hr = StringCchPrintf(pszDest, 30, pszFormat, pscText, number - i);
			SetWindowText(clr_labels[i], pszDest);

			clr_butns[i] = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"0", BS_OWNERDRAW | WS_CHILD | WS_VISIBLE,
				x + 40, y, sx, sy, hwnd, (HMENU)IDS_BTNS[i], hInst, NULL);
			y += sy + 5;

			p++;
			if (p == 10) {
				p = 0;
				x += x + 2 * sx + 5;
				y = 35;
			}
		}
	}

	case WM_COMMAND:

		if (LOWORD(wparam) == IDOK)
		{
			double kof[MAX_LOADSTRING];
			TCHAR buf[10];
			for (int i = 0; i < number + 1; i++)//number
			{
				GetWindowText(GetDlgItem(hwnd, 1010 + i), buf, 1024);
				kof[i] = _wtof(buf);
			}
			Multinomial NewMulty = Multinomial(number, kof);
			multy.push_back(NewMulty);

			EndDialog(hwnd, 0);
		}
		if (LOWORD(wparam) == IDCANCEL)
		{
			EndDialog(hwnd, 0);
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		break;
	default: break;
	}
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT Message,
	WPARAM wparam, LPARAM lparam)
{
	switch (Message) {
	case WM_COMMAND:
		if (LOWORD(wparam) == IDOK)
		{

			TCHAR buff[1024];
			GetWindowText(GetDlgItem(hwnd, IDC_EDIT1), buff, 1024);
			number = _wtof(buff);
			DialogBoxParam((HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDD_DIALOGBAR1), 0, (DlgProcKof), 0);
			EndDialog(hwnd, 0);
		}
		if (LOWORD(wparam) == IDCANCEL)
		{
			EndDialog(hwnd, 0);
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		break;
	default: break;
	}
	return 0;
}

LRESULT CALLBACK ChildProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   // Обработчик сообщений
	char item[150];
/*	static HWND back1, result1, exit1, addFirst1, addSecond1,
		Label_addfirst1, Label_addsecond1, Label_choose1, Label_result1,
		radio1, radio2, radio3, radio4,
		editresult1, combo1, combo2;*/
	switch (message)
	{
	case WM_CREATE:
	{

		result1 = CreateWindow(
			L"BUTTON", L"Результат", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 250, 270, 100, 30,
			hWnd, (HMENU)result, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		addFirst1 = CreateWindow(
			L"BUTTON", L"+", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 390, 70, 30, 30,
			hWnd, (HMENU)addfirst, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		addSecond1 = CreateWindow(
			L"BUTTON", L"+", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 390, 150, 30, 30,
			hWnd, (HMENU)addsecond, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		back1 = CreateWindow(
			L"BUTTON", L"Назад", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 20, 320, 50, 30,
			hWnd, (HMENU)back, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		exit1 = CreateWindow(
			L"BUTTON", L"Выход", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 515, 320, 50, 30,
			hWnd, (HMENU)exit, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);

		Label_addfirst1 = CreateWindow(L"static", L"1. Добавьтепервый многочлен или выберите из списка", WS_CHILD | WS_VISIBLE | WS_TABSTOP,
			20, 30, 400, 30, hWnd, (HMENU)Label_addfirst, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		Label_addsecond1 = CreateWindow(L"static", L"2. Добавьте второй многочлен или выберите из списка", WS_CHILD | WS_VISIBLE | WS_TABSTOP,
			20, 110, 400, 30, hWnd, (HMENU)Label_addsecond, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		Label_choose1 = CreateWindow(L"static", L"3. Выберите действие справа", WS_CHILD | WS_VISIBLE | WS_TABSTOP,
			20, 190, 300, 30, hWnd, (HMENU)Label_choose, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		Label_result1 = CreateWindow(L"static", L"4. Нажмите на результат", WS_CHILD | WS_VISIBLE | WS_TABSTOP,
			20, 220, 300, 30, hWnd, (HMENU)Label_result, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);

		HWND hGrpButtons = CreateWindowEx(WS_EX_WINDOWEDGE,
			L"BUTTON", L"", WS_VISIBLE | WS_CHILD | BS_GROUPBOX,  // Styles 
			430, 10, 140, 300, hWnd, (HMENU)IDC_GRPBUTTONS, hInst, NULL);

		radio1 = CreateWindowExW(WS_EX_TRANSPARENT, L"BUTTON", L"Сложение",
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
			450, 50, 100, 20, hWnd, (HMENU)ID_RADIOBTN1, GetModuleHandle(NULL), 0);
		radio2 = CreateWindowExW(WS_EX_TRANSPARENT, L"BUTTON", L"Вычитание",
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
			450, 120, 100, 20, hWnd, (HMENU)ID_RADIOBTN2, GetModuleHandle(NULL), 0);
		radio3 = CreateWindowExW(WS_EX_TRANSPARENT, L"BUTTON", L"Умножение",
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
			450, 190, 100, 20, hWnd, (HMENU)ID_RADIOBTN3, GetModuleHandle(NULL), 0);
		radio4 = CreateWindowExW(WS_EX_TRANSPARENT, L"BUTTON", L"Деление",
			WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
			450, 260, 100, 20, hWnd, (HMENU)ID_RADIOBTN4, GetModuleHandle(NULL), 0);

		editresult1 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"0", BS_OWNERDRAW | WS_CHILD | WS_VISIBLE,
			80, 320, 430, 30, hWnd, (HMENU)ID_EDITRESULT1, hInst, NULL);

		combo1 = CreateWindow(L"combobox", NULL,
			WS_CHILD | WS_VISIBLE | WS_TABSTOP | CBS_AUTOHSCROLL | CBS_DROPDOWN | CBS_SORT,
			20, 70, 350, 200, hWnd, (HMENU)ID_COMBO1, NULL, NULL);


		/*	SendMessage(combo1, CB_SETCURSEL, 1, 0);
			SendMessage(combo1, CB_SETEXTENDEDUI, 2, 0);*/

		combo2 = CreateWindow(L"combobox", NULL, WS_CHILD | WS_VISIBLE | WS_TABSTOP | CBS_AUTOHSCROLL | CBS_DROPDOWN | CBS_SORT,
			20, 150, 350, 200, hWnd, (HMENU)ID_COMBO2, NULL, NULL);
		vector<string> multystring = multToString(multy);
		if (multystring.empty() != true)
		{
			for (int i = 0; i <= multystring.size() - 1; i++)
			{
				SendMessageA(combo1, CB_ADDSTRING, 0, (LPARAM)multystring[i].c_str());
				SendMessageA(combo2, CB_ADDSTRING, 0, (LPARAM)multystring[i].c_str());
			}
		}
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HBITMAP hbitmap;
		BITMAP bm;
		HDC hDC;
		HDC hMemDC;

		hDC = BeginPaint(hWnd, &ps);
		hMemDC = CreateCompatibleDC(hDC);
		//	hbitmap = (HBITMAP)LoadImage(hInst, L"2.bmp", IMAGE_BITMAP, 600, 400, LR_LOADFROMFILE);
	//		GetObject(hbitmap, sizeof(BITMAP), &bm);
		//	SelectObject(hMemDC, hbitmap);
		//	BitBlt(hDC, 0, 0, bm.bmWidth, bm.bmHeight, hMemDC, 0, 0, SRCCOPY);
		DeleteDC(hMemDC);
		ReleaseDC(hWnd, hDC);
		//		DeleteObject(hbitmap);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_COMMAND:
		if (HIWORD(wParam) == CBN_SELCHANGE)
			// If the user makes a selection from the list:
			//   Send CB_GETCURSEL message to get the index of the selected list item.
			//   Send CB_GETLBTEXT message to get the item.
			//   Display the item in a messagebox.
		{
			if (LOWORD(wParam) == ID_COMBO1)
			{
				ItemCombo1 = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,
					(WPARAM)0, (LPARAM)0);
				/*		TCHAR  ListItem[256];
						(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT,
							(WPARAM)ItemCombo1, (LPARAM)ListItem);
						MessageBox(hWnd, (LPCWSTR)ListItem, TEXT("Item Selected"), MB_OK);*/
			}

			if (LOWORD(wParam) == ID_COMBO2)
				ItemCombo2 = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,
				(WPARAM)0, (LPARAM)0);
		}
		if (LOWORD(wParam) == result)
		{
			if (IsDlgButtonChecked(hWnd, ID_RADIOBTN1)) //Сложение
			{

				TCHAR  ListItem[256];
				Multinomial plusresult = multy[ItemCombo1] + multy[ItemCombo2];
				addToVector(multy, plusresult, editresult1, combo1, combo2);

			}
			if (IsDlgButtonChecked(hWnd, ID_RADIOBTN2)) //Вычитание
			{

				TCHAR  ListItem[256];
				Multinomial plusresult = multy[ItemCombo1] - multy[ItemCombo2];
				addToVector(multy, plusresult, editresult1, combo1, combo2);
			}
			if (IsDlgButtonChecked(hWnd, ID_RADIOBTN3)) //Деление
			{

				TCHAR  ListItem[256];
				Multinomial plusresult = multy[ItemCombo1] * multy[ItemCombo2];
				//проверка, нет ли такого уже в списках
				addToVector(multy, plusresult, editresult1, combo1, combo2);
			}
			if (IsDlgButtonChecked(hWnd, ID_RADIOBTN4)) //Умножение
			{
				TCHAR  ListItem[256];

				//хуетень!
				int e,t;
				Multinomial main;
				main.n = multy[ItemCombo1].n - 1;
				main.dMN = new double[multy[ItemCombo1].n + 1];
				for (int i = main.n; i >= 0; i--)
				{
					main.dMN[multy[ItemCombo1].n - i-1] = multy[ItemCombo1].dMN[i];
							e = main.dMN[multy[ItemCombo1].n - i-1];
							t = multy[ItemCombo1].n - i-1;
				}

				Multinomial plusresult = main / multy[ItemCombo2];
				addToVector(multy, plusresult, editresult1, combo1, combo2);
			}

		}

		if (LOWORD(wParam) == exit)
		{
			DestroyWindow(hWnd);
			//	EnableWindow(hWnd,TRUE);
		}
		if (LOWORD(wParam) == 1000)
		{
			DialogBoxParam((HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDD_DIALOGBAR), 0, (DlgProc), 0);
			vector<string> multystring = multToString(multy);
			SendMessageA(combo1, CB_RESETCONTENT, 0, 0);
			SendMessageA(combo2, CB_RESETCONTENT, 0, 0);

			for (int i = 0; i <= multystring.size() - 1; i++)
			{
				SendMessageA(combo1, CB_ADDSTRING, 0, (LPARAM)multystring[i].c_str());
				SendMessageA(combo2, CB_ADDSTRING, 0, (LPARAM)multystring[i].c_str());
			}
		}
		switch (message)
		{
			/*	case addfirst:
					{
						DialogBoxParam((HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDD_DIALOGBAR), 0, (DlgProc), 0);
					}*/
		case ID_COMBO1:
			if (HIWORD(wParam) == CBN_EDITCHANGE) {
				GetWindowText(combo1, (LPWSTR)item, sizeof(item));
				SetWindowText(hWnd, (LPWSTR)item);
			}
			if (HIWORD(wParam) == CBN_KILLFOCUS) {
				GetWindowText(combo1, (LPWSTR)item, sizeof(item));
				if (SendMessage(combo1, CB_FINDSTRINGEXACT, 0, (LPARAM)item) == CB_ERR) {
					SendMessage(combo1, CB_ADDSTRING, 0, (LPARAM)item);
					SetWindowText(combo1, L"");
				}
			}
			//break;
		case ID_COMBO2:
			if (HIWORD(wParam) == CBN_EDITCHANGE) {
				GetWindowText(combo2, (LPWSTR)item, sizeof(item));
				SetWindowText(hWnd, (LPWSTR)item);
			}
			if (HIWORD(wParam) == CBN_KILLFOCUS) {
				GetWindowText(combo2, (LPWSTR)item, sizeof(item));
				if (SendMessage(combo2, CB_FINDSTRINGEXACT, 0, (LPARAM)item) == CB_ERR) {
					SendMessage(combo2, CB_ADDSTRING, 0, (LPARAM)item);
					SetWindowText(combo2, L"");
				}
			}
			break;
		}
		break;
	case WM_DESTROY: PostQuitMessage(0);
		break; // Завершение программы
			   // Обработка сообщения по умолчанию
	default: return DefWindowProc(hWnd, message, wParam, lParam);
	}
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  НАЗНАЧЕНИЕ:  обрабатывает сообщения в главном окне.
//
//  WM_COMMAND — обработать меню приложения
//  WM_PAINT — отрисовать главное окно
//  WM_DESTROY — отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND NewMult, tmp;
	static int number;
	static HWND hwndPopup = 0;
	switch (message)
	{
	case WM_CREATE:
	{
		NewMult = CreateWindow(
			L"BUTTON", L"Добавить многочлен для работы", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 180, 300, 240, 30,
			hWnd, (HMENU)A0_BUTTON, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		double a[3] = { 0.0,0,1 };
		multy.push_back(Multinomial(2, a));
		double b[3] = { 1,1,1 };
		multy.push_back(Multinomial(2, b));
		double c[3] = { 2,2,2 };
		multy.push_back(Multinomial(2, c));
		double d[4] = { 3,2,1,0 };
		multy.push_back(Multinomial(3, d));
		double e[4] = { -3,-2,-1,0 };
		multy.push_back(Multinomial(3, e));
	}
	case WM_COMMAND:
	{

		if (LOWORD(wParam) == 1000)
		{
			DialogBoxParam((HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), MAKEINTRESOURCE(IDD_DIALOGBAR), 0, (DlgProc), 0);
		}
		//	break;
		int wmId = LOWORD(wParam);
		// Разобрать выбор в меню:
		switch (wmId)
		{

		case ID_32770:
		{

			HWND childHwnd = CreateWindow(ChildName, ChildName, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 150, 150, 600, 400, hWnd, 0, hInst, 0);
			if (!childHwnd)
			{
				return FALSE;
			}
			EnableWindow(hWnd, FALSE);
			return TRUE;
		}
		break;
		case ID_32771:
		{
			MessageBox(hWnd, L"Я - второй пункт меню!", L"kol-vo", MB_OK);
		}
		break;
		case ID_32772:
		{
			MessageBox(hWnd, L"Я - третий пункт меню!", L"kol-vo", MB_OK);
		}
		break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HBITMAP hbitmap;
		BITMAP bm;
		HDC hDC;
		HDC hMemDC;

		hDC = BeginPaint(hWnd, &ps);
		hMemDC = CreateCompatibleDC(hDC);
		hbitmap = (HBITMAP)LoadImage(hInst, L"2.bmp", IMAGE_BITMAP, 600, 400, LR_LOADFROMFILE);
		GetObject(hbitmap, sizeof(BITMAP), &bm);
		SelectObject(hMemDC, hbitmap);
		BitBlt(hDC, 0, 0, bm.bmWidth, bm.bmHeight, hMemDC, 0, 0, SRCCOPY);
		DeleteDC(hMemDC);
		ReleaseDC(hWnd, hDC);
		DeleteObject(hbitmap);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

