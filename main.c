/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "types.h"
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

const int screenWidth = 800;
const int screenHeight = 500;
int more1 = 1;
int more2 = 1;
float yPos = 225.0f;
float yPos2 = 275.0f;

void update(node_t barcos[]);
void draw(node_t barcos[]);
int isInside(struct Barco barco);


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------


    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
	
	struct Barco barco1 = {{ 25.0f, 75.0f }, 25, 1.5f};
	struct Barco barco2 = {{ 25.0f, 125.0f },25, 2.5f};
	struct Barco barco3 = {{ 25.0f, 175.0f },25, 3.5f};
	
	node_t * head = new_list(barco1);
	push(head, barco2);
	push(head, barco3);
	//print_list(head);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
		update(head);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
		draw(head);
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}



int isInside(struct Barco barco){
	if (barco.position.x < screenWidth){
		return 1;
	}
	return 0;
}


void update(node_t barcos[]){

	// TEST CODE
	if(IsKeyDown(KEY_C) && more1 != 0){
		struct Barco barcoNuevo = {{ 25.0f, yPos },25, 3.5f};
		push(barcos,barcoNuevo);
		more1 -= 1;
	}else if(IsKeyDown(KEY_N) && more2 != 0){
		struct Barco barcoNuevo = {{ 25.0f, yPos2 },25, 3.5f};
		push(barcos,barcoNuevo);
		more2 -= 1;
	}
	// TEST CODE

    node_t * current = barcos;

    while (current != NULL) {
		if (isInside(current->barco)){
			current->barco.position.x += current->barco.speed;
		}else{
			current->barco.position.x = 25.0f;
		}        
        current = current->next;
    }	
}


void draw(node_t barcos[]){
	BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

    node_t * current = barcos;

    while (current != NULL) {
		DrawCircleV(current->barco.position, 25, MAROON);
      
        current = current->next;
    }
    EndDrawing();
}