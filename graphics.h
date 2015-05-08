#ifndef INCLUDE_LOCK  /*!< INCLUDE_LOCK : This makes sure that the compiler doesn't include the files multiple times */
#define INCLUDE_LOCK
#include "main.h"
#endif



void initGraphics();/*!<This initialises pdCurses to use colour, standard screen, not to echo and to use standard interrupts (CTRL^C etc) */
void printMessage(int colourPair,vectorData coords, char *Message);/*!< takes a message, and prints it at the desired coordinates (in coords) and with the desired colour pair */
void printEntity(entity *entityPointer, int colorPair);/*!< prints out a character at its coords with given colour pair */
void printEntityList(entity *entityList, int sizeOfList);/*!< A helper function to print out s list of entities from a 1 dimensional pointer array based on their set type */
void printUI(int pointNumber, int waveNumber, int colorPair);/*!< Prints out the wave number, controls, and points in a user understandable manner*/
void clearScreen();/*!< Prints blank characters across the screen */