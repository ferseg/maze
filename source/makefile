CLASES = main.c matrizGUI.c creadorLaberinto.c generadorMatriz.c eventos.c raton.c stack.c
CFLAGS = -I ../includes #-Wall
CC = gcc
PROG_NAME = gtkex
LIBS = `pkg-config --cflags --libs gtk+-3.0`

clear_screen: program
	clear

program: 
	$(CC) $(CFLAGS) $(CLASES) -o $(PROG_NAME) $(LIBS)

#clean:
#	rm $(PROG_NAME)
