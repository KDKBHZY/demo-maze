// WindowsProject2.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "WindowsProject2.h"

#define MAX_LOADSTRING 100
int MIgo[10][10] =
{
		{0,1,0,0,0,0,0,1,0,1},
		{0,0,0,0,0,0,0,1,0,1},
		{0,1,0,1,1,0,0,1,0,1},
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,1,0,0,0},
		{1,1,0,1,0,0,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,1,1,1,0,1},
		{0,0,0,0,0,0,0,1,0,1},
		{1,1,0,0,0,0,0,1,0,0}
};
// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT2));

    MSG msg;

    // 主消息循环:
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



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT2));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT2);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 将实例句柄存储在全局变量中

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		100, 100, 600, 600, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	

	static int x1 = 0;
	static int y1 = 0;
	static int x2 = 50;
	static int y2 = 50;
	switch (message)
	{
	
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 分析菜单选择:
		switch (wmId)
		{
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
		HDC hdc = BeginPaint(hWnd, &ps);
		HBRUSH hBrush;
		hBrush = CreateSolidBrush(RGB(65, 105, 225));
		RECT rect;
		 
		Ellipse(hdc,x1, y1, x2, y2);

		rect.left = 0;
		rect.right = 50;
		rect.top = 0;
		rect.bottom = 50;
		for(int i = 0;i < 10;i++){
		for (int j = 0;j < 10;j++) {
			if (MIgo[i][j] == 1) {
				FillRect(hdc, &rect, hBrush);
			}
			rect.left += 50;
			rect.right += 50;

		}
		rect.left = 0;
		rect.right = 50;
		rect.top += 50;
		rect.bottom +=50;
}
		HPEN hPen;
		hPen = CreatePen(PS_SOLID, 2, RGB(188, 20, 20));

		MoveToEx(hdc, 0, 0, NULL);
		LineTo(hdc, 0, 500);
		MoveToEx(hdc, 0, 0, NULL);
		LineTo(hdc, 500, 0);
		MoveToEx(hdc, 500, 0, NULL);
		LineTo(hdc, 500, 500);
		MoveToEx(hdc, 0, 500, NULL);
		LineTo(hdc, 500, 500);
EndPaint(hWnd, &ps);
        }
        break;
		
		
	case WM_KEYDOWN:
	{
		switch (wParam) {

		case VK_LEFT:
			//VK_UP、VK_RIGHT、VK_DOWN
			if (x2 <= 500 && y2 <= 500 && x1 >= 0 && y1 >= 0) {
				x1 = x1 - 50;
				x2 = x2 - 50;
				InvalidateRect(hWnd, NULL, TRUE);

			}//重绘

			break;
		case VK_RIGHT:
			if (x2 <= 500 && y2 < 500 && x1 >= 0 && y1 >= 0) {
				x1 = x1 + 50;
				x2 = x2 + 50;
				InvalidateRect(hWnd, NULL, TRUE);

			}//重绘

			break;
		case VK_UP:
			if (x2 <= 500 && y2 < 500 && x1 >= 0 && y1 >= 0) {
				y1 = y1 - 50;
				y2 = y2 - 50;
				InvalidateRect(hWnd, NULL, TRUE);

			}//重绘	

			break;
		case VK_DOWN:
			if (x2 <= 500 && y2 < 500 && x1 >= 0 && y1 >= 0) {
				y1 = y1 + 50;
				y2 = y2 + 50;
				InvalidateRect(hWnd, NULL, TRUE);

			}//重绘
			break;
		default:
			break;
		}
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

// “关于”框的消息处理程序。
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
