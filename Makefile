barcos: main.c linked_list.c
	gcc main.c linked_list.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o main