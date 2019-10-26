#ifndef X_INPUT_H
#define X_INPUT_H

#define WIN32_LEAN_AND_MEAN

// Window �AXinput �w�b�_�[
#include <Windows.h>
#include <XInput.h>

// XInput Library �ǉ�
#pragma comment(lib, "XInput.lib")

class XBOXPad
{
private:

	XINPUT_STATE g_padState;
	int g_padNum;

public:

	XBOXPad(int playerNumber);
	XINPUT_STATE GetState();
	bool IsConnected();
	void Vibrate(int leftVal = 0, int rightVal = 0);

};

/*if (state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

	// A Button���������Ƃ��̏������e
}*/

/*XINPUT_STATE state;
ZeroMemory(&state, sizeof(XINPUT_STATE)); // �R���g���[���[ state ������
DWORD result = XInputGetState(0, &state); // �R���g���[���[ state �l��
while (result == ERROR_SUCCESS) {
	//�@�R���g���[���[�̐���R�[�h������

	Sleep(30); // ���̂܂܎g����CPU�g�p����100%�ɂȂ�炵��
	result = XInputGetState(0, &state);
	*/


#endif