
#ifndef INCLUDE_LOCK
#define INCLUDE_LOCK
#include "main.h"
#endif



void initGraphics();
void printMessage(int colourPair,vectorData coords, char *Message);
void printEntity(entity *entityPointer, int colorPair);
void printEntityList(entity *entityList, int sizeOfList);
void printUI(int pointNumber, int waveNumber, int colorPair);
void clearScreen();