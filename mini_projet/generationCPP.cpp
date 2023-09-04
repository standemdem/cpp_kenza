#include "lib.h"

void generationCPP(string nom_fichier, vector<string> &attributes){
    
    ofstream fichier1(nom_fichier+".cpp"); 

    if(fichier1.is_open()){
        fichier1<< "#include " << "\"" << nom_fichier 
        << ".h\"" << endl;
        fichier1 << endl;
        fichier1 << firstMaj(nom_fichier) << "::" << firstMaj(nom_fichier) <<"() {" << endl;
        string attribute;
        cout << "Entrez les attributs (finissez par \"end\"): ";
        while (cin >> attribute && (attribute !="end")){
            attributes.push_back(attribute);
            cin.clear();
            cin.ignore();
        }
        
        for(string elem : attributes ){
            fichier1 << "\t"<< elem << " = "<< 0 << ";" << endl;
        }
        fichier1 << "}" << endl;
        fichier1 << firstMaj(nom_fichier) << "::" << firstMaj(nom_fichier) << "(";
        
        for(string elem: attributes){ 
            if(attributes.back()!=elem){
                fichier1 << "int " << elem << ", " ;
            }else{
                fichier1 << "int " << elem << ") {" << endl;
            }
        }

        for(string elem : attributes ){
            fichier1 << "\t this->"<< elem << " = "<< elem << ";" << endl;
        }

        fichier1 << "}" << endl;
        createGetters(&fichier1, attributes, firstMaj(nom_fichier));
        createSetters(&fichier1, attributes, firstMaj(nom_fichier));
        
        fichier1.close();
    }
}