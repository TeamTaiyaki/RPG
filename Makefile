
CC=gcc
CFLAGS=-Wall

SRC=rpg.c file.c make_char.c print_screen.c Yusha.c Fujiwara.c game.c
default: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o game.exe
