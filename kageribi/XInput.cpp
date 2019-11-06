#include "XInput.h"

XBOXPad::XBOXPad(int playerNumber)
{
	// Controller ”Ô†
	g_padNum = playerNumber - 1;
}

XINPUT_STATE XBOXPad::GetState()
{
	//memory ‰Šú‰»
	ZeroMemory(&g_padState, sizeof(XINPUT_STATE));

	// ó‘Ô Šl“¾
	XInputGetState(g_padNum, &g_padState);

	return g_padState;
}

bool XBOXPad::IsConnected()
{
	//memory ‰Šú‰»
	ZeroMemory(&g_padState, sizeof(XINPUT_STATE));

	// State Šl“¾
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
	// Vibration State ¶¬
	XINPUT_VIBRATION Vibration;

	// Vibration ‰Šú‰»
	ZeroMemory(&Vibration, sizeof(XINPUT_VIBRATION));

	// Vibration‚Ì”’l‚ğİ’è
	Vibration.wLeftMotorSpeed = leftVal;
	Vibration.wRightMotorSpeed = rightVal;

	// Vibration‚ğPad‚ÉÀ‘•
	XInputSetState(g_padNum, &Vibration);
}