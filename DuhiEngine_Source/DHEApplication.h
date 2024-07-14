#pragma once
#include "CommonInclude.h"
#include "DHGameObject.h"
#include "DHGameObject2p.h"
#include "DHDinoObject.h"

namespace dh {
	class Application
	{
	public:
		Application();
		~Application();		
		void Initialize(HWND handle, UINT width, UINT height);
		void Update();
		void LateUpdate();
		void Run();
		void Render();


	private: // function
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);	
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBuffer;
		

		UINT mWidth;
		UINT mHeight;
	

		GameObject mPlayer;
		/*GameObject2p mPlayer2p;*/
		DinoObject Dino;

		std::vector<GameObject2p*> mGameObjects2p;

		
	};

}
