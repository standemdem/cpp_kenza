CXX = g++
CXXFLAGS = -std=c++11 -Wall
all: project

project: 
	mkdir -p dossierProjet
	$(CXX) $(CXXFLAGS) -o ./dossierProjet/monExe project.cpp helpers.cpp generationCPP.cpp generationH.cpp generationMain.cpp generationMakefile.cpp
	

run:
	dossierProjet/monExe
