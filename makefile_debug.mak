all:
	cc	-c	main.h	-g	-Wall
	cc	-c	graphics.h	-g	-Wall
	cc	-c	init.h	-g	-Wall
	cc	-c	other.h	-g	-Wall
	cc	-c	graphics.c	-g	-Wall
	cc	-c	other.c	-g	-Wall
	cc	-c	init.c	-g	-Wall
	cc	-c	main.c	-g	-Wall
	cc	-o	Zombies	main.o	graphics.o	init.o	other.o	-lpdcurses	-g	-Wall