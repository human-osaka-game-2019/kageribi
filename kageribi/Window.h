#ifndef WINDOW_HEADER
#define WINDOW_HEADER

#include <Windows.h>

#define WINDOW_CLASS_NAME "kageribi"
//#define CreateWindow

//#pragma once



class CMainWindow
{
public :
	CMainWindow(void);
	~CMainWindow(void);

public :
		// 初期化　及び　処理
	BOOL Begin(LPCTSTR Name, HINSTANCE hInstance, INT nCmdShow, INT iWidth, INT iHeight);

		// Message ループ
	INT MessageLoop(void);

	//　Winodw プロシージャ　CallBack
 static	LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM IParam);

};

#endif // !WINDOW_HEADER