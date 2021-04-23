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

# file groups
CLASSES := $(INC)/Player.h $(INC)/Member.h $(INC)/Owner.h

# testclass script
testclass: $(TEST)/testclass.cpp $(CLASSES)
	$(PP) $(CXXFLAGS) -o $(EXE)/testclass.exe $(TEST)/testclass.cpp

# Standard Make recipes
all: testclass

initialize: 
	mkdir $(OBJ) $(EXE)

clean:
	rm -rf $(OBJ)/* $(EXE)/*
