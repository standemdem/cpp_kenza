#include "lib.h"


void generationH(string nom_fichier,vector<string> &attributes)
{
    ofstream fichier2(nom_fichier+".h"); 
    if(fichier2.is_open()){
        fichier2 << "#ifndef " << fullMaj(nom_fichier) << "_H\n#define " << fullMaj(nom_fichier) << "_H\n\n"
        << "class "<< firstMaj(nom_fichier) << " {\npublic:\n\t" 
        << firstMaj(nom_fichier) <<"();\n\t" << firstMaj(nom_fichier)
        << "(" ;

        
        for(string elem : attributes){
            if(attributes.back()!=elem){
                fichier2 << "int " << elem << ", ";
            }else{
                fichier2 << "int " << elem;
            }
        }
        fichier2 << ");\n\n\t";


        for(string elem : attributes){
            fichier2 << "int get"<< firstMaj(elem) << "() const;\n\tvoid set" 
            << firstMaj(elem)<< "(int " << elem<<");\n\t" ;
        }
        fichier2 << "\n\nprivate:";
        for(string elem : attributes){
            fichier2 << "\n\tint "<< elem << ";"; 
        }
        fichier2 << "\n};\n\n#endif";
    }
    else
        cout << "Impossible d'ouvrir le fichier\n";

    fichier2.close();
}
