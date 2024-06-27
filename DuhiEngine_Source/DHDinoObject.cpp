#include "DHDinoObject.h"
#include "DHInput.h"


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
		

		if (Input::GetKey(eKeyCode::Left)) {// 해당 키를 누르고 있으면(Pressed)
			Xacc = -0.000001;
		}
		
		if (Input::GetKey(eKeyCode::Right)) {
			Xacc = 0.000001;
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

	


		if (Xacc) {
			if (-0.01 < Xspeed && Xspeed < 0.01) {
				Xspeed += Xacc;
			}
			else if (Xspeed>=0.01) { Xspeed == 0.01; }
			else if (Xspeed <= -0.01) { Xspeed == -0.01; }
		}

		else {
			if (Xspeed > 0) {
				Xspeed -= 0.0000003;
				if (Xspeed < 0) Xspeed = 0;
			}
			else if (Xspeed < 0) {
				Xspeed += 0.0000003; 
				if (Xspeed > 0) Xspeed = 0;
			}
		}
		Xpos += Xspeed;



		if (Ypos > 0) { Ypos = 0; Yacc = 0; Yspeed = 0; }

		if (Input::GetKey(eKeyCode::Up) && !Ypos) {
			if (Yspeed > -0.01)
				Yspeed = -0.03;
		}
		Yacc = 0.000002;

		if (Ypos < -700) { Yspeed = 0.00005; }
		Ypos += Yspeed;
		Yspeed += Yacc;


		

		height = 0;
		if (Input::GetKey(eKeyCode::Down)) {
			height = 50;
		}
	
	}

}