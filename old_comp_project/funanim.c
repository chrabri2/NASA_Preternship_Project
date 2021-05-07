//Carter Hrabrick
//chrabri2

#define _BSD_SOURCE 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include "gfx.h"

#define MAXSHAPES 128
#define WINDOWLENGTH 1024
#define WINDOWWIDTH 720
#define FPS 60
#define SPEEDCONST .01
#define GRAVITYCONST .1

typedef struct {
	double x;
	double y;
	double vx;
	double vy;
	double radius;
	int type;
	int color;
	int index;
} Shape;

void drawShapeCounter(int shapeCount, int shapeTotal, int shapeMax);
void drawInstructions();
void drawShape(Shape *shape);
void drawSquare(double x, double y, double radius);
void drawCircle(double x, double y, double radius);
void drawTriangle(double x, double y, double radius);
void drawSnowflake(double x, double y, double radius);
void drawShapes(Shape *shapes[], int shapeCount);
void deleteShape(Shape *shapes[], Shape *shape, int shapeCount);
int collisionTest(Shape *shapes[], Shape *shape, int shapeCount);
int runCollisions(Shape *shapes[], int shapeCount);
Shape* summonShape(int shapeCount);
void calculateVelocities(Shape *shapes[], int shapeCount);
void iterate(Shape *shapes[], int shapeCount);

//My apologies for the lack of comments. See report.txt
int main() {
	Shape *shapes[MAXSHAPES];
	int shapeCount = 0, shapeTotal = 0, shapeMax = 0;
	int running = 1;
	int frameLength = 1000000/FPS;
	
	gfx_open(WINDOWLENGTH, WINDOWWIDTH, "Gravitational Circles");
	srand(time(0));
	
	while(running) {
		gfx_clear();
		iterate(shapes, shapeCount);
		shapeCount -= runCollisions(shapes, shapeCount);
		drawShapes(shapes, shapeCount);
		gfx_color(255, 255, 255);
		drawShapeCounter(shapeCount, shapeTotal, shapeMax);
		drawInstructions();
		
		if (gfx_event_waiting()) {
			int c = (int)gfx_wait();
			switch(c) {
				case 113: 
					running = 0;
					break;
				case 1:
					shapes[shapeCount] = summonShape(shapeCount);
					shapeCount++;
					shapeTotal++;
					if (shapeCount > shapeMax)
						shapeMax = shapeCount;
					break;
			}
		}
		usleep(frameLength);
	}
	
	
	return 0;
}

void drawShapeCounter(int shapeCount, int shapeTotal, int shapeMax) {
	char string[64];
	sprintf(string, "Shapes: %d, Total Shapes: %d, Max Shapes: %d", shapeCount, shapeTotal, shapeMax);
	gfx_text(20, 640, string);
}

void drawInstructions() {
	gfx_text(20, 660, "Click once to make a shape of random size (or 'q' to quit)");
	gfx_text(20, 680, "Click a second time to determine the shape's speed (or 'x' to make it motionless)");
	gfx_text(20, 700, "Shapes collide when they intersect. Try to see how many you can fit on the screen!");
}

void drawShape(Shape *shape) {
	double x = shape->x;
	double y = shape->y;
	double radius = shape->radius;
	int type = shape->type;
	int color = shape->color;
	
	switch(color) {
		case 0: gfx_color(255, 255, 255); break;
		case 1: gfx_color(255, 0, 0); break;
		case 2: gfx_color(255, 255, 0); break;
		case 3: gfx_color(0, 255, 0); break;
		case 4: gfx_color(0, 255, 255); break;
		case 5: gfx_color(0, 0, 255); break;
		case 6: gfx_color(255, 0, 255); break;
		default: break;
	}
	
	switch(type) {
		case 0: drawSquare(x, y, radius); break;
		case 1: gfx_circle(x, y, radius); break;
		case 2: drawTriangle(x, y, radius); break;
		case 3: drawSnowflake(x, y, radius); break;
	}
}

void drawSquare(double x, double y, double radius) {
	gfx_line(x+radius, y-radius, x+radius, y+radius);
	gfx_line(x+radius, y+radius, x-radius, y+radius);
	gfx_line(x-radius, y+radius, x-radius, y-radius);
	gfx_line(x-radius, y-radius, x+radius, y-radius);
}

