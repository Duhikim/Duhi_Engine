#pragma once
#include "CommonInclude.h"
#include "DHGameObject.h"
#include "DHGameObject2p.h"
#include "DHDinoObject.h"
#include "DHbullets.h"
#include "DHSceneManager.h"
#include "..\\DuhiEngine_Window\DHPlayScene.h"

namespace dh {
	class Application
	{
	public:
		Application();
		~Application();
		void test();
		void Initialize(HWND handle, UINT width, UINT height);
		void Update();
		void LateUpdate();
		void Run();
		void Render();
		

	private:
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBuffer;
		

		UINT mWidth;
		UINT mHeight;
	

		GameObject mPlayer;
		GameObject2p mPlayer2p;
		/*DinoObject Dino;*/

		std::vector<DinoObject*> mDinoObjects;
		

		
	};

}
