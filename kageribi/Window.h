#ifndef _WINDOW_H_
#define _WINDOW_H_

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
		// �������@�y�с@����
	BOOL Begin(LPCTSTR Name, HINSTANCE hInstance, INT nCmdShow, INT iWidth, INT iHeight);

		// Message ���[�v
	INT MessageLoop(void);

	//�@Winodw �v���V�[�W���@CallBack
 static	LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM IParam);

};

#endif