#include "Window.h"


int isInside(struct Barco barco, struct Window window){
	if (barco.position.x < window.screenWidth){
		return 1;
	}
	return 0;
}