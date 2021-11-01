#pragma once
#include <iostream>
#include <windows.h>
//#include <chrono>

#include "Fps.h"




class Game
{
public:
	void start();
	Game();
private:
	
	void events();
	void update();
	void render();
	void clearScreen();
	void renderTextType(char map[60][30], int x, int y);
	
	Fps fps;
	COORD cursor;


	bool m_LoopRun = true;

	int viewSizeX = 20;//range what you going to see 
	int viewSizeY = 10;

	int speedSize = 5;

	int mapSizeX = 100;
	int mapSizeY = 100;

	char m_map[100][100];

	char map[60][30];
	char buffer[60][30];

	int posX = 0;
	int posY = 0;

	bool clrSc = false;

	bool oneFrame = false;
	
	HANDLE m_hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);


};

