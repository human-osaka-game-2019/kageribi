#include "XInput.h"

# define XINPUT_GAMEPAD_TRIGGER_THRESHOLD 30

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

void X_CONTROL::PadNumSet()
{

	Player1 = new XBOXPad(1);

}

void X_CONTROL::PadNumDel()
{

	delete(Player1);

}

bool X_CONTROL::DPadUp()
{
	if (Player1->IsConnected())
	{
		if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP)
		{
			return true;
		}
	}

	return false;
}

bool X_CONTROL::DPadDown()
{
	if (Player1->IsConnected())
	{
		if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN)
		{
			return true;
		}
	}

	return false;
}

bool X_CONTROL::DPadLeft()
{
	if (Player1->IsConnected())
	{
		if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT)
		{
			return true;
		}
	}

	return false;
}

bool X_CONTROL::DPadRight()
{
	if (Player1->IsConnected())
	{
		if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
		{
			return true;
		}
	}

	return false;
}

bool X_CONTROL::PadA()
{
	if (Player1->IsConnected())
	{
		if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)
		{
			return true;
		}
	}

	return false;
}

bool X_CONTROL::PadB()
{
	if (Player1->IsConnected())
	{
		if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B)
		{
			return true;
		}
	}

	return false;
}

bool X_CONTROL::PadX()
{
	if (Player1->IsConnected())
	{
		if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X)
		{
			return true;
		}
	}

	return false;
}

bool X_CONTROL::PadY()
{
	if (Player1->IsConnected())
	{
		if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y)
		{
			return true;
		}
	}

	return false;
}

bool X_CONTROL::LeftSholder()
{
	if (Player1->IsConnected())
	{
		if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
		{
			return true;
		}
	}

	return false;
}

bool X_CONTROL::RightSholder()
{
	if (Player1->IsConnected())
	{
		if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER)
		{
			return true;
		}
	}

	return false;
}

bool X_CONTROL::LeftTrigger()
{
	if (Player1->IsConnected())
	{
		if (Player1->GetState().Gamepad.bLeftTrigger & XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
		{
			return true;
		}
	}

	return false;
}

bool X_CONTROL::RightTrigger()
{
	if (Player1->IsConnected())
	{
		if (Player1->GetState().Gamepad.bRightTrigger & XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
		{
			return true;
		}
	}

	return false;
}

bool X_CONTROL::LeftStick()
{
	if (Player1->IsConnected())
	{
		if ((Player1->GetState().Gamepad.sThumbLX & XINPUT_GAMEPAD_LEFT_THUMB) &&
			(Player1->GetState().Gamepad.sThumbLY & XINPUT_GAMEPAD_LEFT_THUMB))
		{
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

			if (Player1->GetState().Gamepad.sThumbLX > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
			{
				return true;
			}

			if (Player1->GetState().Gamepad.sThumbLX < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
			{
				return true;
			}

			if (Player1->GetState().Gamepad.sThumbLY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
			{
				return true;
			}

			if (Player1->GetState().Gamepad.sThumbLY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
			{
				return true;
			}
		}
	}

	return false;
}

bool X_CONTROL::RightStick()
{
	if (Player1->IsConnected())
	{
		if ((Player1->GetState().Gamepad.sThumbRX & XINPUT_GAMEPAD_RIGHT_THUMB) &&
			(Player1->GetState().Gamepad.sThumbRY & XINPUT_GAMEPAD_RIGHT_THUMB))
		{

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

			if (Player1->GetState().Gamepad.sThumbRX > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
			{
				return true;
			}

			if (Player1->GetState().Gamepad.sThumbRX < -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
			{
				return true;
			}

			if (Player1->GetState().Gamepad.sThumbRY > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
			{
				return true;
			}

			if (Player1->GetState().Gamepad.sThumbRY < -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
			{
				return true;
			}
		}
	}

	return false;
}

bool X_CONTROL::BackButton()
{
	if (Player1->IsConnected())
	{
		if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_BACK)
		{
			return true;
		}
	}

	return false;
}

bool X_CONTROL::StartButton()
{
	if (Player1->IsConnected())
	{
		if (Player1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_START)
		{
			return true;
		}
	}

	return false;
}

void X_CONTROL::VibrateStrong()
{
	Player1->Vibrate(65535, 0);
}

void X_CONTROL::VibrateWeak()
{
	Player1->Vibrate(0, 65535);
}

void X_CONTROL::VibrateBoth()
{
	Player1->Vibrate(65535, 65535);
}

void X_CONTROL::VibrateEnd()
{
	Player1->Vibrate(0, 0);
}