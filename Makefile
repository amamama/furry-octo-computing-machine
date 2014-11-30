SRC = $(wildcard ./*.c)
OBJ = $(SRC:.c=.o)
all : a.out

a.out : $(OBJ)
	gcc -g -std=c99 -Wall $(OBJ) -lwiringPi 
%.o : %.c
	gcc -g -std=c99 -Wall $< -c -lwiringPi
