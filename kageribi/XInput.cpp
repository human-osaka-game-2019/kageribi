#include "XInput.h"

XBOXPad::XBOXPad(int playerNumber)
{
	// Controller �ԍ�
	g_padNum = playerNumber - 1;
}

XINPUT_STATE XBOXPad::GetState()
{
	//memory ������
	ZeroMemory(&g_padState, sizeof(XINPUT_STATE));

	// ��� �l��
	XInputGetState(g_padNum, &g_padState);

	return g_padState;
}

bool XBOXPad::IsConnected()
{
	//memory ������
	ZeroMemory(&g_padState, sizeof(XINPUT_STATE));

	// State �l��
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
	// Vibration State ����
	XINPUT_VIBRATION Vibration;

	// Vibration ������
	ZeroMemory(&Vibration, sizeof(XINPUT_VIBRATION));

	// Vibration�̐��l��ݒ�
	Vibration.wLeftMotorSpeed = leftVal;
	Vibration.wRightMotorSpeed = rightVal;

	// Vibration��Pad�Ɏ���
	XInputSetState(g_padNum, &Vibration);
}