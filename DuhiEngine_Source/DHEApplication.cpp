#include "DHEApplication.h"

namespace dh {

    Application::Application()
        : mHwnd(nullptr)
        , mHdc(nullptr)
        
    { }

    Application::~Application() {}

	void Application::test() {
		
	}

	void Application::Initialize(HWND handle) { // 핸들은 대부분 pointer 형태라 참조 안해도 됨.
		mHwnd = handle;
		mHdc = GetDC(handle);

        mPlayer.SetPosition(0, 0);
	}
	void Application::Update() {
            
       mPlayer.Update();
	   mPlayer2p.Update();     

    }
	void Application::LateUpdate() {}
	void Application::Run() {
		Update();
		LateUpdate();
		Render();
	}
	void Application::Render() {
        mPlayer.Render(mHdc);
		mPlayer2p.Render(mHdc);

	}

}