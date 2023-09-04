#include <iostream>

using namespace std;

class Rectangle {
private:
    int largeur;
    int hauteur;
    int surface;
public:
    Rectangle(float largeur, float hauteur){
        this->largeur = largeur;
        this->hauteur = hauteur;
        this->surface = aire();
    }

    int aire(){
        return largeur * hauteur;
    }

    bool operator==(Rectangle& autreRect){
        // "egaux";
        return (surface == autreRect.surface);
    }

    bool operator!=(Rectangle& autreRect){
        // "différents";
        return (surface != autreRect.surface);
    }
};

int main(){
    Rectangle rec1(2,7);
    Rectangle rec2(2,7);
    bool egal = (rec1 == rec2);
    bool diff = (rec1 != rec2);
    cout << "les rectangles sont ils égaux? " << (egal ? "Yes" : "No") << endl;
    cout << "les rectangles sont ils different? " << (diff ? "Yes" : "No") << endl;
    return 0;
}