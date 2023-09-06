#include "lib.h"

int main(){

    regex variableName("^[_a-z][_a-zA-Z0-9]*$");
    regex notType("^(?!.*\\b(vector|string|int|bool|float|double|char|null|const|static|volatile|inline|void|short|long|signed|unsigned|struct|union|class|enum|virtual|override|final|public|protected|private)\\b).*$");
    regex accent(".*[àáâãäåçèéêëìíîïðòóôõöùúûüýÿÀÁÂÃÄÅÇÈÉÊËÌÍÎÏÐÒÓÔÕÖÙÚÛÜÝ].*");
   
    system("chcp 65001");
    string nom_fichier;
    vector<string> attributes;
    vector<string> monType;
    while(1){
    cout << "Entrez un nom de fichier : (syntaxe : pas d'accent-pas de caractere spéciaux ou type existant)"<< endl;
    getline(cin, nom_fichier);
    if(regex_match(nom_fichier, variableName) && regex_match(nom_fichier, notType) && !regex_match(nom_fichier, accent)){
        break;
    }
    }

    generationCPP(nom_fichier,attributes,monType);
    generationH(nom_fichier,attributes,monType);
    generationMain(nom_fichier,attributes);
    generationMakefile(nom_fichier,attributes);
  
    return 0;
}

