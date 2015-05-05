#include "graphics.h"


void initGraphics()
{
	initscr();
	start_color();
	keypad(stdscr, TRUE);
	noecho();
	cbreak();
	init_pair(PAIR_DEFAULT, COLOR_GREEN, COLOR_BLACK);
	init_pair(PAIR_PLAYER, COLOR_WHITE, COLOR_BLACK);
	init_pair(PAIR_PIT, COLOR_CYAN, COLOR_BLACK);
	
}

void printMessage(int colourPair, vectorData coords, char *message)
{
	attron(COLOR_PAIR(colourPair));
	mvprintw(coords.yPos, coords.xPos,"%s", message);
	attroff(COLOR_PAIR(colourPair));


}
void printEntity(entity *entityPointer, int colorPair)
{
	int x,y, character;
	x = entityPointer->position.xPos;
	y = entityPointer->position.yPos;
	character = entityPointer->representScreen;
	attron(COLOR_PAIR(colorPair));
	mvaddch(y,x,character);
	attroff(COLOR_PAIR(colorPair));
	
	
	
}
void printEntityList(entity *entityList, int sizeOfList)
{
	int mainLooper = 0;
	for(mainLooper = 0; mainLooper < sizeOfList; mainLooper++)
	{
		if(entityList[mainLooper].dead != TRUE)
		{
			
			if(entityList[mainLooper].entityType == TYPE_ZOMBIE)
			{
				printEntity(&entityList[mainLooper], PAIR_DEFAULT);
			}
			else if(entityList[mainLooper].entityType == TYPE_PIT)
			{
				printEntity(&entityList[mainLooper], PAIR_PIT);
			}	
				
			
			
		}
	}
	
	
}

void printUI(int pointNumber, int waveNumber, int colorPair)
{
	attron(COLOR_PAIR(colorPair));
	mvprintw(TOP_LEFT_Y, TOP_LEFT_X, "Points : %d \t Wave Number : %d", pointNumber, waveNumber);
	mvprintw(TOP_LEFT_Y+1,TOP_LEFT_X,"Press Q to quit, arrows and numpad on moves");
	attroff(COLOR_PAIR(colorPair));
	
	
}
void clearScreen()
{
	int mainLooper,internalLooper;
	for(mainLooper=0;mainLooper < WIN_SIZE_X; mainLooper++)
	{
		for(internalLooper=0;internalLooper < WIN_SIZE_Y; internalLooper++)
		{
			mvaddch(internalLooper, mainLooper, ' ');
			
		}
	}
	
	
}
