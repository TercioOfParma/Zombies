#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif
/**
	Where everything happens
**/
int main(int argc, char *argv[])
{
	//VARIABLE DECLARATIONS
	srand(time(NULL));
	int **map;
	entity player, *enemies, *pits;
	int waveNumber, playerPoints, allDead;
	initGraphics();
	waveNumber = 1;
	playerPoints = 0;
	allDead = 0;
	while(1 == 1)
	{
		//this seem odd as it is in a loop, but this loop completes relatively little times per second and is neccessary as it is freed at the bottom 
		pits = malloc(sizeof(entity) * (GEOMETRIC_PROGRESSION * waveNumber * STARTING_PITS));
		enemies = malloc(sizeof(entity) * (GEOMETRIC_PROGRESSION * waveNumber * STARTING_ZOMBIES));
		initGame(&player, enemies,pits,map,waveNumber);
		while(allDead == 0)
		{
			//for details on what they do read the docs
			clearScreen();
			printUI(playerPoints, waveNumber, PAIR_PLAYER);
			printEntity(&player, PAIR_PLAYER);
			zombiesThink(enemies, waveNumber, player);
			printEntityList(enemies, (GEOMETRIC_PROGRESSION * STARTING_ZOMBIES * waveNumber));
			printEntityList(pits, (GEOMETRIC_PROGRESSION * STARTING_PITS * waveNumber));
			checkCollision(enemies, pits, player, waveNumber, &playerPoints, &allDead);
			handleInput(&player);
			refresh();
			
			
		}
		if(allDead == GAME_OVER_VALUE)//if the player is dead
		{
			getch();
			free(pits);
			free(enemies);
			deinit(playerPoints, waveNumber);
			getch();
			endwin();
			exit(0);
		}
		clearScreen();
		allDead = 0;
		waveNumber++;
		free(pits);
		free(enemies);
	}
	//it is nigh impossible for this to execute
	
	return 0;
}
