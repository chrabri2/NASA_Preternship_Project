// Carter Hrabrick
// chrabri2
// planet.c
// This contains the heavy lifting functions for managing interactions with and between planets

#include "planet.h"

// Removes a planet and adjusts the indices of the rest of the planets accordingly, like a list
void deleteplanet(Planet *planets[], Planet *planet, int planetcount) {
	int index = planet->index;
	
	// Collapses the remainder of the list
	for (int i = index; i < planetcount-1; i++) {
		planets[i] = planets[i+1];
		planets[i]->index = i;
	}
	
	free(planet);
}

// Checks to see if any planets need deleting. Returns number of deleted planets
// The reason for multiple methods of deleting planets is because of an earlier failed collision algorithm
int deleteplanets(Planet *planets[], int planetcount) {
	int deleted = 0;
	
	for (int i = 0; i < planetcount; i++) {
		if (planets[i]->to_be_deleted) {
			deleteplanet(planets, planets[i], planetcount);
			i--;
			planetcount--;
			deleted++;
		}
	}
	
	return deleted;
}

// Checks if a planet is colliding with another planet and acts accordingly
bool collisiontest(Planet *planets[], Planet *planet, int planetcount, Settings settings) {
	planet->incollision = false;
	if (planet->ignorecollisions) 
		return false;
	
	int index = planet->index;
	double x1 = planet->x;
	double y1 = planet->y;
	double r1 = planet->radius;
	
	for (int i = 0; i < planetcount; i++) {
		if (i == index) continue;
		if (planets[i]->ignorecollisions) continue;
		
		double x2 = planets[i]->x;
		double y2 = planets[i]->y;
		double r2 = planets[i]->radius;
		double dx = x2-x1;
		double dy = y2-y1;
		double sr = r1+r2;
		
		// Checks if the radii overlap
		if (dx*dx + dy*dy < sr*sr) {
			int i1, i2, itemp;
			
			// This determines what to do if there's a collision. Collision settings can be updated in
			// file_io.c
			switch(settings.collisionmode) {
				case 0: // Do nothing
					continue;
					break;
				case 2: // Delete both planets
					i1 = planet->index;
					i2 = i;
					
					// The larger index needs to be called first to avoid indexing issues
					if (i2 < i1) {
						itemp = i2;
						i2 = i1;
						i1 = itemp;
					}
					
					deleteplanet(planets, planets[i2], planetcount);
					deleteplanet(planets, planets[i1], planetcount-1);
					return true;
				// This option uses physics to combine the two planets into a single super planet
				case 1: ; // Semicolon to make compiler happy <3
					double m1 = planet->mass; // All of this is physics
					double m2 = planets[i]->mass;
					double px = m1*planet->vx + m2*planets[i]->vx;
					double py = m1*planet->vy + m2*planets[i]->vy;
					double sm = m1 + m2;
					double cx = (m1*x1 + m2*x2)/sm;
					double cy = (m1*y1 + m2*y2)/sm;
					double nvx = px/sm;
					double nvy = py/sm;
					
					// Determines which planet is bigger to delete the tiny one
					if (planet->mass > planets[i]->mass) {
						i1 = planet->index;
						i2 = i;
					} else {
						i1 = i;
						i2 = planet->index;
					}
					
					// Adjust larger planet with correct settings
					planets[i1]->x = cx;
					planets[i1]->y = cy;
					planets[i1]->mass = sm;
					planets[i1]->gravityconst = sm*settings.gravityconst;
					planets[i1]->vx = nvx;
					planets[i1]->vy = nvy;
					int massconst = 1;
					for (int i = 0; i < planets[i1]->rings; i++) {
						massconst *= 10;
					}
					
					planets[i1]->radius = cbrt(sm);
					
					deleteplanet(planets, planets[i2], planetcount);
					return true;
				default: printf("here4\n");
			}
		}
	}
	return false;
}

// Runs collisiontest() for all planets. Also checks if planets go out of bounds
int runcollisions(Planet *planets[], int planetcount, Settings settings) {
	// This is how far a planet center has to go out of the window before being deleted
	int xpadding = (settings.xboundary-settings.windowlength)/2;
	int ypadding = (settings.yboundary-settings.windowwidth)/2;
	
	int deleted = 0;
	for (int i = 0; i < planetcount; i++) {
		bool collided = collisiontest(planets, planets[i], planetcount, settings);
		
		// Numbers need to be adjusted depending on how many planets get deleted by settings
		// collisionmode 1 deletes 1 planet, mode 2 deletes 2
		if (collided) {
			if (settings.collisionmode == 1) {
				i--;
				planetcount--;
				deleted++;
				continue;
			} else if (settings.collisionmode == 2) {
				i--;
				planetcount -= 2;
				deleted += 2;
				continue;
			}
		}
		
		// Ease of use		
		double x = planets[i]->x;
		double y = planets[i]->y;
		
		// boundary checking
		if (x > settings.windowlength + xpadding)
			planets[i]->to_be_deleted = true;
		if (x < -xpadding)
			planets[i]->to_be_deleted = true;
		if (y > settings.windowwidth + ypadding)
			planets[i]->to_be_deleted = true;
		if (y < -ypadding)
			planets[i]->to_be_deleted = true;
	}
	return deleted;
}

