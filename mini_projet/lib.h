#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

string fullMin(string str);
string fullMaj(string str);
string firstMaj(string str);
void createGetters(ofstream *fichier, vector<string> attributes, string className);
void createSetters(ofstream *fichier, vector<string> attributes, string className);
void generationH(string nom_fichier,vector<string> &attributes);
void generationCPP(string nom_fichier, vector<string> &attributes);
void generationMain(string nom_fichier,vector<string> &attributes);
void generationMakefile(string nom_fichier, vector<string> &attributes);

#endif