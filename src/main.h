#include <stdlib.h>
#include <pdcurses\curses.h>
#include <stdio.h>
const static unsigned char TYPE_PLAYER = 1;
const static unsigned char TYPE_PIT = 2;
const static unsigned char TYPE_ZOMBIE = 3;
const static unsigned char PAIR_DEFAULT = 1;
const static unsigned char PAIR_PLAYER = 2;
const static unsigned char PAIR_PIT = 3;
//const static unsigned char PAIR_FLOOR = 4;
//const static unigned char PAIR_WALL = 5;
const static unsigned int WIN_SIZE_X = 80;
const static unsigned int WIN_SIZE_Y = 25;
const static unsigned int STARTING_ZOMBIES = 3;
const static unsigned int STARTING_PITS = 30;
const static unsigned int GEOMETRIC_PROGRESSION = 2;
const static unsigned int TOP_LEFT_X = 0;
const static unsigned int TOP_LEFT_Y  = 0;
const static unsigned int GAME_OVER_X = 13;
const static unsigned int GAME_OVER_Y = 15;
typedef struct
{
	unsigned char xPos,yPos;
	
}vectorData;

typedef struct
{
	char representScreen;
	vectorData position;
	unsigned char entityType;
	unsigned char dead;
}entity;
