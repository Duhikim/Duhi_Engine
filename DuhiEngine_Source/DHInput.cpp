#include "DHInput.h"

namespace dh {

	std::vector<Input::Key> Input::mKeys = {};

	int ASCII[(UINT)eKeyCode::End] = {
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D' ,'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP, VK_SPACE,
	};

	void Input::Initailize()
	{
		/*mKeys.resize((UINT)eKeyCode::End);*/
		
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			mKeys.push_back(key);
		}
	}
	void Input::Update()
	{
		for (size_t i = 0; i < mKeys.size(); i++)
		{
			//키가 눌림
			if (GetAsyncKeyState(ASCII[i]) & 0x8000) {
				if (mKeys[i].bPressed == true) { // 이전 프레임에 눌려있던 상태
					mKeys[i].state = eKeyState::Pressed; 
				}
				else { // 이전 프레임에 안 눌려있던 상태
					mKeys[i].state = eKeyState::Down;
				}
				mKeys[i].bPressed = true;
			}
			//키가 안눌림
			else {
				if (mKeys[i].bPressed == true) { 
					mKeys[i].state = eKeyState::Up;
				}
				else {
					mKeys[i].state = eKeyState::None;
				}
				mKeys[i].bPressed = false;

			}
		}
	}
}
