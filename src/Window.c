#include "../header/Window.h"
float base = 225.0f;


void update(node_t barcos[], struct Window window, struct Canal canal){

	// TEST CODE
	if(IsKeyPressed(KEY_ENTER)){
		struct Barco barcoNuevo = {{ 25.0f, base },25, 3.5f, 'L', 1};
		push(barcos,barcoNuevo);
        base += 50;
	}
	// TEST CODE

    node_t * currentNode = barcos;

    while (currentNode != NULL) {
		if (isInside(currentNode->barco, window)){
			//currentNode->barco.position.x = updateStage(window,canal,currentNode->barco);
			currentNode->barco.position.x += currentNode->barco.speed;
		}else{
			currentNode->barco.position.x = 25.0f;
		}
        currentNode = currentNode->next;
    }
}


void draw(node_t barcos[], struct Window window, struct Canal canal){
	BeginDrawing();

    ClearBackground(RAYWHITE);

    //DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

    node_t * currentNode = barcos;

    while (currentNode != NULL) {
		DrawCircleV(currentNode->barco.position, 25, MAROON);
      
        currentNode = currentNode->next;
    }
    EndDrawing();
}


/* --------------------------------------  UPDATE METHODS ----------------------- */

float updateStage(struct Window window, struct Canal canal, struct Barco barco){
	int stageWidth = window.screenWidth/canal.stages;
	float middleStage = (float)stageWidth/2;
	float stageXPos = barco.stage*stageWidth + middleStage;

	return stageXPos;
	
}


int isInside(struct Barco barco, struct Window window){
	if (barco.position.x < window.screenWidth && barco.position.x >= 0){
		return 1;
	}
	return 0;
}



/* --------------------------------------  DRAW METHODS ---------------------- */