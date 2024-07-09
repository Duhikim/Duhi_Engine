#pragma once
#include "CommonInclude.h"

namespace dh {
	class DinoObject
	{
	public:
		DinoObject();
		DinoObject(float a, float b);
		~DinoObject();

		void Setposition(float a, float b) { Xpos = a; Ypos = b; }
		
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	private:
		float Xpos;
		float Ypos;
		float Xspeed;
		float Yspeed;
		double Xacc;
		float Yacc;
		float height;
		
		void creatKeyInput();
	};

}