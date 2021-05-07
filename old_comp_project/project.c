// Carter Hrabrick
// chrabri2
// project.c

#ifndef _BSD_SOURCE
#define _BSD_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "gfx3.h"
#include "structs.h"
#include "planet.h"
#include "graphics.h"
#include "file_io.h"
#include "camera.h"

int main(int argc, char *argv[]) {
	// Internal settings
	Settings settings = get_default_settings();
	gfx_open(settings.windowlength, settings.windowwidth, "Gravity Simulator");
	
	Color colors[6]; // Color palette
	reset_colors(colors, 6);
	Camera camera = default_cam(settings);
	bool iowasd_pressed[6] = {false, false, false, false, false, false}; // Checks if buttons are pressed
	
	Planet *planets[128];
	int planetcount = 0;
	
	bool running = true;
	int status, key;
	int mode = play;
	
	while (running) {
		status = gfx_event_waiting();
		if (status) {
			key = gfx_wait();
			switch (status) {
				case 1: // Only thing that concerns keydowns are the camera
						// which needs to be a fluid movement
					switch(key) {
						/*case 'i': iowasd_pressed[0] = true; break;
						case 'o': iowasd_pressed[1] = true; break;
						case 'w': iowasd_pressed[2] = true; break;
						case 'a': iowasd_pressed[3] = true; break;
						case 's': iowasd_pressed[4] = true; break;
						case 'd': iowasd_pressed[5] = true; break;*/
						default: ;
					}
				case 2: // keyups
					switch(key) {
						case 'q': running = false; break;
						case 'p': break; // Supposed to be pause function
						case 'z': break; // Supposed to delete the most previously created planet
						case ',': break; // Supposed to track planets
						case '.': break; // Supposed to track planets
						/*case 'i': iowasd_pressed[0] = false; break;
						case 'o': iowasd_pressed[1] = false; break;
						case 'w': iowasd_pressed[2] = false; break;
						case 'a': iowasd_pressed[3] = false; break;
						case 's': iowasd_pressed[4] = false; break;
						case 'd': iowasd_pressed[5] = false; break;*/
						default: ;
					}
					break;
				case 4: // A click starts the planet making editor
					if (key == 1) {
						// The planet making editor
						Planet *newplanet = summonplanet(planets, planetcount, colors, settings, &camera); 
						
						// This is in case the editor exits without making a planet
						if (newplanet) {
							planets[planetcount] = newplanet;
							planetcount++;
						}
					}
					break;
				default: ;
			}
		}
		calculatevelocities(planets, planetcount, settings); // Calculates gravity
		updatepositions(planets, planetcount); // Moves planets
		planetcount -= runcollisions(planets, planetcount, settings); // manges collided planets
		planetcount -= deleteplanets(planets, planetcount); // deletes out of bound planets
		//interpret_presses(&camera, settings, iowasd_pressed); // unimplemented camera movement
		drawframe(planets, planetcount, colors, mode, NULL, &camera); // draws everything
		if (running) usleep(settings.framespeed);
	}
	
	return 0;
}

