#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif


void initGame(entity *playerChar, entity *zombieChar, entity *pits, int *map, int waveNumber);
void initPlayer(entity *playerChar);
entity *initZombies(entity *zombieChar, int waveNumber);
entity *initPits(entity *pits, int waveNumber);

