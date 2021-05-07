// Carter Hrabrick
// chrabri2
// camera.c
// This manages the camera, which is a piece of software that should allow the user to zoom in/out and pan
// the screen. However it does not work, so it is currently unimplemented. It should work by managing two
// coordinate systems, an internal one and a window one

#include "camera.h"

// Turns an x coordinate from internal to window
double xpos_to_xwin(double xpos, Camera *camera) {
	double dx = xpos - camera->x1;
	return dx/camera->scale;
}

// Turns a y coordinate from internal to window
double ypos_to_ywin(double ypos, Camera *camera) {
	double dy = ypos - camera->y1;
	return dy/camera->scale;
}

// Turns a scalar from internal to window
double rpos_to_rwin(double rpos, Camera *camera) {
	return rpos/camera->scale;
}

// Turns an x coordinate from window to internal
double xwin_to_xpos(double xwin, Camera *camera) {
	return xwin*camera->scale + camera->x1;
}

// Turns a y coordinate from window to internal
double ywin_to_ypos(double ywin, Camera *camera) {
	return ywin*camera->scale + camera->y1;
}

// Turns a scalar from window to internal
double rwin_to_rpos(double rwin, Camera *camera) {
	return rwin*camera->scale;
}

// Returns a camera with the defualt settings, which is zoomed out to the max encompassing the whole game
Camera default_cam(Settings settings) {
	Camera camera;
	camera.scale = 1.0;
	camera.x1 = 0;
	camera.y1 = 0;
	camera.x2 = settings.windowlength;
	camera.y2 = settings.windowwidth;
	return camera;
}

// If a camera moves out of bounds for whatever reason, this will readjust it
void fix_cam(Camera *camera, Settings settings) {
	double dx = camera->x2-camera->x1; // internal coords. Viewing length
	double dy = dx/settings.aspectratio; // internal viewing width
	double cx = (camera->x1+camera->x2)/2; // Center coord of the camera
	double cy = (camera->y1+camera->y2)/2; 
	
	// If scale is too far out, shrink it back to default
	if (camera->scale > 1.0) {
		*camera = default_cam(settings);
		return;
	} else if (camera->scale < settings.minscale) { // This is if the camera is zoomed to far in
		double ratio = settings.minscale/camera->scale;
		dx *= ratio; // Adjusts window length and width
		dy *= ratio;
		
		camera->x1 = cx-(dx/2); // When zooming, the center shouldn't change
		camera->x2 = cx+(dx/2); // So this builds the new screen 
		camera->y1 = cy-(dy/2);
		camera->y2 = cy+(dy/2);
		camera->scale = settings.minscale;
	}
	
	// Basic shifts if the camera moves too far left, right, up, or down
	if (camera->x1 < 0) {
		camera->x2 -= camera->x1;
		camera->x1 = 0;
	} else if (camera->x2 > settings.windowlength) {
		camera->x1 -= (camera->x2 - settings.windowlength);
		camera->x2 = settings.windowlength;
	}
	
	if (camera->y1 < 0) {
		camera->y2 -= camera->y1;
		camera->y1 = 0;
	} else if (camera->y2 > settings.windowwidth) {
		camera->y1 -= (camera->y2 - settings.windowwidth);
		camera->y2 = settings.windowwidth;
	}
}

// Takes the camera and moves it, including zooming in/out
// The doubles should only be balled as -1, 0, or 1 values
// This lets the caller control direction, but the function controls speed
void move_cam(Camera *camera, Settings settings, double dx, double dy, double dz) {
	dx *= settings.movespeed/settings.framerate;
	dy *= settings.movespeed/settings.framerate;
	
	// Fancy math because zooming works on a logarithmic scale
	// Also everything gets adjusted with framerate because speeds are measured in 'per seconds'
	if (dz == 1.0)
		dz = log(settings.zoomspeed)/log(settings.framerate);
	else if (dz == -1.0)
		dz = log(settings.framerate)/log(settings.zoomspeed);
	else
		dz = 1.0;
	
	// Checks to make sure zoom doesn't go out of bounds
	if (camera->scale*dz > 1.0) {
		*camera = default_cam(settings);
		return;
	} else if (camera->scale*dz < settings.minscale) {
		dz = settings.minscale/camera->scale;
	}
	
	double ndx = (camera->x2-camera->x1)*dz; // New adjusted length/width
	double ndy = ndx/settings.aspectratio; // I use the aspect ratio so that rounding errors don't cause
	double cx = (camera->x1+camera->x2)/2; // issues the the aspect ratio of the camera changing
	double cy = (camera->y1+camera->y1)/2;
	
	camera->x1 = cx-(ndx/2);
	camera->x2 = cx+(ndx/2);
	camera->y1 = cy-(ndy/2);
	camera->y2 = cy+(ndy/2);
	camera->scale *= dz;
	
	// Boundary checking
	if (camera->x2+dx > settings.windowlength)
		dx = settings.windowlength - camera->x2;
	else if (camera->x1+dx < 0)
		dx = -camera->x1;
	 
	camera->x1 += dx;
	camera->x2 += dx;
	
	
	if (camera->y2+dy > settings.windowwidth)
		dy = settings.windowwidth - camera->y2;
	else if (camera->y1+dy < 0)
		dy = -camera->y1;
	
	camera->y1 += dy;
	camera->y2 += dy;
	
}

// Takes pressed keys, figures out how it should make the camera move, and then calls move_cam()
// Note that move_cam needs the doubles to be -1, 0, or 1
void interpret_presses(Camera *camera, Settings settings, bool iowasd_pressed[6]) {
	int dx = 0, dy = 0, dz = 0;
	if (iowasd_pressed[0])
		dz += 1;
	if (iowasd_pressed[1])
		dz -= 1;
	if (iowasd_pressed[2])
		dy -= 1;
	if (iowasd_pressed[3])
		dx -= 1;
	if (iowasd_pressed[4])
		dy += 1;
	if (iowasd_pressed[5])
		dx += 1;
	
	move_cam(camera, settings, dx, dy, dz);
}
