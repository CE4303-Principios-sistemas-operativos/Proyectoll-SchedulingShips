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
    struct Window window = {1000,800};
    struct Canal canal = {10};
    // 80 pixeles por etapa


    
    
    // Initialization
    //--------------------------------------------------------------------------------------
	
    InitWindow(window.screenWidth,window.screenHeight, "raylib [core] example - keyboard input");

    Image imageNormalE = LoadImage("assets/normal_este.png");     // Loaded in CPU memory (RAM)
    Texture2D textureNormalE = LoadTextureFromImage(imageNormalE);          // Image converted to texture, GPU memory (VRAM)
    UnloadImage(imageNormalE);   // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM
    Image imageNormalO = LoadImage("assets/normal_oeste.png");     // Loaded in CPU memory (RAM)
    Texture2D textureNormalO = LoadTextureFromImage(imageNormalO);          // Image converted to texture, GPU memory (VRAM)
    UnloadImage(imageNormalO);   // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM
    
    Image imagePesqueroE = LoadImage("assets/pesquero_este.png");     // Loaded in CPU memory (RAM)
    Texture2D texturePesqueroE = LoadTextureFromImage(imagePesqueroE);          // Image converted to texture, GPU memory (VRAM)
    UnloadImage(imagePesqueroE);   // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM
    Image imagePesqueroO = LoadImage("assets/pesquero_oeste.png");     // Loaded in CPU memory (RAM)
    Texture2D texturePesqueroO = LoadTextureFromImage(imagePesqueroO);          // Image converted to texture, GPU memory (VRAM)
    UnloadImage(imagePesqueroO);   // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM
	
    struct Barco barco1 = {{ 25.0f, 75.0f }, 25, 1.5f, 'R',0,textureNormalE,textureNormalE,textureNormalO};
	struct Barco barco2 = {{ 25.0f, 125.0f },25, 2.5f, 'L',1,texturePesqueroE,texturePesqueroE,texturePesqueroO};
	struct Barco barco3 = {{ 25.0f, 175.0f },25, 3.5f, 'R',3,texturePesqueroE,texturePesqueroE,texturePesqueroO};

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