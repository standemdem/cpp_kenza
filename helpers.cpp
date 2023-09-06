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

string fullMin(string str){
    string chaineFullMin;
    for(int i=0 ; str[i] !='\0';i++)
        chaineFullMin += tolower(str[i]);
    return chaineFullMin;
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

void createGettersPrototype(ofstream *fichier, vector<string> attributes, string className){
    if(attributes.empty()){
        *fichier << '\n';
    }else{
        for(string attribute: attributes){
            *fichier << "\tint " << className << "::get" 
            << firstMaj(attribute) << "() const;" << endl;
        }
        *fichier << endl;
    }
}

void createSettersPrototype(ofstream *fichier, vector<string> attributes, string className){
    if(attributes.empty()){
        *fichier << '\n';
    }else{
        for(string attribute: attributes){
            *fichier << "\tvoid " << className << "::set" 
            << firstMaj(attribute) << "(int " 
            << attribute
            << "); "<<endl; 
        }
    }
}