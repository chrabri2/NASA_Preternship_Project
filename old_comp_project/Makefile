# Makefile for final project
# 	"make" creates all executables, like the main one

EXEC = gravity_sim
MAIN = project
CMP = gcc
FUNC1 = file_io
FUNC2 = graphics
FUNC3 = planet
FUNC4 = camera
GFX = gfx3

$(EXEC): $(MAIN).o $(FUNC1).o $(FUNC2).o $(FUNC3).o $(FUNC4).o
	$(CMP) $(MAIN).o $(FUNC1).o $(FUNC2).o $(FUNC3).o $(FUNC4).o $(GFX).o -lX11 -lm -o $(EXEC)

$(MAIN).o: $(MAIN).c
	$(CMP) -c -std=c99 $(MAIN).c -o $(MAIN).o

$(FUNC1).o: $(FUNC1).c
	$(CMP) -c -std=c99 $(FUNC1).c -o $(FUNC1).o

$(FUNC2).o: $(FUNC2).c 
	$(CMP) -c -std=c99 $(FUNC2).c -o $(FUNC2).o

$(FUNC3).o: $(FUNC3).c
	$(CMP) -c -std=c99 $(FUNC3).c -o $(FUNC3).o

$(FUNC4).o: $(FUNC4).c
	$(CMP) -c -std=c99 $(FUNC4).c -o $(FUNC4).o

clean:
	rm $(MAIN).o
	rm $(FUNC1).o
	rm $(FUNC2).o
	rm $(FUNC3).o
	rm $(FUNC4).o
	rm $(EXEC)
