#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Matrice {
private:
    vector<vector<int>> ma_matrice;

public:
    // Constructeur par défaut
    Matrice() : ma_matrice(3, vector<int>(3, 3)) {
        // Initialise la matrice avec des valeurs par défaut (0)
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
    ostream &operator<<(ostream &os) const {
        for (int i = 0; i < 3; ++i) {
            os << "| ";
            for (int j = 0; j < 3; ++j) {
                os << ma_matrice[i][j] << " ";
            }
            os << "|" << endl;
        }
        return os;
    }

    // Opérateur d'appel de fonction (operator())
    int operator()(int row, int col) const {
        // Vérifie que les indices sont valides (commencent à 1)
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3) {
            return ma_matrice[row - 1][col - 1];
        } else {
            cerr << "Indices hors limites." << endl;
            return 0; // Ou une valeur par défaut appropriée
        }
    }

    // Opérateur de conversion de type
    operator string() const {
        stringstream ss;
        ss << "[";
        for (int i = 0; i < 3; ++i) {
            ss << "[";
            for (int j = 0; j < 3; ++j) {
                ss << ma_matrice[i][j];
                if (j < 2) ss << ", ";
            }
            ss << "]";
            if (i < 2) ss << ",";
        }
        ss << "]";
        return ss.str();
    }
};

int main() {
    Matrice m;

    // Saisie et affichage de la matrice
    cin >> m;
    cout << "La matrice saisie est : " << endl;
    m.operator<<(cout); // Utilisation de l'opérateur << pour l'affichage
    cout << endl;

    // Accéder à un élément de la matrice et l'afficher
    int element = m(1, 2); // Récupère l'élément en (1, 2)
    cout << "L'élément en (1, 2) est : " << element << endl;

    // Conversion de la matrice en chaîne de caractères
    string str_m = static_cast<string>(m);
    cout << "La matrice en chaîne de caractères est : " << str_m << endl;

    return 0;
}
