#include "Window.h"

CMainWindow* pMainWindow = 0;

CMainWindow::CMainWindow(void)
{
	pMainWindow = this;
}

CMainWindow::~CMainWindow(void)
{

}

BOOL CMainWindow::Begin(LPCTSTR Name, HINSTANCE hInstance, INT nCmdShow, INT iWidth, INT iHeight)
{
		return FALSE;
}

 
LRESULT CALLBACK CMainWindow::WndProc(HWND hWnd, UINT Msg,
	WPARAM wParam, LPARAM lParam)
{
	switch (Msg)                                                        // 메시지의 번호
	{
	case WM_CREATE:                                                      // 윈도우 생성시
		break;
	case WM_DESTROY:                                                     // 윈도우 종료시
		PostQuitMessage(0);                                              // 강제 종료
		break;
	}                                                                    // 처리할 메시지만 case문에 나열한다. 

	return DefWindowProc(hWnd, Msg, wParam, lParam);					 // 나머지는 커널이 처리하도록 메시지를 전달한다.
}

