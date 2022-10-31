#ifndef _MY_HEADER_BARCO_
#define _MY_HEADER_BARCO_

#include "raylib.h"

struct Barco
{
	Vector2 position;
	int size;
	int speed;
	char dock;
	int stage;
	Texture2D texture;
	Texture2D textureE;
	Texture2D textureO;
};



#endif /* _MY_HEADER_BARCO_ */

