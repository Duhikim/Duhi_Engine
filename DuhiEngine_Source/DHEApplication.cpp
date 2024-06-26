#include "DHEApplication.h"
#include "DHInput.h"

namespace dh {

    Application::Application()
        : mHwnd(nullptr)
        , mHdc(nullptr)
        
    { }

    Application::~Application() {}

	void Application::test() {
		
	}

	void Application::Initialize(HWND handle) { // �ڵ��� ��κ� pointer ���¶� ���� ���ص� ��.
		mHwnd = handle;
		mHdc = GetDC(handle);

        mPlayer.SetPosition(0, 0);

		Input::Initailize();
	}
	void Application::Update() {
		Input::Update();

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
       // mPlayer.Render(mHdc);
		//mPlayer2p.Render(mHdc);
		Dino.Render(mHdc);

	}

}