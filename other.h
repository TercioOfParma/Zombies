#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif

/**
*	
*	Takes in the players character, and takes input and acts on that
*	At the moment it is quitting and moving around , as well as placing a space where it was if it is moving
*
**/
void handleInput(entity *player);
/**
*
*		AI for the zombies, zombies more relative to the player's position in a predictable fashion
**/

void zombiesThink(entity *zombies, int waveNumber, entity player);
/**
* 	Handles collision, adds to the points of the players, and also tells if the zombies are dead or players are dead
*
**/
void checkCollision(entity *zombies, entity *pits, entity player, int waveNumber, int *points, int *isOver);
/**
*	Handles game over as well as writing the users score to a pseudo leaderboard
*
**/
void deinit(int points, int waveNumber);