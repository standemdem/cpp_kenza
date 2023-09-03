#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string nametoupper(string name){
    string temp = name;
    temp[0]=toupper(temp[0]);
    return temp;

}
void createGetters(ofstream *fichier, vector<string> attributes, string className){
    for(string attribute: attributes){
        *fichier << "int " << className << "::get" 
        << nametoupper(attribute) << "() const {"
        << '\n' << '\t'
        << "return " << attribute << ';' << '\n'
        << '}' <<endl; 

    }
}
void createSetters(ofstream *fichier, vector<string> attributes, string className){
    for(string attribute: attributes){
        *fichier << "void " << className << "::set" 
        << nametoupper(attribute) << "(int " 
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
    nom_fichier_maj = nametoupper(nom_fichier);
    ofstream fichier1(nom_fichier+".cpp"); //1
    ofstream fichier2(nom_fichier+".h"); //2
    ofstream fichier3("main.cpp"); //3
    ofstream fichier4("Makefile"); //4

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
    if(fichier3.is_open()){
        while(true){
            fichier3<< "#include " << "\"" << nom_fichier 
            << ".h\"" << '\n'
            << "#include <iostream>" << '\n'
            << '\n'
            << "int main() {" << '\n'
            << '\t' << nametoupper(nom_fichier) << " obj;\n";
            for(string elem : attributes){
                fichier3 << "\tobj.set" << nametoupper(elem) <<"(42);\n";
            }
            for(string elem : attributes){
                fichier3 <<"\tstd::cout << " << "\"" << nametoupper(elem)
                << " = \" << obj.get" << nametoupper(elem) << "() << std::endl;" << '\n';
            }
            fichier3 << '\n' <<"return 0;\n}";            
            break;
        }
        fichier3.close();
    }   
    return 0;
}