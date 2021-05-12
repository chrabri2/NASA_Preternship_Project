// Project graphics function file

#include "../inc/graphics.h"
#include <cstdio>

// Helper functions

void draw_button(int i, int x, int y){
	gfx_color(100,0,0);
	gfx_rectangle(x/4, i*y/8, x/5+6, y/9+6);
	gfx_color(10,10,10);
}

void draw_boxes(int x, int y){
	
	
	for( int i = 1; i <= 7; i++)
		gfx_fill_rectangle(x/5, i*y/8, x/5, y/9);

}

void text_options(int x, int y){
	
	

	gfx_color(200, 200, 200);
	
	gfx_text(x/5, 10*y/9"Select option on keyboard");
	gfx_text(x/5, 11*y/18, "1. overall");
	gfx_text(x/5, 12*y/18, "2. weight");
	gfx_text(x/5, 13*y/18, "3. volume");
	gfx_text(x/5, 14*y/18, "4. energy");
	gfx_text(x/5, 15*y/18, "5. sounds");
	gfx_text(x/5, 16*y/18, "6. years");
	gfx_text(x/5, 17*y/18, "7. surface temp");

}

int draw_frame( int c, int x, int y, const char *first, int first_money, const char *second, int second_money, const char * third, int third_money) {
	
	
	
	gfx_clear_color(10, 10, 300);
	gfx_color(100,100,100);

	draw_boxes(x,y);
	draw_button(c, x, y);
	text_options(x, y);
	
	gfx_changefont("12x24");
	char buffer[BUFSIZ];

	std::sprintf(buffer, "1. %s     $%d",first, first_money);
	gfx_text(3*x/4, y/4, buffer);

	std::sprintf(buffer, "2. %s     $%d",second, second_money);
	gfx_text(3*x/4, 2*y/4, buffer);

	std::sprintf(buffer,"3. %s     $%d",third, third_money);
	gfx_text(3*x/4, 3*y/4, buffer);

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
	return 0;
}


	
