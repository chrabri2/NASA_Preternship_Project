// Project graphics function file

#include "../inc/graphics.h"
#include <cstdio>

// Helper functions

void draw_button(int i, int x, int y){
	gfx_color(100,0,0);
	gfx_rectangle(10, (i+10-'1')*y/18+5, x/5, y/19);
	gfx_color(10,10,10);
}

void draw_boxes(int y, int first_value, int second_value, int third_value){
	
	if (first_value && second_value && third_value) {
		if (first_value > third_value) {
			gfx_fill_rectangle(530, 1*y/4+60, 450, y/9);
			gfx_fill_rectangle(530, 2*y/4+60, 450*second_value/first_value, y/9);
			gfx_fill_rectangle(530, 3*y/4+60, 450*third_value/first_value, y/9);
		} else {
			gfx_fill_rectangle(530, 1*y/4+60, 450*first_value/third_value, y/9);
			gfx_fill_rectangle(530, 2*y/4+60, 450*second_value/third_value, y/9);
			gfx_fill_rectangle(530, 3*y/4+60, 450, y/9);
		}
	}
}

void text_options( int y){
	
	

	gfx_color(200, 200, 200);
	
	gfx_text(15, 10*y/18-10, "Select option on keyboard");
	gfx_text(15, 11*y/18-10, "1. overall");
	gfx_text(15, 12*y/18-10, "2. weight");
	gfx_text(15, 13*y/18-10, "3. volume");
	gfx_text(15, 14*y/18-10, "4. energy");
	gfx_text(15, 15*y/18-10, "5. sounds");
	gfx_text(15, 16*y/18-10, "6. years");
	gfx_text(15, 17*y/18-10, "7. surface temp");
	gfx_text(15, 18*y/18-10, "q. quit");

}


//int draw_frame(int c,int x, int y, const char *first, int first_money, const char *second, int second_money, const char * third, int third_money){

void draw_frame( int c, int x, int y, const char *param, const char *first, int first_value, const char *second, int second_value, const char * third, int third_value) {
	
	gfx_clear_color(10, 10, 300);
	gfx_clear();
	
	gfx_color(100,100,100);

	gfx_changefont((char *)"12x24");
	draw_boxes(y, first_value, second_value, third_value);
	draw_button(c, x, y);
	text_options( y);
	
	char buffer[BUFSIZ];
	
	std::sprintf(buffer, "NASA Waste Handling in");
	gfx_text(25, 150, buffer);
	gfx_text(30, 200, "Space Competition");


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


	
