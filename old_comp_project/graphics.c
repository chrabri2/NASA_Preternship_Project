// Carter Hrabrick
// chrabri2
// graphics.c
// Manages the drawing of the program

#include "graphics.h"

// Not yet implemented. Supposed to display useful information to the user
void drawinfo() {
	
}

// Takes a planet and puts it on the screen
void drawplanet(Planet *planet, Color colors[], Camera *camera) {
	
	// Info about the planet for ease of use
	double x = /*xpos_to_xwin(*/planet->x/*, camera)*/;
	double y = /*ypos_to_ywin(*/planet->y/*, camera)*/;
	double r = /*rpos_to_rwin(*/planet->radius/*, camera)*/;
	int type = planet->type;
	int color = planet->color;
	int rings = planet->rings;
	double pi = 3.14159;
	
	// The primary drawing color for the primary shape
	gfx_color(colors[color].red1, colors[color].green1, colors[color].blue1);
	switch(type) {
		case circle: 
			if (planet->immobile)
				gfx_fill_circle(x, y, r);
			else
				gfx_circle(x, y, r); 
			break;
		case snowflake: drawsnowflake(x, y, r); break;
		default: break;
	}
	
	// The secondary color. If the planet ignores collisions then it's white
	if (planet->ignorecollisions)
		gfx_color(255, 255, 255);
	else
		gfx_color(colors[color].red2, colors[color].green2, colors[color].blue2);
	
	// This part makes the secondary parts of a planet, like its rings
	if (type == circle && rings > 0) {
		double angle = pi/2/(rings+1);
		for (int i = 1; i <= rings; i++) {
			gfx_circle(x, y, sin(i*angle)*r);
		}	
	} else if (type == circle && planet->ignorecollisions) {
		drawsnowflake(x, y, r/3);
	}
	
	if (type == snowflake && planet->immobile)
		gfx_circle(x, y, r);
	else if (type == snowflake && planet->ignorecollisions)
		drawsnowflake(x, y, r/2);
}

// A function to draw a snowflake to the screen
void drawsnowflake(double x, double y, double radius) {
	gfx_line(x, y-radius, x, y+radius);
	gfx_line(x+radius*.866, y-radius*.5, x-radius*.866, y+radius*.5);
	gfx_line(x+radius*.866, y+radius*.5, x-radius*.866, y-radius*.5);
}

// A for loop that calls drawplanet) for every planet
void drawplanets(Planet *planets[], int planetcount, Color colors[], Camera *camera) {
	for (int i = 0; i < planetcount; i++) {
		drawplanet(planets[i], colors, camera);
	}
}

// An overarching function that draws everything
void drawframe(Planet *planets[], int planetcount, Color colors[], int mode, Planet *newplanet, Camera *camera) {
	gfx_clear();
	drawplanets(planets, planetcount, colors, camera);
	
	// This is to draw the planet editor for when the user is making a new planet
	if (mode == summon) {
		drawplanet(newplanet, colors, camera);
		
		// This draws the velocity vector
		if (newplanet->vx || newplanet->vy) {
			gfx_color(255, 255, 255);
			double x = /*xpos_to_xwin(*/newplanet->x/*, camera)*/;
			double y = /*ypos_to_ywin(*/newplanet->y/*, camera)*/;
			double vx = /*rpos_to_rwin(*/newplanet->vx/*, camera)*/;
			double vy = /*rpos_to_rwin(*/newplanet->vy/*, camera)*/;
			gfx_line(x, y, x+vx, y+vy);
		}
	}
}

	
