#include "lib.h"

string fullMaj(string str) {
    string chaineFullMaj;
    for(int i = 0; str[i] != '\0'; i++)
        chaineFullMaj += toupper(str[i]);
    return chaineFullMaj;
}

string firstMaj(string str) {
    string chaineFirstmaj = str;
    chaineFirstmaj[0] = toupper(chaineFirstmaj[0]);
    return chaineFirstmaj;
}

string fullMin(string str) {
    string chaineFullMin;
    for(int i = 0; str[i] != '\0'; i++)
        chaineFullMin += tolower(str[i]);
    return chaineFullMin;
}

void createGetters(ofstream *fichier, vector<string> attributes, string className,vector<string> monType) {
    int index=0;
    
    if(attributes.empty()) {
        *fichier << '\n';
    } else {
        for(string attribute: attributes) {
            *fichier << monType[index] << " " << className << "::get" 
            << firstMaj(attribute) << "() const {"
            << '\n' << '\t'
            << "return " << attribute << ';' << '\n'
            << '}' <<endl; 
            index++;
        }
    }
}

void createSetters(ofstream *fichier, vector<string> attributes, string className,vector<string> monType) {
    
    int index=0;
    if(attributes.empty()) {
        *fichier << '\n';
    } else {
        for(string attribute: attributes) {
            *fichier << "void " << className << "::set" 
            << firstMaj(attribute) << "(" << monType[index] << " "
            << attribute
            << ") {"
            << '\n' << '\t'
            << "this->" << attribute << " = " << attribute << ';' 
            << '\n'
            << '}' << endl; 
            index++;
        }
    }
}

void createGettersPrototype(ofstream *fichier, vector<string> attributes, string className,vector<string> monType) {
    int index=0;
    if(attributes.empty()) {
        *fichier << '\n';
    } else {
        for(string attribute: attributes) {
            *fichier << "\t" << monType[index] << " " <<  "get" 
            << firstMaj(attribute) << "() const;" << endl;
            index++;
        }
        *fichier << endl;
    }    
}

void createSettersPrototype(ofstream *fichier, vector<string> attributes, string className,vector<string> monType) {
    int index =0;
    if(attributes.empty()) {
        *fichier << '\n';
    } else {
        for(string attribute: attributes) {
            *fichier << "\tvoid " << "set" 
            << firstMaj(attribute) << "(" << monType[index] << " " 
            << attribute
            << "); "<< endl; 
            index++;
        }
    }
}

bool notExist(string attribute, vector<string> attributes) {
    for(string exist: attributes)
        if(attribute == exist)
            return false;
    return true;
}

bool contientAccent(const string& var) {
    const string accents = "àáâãäåçèéêëìíîïðòóôõöùúûüýÿÀÁÂÃÄÅÇÈÉÊËÌÍÎÏÐÒÓÔÕÖÙÚÛÜÝ";
    for (int i=0; i < 107 ;i++) 
        for(unsigned int j=0;j<var.size();j++)
            if (var[j] == accents[i]) 
                return true;
    return false;
}


