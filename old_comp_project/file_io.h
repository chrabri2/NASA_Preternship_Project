// Carter Hrabrick
// chrabri2
// file_io.h
// Manages file import/outport, but that has been unimplemented

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "structs.h" // See for details on the structs below

// Returns the settings struct in its default state
Settings get_default_settings();

// Resets the color palette to its defualt
void reset_colors(Color colors[], int colorcount);

