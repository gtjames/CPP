# Makefile for grading program

CXX = g++
CXXFLAGS = -Wall -std=c++11

all: grading

grading: grading.cpp
	$(CXX) $(CXXFLAGS) grading.cpp -o grading

run: grading
	./grading

clean:
	rm -f grading