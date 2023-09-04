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

void generationMain(string nom_fichier,vector<string> &attributes){
    
    ofstream fichier3("main.cpp");
    if(fichier3.is_open()){
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
        fichier3.close();
    }
}

void generationMakefile(string nom_fichier, vector<string> &attributes){
        ofstream fichier4("Makefile");
        if(fichier4.is_open()){
            fichier4 << "CXX = g++\n"
            << "CXXFLAGS = -std=c++11 -Wall\n\n"
            << "all: " << nom_fichier << "\n\n"
            << nom_fichier << ": " << nom_fichier <<".cpp main.cpp\n\t"
            <<"$(CXX) $(CXXFLAGS) -o " << nom_fichier << ' ' 
            << nom_fichier <<".cpp main.cpp\n\n"
            << "run:\n\t"
            << "./" << nom_fichier <<"\n\n"
            << "clean:\n\t"
            << "rm -f " << nom_fichier << "\n\t"
            << "rm -f " << nom_fichier << ".h" << "\n\t"
            << "rm -f " << nom_fichier << ".cpp" << "\n\t"
            << "rm -f main.cpp\n\t"
            << "rm -f Makefile";

        }else{
            cout << "Impossible d'ouvrir le fichier";
        }
    
}
int main(){
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