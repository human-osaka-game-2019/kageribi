#ifndef X_INPUT_H
#define X_INPUT_H

#define WIN32_LEAN_AND_MEAN

// Window 、Xinput ヘッダー
#include <Windows.h>
#include <XInput.h>

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

/*if (state.Gamepad.wButtons & XINPUT_GAMEPAD_A) {

	// A Buttonを押したときの処理内容
}*/

/*XINPUT_STATE state;
ZeroMemory(&state, sizeof(XINPUT_STATE)); // コントローラー state 初期化
DWORD result = XInputGetState(0, &state); // コントローラー state 獲得
while (result == ERROR_SUCCESS) {
	//　コントローラーの制御コードが入る

	Sleep(30); // そのまま使うとCPU使用率が100%になるらしい
	result = XInputGetState(0, &state);
	*/


#endif