// Carter Hrabrick
// chrabri2
// file_io.c
// This program is supposed to do file management things, but they have not yet been implemented.
// As of now it only contains the default settings for color and settings

#include "file_io.h"

// Returns the default settings struct, see the struct in structs.h for more details
Settings get_default_settings() {
	Settings settings = {1080, 720, 1120, 760, 60, 1000000/60, 1, .001, .001, 1.5, 540, 1.5};
	return settings;
}

// Adjust the color palette to default. See structs.h for more details
void reset_colors(Color colors[], int colorcount) {
	Color defaultcolors[6] = {{255, 0, 0, 170, 0, 0},
							{255, 127, 0, 170, 84, 0},
							{255, 255, 0, 170, 190, 0},
							{0, 255, 0, 0, 170, 0},
							{0, 0, 255, 0, 0, 170},
							{255, 0, 255, 170, 0, 170}};
	for (int i = 0; i < colorcount; i++) {	
			colors[i] = defaultcolors[i]; 
	}
}

