#include "DHbullets.h"
#include "DHTime.h"


namespace dh {
	bullets::bullets()
		:Xpos(0)
		,Ypos(0)
		,Xspeed(0)
		,Yspeed(0)
		,Xacc(0)
		,Yacc(0)
		,exist(0)
	{	}
	
	void bullets::Setposition(float x, float y) {
		Xpos = x;
		Ypos = y;
		exist = true;
	}
	void bullets::Update()
	{
		int bulletspeed = 1000;
		Xpos += bulletspeed * Time::DeltaTime();

		if (Xpos > 1600) {
			Xpos = 2000;
			exist = false;
		}
	}

	void bullets::LateUpdate()
	{
	}

	void bullets::Render(HDC hdc)
	{
		
		if (exist) {
			HBRUSH RedBrush = CreateSolidBrush(RGB(255, 0, 0));
			HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, RedBrush);

			Ellipse(hdc, (int)Xpos, (int)Ypos - 20, (int)Xpos + 50, (int)Ypos - 10);

			DeleteObject(RedBrush);
		}
	}




}