//Carter Hrabrick
//chrabri2

void printOptions();

int main() {
	
	
	return 0;
}

void printOptions() {
	printf("Welcome to the Gravity Simulator\n");
	printf("How this works: \n");
	printf("Click anywhere on the screen to start drawing a shape\n");
	printf("The second click will set the size of the shape, which correlates to mass\n");
	printf("If applicable, a third click will determine the speed of the shape, as indicated by an arrow\n");
	printf("After all clicks are done, press 'c' to confirm the changes, draw the object,\n");
	printf("and the animation will continue\n");
	printf("At any time when making an object, press 'x' to cancel drawing an object\n");
	printf("Press 'z' to remove the most recently made object\n");
	printf("The console can't be interacted with beyond the start, but provides feedback information\n");
	printf("After the second click, here are some things you can modify:\n");
	printf("Colors:\n");
	printf("'r': red\n");
	printf("'o': orange\n");
	printf("'y': yellow\n");
	printf("'g': green\n");
	printf("'b': blue\n");
	printf("'p': purple\n");
	printf("Shapes:\n");
	printf("'a': circle - normal behavior\n");
	printf("'s': snowflake - has no mass, and therefore no gravity\n");
	printf("'d': square - only affected by the gravity of its nearest neighbor\n");
	printf("Modifiers:\n");
	printf("'x': makes an object immobile\n");
}
