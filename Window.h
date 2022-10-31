#ifndef _MY_HEADER_WINDOW_
#define _MY_HEADER_WINDOW_


#include "Barco.h"


struct Window
{
    int screenWidth;
    int screenHeight;
};

int isInside(struct Barco barco, struct Window window);




#endif /* _MY_HEADER_WINDOW_ */

