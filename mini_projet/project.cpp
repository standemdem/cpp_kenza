#include "lib.h"

int main(){

    system("chcp 65001");
    string nom_fichier;
    vector<string> attributes;
    vector<string> monType;
    cout << "Entrez un nom de fichier"<< endl;
    getline(cin, nom_fichier);
    nom_fichier= "./dossierProjet/"+nom_fichier;
    generationCPP(nom_fichier,attributes,monType);
    generationH(nom_fichier,attributes,monType);
    generationMain(nom_fichier,attributes);
    generationMakefile(nom_fichier,attributes);
  
    return 0;
}

