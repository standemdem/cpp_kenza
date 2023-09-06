CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: dossierProjet/monExe

dossierProjet/monExe: 
	@mkdir -p dossierProjet
	$(CXX) $(CXXFLAGS) -o $@ 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:
	./dossierProjet/monExe
