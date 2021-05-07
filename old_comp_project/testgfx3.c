// testgfx3.c
// this program tests some of gfx3's new features,
// mainly new keyboard and mouse events

#include <stdio.h>
#include <stdbool.h>

#include "gfx3.h"

void showpos();

int main()
{
  char c;      // keyboard key or mouse code  
  int event;   // event code
  bool ispressed = false;   // flag for keyboard events
  bool isclicked = false;   // flag for mouse events

  gfx_open(600, 500, "My window"); 
  gfx_clear();

  while(true) { 
    event = gfx_event_waiting();    // get the event code
    if (event != 0) {               // if 'something' is happening
      c = gfx_wait();
      printf("event %d: ", event);  // display event code

      // keyboard events
      if (c >= 32 && c <= 126) {    // range of most keyboard keys
        if (event == 1) {           // key press event
          printf("you pressed key: %c\n", c);
          ispressed = true;
        } else if (event == 2) {    // key release event
          if (ispressed) printf("you released key: %c\n", c);
          ispressed = false;
        }
      }

      // mouse click events
      if (c == 1 || c == 2 || c == 3) {  // mouse click (left, middle, or right)
        if (event == 3) {                // mouse down event
          printf("you clicked mouse button %d at: ", c);
          isclicked = true;
        } else if (event == 4) {         // mouse release event
          if (isclicked) printf("you released mouse button %d at: ", c);
          isclicked = false;
        }
        showpos();
      }

      // mouse move event
      if (event == 5) {
        printf("mouse is moving; it's at: ");
        showpos();
      }

      // exit the loop
      if (c == 'q')  break;
    }
  }

  return 0;
}

void showpos()
{
   printf(" (%d,%d)\n", gfx_xpos(), gfx_ypos());
}

