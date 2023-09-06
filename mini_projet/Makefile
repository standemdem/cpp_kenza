CXX = g++
CXXFLAGS = -std=c++11 -Wall
all: project

project: 
	mkdir -p dossierProjet
	project.cpp helpers.cpp generationCPP.cpp generationH.cpp generationMain.cpp generationMakefile.cpp
	$(CXX) $(CXXFLAGS) -o ./dossierProjet/monExe project.cpp helpers.cpp generationCPP.cpp generationH.cpp generationMain.cpp generationMakefile.cpp
	./monExe

run:
	dossierProjet/monExe.exe

