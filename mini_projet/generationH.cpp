#include "lib.h"

void generationH(string nom_fichier,vector<string> &attributes,vector<string> &monType) {
    ofstream fichier2("./dossierProjet/" + nom_fichier + ".h");
    int index = 0;
    if(fichier2.is_open()) {
        fichier2 << "#ifndef " << fullMaj(nom_fichier) << "_H\n#define " 
        << fullMaj(nom_fichier) << "_H" << endl ;
        fichier2 << "#include <iostream>" << endl 
        << "using namespace std;\n\n" << endl 
        << "class " << firstMaj(nom_fichier) << " {\npublic:\n\t" 
        << firstMaj(nom_fichier) <<"();\n\t"; 
        
        
        if(!attributes.empty()) {
            fichier2 << firstMaj(nom_fichier) << "(" ;
    
            for(string elem : attributes) {
                if(attributes.back() != elem) {
                    fichier2 << monType[index] << " " << elem << ", ";
                } else {
                    fichier2 << monType[index] << " " << elem;
                }
                index++;
            }

            fichier2 << ");\n\n";
        }

        createGettersPrototype(&fichier2, attributes, firstMaj(nom_fichier), monType);
        createSettersPrototype(&fichier2, attributes, firstMaj(nom_fichier), monType);

        fichier2 << "\n\nprivate:";
        index = 0;
        for(string elem : attributes) {
            fichier2 << "\n\t" << monType[index] << " " << elem << ';'; 
            index++;
        }

        fichier2 << "\n};\n\n#endif";
    } else {
        cout << "Impossible d'ouvrir le fichier\n";
    }

    fichier2.close();
}