#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template<typename T>
T divise(T numerateur, T denominateur){
    T result;
    if(denominateur == 0){
        throw runtime_error("division par zéro");
    }
    return numerateur/denominateur;
}

int main(){

    try
    {
        cout << "resultat = " << divise(22, 0) << endl;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    return 0;
}