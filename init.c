#include "init.h"


void initGame(entity *playerChar, entity *zombieChar, entity *pits, int *map, int waveNumber)
{
	if(waveNumber == 1)//initializes the player on the first wave
	{
		initPlayer(playerChar);
	}
	zombieChar = initZombies(zombieChar, waveNumber);//it will reinitialize the zombies and pits regardless since all the zombies at least are dead
	pits = initPits(pits, waveNumber);
	
	
	
}

void initPlayer(entity *playerChar)// i think these init<name> functions should be quite clear
{
	playerChar->representScreen = '@';
	playerChar->entityType = TYPE_PLAYER;
	playerChar->position.xPos = 10;
	playerChar->position.yPos = 10;
	playerChar->dead = FALSE;
	printEntity(playerChar, PAIR_PLAYER);
	
}

entity *initZombies(entity *zombieChar, int waveNumber)
{
		
		int mainLooper = 0;
		
		for(mainLooper =0; mainLooper < (GEOMETRIC_PROGRESSION * waveNumber * STARTING_ZOMBIES) ; mainLooper++)
		{
			zombieChar[mainLooper].representScreen = 'Z';
			zombieChar[mainLooper].entityType = TYPE_ZOMBIE;
			zombieChar[mainLooper].position.xPos = rand() % WIN_SIZE_X;
			zombieChar[mainLooper].position.yPos = rand() % WIN_SIZE_Y;
			zombieChar[mainLooper].dead = FALSE;
			
		}
	return zombieChar;
}
entity *initPits(entity *pits, int waveNumber)
{
		
		int mainLooper = 0;
		
		for(mainLooper =0; mainLooper < (GEOMETRIC_PROGRESSION * waveNumber * STARTING_PITS) ; mainLooper++)
		{
			pits[mainLooper].representScreen = 'O';
			pits[mainLooper].entityType = TYPE_PIT;
			pits[mainLooper].position.xPos = rand() % WIN_SIZE_X;
			pits[mainLooper].position.yPos = rand() % WIN_SIZE_Y;
			pits[mainLooper].dead = FALSE;
			
		}
	return pits;
}
