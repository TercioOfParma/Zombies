#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif


int main(int argc, char *argv[])
{
	
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
		
		pits = malloc(sizeof(entity) * (GEOMETRIC_PROGRESSION * waveNumber * STARTING_PITS));
		enemies = malloc(sizeof(entity) * (GEOMETRIC_PROGRESSION * waveNumber * STARTING_ZOMBIES));
		initGame(&player, enemies,pits,map,waveNumber);
		while(allDead == 0)
		{
			
			printUI(playerPoints, waveNumber, PAIR_PLAYER);
			handleInput(&player);
			clearScreen();
			printEntity(&player, PAIR_DEFAULT);
			zombiesThink(enemies, waveNumber, player);
			printEntityList(enemies, (GEOMETRIC_PROGRESSION * STARTING_ZOMBIES * waveNumber));
			printEntityList(pits, (GEOMETRIC_PROGRESSION * STARTING_PITS * waveNumber));
			checkCollision(enemies, pits, player, waveNumber, &playerPoints, &allDead);
			refresh();
			
			
		}
		if(allDead == 2)
		{
			free(pits);
			free(enemies);
			deinit(playerPoints, waveNumber);
			getch();
			exit(0);
		}
		allDead = 0;
		waveNumber++;
		free(pits);
		free(enemies);
	}
	
	getch();
	endwin();
	return 0;
}
