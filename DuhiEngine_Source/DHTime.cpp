#include "DHTime.h"

namespace dh {

	LARGE_INTEGER Time::CPUFrequency = {};
	LARGE_INTEGER Time::PreFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;

	void dh::Time::Initialize()
	{
		//CPU ���� ������
		QueryPerformanceFrequency(&CPUFrequency);


		//���α׷��� �������� �� ���� ������
		QueryPerformanceCounter(&PreFrequency);
	}

	void dh::Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);


		float frequency_diff = static_cast<float>(CurrentFrequency.QuadPart - PreFrequency.QuadPart);

		DeltaTimeValue = frequency_diff / static_cast<float>(CPUFrequency.QuadPart);

		PreFrequency.QuadPart = CurrentFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;
		
		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;
		
		
		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"FPS : %d", (int)fps);
		int len = wcsnlen_s(str, 50);


		TextOut(hdc, 0, 0, str, len);

	}
}