#include "lib.h"

void generationCPP(string nom_fichier, vector<string> &attributes, vector<string> &monType){
    regex variableName("^[_a-z][_a-zA-Z0-9]*$");
    regex notType("^(?!.*\\b(vector|string|int|bool|float|double|char|null|const|static|volatile|inline|void|short|long|signed|unsigned|struct|union|class|enum|virtual|override|final|public|protected|private)\\b).*$");
    regex type("^(string|int|bool|float|double|char|void|short|int|long|unsigned|signed|wchar_t|char16_t|char32_t|char8_t)$");
    string choix;
    
    int cpt =0,index=0;
    ofstream fichier1(nom_fichier+".cpp"); 

    if(fichier1.is_open()){
        fichier1<< "#include " << "\"" << nom_fichier 
        << ".h\"" << endl;
        fichier1 << endl;
        fichier1 << firstMaj(nom_fichier) << "::" << firstMaj(nom_fichier) <<"() {" << endl;
        string attribute;


        
        while(1){
            cout << "Voulez vous un type global à tous les attributs ?(Y/N)" << endl;
            if(cin >> choix && (choix =="y" || choix =="Y")) {
                cout << "Entrez les attributs au format commencant par une lettre minuscule ou _ (finissez par \"end\"):\n";
                while (cin >> attribute && (attribute !="end")){
                    if(regex_match(attribute, variableName) && regex_match(attribute, notType)){
                        monType.push_back("int");
                        attributes.push_back(attribute);
                        cin.clear();
                        cin.ignore();
                        }
                        else
                            cout << "La variable : " << attribute << " a une mauvaise syntaxe - Variable non créer" << endl;
                        
                }
                break;
            }
            if((choix =="N" || choix =="n")) {     
                cout << "Entrez les types (en minuscule) puis attributs (ex : int nombre1 char lettre1 end(finissez par \"end\"): \n";
                // Cas ou l'on saisie un type
                while (cin >> attribute && (attribute !="end")){
                    if(regex_match(attribute, type) && cpt %2 ==0){
                        monType.push_back(attribute);                      
                        cin.clear();
                        cin.ignore();
                        cpt++;
                        }
                // Cas ou l'on saisie une variable
                    if(regex_match(attribute, variableName) && regex_match(attribute, notType) && cpt %2 ==1) {
                        attributes.push_back(attribute);
                        cin.clear();
                        cin.ignore();
                        cpt++;
                        }
                }
                break;
            }
            
        }
    }
        for(string elem : attributes ){
            fichier1 << "\t"<< elem << " = "<< 0 << ";" << endl;
        }
        fichier1 << "}" << endl;
        fichier1 << firstMaj(nom_fichier) << "::" << firstMaj(nom_fichier) << "(";
        
        for(string elem: attributes){ 
            if(attributes.back()!=elem){
                fichier1 << monType[index]  << " " << elem << ", " ;
            }else{
                fichier1 << monType[index] << " " <<  elem << ") {" << endl;
            }
            index++;
        }

        for(string elem : attributes ){
            fichier1 << "\t this->"<< elem << " = "<< elem << ";" << endl;
        }

        fichier1 << "}" << endl;
        createGetters(&fichier1, attributes, firstMaj(nom_fichier),monType);
        createSetters(&fichier1, attributes, firstMaj(nom_fichier),monType);
        
        fichier1.close();
}