void drawTriangle(double x, double y, double radius) {
	gfx_line(x, y-1.41*radius, x+1.41*radius*.866, y+1.41*radius*0.5);
	gfx_line(x+1.41*radius*.866, y+1.41*radius*0.5, x-1.41*radius*.866, y+1.41*radius*0.5);
	gfx_line(x-1.41*radius*.866, y+1.41*radius*0.5, x, y-1.41*radius);
}

void drawSnowflake(double x, double y, double radius) {
	gfx_line(x, y-radius, x, y+radius);
	gfx_line(x+radius*.866, y-radius*0.5, x-radius*.866, y+radius*0.5);
	gfx_line(x+radius*.866, y+radius*0.5, x-radius*.866, y-radius*0.5);
}

void drawShapes(Shape *shapes[], int shapeCount) {
	for (int i = 0; i < shapeCount; i++) {		
		drawShape(shapes[i]);
	}
}

void deleteShape(Shape *shapes[], Shape *shape, int shapeCount) {
	int index = shape->index;
	for (int i = index; i < shapeCount-1; i++) {
		shapes[i] = shapes[i+1];
		shapes[i]->index = i;
	}
	free(shape);
}

int collisionTest(Shape *shapes[], Shape *shape, int shapeCount) {
	int safe = 1;
	int deleted = 0;
	int index = shape->index;
	double x1 = shape->x;
	double y1 = shape->y;
	double r1 = shape->radius;
	
	for (int i = index+1; i < shapeCount; i++) {
		double x2 = shapes[i]->x;
		double y2 = shapes[i]->y;
		double r2 = shapes[i]->radius;
		if ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) < (r1+r2)*(r1+r2)) {
			deleteShape(shapes, shapes[i], shapeCount);
			deleted++;
			safe = 0;
			i--;
			shapeCount--;
		}
	}
	
	if (x1+r1 > WINDOWLENGTH || x1-r1 < 0) {
		safe = 0;
	} else if (y1+r1 > WINDOWWIDTH || y1-r1 < 0) {
		safe = 0;
	}
	if (!safe) {
		deleteShape(shapes, shape, shapeCount);
		deleted++;
	}
	
	return deleted;
}

int runCollisions(Shape *shapes[], int shapeCount) {
	int deleted = 0;
	for (int i = 0; i < shapeCount; i++) {
		int deletions = collisionTest(shapes, shapes[i], shapeCount);
		if (deletions) {
			i--;
			shapeCount -= deletions;
			deleted += deletions;
		}
	}
	return deleted;
}

Shape* summonShape(int shapeCount) {
	Shape *shape = malloc(sizeof(Shape));
	int randomRadius = rand()%20 - rand()%20;
	if (randomRadius < 0)
		randomRadius *= -1;
	randomRadius += 4;
	
	shape->x = gfx_xpos();
	shape->y = gfx_ypos();
	shape->radius = (double)randomRadius;
	shape->type = rand()%4;
	shape->color = rand()%7;
	shape->index = shapeCount;
	
	drawShape(shape);
	
	int choice = (int)gfx_wait();
	while (choice != 1 && choice != 120) {
		choice = (int)gfx_wait();
	}
	
	switch(choice) {
		case 120:
			shape->vx = 0;
			shape->vy = 0;
			break;
		case 1:
			shape->vx = (gfx_xpos() - shape->x)*SPEEDCONST;
			shape->vy = (gfx_ypos() - shape->y)*SPEEDCONST;
			break;
		default: break;
	} 
	
	
	return shape;
}

void calculateVelocities(Shape *shapes[], int shapeCount) {
	for (int i = 0; i < shapeCount; i++) {
		double vx = 0, vy = 0;
		double x = shapes[i]->x;
		double y = shapes[i]->y;
		for (int j = 0; j < shapeCount; j++) {
			if (j == i)
				continue;
			double dx = shapes[j]->x - x;
			double dy = shapes[j]->y - y;
			double r = shapes[j]->radius;
			double dist = sqrt((dx)*(dx) + (dy)*(dy));
			double grav = (r*r*r)/(dist*dist*dist);
			vx += grav*dx*GRAVITYCONST;
			vy += grav*dy*GRAVITYCONST;
		}
		shapes[i]->vx += vx;
		shapes[i]->vy += vy;
	}
}

void iterate(Shape *shapes[], int shapeCount) {
	calculateVelocities(shapes, shapeCount);
	
	for (int i = 0; i < shapeCount; i++) {
		shapes[i]->x += shapes[i]->vx;
		shapes[i]->y += shapes[i]->vy;
	}
}
