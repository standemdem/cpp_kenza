#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Forme {
public:
    float aire(){
        cout << "Surcharge moi béta" << endl;
        return 0.0;
    }
};

class Rectangle : public Forme {

public:
    Rectangle(float _largeur, float _longueur){
        largeur = _largeur;
        longueur = _longueur;
    }

    float aire(){
        return largeur * longueur;
    }

private:
    float largeur;
    float longueur;

}; 

class Cercle : public Forme {

public:
    Cercle(float rayon){
        this->rayon = rayon;
    }

    float aire(){
        return pi * rayon * rayon;
    }

private:
    float rayon;
    float pi = M_PI;
};


int main()
{
    Rectangle rectangle1(12, 3);
    cout << "aire rectangle: " << rectangle1.aire() <<endl;
    Cercle cercle1(10);
    cout << "aire rectangle: " << cercle1.aire() <<endl;

    return 0;
}