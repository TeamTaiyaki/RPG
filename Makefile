
CC=gcc
CFLAGS=-Wall

SRC=rpg.c file.c make_char.c print_screen.c Yusha.c Fujiwara.c tomo.c
default: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o game.exe

clean:
	rm -f *.o *.exe
