#include "lib.h" 

void generationCPP(string nom_fichier, vector<string> &attributes, vector<string> &monType) {

    string choix;
    string attribute;
    regex variableName("^[_a-z][_a-zA-Z0-9]*$");
    regex notType("^(?!.*\\b(vector|string|int|bool|float|double|char|null|const|static|volatile|inline|void|short|long|signed|unsigned|struct|union|class|enum|virtual|override|final|public|protected|private)\\b).*$");
    regex type("^(string|int|bool|float|double|char|void|short|int|long|unsigned|signed|wchar_t|char16_t|char32_t|char8_t)$");
    regex accent(".*[àáâãäåçèéêëìíîïðòóôõöùúûüýÿÀÁÂÃÄÅÇÈÉÊËÌÍÎÏÐÒÓÔÕÖÙÚÛÜÝ].*");

    int compteur_err = 1;
    int compteur = 0;
    int index = 0;
    
    ofstream fichier1("./dossierProjet/"+nom_fichier+".cpp"); 

    if(fichier1.is_open()) {
        fichier1 << "#include " << "\"" << nom_fichier << ".h\"" << endl
        << endl
        << firstMaj(nom_fichier) << "::" << firstMaj(nom_fichier) << "() {" << endl;

        while(true) {
            cout << "Voulez vous un type global pour tous les attributs? (Y/N)" << endl;

            if(cin >> choix && (choix == "y" || choix == "Y")) {
                cout << "Entrez les attributs au format commencant par une lettre minuscule ou _ (finissez par \"end\"):\n";
            
                while (cin >> attribute && (attribute != "end")) {

                    if(regex_match(attribute, variableName) && regex_match(attribute, notType) && notExist(attribute,attributes) && !(contientAccent(attribute)) ) {
                        monType.push_back("int");                   
                        attributes.push_back(attribute);
                        cin.clear();
                        cin.ignore();
                    } else if (contientAccent(attribute)) {
                        cout << "La variable numero : " << compteur_err << " contient un accent ! (cette variable est donc effacé)" << endl;
                        cin.clear();
                        cin.ignore();
                    } else if(notExist(attribute,attributes)) {
                        cout << "La variable : " << attribute << " a une mauvaise syntaxe - Variable non créée" << endl;
                        cin.clear();
                        cin.ignore();
                    } else {
                        cout << "La variable : " << attribute << " est déjà existante- Variable non créée" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    compteur_err++;
                }
                break;
            }
            if((choix == "N" || choix == "n")) {     
                cout << "Entrez les types (en minuscule) puis attributs (ex: int nombre1 char lettre1 end(finissez par \"end\"): \n";
                
                while (cin >> attribute && (attribute != "end")) {
                
                    // Cas ou l'on saisie un type
                    if(compteur % 2 == 0 ){
                        if(regex_match(attribute, type)) {
                            monType.push_back(attribute);                      
                            cin.clear();
                            cin.ignore();
                        } else {
                            cout << "Le type de : " << attribute << " n'est pas un type de variable existant" << endl;
                        }
                        compteur++;
                        continue;
                    }

                    // Cas ou l'on saisie une variable
                    if(compteur % 2 == 1 ) {
                        if(regex_match(attribute, variableName) && regex_match(attribute, notType) && notExist(attribute,attributes)) {
                            attributes.push_back(attribute);
                            cin.clear();
                            cin.ignore();
                        } else if(contientAccent(attribute)) {
                        cout << "La variable numero : " << compteur_err << " contient un accent ! (cette variable est donc effacé)" << endl;
                        cin.clear();
                        cin.ignore();
                    } else if(notExist(attribute,attributes)) {
                        cout << "La variable : " << attribute << " a une mauvaise syntaxe - Variable non créée" << endl;
                        cin.clear();
                        cin.ignore();
                    } else {
                        cout << "La variable : " << attribute << " est déjà existante- Variable non créée" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                    compteur_err++;
                    compteur++;
                    }
                }
                break;
            }
        }
    }

    for(string elem : attributes) {
        fichier1 << "\t" << elem << " = " << 0 << ";" << endl;
    }
    fichier1 << "}" << endl;
    fichier1 << firstMaj(nom_fichier) << "::" << firstMaj(nom_fichier) << "(";
    
    for(string elem: attributes) { 
        
        if(attributes.back()!= elem) {
            fichier1 << monType[index]  << " " << elem << ", " ;
        } else {
            fichier1 << monType[index] << " " <<  elem << ") {" << endl;
        }
        index++;
    }

    for(string elem : attributes) {
        fichier1 << "\t this->" << elem << " = "<< elem << ";" << endl;
    }

    fichier1 << "}" << endl;
    createGetters(&fichier1, attributes, firstMaj(nom_fichier), monType);
    createSetters(&fichier1, attributes, firstMaj(nom_fichier), monType);
    
    fichier1.close();
}
