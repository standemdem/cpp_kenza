#include <iostream>
#include <cassert>
#include <math.h>
#include <typeinfo>

using namespace std;
const double REF_NUM=12.00;

double racineCarree(double n){
    if((n > INT16_MAX) || typeid(n).name() != typeid(REF_NUM).name()){ // checker le type ainsi ne sert à rien
        
        throw runtime_error("Nombre trop grand");
    }
    assert(n > 0 && "Nombre négatif et strings interdits");
    return pow(n, 0.5);
}

template<typename T>
T racineCarree2(T n){
    assert(n>0 && "nombre négatifs interdits");
    if(n > INT16_MAX) throw runtime_error("Nombre trop grand");
    return pow(n, 0.5);
}

int main(){
    double input;
    while(input !=666){

        cout << "Entrez un nombre réel positif:";
        cin >> input;
        try
        {
            cout << "Racine carré de " << input << " = " <<racineCarree(input) << endl;
        }
        catch(const runtime_error& e)
        {
            cerr << e.what() << '\n';
        }
    }

    return 0;
}