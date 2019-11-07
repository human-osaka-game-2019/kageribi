#ifndef X_INPUT_H
#define X_INPUT_H

#define WIN32_LEAN_AND_MEAN

// Window 、Xinput ヘッダー
#include <Windows.h>
#include <XInput.h>
#include <iostream>

// XInput Library 追加
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

	void VibrateStrong(); // 強振動

	void VibrateWeak(); // 弱振動

	void VibrateBoth(); //　両振動

	void VibrateEnd(); // 振動ストップ

	void PadNumDel();

};


#endif