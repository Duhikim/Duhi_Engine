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

	{ }

    Application::~Application() {}

	void Application::test() {
		
	}

	void Application::Initialize(HWND handle, UINT width, UINT height) { // �ڵ��� ��κ� pointer ���¶� ���� ���ص� ��.
		mHwnd = handle;
		mHdc = GetDC(handle);



		RECT rect = {0, 0, width, height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		// Window �ػ󵵿� �´� �����(��ȭ��) ����
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

		// DC�� ���� ����ž�. �޸� ���Ἥ ������ ����.
		
		// ����۸� ����ų DC ����
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);

        mPlayer.SetPosition(0, 0);

		Input::Initailize();
		Time::Initialize();
	}
	void Application::Update() {
		Input::Update();
		Time::Update();

       //mPlayer.Update();
	   //mPlayer2p.Update();
	   
		Dino.Update();
	   
    }
	void Application::LateUpdate() {}
	void Application::Run() {
		Update();
		LateUpdate();
		Render();
	}
	void Application::Render() {
		
		Rectangle(mBackHdc, 0, 0, 1600, 900);
		
		Time::Render(mBackHdc);
		
		
		// mPlayer.Render(mHdc);
		//mPlayer2p.Render(mHdc);
		Dino.Render(mBackHdc);


		BitBlt(mHdc, 0, 0, mWidth, mHeight, 
			mBackHdc, 0, 0, SRCCOPY);
	}

}