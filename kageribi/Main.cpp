#include <iostream>
#include "Window.h"
#include "XInput.h"

# define XINPUT_GAMEPAD_TRIGGER_THRESHOLD 30

XBOXPad* Player1;

int PadControl(int argc, char* argv[])
{
	Player1 = new XBOXPad(1);

	std::cout << "Instructions:\n";
	std::cout << "[A] Vibrate Left Only\n";
	std::cout << "[B] Vibrate Right Only\n";
	std::cout << "[X] Vibrate Both\n";
	std::cout << "[Y] Vibrate Neither\n";
	std::cout << "[BACK] Exit\n";
	
	while (true)
	{

		if (Player1->IsConnected())
		{

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP)
			{

				std::cout << "[UP] Working Now\n";

			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN)
			{

				std::cout << "[DOWN] Working Now\n";

			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT)
			{

				std::cout << "[LEFT] Working Now\n";

			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
			{

				std::cout << "[RIGHT] Working Now\n";

			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)
			{
				std::cout << "[A] Working Now\n";
				Player1->Vibrate(65535, 0);
			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B)
			{
				std::cout << "[B] Working Now\n";
				Player1->Vibrate(0, 65535);
			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X)
			{
				std::cout << "[X] Working Now\n";
				Player1->Vibrate(65535, 65535);
			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y)
			{
				std::cout << "[Y] Working Now\n";
				Player1->Vibrate();
			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
			{
				std::cout << "[LEFT SHOULDER] Working Now\n";
			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER)
			{
				std::cout << "[RIGHT SHOULDER] Working Now\n";
			}

			if (Player1->GetState().Gamepad.bLeftTrigger & XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
			{

				std::cout << "[LEFT TRIGGER] Working Now\n";

			}

			if (Player1->GetState().Gamepad.bRightTrigger & XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
			{

				std::cout << "[RIGHT TRIGGER] Working Now\n";

			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB)
			{

				std::cout << "[Left Stick] Working Now\n";

				float LX = Player1->GetState().Gamepad.sThumbLX;
				float LY = Player1->GetState().Gamepad.sThumbLY;

				// Lスティックが押された距離(どのぐらい押されたか)
				float magnitude = sqrt(LX * LX + LY * LY);

				// Lスティックが押された方向
				float normalizedLX = LX / magnitude;
				float normalizedLY = LY / magnitude;

				float normalizedMagnitude = 0;

				if (magnitude > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
				{
					// 最大値
					if (magnitude > 32767) magnitude = 32767;

					// DeadZoneの限界の相対的な大きさ
					magnitude -= XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE;


					//　数値を0.0 から 1.0まで与えることができる
					normalizedMagnitude = magnitude / (32767 - XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);
				}
				else // コントローラーがDeadZoneにある時、数値が減少(reduce or Zero Out)
				{
					magnitude = 0.0;
					normalizedMagnitude = 0.0;
				}


			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB)
			{

				std::cout << "[Right Stick] Working Now\n";

				float RX = Player1->GetState().Gamepad.sThumbRX;
				float RY = Player1->GetState().Gamepad.sThumbRY;

				// Rスティックが押された距離(どのぐらい押されたか)
				float magnitude = sqrt(RX * RX + RY * RY);

				// Rスティックが押された方向
				float normalizedRX = RX / magnitude;
				float normalizedRY = RY / magnitude;

				float normalizedMagnitude = 0;

				if (magnitude > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
				{
					// 最大値
					if (magnitude > 32767) magnitude = 32767;

					// DeadZoneの限界の相対的な大きさ
					magnitude -= XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE;


					//　数値を0.0 から 1.0まで与えることができる
					normalizedMagnitude = magnitude / (32767 - XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE);
				}
				else // コントローラーがDeadZoneにある時、数値が減少(reduce or Zero Out)
				{
					magnitude = 0.0;
					normalizedMagnitude = 0.0;
				}


			}

			if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_BACK)
			{
				break;
			}

		}
		else
		{
			std::cout << "\n\tERROR! PLAYER 1 - XBOX 360 Controller Not Found!\n";
			std::cout << "Press Any Key To Exit.";
			std::cin.get();
			break;
		}

	}

	delete(Player1);

	return(0);

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPTSTR lpszCmdLine, int nCmdShow)
{

	HWND hWnd;
	
	CMainWindow* pMainWindow;

	WNDCLASS WndClass;                                                   // 윈도우 클래스 타입인 WNDCLASSEX의 변수를 만들고 각 필드에 값 부여

	WndClass.style = CS_HREDRAW | CS_VREDRAW;							 // 윈도우의 크기를 변경하면 다시 그리는 형태의 윈도우
	WndClass.lpfnWndProc = CMainWindow::WndProc;										 // WndProc은 메시지 처리를 위한 함수의 이름
	WndClass.cbClsExtra = 0;                                             // 보통 클래스와 운도우를 위한 여분의 메모리는 사용치 않는다.
	WndClass.cbWndExtra = 0;                                             // 그러므로 값을 0을 써준다.
	WndClass.hInstance = hInstance;										 // 응용 프로그램 인스턴스를 WinMain()의 첫번째 매개변수로 넣어줌 
	WndClass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);					 // 로드하는 아이콘
	WndClass.hCursor = LoadCursor(hInstance, IDC_ARROW);						 // 로드하는 커서
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		 // 흰색바탕(WHITE_BRUSH)의 윈도우를 생성한다.
	WndClass.lpszMenuName = NULL;										 // 아직은 메뉴도 만들지 않고 사용치 않으므로 NULL이다.
	WndClass.lpszClassName = WINDOW_CLASS_NAME;						 // 윈도우 클래스 이름을 "Window Class Name 라고 하였다.
	RegisterClass(&WndClass);										 // 커널에 등록하기 위한 함수 사용방법은 매개변수로 WNDCLASSEX의


																		 // 주소를 넣어주면 된다.
	hWnd = CreateWindow(												 // 윈도의 핸들값 반환
		WINDOW_CLASS_NAME,                                             // 윈도우 클래스 이름 
		"kageribi",													     // 만들어질 윈도우 타이틀바에 나타날 이름
		WS_POPUP,														 // 이미 정의된 스타일 값중 선택할수 있다. (WS_OVERLAPPEDWINDOW)는 타이틀바에 최소 , 최대화 ,닫기 버튼이 나타나며 오른쪽 마우스 버튼을 눌렀을 때 시스템 메뉴가 나타나는 윈도우이다.
		0,																 // 생성되는 윈도우가 어느 위치에 나타나야 하는지 x값과 y좌표값으로 써준다.
		0,																 // CW_USEDEFAULT는 커널에 의해 기본값을 사용하라는 의미이다.
		GetSystemMetrics(SM_CXSCREEN),                                   // 생성되는 윈도우의 폭과 높이 값으로 단위는 픽셀이다.
		GetSystemMetrics(SM_CXSCREEN),                                   // CW_USEDEFAULT는 커널에 의해 기본값을 사용하라는 의미이다.
		0,
		0,
		NULL,
		NULL
	);

	ShowWindow(hWnd, nCmdShow);								 // nCmdShow는 윈도우를 화면에 나타내는 방법으로 상수값을 제공한다.
	UpdateWindow(hWnd);													 // 윈도우에 WM_PAINT 메시지를 보내 화면에 기본 출력을 한다.


	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{

			TranslateMessage(&msg);                                          // 두 메시지를 하나로 변형할때 사용한다.
			DispatchMessage(&msg);                                           // 메시지를 처리하는 함수에 메시지를 보낸다.
				
	}

	return (int)msg.wParam;

	return TRUE;
}