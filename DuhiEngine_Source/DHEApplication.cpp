#include "DHEApplication.h"
#include "DHInput.h"
#include "DHTime.h"
#include "DHbullets.h"
#include "DHDinoObject.h"
#include "CommonInclude.h"
#include "DHSceneManager.h"
#include "DHScene.h"
#include "..\\DuhiEngine_Window\DHPlayScene.h"


namespace dh {

	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBuffer(NULL)
		, mDinoObjects{}

	{ }

    Application::~Application() {}

	void Application::test() {
		
	}

	void Application::Initialize(HWND handle, UINT width, UINT height) { // 핸들은 대부분 pointer 형태라 참조 안해도 됨.
		mHwnd = handle;
		mHdc = GetDC(handle);

		SceneManager::Initialize();
		


		RECT rect = {0, 0, width, height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		// Window 해상도에 맞는 백버퍼(도화지) 생성
		mBackBuffer = CreateCompatibleBitmap(mHdc, (int)width, (int)height);

		// DC를 새로 만들거야. 메모리 더써서 연산은 줄임.
		
		// 백버퍼를 가르킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);

        mPlayer.SetPosition(0,0);
		for (int i = 0; i < mDinoObjects.size(); i++) {
			mDinoObjects[i]->Setposition(0, 0);
		}

		Input::Initailize();
		Time::Initialize();
	}
	void Application::Update() 
	{
		Input::Update();
		Time::Update();


		SceneManager::Update();
	/*	for (int i = 0; i < mDinoObjects.size(); i++) {
			mDinoObjects[i]->Update();
		}*/

       //mPlayer.Update();
	   //mPlayer2p.Update();
	   
		//Dino.Update();	
	   
    }
	void Application::LateUpdate() {}
	void Application::Run() {
		Update();
		LateUpdate();
		Render();
	}
	void Application::Render() {

		clearRenderTarget();
		Time::Render(mBackHdc);
		//Dino.Render(mBackHdc);

		//SceneManager::Render(mBackHdc);
		for (int i = 0; i < mDinoObjects.size(); i++) {
			mDinoObjects[i]->Render(mBackHdc);
		}

		copyRenderTarget(mBackHdc, mHdc);

	}

	void Application::clearRenderTarget() {
		HBRUSH WhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, WhiteBrush);


		SelectObject(mBackHdc, WhiteBrush);
		Rectangle(mBackHdc, -10, -10, 1610, 910);
		DeleteObject(WhiteBrush);

	}

	void Application::copyRenderTarget(HDC source, HDC dest) {
		BitBlt(dest, 0, 0, mWidth, mHeight,
			source, 0, 0, SRCCOPY);

	}

}