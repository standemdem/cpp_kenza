#include "lib.h"

void generationCPP(string nom_fichier, vector<string> &attributes){
    regex onlyAlphabet("^[a-zA-Z]+$");
    regex notType("^(?!.*\\b(string|int|bool|float|double|char|null|const|static|volatile|inline|void|short|long|signed|unsigned|struct|union|class|enum|virtual|override|final|public|protected|private)\\b).*$");
    string choix;
    ofstream fichier1(nom_fichier+".cpp"); 


    
    if(fichier1.is_open()){
        fichier1<< "#include " << "\"" << nom_fichier 
        << ".h\"" << endl;
        fichier1 << endl;
        fichier1 << firstMaj(nom_fichier) << "::" << firstMaj(nom_fichier) <<"() {" << endl;
        string attribute;
        cout << "Voulez vous un type global à tous les attributs ?(Y/N)";

        if(cin >> choix && (choix =="y" || choix =="Y"))
        {
            cout << "Entrez les attributs (finissez par \"end\"): ";
            while (cin >> attribute && (attribute !="end")){
                if(regex_match(attribute, onlyAlphabet) && regex_match(attribute, notType)){
                    attribute = fullMin(attribute);
                    attributes.push_back(attribute);
                    cin.clear();
                    cin.ignore();
                    }
            }
        }
        else
        {
            cout << "Entrez les types puis attributs (ex : int nombre1 char lettre1 end(finissez par \"end\"): ";
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