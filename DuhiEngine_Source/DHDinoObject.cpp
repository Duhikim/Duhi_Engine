#include "DHDinoObject.h"
#include "DHInput.h"
#include "DHTime.h"


namespace dh {
	DinoObject::DinoObject() 
		: Xpos(0)
		, Ypos(0)
		, Xspeed(0)
		, Yspeed(0)
		, Xacc(0)
		, Yacc(0)
		, height(0)
	{
	}
	
	DinoObject::~DinoObject() {


	}

	
	void DinoObject::Update() {
		const int speed = 100.0f;
		
		creatKeyInput();

	}
	void DinoObject::LateUpdate() {


	}
	void DinoObject::Render(HDC hdc) {
		
		HBRUSH GreenBrush = CreateSolidBrush(RGB(0, 255, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, GreenBrush);

		
		SelectObject(hdc, GreenBrush);
		Rectangle(hdc, 100+Xpos, 700+Ypos+height, 150+Xpos, 800+Ypos);

		DeleteObject(GreenBrush);
		

	}

	void DinoObject::creatKeyInput() {
		
		const int speed = 500.0f;
		float MaxSpeed = 0.5;// speed* Time::DeltaTime();
		int FPS = 1 / Time::DeltaTime();
				

		if (Input::GetKey(eKeyCode::Left)) {// 해당 키를 누르고 있으면(Pressed)
			if (Xspeed > 0) { Xspeed /= 1.001f; Xacc = -0.8 * MaxSpeed / FPS; } // 반대쪽 입력 브레이크
			else Xacc = -MaxSpeed / FPS; //1초동안 MaxSpeed에 도달
		}
		
		if (Input::GetKey(eKeyCode::Right)) {
			if (Xspeed < 0) { Xspeed /= 1.001f; Xacc = 0.8 * MaxSpeed / FPS; }
			else Xacc = MaxSpeed / FPS;			
		}

		if (!Input::GetKey(eKeyCode::Left) && !Input::GetKey(eKeyCode::Right)) { 
			Xacc = 0;
		}
		if (Input::GetKey(eKeyCode::Left) && Input::GetKey(eKeyCode::Right)) {
			Xacc = 0;
		}
		if (Input::GetKey(eKeyCode::Down)) {
			Xacc = 0.0;		
		}

	

		//MAX Speed 설정
		if (Xacc) {
			if (-MaxSpeed < Xspeed && Xspeed < MaxSpeed) {
				Xspeed += Xacc;
			}
			else if (Xspeed>=MaxSpeed) { Xspeed == MaxSpeed; }
			else if (Xspeed <= -MaxSpeed) { Xspeed == -MaxSpeed; }
		}

		// 저항으로 인한 속도 감소
		else {
			if (Xspeed > 0) {
				Xspeed -= MaxSpeed / FPS;
				if (Xspeed < 0) Xspeed = 0;
			}
			else if (Xspeed < 0) {
				Xspeed += MaxSpeed / FPS;
				if (Xspeed > 0) Xspeed = 0;
			}
		}
		Xpos += Xspeed;



		if (Ypos > 0) { Ypos = 0; Yacc = 0; Yspeed = 0; }

		if (Input::GetKeyDown(eKeyCode::Up) && Ypos>-50) {
			Ypos = 0;
			Yspeed = -MaxSpeed;			
		}
		
		Yacc = 2*MaxSpeed/(float)FPS;

		if (Ypos < -700) { Yspeed = -Yspeed; }
		
		Yspeed += Yacc;
		Ypos += Yspeed;



		if (Xpos < 0) {
			Xpos = 0; Xspeed = 0;
		}
		else if (Xpos > 1400) {
			Xpos = 1400; Xspeed = 0;
		}

		

		height = 0;
		if (Input::GetKey(eKeyCode::Down)) {
			height = 50;
		}
	
	}

}