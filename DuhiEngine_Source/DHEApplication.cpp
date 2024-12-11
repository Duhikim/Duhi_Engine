#include "DHEApplication.h"
#include "DHInput.h"
#include "DHTime.h"

namespace dh {

	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBuffer(NULL)
		/*, mGameObjects2p{}*/
	{ }

    Application::~Application() {}

	void Application::Initialize(HWND handle, UINT width, UINT height) { // 핸들은 대부분 pointer 형태라 참조 안해도 됨.
		
		adjustWindowRect(handle, width, height);
		createBuffer(width, height);   
		initializeEtc();

		SceneManager::Initialize();
		/*for (int i = 0; i < 5; i++) {
			GameObject2p* gameObj2p = new GameObject2p;
			gameObj2p->SetPosition(rand()%1600, rand()%900);
			mGameObjects2p.push_back(gameObj2p);
		}*/
	}

	void Application::Update() {
		Input::Update();
		Time::Update();
		       	   
		/*for (int i = 0; i < mGameObjects2p.size(); i++) {
			mGameObjects2p[i]->Update();
		}*/
		Dino.Update();

		SceneManager::Update();
	   
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
		
		Dino.Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		copyRenderTarget(mBackHdc, mHdc);
		
	}



	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);
	}

	void Application::createBuffer(UINT width, UINT height)
	{

		// Window 해상도에 맞는 백버퍼(도화지) 생성
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

		// DC를 새로 만들거야. 메모리 더써서 연산은 줄임.

		// 백버퍼를 가르킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		SelectObject(mBackHdc, mBackBuffer);

	}

	void Application::clearRenderTarget()
	{
		HBRUSH WhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHdc, WhiteBrush);

		SelectObject(mBackHdc, WhiteBrush);
		Rectangle(mBackHdc, -1, -1, 1601, 901);
		
		DeleteObject(WhiteBrush);
	}

	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight,
			source, 0, 0, SRCCOPY);
	}

	void Application::initializeEtc()
	{
		Input::Initailize();
		Time::Initialize();
	}
}