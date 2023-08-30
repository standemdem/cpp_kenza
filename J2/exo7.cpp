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
private:
    float largeur;
    float longueur;

public:
    Rectangle(float largeur, float longueur){
        this->largeur = largeur;
        this->longueur = longueur;
    }


    float aire(){
        return largeur * longueur;
    }

}; 

class Cercle : public Forme {
private:
    float rayon;
    float pi = M_PI;

public:
    Cercle(float rayon){
        this->rayon = rayon;
    }

    float aire(){
        return pi * rayon * rayon;
    }
};


int main()
{
    Rectangle rectangle1(12, 3);
    cout << "aire rectangle: " << rectangle1.aire() <<endl;
    Cercle cercle1(10);
    cout << "aire rectangle: " << cercle1.aire() <<endl;

    return 0;
}