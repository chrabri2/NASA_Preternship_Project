Carter Hrabrick
chrabri2

Hi grader! Welcome to my Gravity Simulator
It's a little late, but I got an extension (although I overstayed the extension a bit...)
Talk to Ramzi about it

Also this program is incomplete, but very usable I'll talk about the features not yet implemented later

Here's how it works from the user perspective.
Upon running the program, The screen is blank.

The user can click anywhere on the screen to start the planet making editor
The second click will determine the planet's radius.
The third click will determine planet's velocity.
There are guides to help out. The velocity vector shows how far the planet will move in one second

While in the planet making editor, there are loads of commands that can alter properties about the planets
x: cancels previous action
z: allows you to make a planet that has no velocity after the second click
v: makes the planet a snowflake (satellite). Satellites have no mass
c: makes the planet a circle, which is normal
roygbp: changes the color of the planet
m: makes the planet immovile. This is indicated by a filled circle, or a circle around a snowflake
i: makes the planet ignore collisions. This is indicated with white
.: adds a ring to the planet. Rings multiply the mass by 10. There is a max of 5 rings.
,: subtracts a ring from the planet

Out of the editor, planets will gravitationally attract each other and move around and collide.
WARNGING! High velocities and masses cause bugginess

If you look through the code, you'll notice something called a Camera. The camera is supposed to be a way that
the user can zoom in/out, pan the screen, and track planets. This would allow planets and systems at multiple
scales at once, like how the solar system has the sun, planets, and moons. Unfortunately it was really difficult
to work out the bugs and I unimplemented the system by commenting out key sections in projects.c, planet.c, and
graphics.c. If you want, there is another directory called camerafails which has these sections uncommented and
the bugginess in full force.

You'll also notice that file_io.c is empty. It was actually quite full earlier with hours of work involved with 
a config and color file import/outport system. Unfortunately, I ran into an issue where C can't distinguish 
between strings and struct variables, and no other easy way to systematically work it without using tons of 
ugly hacks. It all got deleted.

I was later going to combine the config/color import/outport with a mechanism that allows one to save and load
program data, but I didn't have time for that.

Other features that I didn't have time for:

An ability to be able to track planets. This would have the camera keep the planet centered as it moves. It also
involves adding relative speed to new planets for easy moon creation. Unfortunately this is dependent on the 
camera working.

An ability to pause the program without editing planets
An ability to quit the program from the planet making editor
An ability to delete the most recently made planet
An ability to name planets from the console

I hope you enjoy it, it is fun to mess around with!

-Carter H
