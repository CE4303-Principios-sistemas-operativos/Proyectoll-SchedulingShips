#include "../header/Window.h"
float base = 225.0f;


void update(node_t barcos[], struct Window window, struct Canal canal){

	// TEST CODE
	if(IsKeyPressed(KEY_ENTER)){
		struct Barco barcoNuevo = {{ 25.0f, base },25, 3.5f, 'L',9, barcos->barco.texture,barcos->barco.texture,barcos->barco.texture};
		push(barcos,barcoNuevo);
        base += 50;
	}
	// TEST CODE

    node_t * currentNode = barcos;

    while (currentNode != NULL) {
		if (isInside(currentNode->barco, window)){
			currentNode->barco.position.x = updateStage(window,canal,currentNode->barco);
			currentNode->barco.texture = orientation(currentNode->barco);
			//currentNode->barco.position.x += currentNode->barco.speed;
		}else{
			currentNode->barco.position.x = 0.0f;
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
		//DrawCircleV(currentNode->barco.position, 25, MAROON);
		DrawTexture(currentNode->barco.texture,currentNode->barco.position.x, currentNode->barco.position.y, WHITE);
      
        currentNode = currentNode->next;
    }
    EndDrawing();
}


/* --------------------------------------  UPDATE METHODS ----------------------- */

float updateStage(struct Window window, struct Canal canal, struct Barco barco){
	int stageWidth = window.screenWidth/canal.stages;
	float middleStage = (float)stageWidth/2;
	float stageXPos = barco.stage*stageWidth;

	return stageXPos;
	
}


int isInside(struct Barco barco, struct Window window){
	int val = window.screenWidth - 49;
	if (barco.position.x < val && barco.position.x >= 0){
		return 1;
	}
	return 0;
}

Texture2D orientation(struct Barco barco){
	if (barco.dock == 'L'){
		return barco.textureE;
	}else{
		return barco.textureO;
	}
}




/* --------------------------------------  DRAW METHODS ---------------------- */