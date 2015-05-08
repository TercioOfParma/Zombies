#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif

/**
*	Generates the next wave of the game, resets variables in the required places TODO map
*
*
**/
void initGame(entity *playerChar, entity *zombieChar, entity *pits, int *map, int waveNumber);
/**
*	Sets the player to a predetermined position at the beginning of the game and makes all of the other variables equal what they should by default
*
*
**/
void initPlayer(entity *playerChar);
/**
*	Sets the zombies equal to a random position and generates each zombie in sequence
*
**/
entity *initZombies(entity *zombieChar, int waveNumber);
/**
*	Sets the pits equal to a random position in a similar way to initZombies
*
**/
entity *initPits(entity *pits, int waveNumber);

