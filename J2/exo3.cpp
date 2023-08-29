#include <iostream>
#include <string>
#include <limits>

using namespace std;

int sommeParValeur(int a, int b)
{
    return a + b;
}

void produitParReference(int &a, int &b)
{
    cout <<  "Le produit de " << a << " et " << b << " est: " << a*b << endl;
    a = a * b;
}

int get_input(){
    int input;
    while (true)
    {
        if (cin >> input)
        {
            return input;
        }
        else
        {
            cin.clear();
            cin.ignore();
            cout << "Entrée invalide, veuillez réessayer";
        }
    }
}


int main()
{
    int nb1, nb2;
    cout << "Entrez un premier nb entier: ";
    nb1 = get_input();
    cout << "Entrez un second nb entier: ";
    nb2 = get_input();
    
    cout <<  "La somme de " << nb1 << " et " << nb2 << " est: " << sommeParValeur(nb1,nb2) << endl;
    produitParReference(nb1, nb2);
    cout << "valeur de nb1: " << nb1 <<endl;
    
    return 0;
}