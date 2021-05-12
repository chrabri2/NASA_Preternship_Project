// Project graphics function file

#include "../inc/graphics.h"
#include <cstdio>

// Helper functions

void draw_button(int i, int x, int y){
	gfx_color(100,0,0);
	gfx_rectangle(10, (i+10)*y/18+15, x/5, y/19);
	gfx_color(10,10,10);
}

void draw_boxes(int x, int y){
	
	
	for( int i = 1; i <= 3; i++)
		gfx_fill_rectangle(3*x/4, i*y/4, 450, y/9);

}

void text_options( int y){
	
	

	gfx_color(200, 200, 200);
	
	gfx_text(15, 10*y/18, "Select option on keyboard");
	gfx_text(15, 11*y/18, "1. overall");
	gfx_text(15, 12*y/18, "2. weight");
	gfx_text(15, 13*y/18, "3. volume");
	gfx_text(15, 14*y/18, "4. energy");
	gfx_text(15, 15*y/18, "5. sounds");
	gfx_text(15, 16*y/18, "6. years");
	gfx_text(15, 17*y/18, "7. surface temp");

}

void draw_frame( int c, int x, int y, const char *param, const char *first, int first_value, const char *second, int second_value, const char * third, int third_value) {
	
	gfx_clear();
	
	gfx_clear_color(10, 10, 300);
	gfx_color(100,100,100);

	draw_boxes(x,y);
	draw_button(c, x, y);
	text_options( y);
	
	gfx_changefont((char *)"12x24");
	char buffer[BUFSIZ];
	
	std::sprintf(buffer, "NASA Waste Handling in");
	gfx_text(25, 50, buffer);
	gfx_text(30, 100, "Space Competition");

	std::sprintf(buffer, "1. %s     %s: %d",first, param, first_value);
	gfx_text(x/2, y/4+(y/18), buffer);

	std::sprintf(buffer, "2. %s     %s: %d",second, param, second_value);
	gfx_text(x/2, 2*y/4+y/18, buffer);

	std::sprintf(buffer,"3. %s     %s: %d",third, param, third_value);
	gfx_text(x/2, 3*y/4+y/18, buffer);

	gfx_flush();
/*
	while(1){
		gfx_wait();
		int new_x =  gfx_xpos();
		int new_y =  gfx_ypos();
		int bottom = (y/8)-(y/18);
		int top = (y/8)+(y/18);

		int change = y/8;
		
		int lbound = y/4+(y/10);
		int rbound = y/4-(y/10);

		if((rbound <= new_x) && (new_x <= lbound)) {
			for( int it = 1; it<8; it++){
				if(( bottom <= new_y) && (new_y <= top))
					return it;
				bottom = bottom + it*change;
				top = top + it*change;
			}
		}
	}
*/
	return;
}


	
