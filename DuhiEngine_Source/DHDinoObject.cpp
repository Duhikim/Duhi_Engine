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
		float ZeroMax = 1.0; // ���� ���¿��� Max Speed���� �����ϴ� �ð�(��)
		
		int FPS = 1 / Time::DeltaTime();
		
		int tempXacc = MaxSpeed / ZeroMax;

		if (Input::GetKey(eKeyCode::Left)) {// �ش� Ű�� ������ ������(Pressed)
			if (Xspeed > 0) { Xspeed /= 1.004f; Xacc = -0.8 * tempXacc; } // �ݴ��� �Է� �극��ũ
			else Xacc = -tempXacc; //1�ʵ��� MaxSpeed�� ����
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

	

		//MAX Speed ����
		if (Xacc) {
			if (-MaxSpeed < Xspeed && Xspeed < MaxSpeed) {
				Xspeed += Xacc * Time::DeltaTime();				
			}
			else if (Xspeed>=MaxSpeed) { Xspeed = MaxSpeed; }
			else if (Xspeed <= -MaxSpeed) { Xspeed = -MaxSpeed; }
		}

		// �������� ���� �ӵ� ����
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


		//Y��(����) ����
		if (Ypos > 0) { Ypos = 0; Yacc = 0; Yspeed = 0; }

		if (Input::GetKeyDown(eKeyCode::Up) && Ypos>-50) {
			Ypos = 0;
			Yspeed = -2.8 * MaxSpeed;	// default : -2.2
		}
		
		Yacc = MaxSpeed/(0.15 * ZeroMax);

		if (Ypos < -700) { Yspeed = -Yspeed; }
		
		Yspeed += Yacc * Time::DeltaTime();
		Ypos += Yspeed * Time::DeltaTime();


		//���� ��
		if (Xpos < -100) {
			Xpos = -100; Xspeed = 0;
		}
		else if (Xpos > 1450) {
			Xpos = 1450; Xspeed = 0;
		}

		
		//�ɱ�
		height = 0;
		if (Input::GetKey(eKeyCode::Down)) {
			height = 50;
		}

		//�� �߻�
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