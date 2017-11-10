#include <windows.h>
#include <tchar.h>
#include <string>
#include <vector>

using namespace std;

#define wStr(param) to_wstring(param)
#define wArr(param) to_wstring(param).c_str()

// прототип оконной процедуры
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
// »м€ класса окна
TCHAR szClassWindow[] = TEXT("WinAPI App");

vector<HWND> BUTTONS;

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;

	/* 1. ќпределение класса окна */
	// размер структуры WNDCLASSEX
	wcl.cbSize = sizeof(wcl);
	// ѕерерисовать всЄ окно, если изменЄн размер по горизонтали или по вертикали
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	// адрес оконной процедуры
	wcl.lpfnWndProc = WindowProc;
	// используетс€ Windows
	wcl.cbWndExtra = 0;
	// используетс€ Windows
	wcl.cbClsExtra = 0;
	// дескриптор данного приложени€
	wcl.hInstance = hInst;
	// загрузка стандартной иконки
	wcl.hIcon = LoadIcon(NULL, IDI_SHIELD);
	// загрузка стандартного курсора
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	// заполнение окна белым цветом
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//приложение не содержит меню
	wcl.lpszMenuName = NULL;
	//им€ класса окна
	wcl.lpszClassName = szClassWindow;
	// отсутствие маленькой иконки
	wcl.hIconSm = LoadIcon(NULL, IDI_ERROR);

	/* 2. –егистраци€ класса окна */
	if (!RegisterClassEx(&wcl))
		return 0; // при неудачной регистрации - выход

				  /* 3. —оздание окна */
				  // создаетс€ окно и переменной hWnd присваиваетс€ дескриптор окна
	hWnd = CreateWindowEx(
		0, // расширенный стиль окна
		szClassWindow, // им€ класса окна
		TEXT("ѕривет!"), // заголовок окна
		WS_OVERLAPPEDWINDOW, // стиль окна
		CW_USEDEFAULT, // х-координата левого верхнего угла окна
		CW_USEDEFAULT, // y-координата левого верхнего угла окна
		CW_USEDEFAULT, // ширина окна
		CW_USEDEFAULT, // высота окна
		NULL, // дескриптор родительского окна
		NULL, // дескриптор меню окна
		hInst, // идентификатор приложени€, создавшего окно
		NULL); // указатель на область данных приложени€

			   /* 4. ќтображение окна */
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);// перерисовка окна

					   /* 5. «апуск цикла обработки сообщений */
					   // получение очередного сообщени€ из очереди сообщений
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);// трансл€ци€ сообщени€
		DispatchMessage(&lpMsg); // диспетчеризаци€ сообщений
	}
	return lpMsg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	TCHAR buffer[100], text[100];
	static HWND find;
	static int x = 0;
	static int y = 0;
	switch (uMessage)
	{
	case WM_CREATE:
	{
		HWND hButton1 = CreateWindow(	L"BUTTON"/* Predefined class; Unicode assumed*/, L"Move Win"/* Button text*/,WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON/* Styles*/,
		10/* x position*/, 10/* y position*/, 100/* Button width*/, 100/* Button height*/, hWnd/* Parent window*/, NULL/* No menu.*/,(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),NULL);      // Pointer not needed.
		HWND hButton2 = CreateWindow(L"BUTTON"/* Predefined class; Unicode assumed*/, L"Close Win"/* Button text*/, WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON/* Styles*/,
			10/* x position*/, 120/* y position*/, 100/* Button width*/, 100/* Button height*/, hWnd/* Parent window*/, NULL/* No menu.*/, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		HWND hButton3 = CreateWindow(L"BUTTON"/* Predefined class; Unicode assumed*/, L"Change Text"/* Button text*/, WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON/* Styles*/,
			10/* x position*/, 240/* y position*/, 100/* Button width*/, 100/* Button height*/, hWnd/* Parent window*/, NULL/* No menu.*/, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		HWND hText = CreateWindow(L"EDIT"/* Predefined class; Unicode assumed*/, L"Class"/* Button text*/, WS_CHILD | WS_VISIBLE | WS_BORDER | WS_HSCROLL | WS_VSCROLL | ES_MULTILINE | ES_AUTOHSCROLL |
			ES_AUTOVSCROLL/* Styles*/,
			150/* x position*/, 10/* y position*/, 400/* Button width*/, 100/* Button height*/, hWnd/* Parent window*/, NULL/* No menu.*/, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		HWND hText1 = CreateWindow(L"EDIT"/* Predefined class; Unicode assumed*/, L"Some Text"/* Button text*/, WS_CHILD | WS_VISIBLE | WS_BORDER | WS_HSCROLL | WS_VSCROLL | ES_MULTILINE | ES_AUTOHSCROLL |
			ES_AUTOVSCROLL/* Styles*/,
			150/* x position*/, 240/* y position*/, 400/* Button width*/, 100/* Button height*/, hWnd/* Parent window*/, NULL/* No menu.*/, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		BUTTONS.push_back(hButton1);
		BUTTONS.push_back(hButton2);
		BUTTONS.push_back(hButton3);
		BUTTONS.push_back(hText);
		BUTTONS.push_back(hText1);
		break;
	}
	case WM_COMMAND:
	{
		SendMessage(BUTTONS[3], WM_GETTEXT, 100, LPARAM(buffer));
		SendMessage(BUTTONS[4], WM_GETTEXT, 100, LPARAM(text));
		find = FindWindow(buffer, NULL);
		if ((HWND)lParam == BUTTONS[0])
		{
			SetTimer(hWnd, 123, 10, NULL);
			x = 0, y = 0;
			if (x >= 0 && x< 1400 && y == 0)
				x++;
			else if (y >= 0 && y< 520 && x == 1400)
				y++;
			else if (x > 0 && x <= 1400 && y == 520)
				x--;
			else if (y > 0 && y <= 520 && x == 0)
				y--;
			MoveWindow(find, x, y, 500, 500, TRUE);
		}
		if ((HWND)lParam == BUTTONS[1])
		{
			SendMessage(find, WM_CLOSE, NULL, NULL);
		}

		if ((HWND)lParam == BUTTONS[2])
		{
			SetWindowText(find, text);
		}
	/*	HWND hNotepad = FindWindow(L"Notepad", NULL);
		HWND hEdit = FindWindowEx(hNotepad, NULL, L"Edit", NULL);
		SendMessage(hEdit, WM_SETTEXT, NULL, LPARAM(buffer));
		MessageBox(NULL, buffer, L"TITLE", MB_OK);*/
		break;
	}
	case WM_TIMER:
		if (x >= 0 && x< 1400 && y == 0)
			x++;
		else if (y >= 0 && y< 520 && x == 1400)
			y++;
		else if (x > 0 && x <= 1400 && y == 520)
			x--;
		else if (y > 0 && y <= 520 && x == 0)
			y--;
		MoveWindow(find, x, y, 500, 500, TRUE);
		if (x == 0 && y == 0)
		{
			KillTimer(hWnd, 123);
		}
		break;
	case WM_DESTROY: // сообщение о завершении программы
		PostQuitMessage(0); // посылка сообщени€ WM_QUIT
		break;
	default:
		// все сообщени€, которые не обрабатываютс€ в данной оконной
		// функции направл€ютс€ обратно Windows на обработку по умолчанию
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}
	//case WM_KEYDOWN:
	//	if (wParam == VK_UP)
	//	{
	//		MoveWindow(h, x , y += 10, 800, 800, TRUE);
	//	}
	//	else if (wParam == VK_DOWN)
	//	{
	//		MoveWindow(h, x, y -= 10, 800, 800, TRUE);

	//	}
	//	else if (wParam == VK_LEFT)
	//	{
	//		MoveWindow(h, x -= 10, y, 800, 800, TRUE);

	//	}
	//	else if (wParam == VK_RIGHT)
	//	{
	//		MoveWindow(h, x += 10, y, 800, 800, TRUE);
	//	}
	//		//MessageBox(NULL, wArr(wParam), L"Title", MB_OK);
	//	break;


	//case WM_MOUSEMOVE:
	//	x = LOWORD(lParam), y = HIWORD(lParam);
	//	str = L"x: " + wStr(x) + L",y:" + wStr(y);
	//	SetWindowText(hWnd, str.c_str());
	//	//MessageBox(NULL, L"«дорова!", L"«аголовок!", MB_OK);
	//	break;