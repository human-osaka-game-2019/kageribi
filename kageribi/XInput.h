#ifndef X_INPUT_H
#define X_INPUT_H

#define WIN32_LEAN_AND_MEAN

// Window �AXinput �w�b�_�[
#include <Windows.h>
#include <XInput.h>
#include <iostream>

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

class X_CONTROL
{
private:

	void PadNumSet();

	XBOXPad* Player1;


public:

	bool DPadUp();

	bool DPadDown();

	bool DPadRight();

	bool DPadLeft();

	bool PadA();

	bool PadB();
	
	bool PadX();

	bool PadY();

	bool LeftSholder(); // L1

	bool RightSholder(); // R1

	bool LeftTrigger(); // L2

	bool RightTrigger(); // R2

	bool LeftStick();

	bool RightStick();

	bool StartButton();

	bool BackButton();

	void VibrateStrong(); // ���U��

	void VibrateWeak(); // ��U��

	void VibrateBoth(); //�@���U��

	void VibrateEnd(); // �U���X�g�b�v

	void PadNumDel();

};


#endif