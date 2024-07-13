#pragma once
#include "CommonInclude.h"


namespace dh {


	class Time
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return DeltaTimeValue; }

	private:
		static LARGE_INTEGER CPUFrequency;
		static LARGE_INTEGER PreFrequency;
		static LARGE_INTEGER CurrentFrequency;
		static float DeltaTimeValue;

	};

}