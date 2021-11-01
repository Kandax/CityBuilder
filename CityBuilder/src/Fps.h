#pragma once
#include <chrono>
#include <thread>
#include <Windows.h>
#include <iostream>


class Fps
{
	float fps = 15;
	float delay = 0;
	std::chrono::high_resolution_clock::time_point startF;
	std::chrono::high_resolution_clock::time_point endF;
public:
	void setFps(float f);

	void start();
	void end();
};

