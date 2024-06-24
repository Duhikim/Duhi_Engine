#pragma once
#include "CommonInclude.h"
#include "DHGameObject.h"
#include "DHGameObject2p.h"

namespace dh {
	class Application
	{
	public:
		Application();
		~Application();
		void test();
		void Initialize(HWND handle);
		void Update();
		void LateUpdate();
		void Run();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;
	
		GameObject mPlayer;
		GameObject2p mPlayer2p;
		
	};

}
