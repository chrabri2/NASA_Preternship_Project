// Carter Hrabrick
// chrabri2
// planet.h
// This contains the heavy lifting functions for managing interactions with and between planets

#ifndef _PLANET_H_
#define _PLANET_H_

#ifndef _BSD_SOURCE
#define _BSD_SOURCE
#endif

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "graphics.h"
#include "gfx3.h"
#include "structs.h"
#include "camera.h"

// Removes a planet and adjusts the indices of the rest of the planets accordingly, like a list
void deleteplanet(Planet *planets[], Planet *planet, int planetcount);

// Checks to see if any planets need deleting. Returns number of deleted planets
int deleteplanets(Planet *planets[], int planetcount);

// Checks if a planet is colliding with another planet and acts accordingly
bool collisiontest(Planet *planets[], Planet *planet, int planetcount, Settings settings);

// Runs collisiontest() for all planets. Also checks if planets go out of bounds
int runcollisions(Planet *planets[], int planetcount, Settings settings);

// The main mathematical quirk of this program. Calculates the gravitational attractions between
// all planets
void calculatevelocities(Planet *planets[], int planetcount, Settings settings);

// Moves the planets according to their velocities
void updatepositions(Planet *planets[], int planetcount);

// This function is the planet editor for making a new planet
Planet* summonplanet(Planet *planets[], int planetcount, Color colors[], Settings settings, Camera *camera);

#endif
