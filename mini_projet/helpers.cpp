#include "lib.h"

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
    if(attributes.empty()){
        *fichier << '\n';
    }else{
        for(string attribute: attributes){
            *fichier << "int " << className << "::get" 
            << firstMaj(attribute) << "() const {"
            << '\n' << '\t'
            << "return " << attribute << ';' << '\n'
            << '}' <<endl; 
        }
    }
}

void createSetters(ofstream *fichier, vector<string> attributes, string className){
    if(attributes.empty()){
        *fichier << '\n';
    }else{
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
}