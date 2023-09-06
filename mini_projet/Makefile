CXX = g++
CXXFLAGS = -std=c++11 -Wall
OBJS = project.o helpers.o generationCPP.o generationH.o generationMain.o generationMakefile.o

all: dossierProjet/monExe

dossierProjet/monExe: $(OBJS)
	@mkdir -p dossierProjet
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:
	./dossierProjet/monExe
