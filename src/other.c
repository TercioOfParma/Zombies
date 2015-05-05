#include "other.h"



void handleInput(entity *player)
{
	
	int inputHolder = getch();
	attron(COLOR_PAIR(PAIR_DEFAULT));
	switch(inputHolder)
	{
		
		case '1':
			mvaddch(player->position.yPos, player->position.xPos, ' ');
			player->position.xPos -= 1;
			player->position.yPos += 1;
		case '2':
		case KEY_DOWN:
			mvaddch(player->position.yPos, player->position.xPos, ' ');
			player->position.yPos += 1;
			break;
		case '3':
			mvaddch(player->position.yPos, player->position.xPos, ' ');
			player->position.xPos += 1;
			player->position.yPos += 1;
			break;
		case '4':
		case KEY_LEFT:
			mvaddch(player->position.yPos, player->position.xPos, ' ');
			player->position.xPos -= 1;
			break;
		case '6':
		case KEY_RIGHT:
			mvaddch(player->position.yPos, player->position.xPos, ' ');
			player->position.xPos += 1;
			break;
		case '7':
			mvaddch(player->position.yPos, player->position.xPos, ' ');
			player->position.xPos -= 1;
			player->position.yPos -= 1;
		case '8':
		case KEY_UP:
			mvaddch(player->position.yPos, player->position.xPos, ' ');
			player->position.yPos -= 1;
			break;
		case '9':
			mvaddch(player->position.yPos, player->position.xPos, ' ');
			player->position.xPos += 1;
			player->position.yPos -= 1;
			break;
		case 'q':
			
			exit(0);
			break;
		
	}
	attroff(COLOR_PAIR(PAIR_DEFAULT));
	
	
}
void zombiesThink(entity *zombies, int waveNumber, entity player)
{
	int mainLooper;
	
	for(mainLooper=0;mainLooper < (GEOMETRIC_PROGRESSION * waveNumber * STARTING_ZOMBIES); mainLooper++)
	{
		if(zombies[mainLooper].dead != TRUE)
		{
			mvaddch(zombies[mainLooper].position.yPos, zombies[mainLooper].position.xPos, ' ');
			if(player.position.xPos > zombies[mainLooper].position.xPos)
			{
				zombies[mainLooper].position.xPos += 1;
			
			
			}
			else if(player.position.xPos < zombies[mainLooper].position.xPos)
			{
				zombies[mainLooper].position.xPos -= 1;
			
			
			}
			if(player.position.yPos > zombies[mainLooper].position.yPos)
			{
				zombies[mainLooper].position.yPos += 1;
			
			
			}
			else if(player.position.yPos < zombies[mainLooper].position.yPos)
			{
				zombies[mainLooper].position.yPos -= 1;
			
			
			}
		}
	}
	
	
	
}
void checkCollision(entity *zombies, entity *pits, entity player, int waveNumber, int *points,  int *isOver)
{
	int mainLooper, internalLooper;
	int limitForZombies = GEOMETRIC_PROGRESSION * STARTING_ZOMBIES * waveNumber;
	int limitForPits = GEOMETRIC_PROGRESSION * STARTING_PITS * waveNumber;
	int allZombiesDead = 0;
	for(mainLooper=0; mainLooper < limitForZombies; mainLooper++)
	{
		if(player.position.xPos == zombies[mainLooper].position.xPos && player.position.yPos == zombies[mainLooper].position.yPos && zombies[mainLooper].dead != TRUE)
		{	
			printMessage(PAIR_DEFAULT, player.position,  "Arrrrrrggggghhhhhhhh!");
			*isOver = 2;
		}
		if(zombies[mainLooper].dead == TRUE)
		{
			allZombiesDead++;
			
		}
		for(internalLooper=0; internalLooper < limitForPits; internalLooper++)
		{	//and I now not so proudly present the longest if statement in the history of human kind
			if(pits[internalLooper].position.xPos == zombies[mainLooper].position.xPos && pits[internalLooper].position.yPos == zombies[mainLooper].position.yPos  && zombies[
mainLooper].dead != TRUE && pits[internalLooper].dead != TRUE)
			{
				pits[internalLooper].dead = TRUE;
				zombies[mainLooper].dead = TRUE;
				*points += 1;

			}
			
		}
		
	}
	if(allZombiesDead == limitForZombies)//goes onto the next wave
	{
		*isOver = 1;
		for(mainLooper = 0; mainLooper < limitForPits; mainLooper++)
		{
			pits[mainLooper].dead = TRUE;
			
		}
	}
	
}

void deinit(int points, int waveNumber)
{
	echo();
	clearScreen();
	FILE *leaderboardFile = fopen("Leaderboards.txt", "a");
	char *playerName;
	mvprintw(GAME_OVER_Y, GAME_OVER_X, "GAME OVER\n You Scored %d Points and Survive %d Waves\n Please enter your name:", points, (waveNumber - 1));
	scanw("%s", playerName);
	fprintf(leaderboardFile, "%s : Scored %d Points and Survived %d Rounds\n", playerName, points, (waveNumber - 1));
	fclose(leaderboardFile);
	printw("Thank You for playing ZOMBIES!!!!");
	noecho();
	
}