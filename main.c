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


const int screenWidth = 800;
const int screenHeight = 500;

struct Barco
{
	Vector2 position;
	int size;
	int speed;
	int color;
};
void update(struct Barco barcos[]);
void draw(struct Barco barcos[]);
int isInside(struct Barco barco);


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------


    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

	struct Barco barcos[3];
	struct Barco barco1 = {{ 25.0f, 125.0f },25,1.0f};
	struct Barco barco2 = {{ 25.0f, 75.0f },25,1.5f};
    //Vector2 barco1 = { 25.0f, 125.0f };
	//Vector2 barco2 = { 25.0f, 75.0f };
	barcos[0] = barco1;
	barcos[1] = barco2;

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



int isInside(struct Barco barco){
	if (barco.position.x < screenWidth){
		return 1;
	}
	return 0;
}


void update(struct Barco barcos[]){
    if (IsKeyDown(KEY_D))  barcos[0].position.x += 2.0f;
    if (IsKeyDown(KEY_A))  barcos[0].position.x -= 2.0f;
    if (IsKeyDown(KEY_W))  barcos[0].position.y -= 2.0f;
    if (IsKeyDown(KEY_S))  barcos[0].position.y += 2.0f;

	if (isInside(barcos[1])){
		barcos[1].position.x += barcos[1].speed;
	}else{
		barcos[1].position.x = 25.0f;
	}
}


void draw(struct Barco barcos[]){
	BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

    DrawCircleV(barcos[0].position, 25, MAGENTA);
	DrawCircleV(barcos[1].position, 25, MAROON);

    EndDrawing();
}