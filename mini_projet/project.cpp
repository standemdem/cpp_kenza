#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string fullMaj(string str){
    string chaineFullMaj;
    for(int i=0 ; str[i] !='\0';i++)
        chaineFullMaj += toupper(str[i]);
    return chaineFullMaj;
}

string firstMaj(string str){
    string temp = str;
    temp[0]=toupper(temp[0]);
    return temp;

}
void createGetters(ofstream *fichier, vector<string> attributes, string className){
    for(string attribute: attributes){
        *fichier << "int " << className << "::get" 
        << firstMaj(attribute) << "() const {"
        << '\n' << '\t'
        << "return " << attribute << ';' << '\n'
        << '}' <<endl; 

    }
}
void createSetters(ofstream *fichier, vector<string> attributes, string className){
    for(string attribute: attributes){
        *fichier << "void " << className << "::set" 
        << firstMaj(attribute) << "(int " 
        << attribute
        << ") {"
        << '\n' << '\t'
        << "this->" << attribute << " = " << attribute << ';' 
        << '\n'
        << '}' <<endl; 

    }
}

int main(){
    string nom_fichier;
    string nom_fichier_maj;
    vector<string> attributes;
    
    // Generation des fichiers
    cout << "Entrez un nom de fichier"<< endl;
    getline(cin, nom_fichier);
    nom_fichier_maj = firstMaj(nom_fichier);
    ofstream fichier1(nom_fichier+".cpp"); //1
    ofstream fichier2(nom_fichier+".h"); //2
    ofstream fichier3("main.cpp"); //3
    ofstream fichier4("Makefile"); //4
    
    // Generation fichier .cpp
    if(fichier1.is_open()){
        while(true){
            fichier1<< "#include " << "\"" << nom_fichier 
            << ".h\"" << endl;
            fichier1 << endl;
            fichier1 << nom_fichier_maj << "::" << nom_fichier_maj <<"() {" << endl;
            string attribute;
            cout << "Entrez les attributs (finissez par \"end\"): ";
            while (cin >> attribute && (attribute !="end")){
                attributes.push_back(attribute);
                cout<<attribute;
                cin.clear();
                cin.ignore();
            }
            
            for(string elem : attributes ){
                fichier1 << "\t"<< elem << " = "<< 0 << ";" << endl;
            }
            fichier1 << "}" << endl;
            fichier1 << nom_fichier_maj << "::" << nom_fichier_maj << "(";
            
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
            createGetters(&fichier1, attributes, nom_fichier_maj);
            createSetters(&fichier1, attributes, nom_fichier_maj);
            break;
        }
        fichier1.close();
    }
    // Generation fichier .h
    
    if(fichier3.is_open()){
        fichier3 << "#ifndef " << fullMaj(nom_fichier) << "_H\n#define " << fullMaj(nom_fichier) << "_H\n\n"
        << "class "<< firstMaj(nom_fichier) << " {\npublic:\n\t" 
        << firstMaj(nom_fichier) <<"();\n\t" << firstMaj(nom_fichier)
        << "(" ;

        
        for(string elem : attributes){
            if(attributes.back()!=elem){
                fichier3 << "int " << elem << ", ";
            }else{
                fichier3 << "int " << elem;
            }
        }
        fichier3 << ");\n\n\t";


        for(string elem : attributes){
            fichier3 << "int get"<< firstMaj(elem) << "() const;\n\tvoid set" 
            << firstMaj(elem)<< "(int " << elem<<");\n\t" ;
        }
        fichier3 << "\n\nprivate:";
        for(string elem : attributes){
            fichier3 << "\n\tint "<< elem << ";"; 
        }
        fichier3 << "\n};\n\n#endif";
    }
    else
        cout << "Impossible d'ouvrir le fichier\n";

    fichier3.close();
    
    // Generation fichier main.cpp
    if(fichier3.is_open()){
        while(true){
            fichier3<< "#include " << "\"" << nom_fichier 
            << ".h\"" << '\n'
            << "#include <iostream>" << '\n'
            << '\n'
            << "int main() {" << '\n'
            << '\t' << firstMaj(nom_fichier) << " obj;\n";
            for(string elem : attributes){
                fichier3 << "\tobj.set" << firstMaj(elem) <<"(42);\n";
            }
            for(string elem : attributes){
                fichier3 <<"\tstd::cout << " << "\"" << firstMaj(elem)
                << " = \" << obj.get" << firstMaj(elem) << "() << std::endl;" << '\n';
            }
            fichier3 << '\n' <<"return 0;\n}";            
            break;
        }
        fichier3.close();
    }   
    return 0;
}