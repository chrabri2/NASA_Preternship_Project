
New features for gfx3 (the .h file is the same, but the code handles more events):

   a change to the gfx_event_waiting() function's behavior
   do not treat that function a boolean anymore; instead:
   it now returns the following int values based on various events:

     0 :  no event
     1 :  for a key press
     2 :  for a key release
     3 :  for a mouse click
     4 :  for a mouse release
     5 :  for a mouse motion

Note: while gfx_event_waiting() detects one of the above events,
      the gfx_wait() function can still be used to help identify 
      which key was pressed or which mouse button was clicked.

Two programs are added to test the new event handling features and help you undestand them:
 - testgfx3.c :  displays info at the terminal for every user event
 - paint.c :  a simple fun paint program



