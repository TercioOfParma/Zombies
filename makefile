all:
	windres	icon.rc	icon.o
	cc	-c	main.h	
	cc	-c	graphics.h	
	cc	-c	init.h	
	cc	-c	other.h	
	cc	-c	graphics.c	
	cc	-c	other.c	
	cc	-c	init.c	
	cc	-c	main.c		
	cc	-o	Zombies	main.o	graphics.o	init.o	other.o	icon.o	-lpdcurses	