#include "Fps.h"

void Fps::setFps(float f)
{
	fps = f;
}

void Fps::start()
{
	startF = std::chrono::high_resolution_clock::now();
}


void Fps::end()
{
	endF = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = endF - startF;
	delay = (1000.0F / fps) - duration.count();
	std::this_thread::sleep_for(std::chrono::milliseconds((long)delay));
}
