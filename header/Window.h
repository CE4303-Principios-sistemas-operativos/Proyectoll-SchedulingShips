#ifndef _MY_HEADER_WINDOW_
#define _MY_HEADER_WINDOW_


#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#include "Barco.h"
#include "linkedList.h"
#include "Canal.h"



struct Window
{
    int screenWidth;
    int screenHeight;
    //struct Canal canal;
};

void update(node_t barcos[], struct Window window, struct Canal canal);
void draw(node_t barcos[], struct Window window, struct Canal canal);
float updateStage(struct Window window, struct Canal canal, struct Barco barco);
int isInside(struct Barco barco, struct Window window);
Texture2D orientation(struct Barco barco);





#endif /* _MY_HEADER_WINDOW_ */

