# Contributors: Carter Hrabrick, Rebecca Hunt, Ana Gonzalez, Maria Markert
# E-mails: chrabri2@nd.edu, rhunt3@nd.edu, agonza35@nd.edu, mmarkert@nd.edu
#
# Makefile for the NASA Preternship Group's final project
# This makes a program that uses a GUI to analyze crowdsource solutions
# On their effectiveness in solving problems set by NASA's vendors

# C++ compiler is GCC
PP := g++

# CXXFLAGS are production quality flags
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Directories
INC  := inc
SRC  := src
EXE  := exe
OBJ  := obj
TEST := test
BIN  := bin

# file groups
PQS :=  $(INC)/Node.h $(INC)/DLList.h $(INC)/MaxPriorityQueue.h $(INC)/MinPriorityQueue.h
CLASSES := $(INC)/Player.h $(INC)/Member.h $(INC)/Owner.h $(INC)/CSVReader.h
GRAPHICS := $(INC)/graphics.h $(SRC)/graphics.cpp

# testclass script
testclass: $(TEST)/testclass.cpp $(CLASSES)
	$(PP) $(CXXFLAGS) -o $(EXE)/testclass.exe $(TEST)/testclass.cpp

# testPQs script Command: make testPQs
testPQs: $(TEST)/testPQs.cpp $(PQS)
	$(PP) $(CXXFLAGS) -o $(EXE)/testPQs.exe $(TEST)/testPQs.cpp

# Objects
graphics.o: $(GRAPHICS)
	$(PP) $(CXXFLAGS) -c -o $(OBJ)/graphics.o $(SRC)/graphics.cpp

simulator: simulator.o graphics.o
	$(PP) $(CXXFLAGS) -o $(EXE)/CoECISimulator $(OBJ)/CoECISimulator.o $(OBJ)/graphics.o $(BIN)/gfx3.o

# CoECIFinalSimulator
simulator.o: $(SRC)/CoECISimulator.cpp $(PQS) $(CLASSES)
	$(PP) $(CXXFLAGS) -c -o $(OBJ)/CoECISimulator.o $(SRC)/CoECISimulator.cpp

# Standard Make recipes
all: testclass testPQs simulator

initialize: 
	mkdir $(OBJ) $(EXE)

clean:
	rm -rf $(OBJ)/* $(EXE)/* vendorout.csv solutionsout.csv
