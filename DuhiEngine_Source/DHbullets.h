#pragma once
#include "CommonInclude.h"
#include "DHTime.h"

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
		bool exist;


	};

}