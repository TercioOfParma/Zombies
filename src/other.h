#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif


void handleInput(entity *player);
void zombiesThink(entity *zombies, int waveNumber, entity player);
void checkCollision(entity *zombies, entity *pits, entity player, int waveNumber, int *points, int *isOver);
void deinit(int points, int waveNumber);