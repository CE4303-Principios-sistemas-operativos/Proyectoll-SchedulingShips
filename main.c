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

#include <stdio.h>
#include <stdlib.h>

#include "header/Barco.h"
#include "header/Window.h"
#include "header/linkedList.h"



//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{

    // Declaration
    //--------------------------------------------------------------------------------------

    struct Canal canal = {20};
    struct Window window = {800,500};
	struct Barco barco1 = {{ 25.0f, 75.0f }, 25, 1.5f, 'L',0};
	struct Barco barco2 = {{ 25.0f, 125.0f },25, 2.5f, 'L',1};
	struct Barco barco3 = {{ 25.0f, 175.0f },25, 3.5f, 'R',3};
	node_t * barcos = new_list(barco1);
	push(barcos, barco2);
	push(barcos, barco3);
	//print_list(barcos);
    
    
    // Initialization
    //--------------------------------------------------------------------------------------
	
    InitWindow(window.screenWidth,window.screenHeight, "raylib [core] example - keyboard input");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
		update(barcos, window, canal);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
		draw(barcos, window, canal);
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}