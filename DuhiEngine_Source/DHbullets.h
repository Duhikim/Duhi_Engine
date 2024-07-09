#pragma once
#include "CommonInclude.h"

namespace dh {
	class bullets
	{
	public:
		bullets();
		~bullets() {}

		void Setposition(float x, float y);
		void Update();
		void LateUpdate();
		void Render(HDC hdc);
		bool IsItExist() {
			return exist;
		}
	
		

	private:
		float Xpos;
		float Ypos;
		float Xspeed;
		float Yspeed;
		float Xacc;
		float Yacc;
		bool exist;

		
	};

}