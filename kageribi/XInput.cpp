#include "XInput.h"

XBOXPad::XBOXPad(int playerNumber)
{
	// Controller 番号
	g_padNum = playerNumber - 1;
}

XINPUT_STATE XBOXPad::GetState()
{
	//memory 初期化
	ZeroMemory(&g_padState, sizeof(XINPUT_STATE));

	// 状態 獲得
	XInputGetState(g_padNum, &g_padState);

	return g_padState;
}

bool XBOXPad::IsConnected()
{
	//memory 初期化
	ZeroMemory(&g_padState, sizeof(XINPUT_STATE));

	// State 獲得
	DWORD Result = XInputGetState(g_padNum, &g_padState);

	if (Result == ERROR_SUCCESS)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void XBOXPad::Vibrate(int leftVal, int rightVal)
{
	// Vibration State 生成
	XINPUT_VIBRATION Vibration;

	// Vibration 初期化
	ZeroMemory(&Vibration, sizeof(XINPUT_VIBRATION));

	// Vibrationの数値を設定
	Vibration.wLeftMotorSpeed = leftVal;
	Vibration.wRightMotorSpeed = rightVal;

	// VibrationをPadに実装
	XInputSetState(g_padNum, &Vibration);
}