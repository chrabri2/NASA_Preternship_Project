// Project graphics function file

#include "../inc/graphics.h"


// Helper functions

void draw_button(int i, int x, int y){
	gfx_color(100,0,0);
	gfx_rectangle(x/4, i*y/8, x/5+6, y/9+6);
	gfx_color(10,10,10);
}

void draw_boxes(int x, int y){

	for( int i = 1; i <= 7; i++)
		gfx_rectangle(x/4, i*y/8, x/5, y/9);

}

void text_options(int x, int y){

	gfx_color(200, 200, 200);

	gfx_text(x/4, 7*y/8, "overall");
	gfx_text(x/4, 6*y/8, "weight");
	gfx_text(x/4, 5*y/8, "vollume");
	gfx_text(x/4, 4*y/8, "energy");
	gfx_text(x/4, 3*y/8, "sounds");
	gfx_text(x/4, 2*y/8, "years");
	gfx_text(x/4, y/8, "surface temp");

}

void draw_frame( int c, int x, int y, char *first, int first_money, char *second, int second_money, char * third, int third_money) {
	
	gfx_clear_color(10, 10, 300);
	gfx_color(10,10,10);

	draw_boxes(x,y);
	draw_button(c, x, y);
	text_options(x, y);

	char buffer[BUFSIZ];

	std::sprintf(buffer, "1. %s     $%d",first, first_money);
	gfx_text(3*x/4, 3*y/4, buffer);

	std::sprintf(buffer, "2. %s     $%d",second, second_money);
	gfx_text(3*x/4, 3*y/4, buffer);

	std::sprintf(buffer,"3. %s     $%d",third, third_money);
	gfx_text(3*x/4, 3*y/4, buffer);

	gfx_flush();
	while(1){
		gfx_wait();
		int new_x =  gfx_xpos();
		int new_y =  gfx_ypos();
		bottom = (y/8)-(y/18);
		top = (y/8)+(y/18);

		change = y/8;
		
		lbound = y/4+(y/10);
		rbound = y/4-(y/10);

		if(rboud <= new_x <= lbound){
			for( int it = 1; it<8; it++){
				if( bottom <= new_y <= top)
					return it;
				bottom = bottom + it*change;
				top = top + it*change;
			}
		}
	}
}


	
