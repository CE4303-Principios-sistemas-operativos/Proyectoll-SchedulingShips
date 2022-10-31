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
#include "Barco.h"
#include "Window.h"
#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>


struct Window window = {800,500};


float base = 225.0f;
void update(node_t barcos[]);
void draw(node_t barcos[]);




//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------


    InitWindow(window.screenWidth,window.screenHeight, "raylib [core] example - keyboard input");
	
	struct Barco barco1 = {{ 25.0f, 75.0f }, 25, 1.5f};
	struct Barco barco2 = {{ 25.0f, 125.0f },25, 2.5f};
	struct Barco barco3 = {{ 25.0f, 175.0f },25, 3.5f};
	
	node_t * barcos = new_list(barco1);
	push(barcos, barco2);
	push(barcos, barco3);
	//print_list(barcos);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
		update(barcos);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
		draw(barcos);
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}



void update(node_t barcos[]){

	// TEST CODE
	if(IsKeyPressed(KEY_ENTER)){
		struct Barco barcoNuevo = {{ 25.0f, base },25, 3.5f};
		push(barcos,barcoNuevo);
        base += 50;
	}
	// TEST CODE

    node_t * current = barcos;

    while (current != NULL) {
		if (isInside(current->barco, window)){
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

    //DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

    node_t * current = barcos;

    while (current != NULL) {
		DrawCircleV(current->barco.position, 25, MAROON);
      
        current = current->next;
    }
    EndDrawing();
}