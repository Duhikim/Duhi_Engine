#include "DHDinoObject.h"



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
			
		creatKeyInput();
		for (int i = 0; i < 20; i++) {
			bullets[i].Update();
		}
	}

	void DinoObject::LateUpdate() {	}

	void DinoObject::Render(HDC hdc) {
		
		HBRUSH GreenBrush = CreateSolidBrush(RGB(0, 255, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, GreenBrush);

		
		SelectObject(hdc, GreenBrush);
		Rectangle(hdc, 100+Xpos, 700+Ypos+height, 150+Xpos, 800+Ypos);

		DeleteObject(GreenBrush);
		
		for (int i = 0; i < 20; i++) {
			if (bullets[i].IsItExist()) {
				bullets[i].Render(hdc);
			}
		}
	}

	void DinoObject::creatKeyInput() {
		
		float MaxSpeed = 350;
		float ZeroMax = 1.0; // 정지 상태에서 Max Speed까지 도달하는 시간(초)
		
		int FPS = 1 / Time::DeltaTime();
		
		int tempXacc = MaxSpeed / ZeroMax;

		if (Input::GetKey(eKeyCode::Left)) {// 해당 키를 누르고 있으면(Pressed)
			if (Xspeed > 0) { Xspeed /= 1.004f; Xacc = -0.8 * tempXacc; } // 반대쪽 입력 브레이크
			else Xacc = -tempXacc; //1초동안 MaxSpeed에 도달
		}
		
		if (Input::GetKey(eKeyCode::Right)) {
			if (Xspeed < 0) { Xspeed /= 1.004f; Xacc = 0.8 * tempXacc; }
			else Xacc = tempXacc;
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
				Xspeed += Xacc * Time::DeltaTime();				
			}
			else if (Xspeed>=MaxSpeed) { Xspeed = MaxSpeed; }
			else if (Xspeed <= -MaxSpeed) { Xspeed = -MaxSpeed; }
		}

		// 저항으로 인한 속도 감소
		else {
			if (Xspeed > 0) {
				Xspeed -= tempXacc * Time::DeltaTime();
				if (Xspeed < 0) Xspeed = 0;
			}
			else if (Xspeed < 0) {
				Xspeed += tempXacc * Time::DeltaTime();
				if (Xspeed > 0) Xspeed = 0;
			}
		}
		Xpos += Xspeed * Time::DeltaTime();


		//Y축(점프) 설정
		if (Ypos > 0) { Ypos = 0; Yacc = 0; Yspeed = 0; }

		if (Input::GetKeyDown(eKeyCode::Up) && Ypos>-50) {
			Ypos = 0;
			Yspeed = -2.8 * MaxSpeed;	// default : -2.2
		}
		
		Yacc = MaxSpeed/(0.15 * ZeroMax);

		if (Ypos < -700) { Yspeed = -Yspeed; }
		
		Yspeed += Yacc * Time::DeltaTime();
		Ypos += Yspeed * Time::DeltaTime();


		//양쪽 벽
		if (Xpos < -100) {
			Xpos = -100; Xspeed = 0;
		}
		else if (Xpos > 1450) {
			Xpos = 1450; Xspeed = 0;
		}

		
		//앉기
		height = 0;
		if (Input::GetKey(eKeyCode::Down)) {
			height = 50;
		}

		//총 발사
		if (Input::GetKeyDown(eKeyCode::Space)) {
			for (int i = 0; i < 20; i++) {
				if (!bullets[i].IsItExist()) {
					bullets[i].Setposition(150 + Xpos, 750 + Ypos);
					if (height == 50) { bullets[i].Setposition(150 + Xpos, 780 + Ypos); }
					break;
				}
			}
		}
	
	}
}