CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: tutu

tutu: tutu.cpp main.cpp
	$(CXX) $(CXXFLAGS) -o tutu tutu.cpp main.cpp

run:
	./tutu

clean:
	rm -f tutu
	rm -f tutu.h
	rm -f tutu.cpp
	rm -f main.cpp
	rm -f Makefile