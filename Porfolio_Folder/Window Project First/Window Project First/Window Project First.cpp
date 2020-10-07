// Window Project First.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "Window Project First.h"
#include "ControlCenter.h"
#include "SpriteCenter.h"
#include "AnimationCenter.h"
#include "Timer.h"
#include "ObjectCenter.h"
#include "Input.h"
#include "ScrollCenter.h"
#include "MainFrame.h"

#define MAX_LOADSTRING 100
// API Calculator, Painter
// Graphics

// 전역 변수:
// 종류
// Handle Instance
// char -> ASCII 1byte, UNICODE -> 2byte // Window Multibyte
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
SpriteCenter SC;
AnimationCenter AC;
Timer Time;
ObjectCenter OC;
Input KEY;
ScrollCenter Cam;

HWND Control::hWnd;
HINSTANCE Control::hInst;
HWND SpriteCenter::hWnd;
HDC SpriteCenter::hDC;

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

// main -> wWinMain
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    hInst = hInstance;

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWPROJECTFIRST, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWPROJECTFIRST));

    MSG msg;
    BOOL IsWorking = true;

    // Initializing
    static MainFrame mf;
    // 기본 메시지 루프입니다:

    if (mf.Initialize())
    {
        while (IsWorking)
        {
            // Message
            if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
            {
                if (msg.message == WM_QUIT)
                {
                    IsWorking = false;
                }
                else
                {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
            }
            Time.CheckTimer();
            KEY.Progress();
            mf.Progress();
            mf.Render();
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWPROJECTFIRST));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.


   RECT rc = {0, 0, 1200, 1200 };
   AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, NULL);

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, hInstance, nullptr);
   SpriteCenter::hWnd = hWnd;
   SpriteCenter::hDC = GetDC(hWnd);
   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

// Call(호출) Back(동작)

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

// DC -> Device Context

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    RECT rc = { 0, 0, 1200, 1200 };
    switch (message)
    {
    case WM_CREATE:
        break;
    case WM_COMMAND: // 0000 0000 0000 0010 0000 0000 0000 0010
        //center.WindowMessage(LOWORD(wParam), HIWORD(wParam));
        break;
    case WM_PAINT: // 윈도우가 다시그려질때
        break;
    case WM_GETMINMAXINFO:

        AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, NULL);
        ((MINMAXINFO*)(lParam))->ptMinTrackSize.x = rc.right - rc.left;
        ((MINMAXINFO*)(lParam))->ptMaxTrackSize.x = rc.right - rc.left;
        ((MINMAXINFO*)(lParam))->ptMinTrackSize.y = rc.bottom - rc.top;
        ((MINMAXINFO*)(lParam))->ptMaxTrackSize.y = rc.bottom - rc.top;

        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_LBUTTONDOWN: // Left Button Down

        break;
 
    case WM_RBUTTONDOWN:

        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}