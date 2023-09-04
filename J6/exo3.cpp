#include <iostream>
#include <vector>

using namespace std;

class Matrice {
private:
    vector<vector<int>> ma_matrice;

public:
    // Constructeur par défaut
    Matrice() : ma_matrice(3, vector<int>(3, 3)) {
    }

    // Opérateur de flux d'entrée (>>)
    istream &operator>>(istream &is) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                is >> ma_matrice[i][j];
            }
        }
        return is;
    }

    // Opérateur de flux de sortie (<<)
    ostream &operator<<(ostream &out) const {
        for (int i = 0; i < 3; ++i) {
            out << "| ";
            for (int j = 0; j < 3; ++j) {
                out << ma_matrice[i][j] << " ";
            }
            out << "|" << endl;
        }
        return out;
    }

    // Opérateur d'appel de fonction (operator())
    int &operator()(int a, int b){
        return ma_matrice[a-1][b-1];
    }

    //Opérateur de conversion de type


};

int main(){
    Matrice m1;
    
    cout << "Entrez 9 elems"<<endl;
    m1 >> cin;

    cout << "Affichage de la matrice"<<endl;
    m1.operator<<(std::cout);
    cout << m1(1,3)<<endl;
    return 0;
}