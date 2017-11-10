#include <windows.h>
#include <tchar.h>
#include <string>
#include <vector>

using namespace std;

#define wStr(param) to_wstring(param)
#define wArr(param) to_wstring(param).c_str()

// �������� ������� ���������
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
// ��� ������ ����
TCHAR szClassWindow[] = TEXT("WinAPI App");

vector<HWND> BUTTONS;

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wcl;

	/* 1. ����������� ������ ���� */
	// ������ ��������� WNDCLASSEX
	wcl.cbSize = sizeof(wcl);
	// ������������ �� ����, ���� ������ ������ �� ����������� ��� �� ���������
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	// ����� ������� ���������
	wcl.lpfnWndProc = WindowProc;
	// ������������ Windows
	wcl.cbWndExtra = 0;
	// ������������ Windows
	wcl.cbClsExtra = 0;
	// ���������� ������� ����������
	wcl.hInstance = hInst;
	// �������� ����������� ������
	wcl.hIcon = LoadIcon(NULL, IDI_SHIELD);
	// �������� ������������ �������
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	// ���������� ���� ����� ������
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//���������� �� �������� ����
	wcl.lpszMenuName = NULL;
	//��� ������ ����
	wcl.lpszClassName = szClassWindow;
	// ���������� ��������� ������
	wcl.hIconSm = LoadIcon(NULL, IDI_ERROR);

	/* 2. ����������� ������ ���� */
	if (!RegisterClassEx(&wcl))
		return 0; // ��� ��������� ����������� - �����

				  /* 3. �������� ���� */
				  // ��������� ���� � ���������� hWnd ������������� ���������� ����
	hWnd = CreateWindowEx(
		0, // ����������� ����� ����
		szClassWindow, // ��� ������ ����
		TEXT("������!"), // ��������� ����
		WS_OVERLAPPEDWINDOW, // ����� ����
		CW_USEDEFAULT, // �-���������� ������ �������� ���� ����
		CW_USEDEFAULT, // y-���������� ������ �������� ���� ����
		CW_USEDEFAULT, // ������ ����
		CW_USEDEFAULT, // ������ ����
		NULL, // ���������� ������������� ����
		NULL, // ���������� ���� ����
		hInst, // ������������� ����������, ���������� ����
		NULL); // ��������� �� ������� ������ ����������

			   /* 4. ����������� ���� */
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);// ����������� ����

					   /* 5. ������ ����� ��������� ��������� */
					   // ��������� ���������� ��������� �� ������� ���������
	while (GetMessage(&lpMsg, NULL, 0, 0))
	{
		TranslateMessage(&lpMsg);// ���������� ���������
		DispatchMessage(&lpMsg); // ��������������� ���������
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
	case WM_DESTROY: // ��������� � ���������� ���������
		PostQuitMessage(0); // ������� ��������� WM_QUIT
		break;
	default:
		// ��� ���������, ������� �� �������������� � ������ �������
		// ������� ������������ ������� Windows �� ��������� �� ���������
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
	//	//MessageBox(NULL, L"�������!", L"���������!", MB_OK);
	//	break;