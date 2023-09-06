CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: stan

stan: stan.cpp main.cpp
	$(CXX) $(CXXFLAGS) -o stan stan.cpp main.cpp

run:
	./stan

clean:
	rm -f stan
	rm -f stan.h
	rm -f stan.cpp
	rm -f main.cpp
	rm -f Makefile