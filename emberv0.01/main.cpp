
#include <windows.h>
#include <string>
using namespace std;

const wchar_t g_szClassName[] = L"Codename_Ember";

// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static int red = 255, blue = 255, green = 255,
		red2 = 255, blue2 = 255, green2 = 255;

	static int x1 = 100, y1 = 100, x2 = 200, y2 = 200, delta_x = 0, delta_y = 0;

	switch (msg)
	{
	case WM_PAINT:
		HDC hDC;
		PAINTSTRUCT Ps;
		hDC = BeginPaint(hwnd, &Ps);
		HFONT hFont;        // the handle to the font

		int fontHeight;
		RECT rect;

		fontHeight = 35;
		hFont = CreateFont(fontHeight, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, L"Arial");


		HPEN hPen;
		HBRUSH hBrush;

		hPen = CreatePen(PS_SOLID, 2, RGB(red, blue, green));
		hBrush = CreateSolidBrush(RGB(red2, blue2, green2));
		SelectObject(hDC, hPen);
		SelectObject(hDC, hBrush);

		Rectangle(hDC, (x1 + delta_x), (y1 + delta_y), (x2 + delta_x), (y2 + delta_y));

		for (int i = 10; i <= 30; i += 10)
		{
			rect.top = 500;
			rect.bottom = 600;
			rect.left = 100;
			rect.right = 600;

			wstring displayString = L"There are texts here!";

			DrawText(hDC, displayString.c_str(), -1, &rect, DT_CENTER | DT_WORDBREAK);
		}

		DeleteObject(hBrush);
		DeleteObject(hPen);


		EndPaint(hwnd, &Ps);
		break;
	case WM_CHAR:
		if (wParam == 'c' || wParam == 'C')
		{
			red = rand() % 255;
			blue = rand() % 255;
			green = rand() % 255;

			red2 = rand() % 255;
			blue2 = rand() % 255;
			green2 = rand() % 255;
		}
		break;
	case WM_KEYDOWN:
		if (wParam == VK_SPACE)
		{

		}
		else if (wParam == VK_RIGHT)
		{
			if (delta_x < 61)
			{
				delta_x += 2;
			}
		}
		else if (wParam == VK_LEFT)
		{
			if (delta_x > -61)
			{
				delta_x -= 2;
			}
		}
		else if (wParam == VK_UP)
		{
			if (delta_y < 41)
			{
				delta_y += 2;
			}
		}
		else if (wParam == VK_DOWN)
		{
			if (delta_y > -41)
			{
				delta_y -= 2;
			}
		}
		else if (wParam == VK_PRIOR)
		{

		}
		else if (wParam == VK_NEXT)
		{

		}
		else if (wParam == VK_HOME)
		{

		}
		InvalidateRect(hwnd, NULL, true);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;

	//Step 1: Registering the Window Class
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 5);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, L"Window Registration Failed!", L"Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	// Step 2: Creating the Window
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		g_szClassName,
		L"COP_3530_CHRISCARL",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 700, 600,
		NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)
	{
		MessageBox(NULL, L"Window Creation Failed!", L"Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// Step 3: The Message Loop
	while (GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}
