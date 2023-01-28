#include"TimeController.h"
//
//namespace App
//{
//	TimeController::TimeController()
//	{
//		nowCount = prevCount = GetNowHiPerformanceCount();
//		QueryPerformanceFrequency(&freq);
//		QueryPerformanceCounter(&start);
//	}
//
//	TimeController::~TimeController()
//	{
//	}
//
//	void TimeController::StartInstrumentation()
//	{
//		nowCount = GetNowHiPerformanceCount();
//		deltaTime = (nowCount - prevCount) / 1000000.0f;
//
//		QueryPerformanceCounter(&end);
//		time = static_cast<double>(end.QuadPart - start.QuadPart) * 1.0 / freq.QuadPart;
//	}
//
//	void TimeController::EndInstrumentation()
//	{
//		while (GetNowHiPerformanceCount() - nowCount < waitFrameTime)
//		{
//			;
//		}
//		prevCount = nowCount;
//	}
//
//	void TimeController::Show()
//	{
//		char buf[256];
//		sprintf(buf, "Œo‰ßŽžŠÔF%f•b\n", time);
//		DrawString(0, 0, buf, GetColor(255, 0, 0));
//	}
//}