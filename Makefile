barcos: main.c linkedList.c Barco.c Window.c
	gcc main.c linkedList.c Barco.c Window.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o bin/main