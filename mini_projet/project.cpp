#include "lib.h"

int main(){

    system("chcp 65001");
    string nom_fichier;
    vector<string> attributes;
    cout << "Entrez un nom de fichier"<< endl;
    getline(cin, nom_fichier);
    
    generationCPP(nom_fichier,attributes);
    generationH(nom_fichier,attributes);
    generationMain(nom_fichier,attributes);
    generationMakefile(nom_fichier,attributes);
  
    return 0;
}

