// Carter Hrabrick
// chrabri2
// graphics.h
// Manages the drawing of the program

#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "gfx3.h"
#include "structs.h"
#include "math.h"
#include "camera.h"

// Not yet implemented. Suppossed to display useful information to the user
void drawinfo();

// Takes a planet and puts it on the screen
void drawplanet(Planet *planet, Color colors[], Camera *camera);

// A function to draw a snowflake to the screen
void drawsnowflake(double x, double y, double radius);

// A for loop that calls drawplanet() for every planet
void drawplanets(Planet *planets[], int planetcount, Color colors[], Camera *camera);

// An overarching function that draws everything
void drawframe(Planet *planets[], int planetcount, Color colors[], int mode, Planet *newplanet, Camera *camera);

#endif
