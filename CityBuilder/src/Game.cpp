#include "Game.h"


void Game::start()
{
	while (m_LoopRun) {		
		fps.start();
		events();
		update();
		render();
		fps.end();
		
	}
}

Game::Game() {
	fps.setFps(60);
		
		for (int iy = 0; iy < mapSizeY; iy++) {			
			for (int ix = 0; ix < mapSizeX; ix++) {
				m_map[ix][iy] = static_cast<char>(219);
			}
		}
		m_map[0][0] = '1';
		m_map[2][2] = 'X';
		m_map[9][0] = '2';
		m_map[0][9] = '3';
		m_map[9][9] = '4';
		m_map[19][19] = '4';
		m_map[15][5] = '4';
		m_map[15][6] = '4';
		m_map[15][7] = '4';
		m_map[15][8] = '4';

	start();
}

void Game::events() {
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		if(posX < mapSizeX - viewSizeX)
		posX += 1;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		if(posX > 0)
		posX--;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		if(posY > 0)
		posY--;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		if(posY < mapSizeY - viewSizeY)
		posY++;
	}
	if (GetAsyncKeyState(VK_F1) & 0x8000) {
		m_map[posX + (viewSizeX / 2)][posY + (viewSizeY / 2)] = 'M';
	}
	if (GetAsyncKeyState(VK_F2) & 0x8000) {

		if (viewSizeX < 60) {
			viewSizeX += speedSize * 2;
			viewSizeY += speedSize;
			oneFrame = true;
		}
		
		
	}
	if (GetAsyncKeyState(VK_F3) & 0x8000) {
		if (viewSizeX > 20) {
			for (int i = 0; i < 30; i++) {
				for (int j = 0; j < 60; j++) {
					buffer[j][i] = NULL;
				}
			}

			viewSizeX = viewSizeX - speedSize * 2;
			viewSizeY = viewSizeY - speedSize;
			clrSc = true;
			oneFrame = true;
		
		}





		
	}




}
void Game::update() {

	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 60; j++) {
			buffer[j][i] = map[j][i];
		}
	}

	for (int i = 0; i < viewSizeX; i++) {
		for (int j = 0; j < viewSizeY; j++) {
			map[i][j] = m_map[i + posX][j + posY];
		}
		
	}


	

}
void Game::render() {
	cursor.X = 0;
	cursor.Y = 0;
	SetConsoleCursorPosition(m_hConsoleOut, cursor);



	for (int iy = 0; iy < viewSizeY; iy++) {
		for (int ix = 0; ix < viewSizeX; ix++) {
			
			if (clrSc) {
			clearScreen();
				clrSc = false;
			}
            
			if (oneFrame) {
				for (int iiy = 0; iiy < viewSizeY; iiy++) {
					for (int iix = 0; iix < viewSizeX; iix++) {
						cursor.Y = iiy;
						cursor.X = iix;
						SetConsoleCursorPosition(m_hConsoleOut, cursor);

						renderTextType(map, iix, iiy);



					}//ix
				}//iy
				oneFrame = false;
			}


			cursor.Y = iy;
			cursor.X = ix;
			SetConsoleCursorPosition(m_hConsoleOut, cursor);






				
			if (buffer[ix][iy] != map[ix][iy]) {//render whats change
				cursor.X = ix;
				cursor.Y = iy;
				SetConsoleCursorPosition(m_hConsoleOut, cursor);
				
				renderTextType(map, ix, iy);


			}



			
		}//ix


	}//iy


	





}

void Game::clearScreen()
{
	cursor.Y = 0;
	cursor.X = 0;
	SetConsoleCursorPosition(m_hConsoleOut, cursor);
	SetConsoleTextAttribute(m_hConsoleOut, 0);
	for (int y = 0; y < 30; y++) {
		cursor.Y = y;
		SetConsoleCursorPosition(m_hConsoleOut, cursor);
		for (int x = 0; x < 60; x++) {
			printf("%c", static_cast<char>(219));
		}
	}


}

void Game::renderTextType(char map[60][30], int x, int y)
{
	if (map[x][y] == '4') {
		SetConsoleTextAttribute(m_hConsoleOut, (6 + 2 * 16));
		printf("%c", map[x][y]);
	}
	else if (map[x][y] == static_cast<char>(219)) {
		SetConsoleTextAttribute(m_hConsoleOut, 2);
		printf("%c", map[x][y]);
	}
	else {
		SetConsoleTextAttribute(m_hConsoleOut, 32);
		printf("%c", map[x][y]);
	}
	SetConsoleTextAttribute(m_hConsoleOut, 7);
}

