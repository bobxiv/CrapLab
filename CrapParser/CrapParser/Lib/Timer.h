#pragma once

#include <Windows.h>
// timer para medir las llamadas a la API


struct HRTimer {

	void Start(void) {
        QueryPerformanceCounter(&mTimeStart);
    };

	void Stop(void) {
        QueryPerformanceCounter(&mTimeStop);
    };

	double GetDurationInSecs(void)
    {
        LARGE_INTEGER freq;
        QueryPerformanceFrequency(&freq);
        double duration = (double)(mTimeStop.QuadPart-mTimeStart.QuadPart)/(double)freq.QuadPart;
        return duration;
    }

    LARGE_INTEGER mTimeStart;
    LARGE_INTEGER mTimeStop;
};




