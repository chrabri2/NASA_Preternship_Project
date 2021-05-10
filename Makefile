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
PQs :=  $(INC)/Node.h $(INC)/DLList.h $(INC)/MaxPriorityQueue.h $(INC)/MinPriorityQueue.h
CLASSES := $(INC)/Player.h $(INC)/Member.h $(INC)/Owner.h $(INC)/csvio.h

# testclass script
testclass: $(TEST)/testclass.cpp $(CLASSES)
	$(PP) $(CXXFLAGS) -o $(EXE)/testclass.exe $(TEST)/testclass.cpp

# testPQs script Command: make testPQs
testPQs: $(SRC)/testPQs.cpp $(PQs)
	$(PP) $(CXXFLAGS) -o $(EXE)/testPQs.exe $(SRC)/testPQs.cpp

# Objects
$(SRC)/graphics.o: $(SRC)/graphics.cpp $(INC)/graphics.h
	$(PP) $(CXXFlags) -c -o $(OBJ)/graphics.o $(SRC)/graphics.cpp

# CoECIFinalSimulator
simulator: $(SRC)/CoECISimulator.cpp $(PQs) $(CLASSES)
	$(PP) $(CXXFLAGS) -o $(EXE)/CoECISimulator.exe $(SRC)/CoECISimulator.cpp

# Standard Make recipes
all: testclass testPQs main

initialize: 
	mkdir $(OBJ) $(EXE)

clean:
	rm -rf $(OBJ)/* $(EXE)/*
