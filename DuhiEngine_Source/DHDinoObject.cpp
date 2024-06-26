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
		if (Ypos > 0) { Ypos = 0; Yacc = 0; Yspeed = -0.3 * Yspeed; }
		
		if (Input::GetKey(eKeyCode::W) && (Ypos>-3 && Ypos<0)) {
			if (Yspeed > -0.01)
			Yspeed = -0.03;
		}
		Yacc = 0.000002;
		
		if (Ypos < -700) {	Yspeed = 0.00005;	}
		Ypos += Yspeed;
		Yspeed += Yacc;
		

		if (Input::GetKey(eKeyCode::D)) {
			Xpos += 0.01;
		}
		


		if (Input::GetKey(eKeyCode::A)) {
			Xpos -= 0.01;
		}
		
		
		height = 0;
		if (Input::GetKey(eKeyCode::S)) {
			height = 50;
		}

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

}