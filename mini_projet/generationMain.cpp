#include "lib.h"

void generationMain(string nom_fichier, vector<string> &attributes) { 
    
    ofstream fichier3("./dossierProjet/main.cpp");

    if(fichier3.is_open()) {
        fichier3 << "#include " << "\"" << nom_fichier 
        << ".h\"" << '\n'
        << "#include <iostream>" << '\n' 
        << '\n'
        << "int main() {" << '\n'
        << '\t' << firstMaj(nom_fichier) << " obj;\n";

        for(string elem : attributes) {
            fichier3 << "\tobj.set" << firstMaj(elem) << "(42);\n";
        }

        for(string elem : attributes) {
            fichier3 << "\tcout << " << "\"" << firstMaj(elem)
            << " = \" << obj.get" << firstMaj(elem) << "() << endl;" << '\n';
        }
        
        fichier3 << '\n' <<"return 0;\n}";            
        fichier3.close();
    }
}
