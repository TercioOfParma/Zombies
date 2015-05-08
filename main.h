


#include <stdlib.h>
#include <pdcurses\curses.h>
#include <stdio.h>
const static unsigned int TYPE_PLAYER = 1;/*!< The constant representing player type */
const static unsigned int TYPE_PIT = 2;/*!< The constant representing the pit type */
const static unsigned int TYPE_ZOMBIE = 3;/*!< The constant representing the zombie type */
const static unsigned char PAIR_DEFAULT = 1;/*!< The constant representing the default colour scheme (green on black) */
const static unsigned char PAIR_PLAYER = 2;/*!< The constant representing the colour scheme for the player (white on black) */
const static unsigned char PAIR_PIT = 3;/*!< The constant representing the colour scheme for pits (cyan on black) */
//const static unsigned char PAIR_FLOOR = 4;
//const static unigned char PAIR_WALL = 5;
const static unsigned int WIN_SIZE_X = 80;/*!< The amount of columns in the console */
const static unsigned int WIN_SIZE_Y = 25;/*!< The amount of rows in the console */
const static unsigned int STARTING_ZOMBIES = 3;/*!< The zombies on wave 1 factoring out GEOMETRIC_PROGRESSION */
const static unsigned int STARTING_PITS = 30;/*!< The amount of pits on wave 1, similar to STARTING_ZOMBIES */
const static unsigned int GEOMETRIC_PROGRESSION = 2;/*!< The progression of amount of zombies and pits as the wave goes on*/
const static unsigned int TOP_LEFT_X = 0;/*!< Top left of the screen, y component */
const static unsigned int TOP_LEFT_Y  = 0;/*!< Top left of the screen, x component */
const static unsigned int GAME_OVER_X = 13;/*!< The position where the game prints game over, x component */
const static unsigned int GAME_OVER_Y = 15;/*!< The position where the game prints game over, y component */
const static unsigned int GAME_OVER_VALUE = 2;/*!< The value to indicate that the game is over */

	/**
	*	VectorData:
	*	Used for Holding the position vector of an entity, may be used later for other vectors such as velocity
	*
	**/
typedef struct
{	

	unsigned char xPos; /*!< x position of the vector*/
	unsigned char yPos; /*!< y position	of the vector*/

	
}vectorData;


/**
*	entity:
*	Used to represent a generic character in the game, can be pretty much anything although at the moment only pits, zombies and the player
*
**/

typedef struct
{
	char representScreen; /*!< The output to the screen representing the entity */
	vectorData position; /*!< The vector representing the position of the entity */ 
	unsigned int entityType; /*!< The type of entity the entity is */
	unsigned char dead; /*!< Whether or not the entity is dead or not (or is existing in the case of inanimate objects such as pits) */
}entity;
