// Carter Hrabrick
// chrabri2@nd.edu
// structs.h

#include <stdbool.h>

#ifndef _STRUCTS_H_
#define _STRUCTS_H_

enum color{red, orange, yellow, green, blue, purple};
enum shape{circle, snowflake};
enum mode{play, summon, paused, tracking}; // Paused and tracking modes not yet implemented
// Pause is supposed to freeze the simulation using 'p'
// tracking is supposed to allow the user to make the camera follow a planet

// Keeps track of the color palatte
typedef struct {
	int red1; // primary color
	int green1;
	int blue1;
	int red2; // secondary color
	int green2; // default is just a darker version of the primary
	int blue2;
} Color;

typedef struct {
	double x;
	double y;
	double vx;
	double vy;
	double radius;
	double mass;
	double gravityconst;
	int type;
	int rings;
	int color;
	int index;
	bool massless;
	bool to_be_deleted;
	bool immobile;
	bool ignorecollisions;
	bool incollision;
} Planet;

// Game settings
typedef struct {
	int windowlength;
	int windowwidth;
	int xboundary; // How wide the boundary is for planets to stay inside
	int yboundary; // without being deleted
	int framerate; // fps
	int framespeed; // 1/fps
	int collisionmode; // 0 for ignoring collisions, 1 combines collisions, 2 deletes both planets
	double gravityconst; // Generally tiny so that planets don't yeet towards each other
	double minscale; // How far in one can zoom
	double zoomspeed; // How fast one can zoom, ex 1.5 = scales 1.5 times per second
	double movespeed; // How many pixels panned in a second
	double aspectratio; // windowlength/windowwidth
} Settings;

typedef struct {
	double x1; // top left corner
	double y1;
	double x2; // bottom right corner
	double y2;
	double scale; // ratio of internal units to window pixels
} Camera;

#endif
