#include<windows.h>
#include<commctrl.h>
#include "resource1.h"
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
LRESULT CALLBACK a(HWND hwnd, UINT uMsg, WPARAM b, LPARAM c);
LRESULT CALLBACK a1(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam);
LRESULT CALLBACK a2(HWND hwnd, UINT uMsg, WPARAM b1, LPARAM c1);
LRESULT CALLBACK a3(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE bhInstance;
HFONT hfont = CreateFont(
    0,
    0,
    0,
    0,
    500,
    FALSE,
    FALSE,
    FALSE,
    GB2312_CHARSET,
    OUT_DEFAULT_PRECIS,
    CLIP_DEFAULT_PRECIS,
    DEFAULT_QUALITY,
    FF_DONTCARE,
    L"微软雅黑"
);
HFONT hfont1 = CreateFont(
    0,
    0,
    0,
    0,
    500,
    FALSE,
    FALSE,
    FALSE,
    GB2312_CHARSET,
    OUT_DEFAULT_PRECIS,
    CLIP_DEFAULT_PRECIS,
    DEFAULT_QUALITY,
    FF_DONTCARE,
    L"宋体"
);
HFONT hfont2 = CreateFont(
    0,
    0,
    0,
    0,
    500,
    FALSE,
    FALSE,
    FALSE,
    GB2312_CHARSET,
    OUT_DEFAULT_PRECIS,
    CLIP_DEFAULT_PRECIS,
    DEFAULT_QUALITY,
    FF_DONTCARE,
    NULL
);
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR e, int f) {
	const wchar_t g[] = L"aaaaaaaaaa";
	WNDCLASS h{};
	h.lpfnWndProc = a;
	h.hInstance = hInstance;
	h.lpszClassName = g;
    h.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	RegisterClass(&h);
    HMENU hmenu = CreateMenu();
    HMENU hmenu1 = CreateMenu();
    HMENU hmenu2 = CreateMenu();
    AppendMenu(hmenu, MF_POPUP, (UINT_PTR)hmenu1, L"File");
    AppendMenu(hmenu1, MF_POPUP, 101, L"Exit");
    AppendMenu(hmenu1, MF_POPUP, 102, L"千万别点");
    AppendMenu(hmenu, MF_POPUP, (UINT_PTR)hmenu2, L"Help");
    AppendMenu(hmenu2, MF_POPUP, 200, L"About");
	HWND hwnd = CreateWindowEx(
        0,
		g,
		L"一个莫名其妙的windows桌面应用",
		WS_OVERLAPPEDWINDOW,
		500,250,800,800,
		NULL,
		hmenu,
		bhInstance,
		NULL
	);
	if (hwnd == NULL) {
		return 0;
	}
	ShowWindow(hwnd, f);
	MSG i;
	while (GetMessage(&i, NULL, 0, 0)) {
		TranslateMessage(&i);
		DispatchMessage(&i);
	}
    bhInstance = hInstance;
	return 0;
}
LRESULT CALLBACK a(HWND hwnd, UINT uMsg, WPARAM b, LPARAM c) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT j;
        HDC k = BeginPaint(hwnd, &j);
        FillRect(k, &j.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
    }
    return 0;
    case WM_CREATE:
    {
        HWND text = CreateWindowEx(
            0,
            L"static",
            L"This is a Windows APP",
            WS_CHILD | WS_VISIBLE | SS_CENTER,
            360, 100, 200, 20,
            hwnd,
            (HMENU)1003,
            bhInstance,
            NULL
        );
        HWND btn = CreateWindowEx(
            0,
            L"Button",
            L"This is a Button",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            300, 300, 150, 30,
            hwnd,
            (HMENU)1000,
            bhInstance,
            NULL
        );
        HWND btn2 = CreateWindowEx(
            0,
            L"Button",
            L"Exit",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            300, 400, 100, 30,
            hwnd,
            (HMENU)1001,
            bhInstance,
            NULL
        );
        HWND btn3 = CreateWindowEx(
            0,
            L"Button",
            L"About",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            300, 500, 100, 30,
            hwnd,
            (HMENU)1002,
            bhInstance,
            NULL
        );
        HWND btn4 = CreateWindowEx(
            0,
            L"Button",
            L"千万别点",
            WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
            300,600,100,30,
            hwnd,
            (HMENU)1004,
            bhInstance,
            NULL
        );
        HWND hbtn5 = CreateWindowEx(
            0,
            L"Button",
            L"未知",
            WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
            500,300,100,30,
            hwnd,
            (HMENU)1005,
            bhInstance,
            NULL
        );
        HWND btn6 = CreateWindowEx(
            0,
            L"Button",
            L"真正的主页",
            WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
            300,160,300,90,
            hwnd,
            (HMENU)1006,
            bhInstance,
            NULL
        );
        SendMessage(text, WM_SETFONT, (WPARAM)hfont, TRUE);
        SendMessage(btn, WM_SETFONT, (WPARAM)hfont, TRUE);
        SendMessage(btn2, WM_SETFONT, (WPARAM)hfont, TRUE);
        SendMessage(btn3, WM_SETFONT, (WPARAM)hfont, TRUE);
        SendMessage(btn4, WM_SETFONT, (WPARAM)hfont, TRUE);
        SendMessage(hbtn5, WM_SETFONT, (WPARAM)hfont, TRUE);
        SendMessage(btn6, WM_SETFONT, (WPARAM)hfont, TRUE);
        return 0;
    }
    case WM_COMMAND:
    {
        switch (LOWORD(b)) {
        case 101:
            if (MessageBox(hwnd, L"确定退出吗", L"Close the APP", MB_YESNO | MB_ICONQUESTION) == IDYES) {
                DestroyWindow(hwnd);
            }
            break;
        case 102:
            if (MessageBox(hwnd, L"如果你点了是,你会后悔的", L"警告", MB_YESNO | MB_ICONEXCLAMATION) == IDYES) {
                while (true) {
                    MessageBox(hwnd, L"你不用神器永远关不掉我,至于神器是什么,我不会告诉你", L"让你点是", MB_OK);
                }
            }
            break;
        case 200:
            MessageBox(hwnd, L"版本号:1.0.0", L"关于", MB_OK | MB_ICONASTERISK);
        }
        if (LOWORD(b) == 1000 && HIWORD(b) == BN_CLICKED) {
            MessageBox(NULL, L"我又没叫你点我", L"你点我干嘛", MB_OK | MB_ICONERROR);
        }
        else if (LOWORD(b) == 1001 && HIWORD(b) == BN_CLICKED) {
            if (MessageBox(hwnd, L"确定退出吗", L"Close the APP", MB_YESNO | MB_ICONQUESTION) == IDYES) {
                DestroyWindow(hwnd);
            }
        }
        else if (LOWORD(b) == 1002 && HIWORD(b) == BN_CLICKED) {
            MessageBox(hwnd, L"版本号:1.0.0", L"关于", MB_OK|MB_ICONASTERISK);
        }
        else if (LOWORD(b) == 1004 && HIWORD(b) == BN_CLICKED) {
            if (MessageBox(hwnd, L"如果你点了是,你会后悔的", L"警告", MB_YESNO | MB_ICONEXCLAMATION) == IDYES) {
                while (true) {
                    MessageBox(hwnd, L"你不用神器永远关不掉我,至于神器是什么,我不会告诉你", L"让你点是",MB_OK);
                }
            }
        }
        else if (LOWORD(b) == 1005 && HIWORD(b) == BN_CLICKED) {
            MessageBox(hwnd, L"这里啥都没有", L"快退出",MB_OK|MB_ICONEXCLAMATION);
        }
        else if (LOWORD(b) == 1006 && HIWORD(b) == BN_CLICKED) {
            const wchar_t wc[] = L"aaa";
            WNDCLASS wc2{};
            wc2.lpfnWndProc = a1;
            wc2.hInstance = bhInstance;
            wc2.lpszClassName = wc;
            RegisterClass(&wc2);
            HWND hwnd2 = CreateWindowEx(
                0,
                wc,
                L"真正的主页",
                WS_OVERLAPPEDWINDOW,
                CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
                NULL,
                NULL,
                bhInstance,
                NULL
            );
            if (hwnd2 == NULL) {
                MessageBox(NULL, L"出错了", L"错误", MB_OK | MB_ICONERROR);
                return 0;
            }
            ShowWindow(hwnd2, SW_SHOW);
        }
    }
    }
    return DefWindowProc(hwnd, uMsg, b, c);
}
LRESULT CALLBACK a1(HWND hwnd, UINT uMsg, WPARAM wparam, LPARAM lparam) {
    switch (uMsg) {
    case WM_DESTROY:
        DestroyWindow(hwnd);
        return 0;
    case WM_PAINT:
    {
        PAINTSTRUCT ps2;
        HDC hdc2 = BeginPaint(hwnd, &ps2);
        FillRect(hdc2, &ps2.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        EndPaint(hwnd, &ps2);
    }
    return 0;
    case WM_CREATE:
    {
        HWND text1 = CreateWindowEx(
            0,
            L"BUTTON",
            L"文本输入框(测试)",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            500, 150, 500, 100,
            hwnd,
            (HMENU)2000,
            bhInstance,
            NULL
        );
        HWND btn1 = CreateWindowEx(
            0,
            L"BUTTON",
            L"设置",
            WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
            500,350,500,100,
            hwnd,
            (HMENU)2001,
            bhInstance,
            NULL
        );
        HMENU hmenua1 = CreateMenu();
        SetMenu(hwnd, hmenua1);
        HMENU hmenua11 = CreateMenu();
        AppendMenu(hmenua1, MF_POPUP, (UINT_PTR)hmenua11, L"File");
        AppendMenu(hmenua11, MF_POPUP, 300, L"Close the window");
        SendMessage(text1, WM_SETFONT, (WPARAM)hfont, TRUE);
        SendMessage(btn1, WM_SETFONT, (WPARAM)hfont, TRUE);
    }
    case WM_COMMAND:
    {
        switch (LOWORD(wparam)) {
        case 300:
            DestroyWindow(hwnd);
        }
        if (LOWORD(wparam) == 2000 && HIWORD(wparam) == BN_CLICKED) {
            const wchar_t editw[] = L"aaasssddd";
            WNDCLASS editw1{};
            editw1.lpfnWndProc = a2;
            editw1.hInstance = bhInstance;
            editw1.lpszClassName = editw;
            RegisterClass(&editw1);
            HWND hwnd2 = CreateWindowEx(0, editw, L"文本输入框", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, bhInstance, NULL);
            if (hwnd2 == NULL) {
                MessageBox(hwnd, L"错误", L"错误", MB_OK | MB_ICONERROR);
            }
            ShowWindow(hwnd2, SW_SHOW);
        }
        if (LOWORD(wparam) == 2001 && HIWORD(wparam) == BN_CLICKED) {
            const wchar_t setw[] = L"aaasssddd111";
            WNDCLASS set1{};
            set1.lpfnWndProc = a3;
            set1.hInstance = bhInstance;
            set1.lpszClassName = setw;
            RegisterClass(&set1);
            HWND hwnds = CreateWindowEx(0, setw, L"设置", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1400, 800, NULL, NULL, bhInstance, NULL);
            if (hwnds == NULL){
                MessageBox(hwnd, L"错误", L"错误", MB_OK | MB_ICONERROR);
            }
            ShowWindow(hwnds, SW_SHOW);
        }
    }
    }
    return DefWindowProc(hwnd, uMsg, wparam, lparam);
}
LRESULT CALLBACK a2(HWND hwnd, UINT uMsg, WPARAM b1, LPARAM c1) {
    switch (uMsg) {
    case WM_DESTROY:
        DestroyWindow(hwnd);
        return 0;
    case WM_PAINT:
    {
        PAINTSTRUCT ps1;
        HDC hd = BeginPaint(hwnd, &ps1);
        FillRect(hd, &ps1.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        EndPaint(hwnd, &ps1);
    }
    return 0;
    case WM_CREATE:
    {
        int width = LOWORD(c1)-100;
        int height = HIWORD(c1);
        
        HWND edit1 = CreateWindowEx(
            0,
            L"EDIT",
            NULL,
            WS_BORDER|WS_CHILD|WS_VISIBLE|ES_LEFT|ES_AUTOVSCROLL|ES_MULTILINE,
            CW_USEDEFAULT,CW_USEDEFAULT,width,height,
            hwnd,
            (HMENU)3000,
            bhInstance,
            NULL
        );
        SendMessage(edit1, WM_SETFONT, (WPARAM)hfont, TRUE);
    }
    }
    return DefWindowProc(hwnd, uMsg, b1, c1);
}
LRESULT CALLBACK a3(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY:
        DestroyWindow(hwnd);
        return 0;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        EndPaint(hwnd, &ps);
    }
    return 0;
    case WM_CREATE:
    {
        HWND statictxt = CreateWindowEx(
            0,
            L"STATIC",
            L"此功能任然再开发，功能不完整",
            WS_CHILD | WS_VISIBLE | SS_CENTER,
            650, 350, 400, 25,
            hwnd,
            NULL,
            bhInstance,
            NULL
        );
        SendMessage(statictxt, WM_SETFONT, (WPARAM)hfont, TRUE);
        HWND combobox = CreateWindowEx(
            0,
            WC_COMBOBOX,
            L"",
            CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
            750, 450, 100, 30,
            hwnd,
            NULL,
            bhInstance,
            NULL
        );
        SendMessage(combobox, WM_SETFONT, (WPARAM)hfont, TRUE);
        SendMessage(combobox, CB_ADDSTRING, (WPARAM)0, (LPARAM)L"微软雅黑(默认)");
        SendMessage(combobox, CB_ADDSTRING, (WPARAM)0, (LPARAM)L"宋体");
        SendMessage(combobox, CB_ADDSTRING, (WPARAM)0, (LPARAM)L"无样式自创字体");
        SendMessage(combobox, CB_ADDSTRING, (WPARAM)0, (LPARAM)L"Win32API默认字体(开发)");
        HWND statictext = CreateWindowEx(
            0,
            L"STATIC",
            L"字体",
            WS_CHILD|WS_VISIBLE|SS_CENTER,
            650,450,50,25,
            hwnd,
            NULL,
            bhInstance,
            NULL
        );
        SendMessage(statictext, WM_SETFONT, (WPARAM)hfont, TRUE);
        HWND button = CreateWindowEx(
            0,
            L"BUTTON",
            L"应用",
            WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
            700,550,100,30,
            hwnd,
            (HMENU)4000,
            bhInstance,
            NULL
        );
        SendMessage(button, WM_SETFONT, (WPARAM)hfont, TRUE);
    }
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}