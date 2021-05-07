// Carter Hrabrick
// chrabri2
// camera.h
// This manages the camera, which is a piece of software that should allow the user to zoom in/out and pan
// the screen. However it does not work, so it is currently unimplemented. It should work by managing two
// coordinate systems, an internal one and a window one

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <stdbool.h>
#include <math.h>
#include "structs.h"

// Turns an x coordinate from internal to window
double xpos_to_xwin(double xpos, Camera *camera);

// Turns a y coordinate from internal to window
double ypos_to_ywin(double ypos, Camera *camera);

// Turns a scalar from internal to window
double rpos_to_rwin(double rpos, Camera *camera);

// Turns an x coordinate from window to internal
double xwin_to_xpos(double xwin, Camera *camera);

// Turns a y coordinate from window to internal
double ywin_to_ypos(double ywin, Camera *camera);

// Turns a scalar from window to internal
double rwin_to_rpos(double rwin, Camera *camera);

// Returns a camera with the default settings, which is zoomed out to the max
Camera default_cam(Settings settings);

// If a camera moves out of bounds for whatever reason, this will readjust it
void fix_cam(Camera *camera, Settings settings);

// Takes the camera and moves it, including zooming in/out
void move_cam(Camera *camera, Settings settings, double dx, double dy, double dz);

// Takes pressed keys, figures out how it should make the camera move, and then calls move_cam()
void interpret_presses(Camera *camera, Settings settings, bool iowasd_pressed[6]);

#endif
