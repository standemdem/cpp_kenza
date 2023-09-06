#include "lib.h"

void generationMakefile(string nom_fichier, vector<string> &attributes){
        ofstream fichier4("./dossierProjet/Makefile");
        if(fichier4.is_open()){
            fichier4 << "CXX = g++\n"
            << "CXXFLAGS = -std=c++11 -Wall\n\n"
            << "all: " << nom_fichier << "\n\n"
            << nom_fichier << ": " << nom_fichier <<".cpp main.cpp\n\t"
            <<"$(CXX) $(CXXFLAGS) -o " << nom_fichier << ' ' 
            << nom_fichier <<".cpp main.cpp\n\n"
            << "run:\n\t"
            << "./" << nom_fichier <<"\n\n"
            << "clean:\n\t"
            << "rm -f " << nom_fichier << "\n\t"
            << "rm -f " << nom_fichier << ".h" << "\n\t"
            << "rm -f " << nom_fichier << ".cpp" << "\n\t"
            << "rm -f ./dossierProjet/main.cpp\n\t"
            << "rm -f ./dossierProjet/Makefile";

        }else{
            cout << "Impossible d'ouvrir le fichier";
        }
}