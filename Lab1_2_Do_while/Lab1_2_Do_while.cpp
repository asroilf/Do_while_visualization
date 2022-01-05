// Lab1_2_Do_while.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Lab1_2_Do_while.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
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

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB12DOWHILE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB12DOWHILE));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB12DOWHILE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB12DOWHILE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
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
            // TODO: Add any drawing code that uses hdc here...

            int x1 = 10, y1 = 100;
            int x2 = 300, y2 = 100;
            int i = 0;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc,x2, y2);
                y1 -= 5;
                y2 += 10;
                i++;
            } while (i < 16);

            //~~~~~~~~~~~~~~~~~~~~~~~~~~
            x1 = 450;
            y1 = 50;
            x2 = 450;
            y2 = 200;
            i = 0;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);
                x1 -= 5;
                y1 += 10;
                x2 += 5;
                y2 -= 10;
                i++;
            } while (i < 13);

            //~~~~~~~~~~~~~~~~~~~~~~~~~~~
            x1 = 850;
            y1 = 350;
            x2 = 605;
            y2 = 350;
            i = 0;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);
                x1 -= 9;
                y2 -= 9;
                i++;
            } while (i < 28);

            //~~~~~~~~~~~~~~~~~~~~~~~~~~~
            x1 = 950;
            y1 = 50;
            x2 = 950;
            y2 = 250;
            i = 0;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);
                y1 += 10;
                x1 -= 10;
                y2 -= 10;
                i++;
            } while (i < 14);

            //~~~~~~~~~~~~~~~~~~~~~~~~~~
            x1 = 1320;
            y1 = 50;
            x2 = 1150;
            y2 = 220;
            i = 0;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);
                x2 += 7;
                y1 += 10;
                i++;
            } while (i < 16);

            //~~~~~~~~~~~~~~~~~~~~~~~~~~~
            x1 = 150;
            y1 = 420;
            x2 = 150;
            y2 = 650;
            i = 0;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);
                x1 += 10;
                x2 -= 10;
                i++;
            } while (i < 15);

            //~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            x1 = 420;
            y1 = 420;
            x2 = 420;
            y2 = 650;
            i = 0;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);
                x1 += 10;
                y2 -= 12;
                i++;
            } while (i < 13);

            //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            x1 = 600;
            y1 = 450;
            x2 = 600;
            y2 = 550;
            i = 0;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);
                y1 -= 3;
                y2 += 3;
                x1 += 7;
                x2 += 7;
                i++;
            } while (i < 13);

            //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            x1 = 750+200;
            y1 = 420;
            x2 = 750+200;
            y2 = 570;
            i = 0;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x2, y2);
                x1 += 10;
                x2 += 10;
                y1 = y1 + 15;
                y2 = y2 - 14;
                i++;
            } while (i < 13);

            //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            x1 = 1020+200;
            y1 = 420;
            double x0 = 1090+200;
            y2 = 620;
            i = 0;
            do {
                MoveToEx(hdc, x1, y1, NULL);
                LineTo(hdc, x0, y2);
                x1 += 5;
                y1 += 11;
                x0 += 0.35;
                y2 -= 8;
                i++;
            } while (i < 20);

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

// Message handler for about box.
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