// The main mathematical quirk of this program. Calculates the gravitational attractions between
// all planets
void calculatevelocities(Planet *planets[], int planetcount, Settings settings) {
	for (int i = 0; i < planetcount; i++) {
		if (planets[i]->immobile) { 
			planets[i]->vx = 0;
			planets[i]->vy = 0;
			continue;
		}
		
		double dvx = 0, dvy = 0;
		double x1 = planets[i]->x;
		double y1 = planets[i]->y;
		
		for (int j = 0; j < planetcount; j++) {
			if (j == i || planets[j]->massless) continue; // Don't want a planet to try to attract itself
			
			double dx = planets[j]->x - x1;
			double dy = planets[j]->y - y1;
			double dist = sqrt(dx*dx + dy*dy);
			if (dist == 0.0) continue; // A rare edge case
			double grav = planets[j]->gravityconst/(dist*dist*dist);
			
			dvx += grav*dx/settings.framerate; // Physics
			dvy += grav*dy/settings.framerate;
		}
		
		planets[i]->vx += dvx;
		planets[i]->vy += dvy;
	}
}

// Moves the planet according to their velocities
void updatepositions(Planet *planets[], int planetcount) {
	for (int i = 0; i < planetcount; i++) {
		if (planets[i]->immobile) continue;
		planets[i]->x += planets[i]->vx;
		planets[i]->y += planets[i]->vy;
	}
}

// This function is the planet editor for making a new planet
Planet* summonplanet(Planet *planets[], int planetcount, Color colors[], Settings settings, Camera *camera) {
	Planet *planet = malloc(sizeof(Planet));
	
	// Default settings for a new planet
	planet->x = /*xwin_to_xpos(*/gfx_xpos()/*, camera)*/;
	planet->y = /*ywin_to_ypos(*/gfx_ypos()/*, camera)*/;
	planet->vx = 0;
	planet->vy = 0;
	planet->type = circle;
	planet->rings = 0;
	planet->color = red;
	planet->index = planetcount;
	planet->massless = false;
	planet->to_be_deleted = false;
	planet->immobile = false;
	planet->ignorecollisions = false;
	planet->incollision = false;
	
	int summonstatus = 1; // 0 exits loop, 1 is in radius choosing phase, 2 is velocity choosing phase
	int status, key;
	
	// This loop is entirely separate from the main one. Thus 'q' is not yet implemented
	while (summonstatus) {
		status = gfx_event_waiting();
		if (status) {
			key = gfx_wait();
			switch (status) {
				case 5: ; // Mouse movement, determines distance from center to mouse
				double dx = /*rwin_to_rpos(*/gfx_xpos() - /*xpos_to_xwin(*/planet->x/*, camera), camera)*/;
				double dy = /*rwin_to_rpos(*/gfx_ypos() - /*ypos_to_ywin(*/planet->y/*, camera), camera)*/;
				if (summonstatus == 1) { // adjusts radius
					planet->radius = sqrt(dx*dx+dy*dy);
				} else if (summonstatus == 2) { // adjusts velocity
					planet->vx = dx;
					planet->vy = dy; 
				}
					break;
				
				case 4: // Mouse clicks. Progression is click to enter editor -> click to set radius
						// -> click to set velocity and go back to main()
					if (key == 1) {
						if (summonstatus == 1) {
							summonstatus = 2;
						} else if (summonstatus == 2) {
							summonstatus = 0;
						}
					}
					break;
				
				case 2: // Keypresses change lots of propertiess for the planet
					switch (key) {
						case 'x': // is the reverse of a click
							if (summonstatus == 1) {
								free(planet);
								return NULL;
							} else if (summonstatus == 2) {
								planet->vx = 0;
								planet->vy = 0;
								summonstatus = 1;
							}
							break;
						case 'z': // ignores velocity choosing
							if (summonstatus == 2) {
								planet->vx = 0;
								planet->vy = 0;
								summonstatus = 0;
							}
							break;
						case 'r':
							planet->color = red;
							break;
						case 'o':
							planet->color = orange;
							break;
						case 'y':
							planet->color = yellow;
							break;
						case 'g':
							planet->color = green;
							break;
						case 'b':
							planet->color = blue;
							break;
						case 'p':
							planet->color = purple;
							break;
						case 'c':
							planet->type = circle;
							break;
						case 'v':
							planet->type = snowflake;
							break;
						case '.':
							if (planet->rings < 5)
								planet->rings++;
							break;
						case ',':
							if (planet->rings > 0)
								planet->rings--;
							break;
						case 'i':
							planet->immobile = !planet->immobile;
							break;
						case 'n':
							planet->ignorecollisions = !planet->ignorecollisions;
							break;
						default: break;
					}
				default: break;
			}
		}
		
		// Updates editor
		drawframe(planets, planetcount, colors, summon, planet, camera);
		if (summonstatus) usleep(settings.framespeed);
	}
	
	planet->vx /= settings.framerate; // framerate included because speed is in
	planet->vy /= settings.framerate; // pixels per second
	
	int r = planet->radius;	
	planet->mass = r*r*r; // Mass is proportional to volume
	
	// Rings multiply mass by 10
	for (int i = 0; i < planet->rings; i++) {
		planet->mass *= 10;
	}
	
	if (planet->type == snowflake) {
		planet->massless = true;
		planet->mass = 0;
	}
	
	planet->gravityconst = planet->mass*settings.gravityconst;
	
	return planet;
}
