#include <iostream>
#include <vector>

using namespace std;

int main(){
    int ligne, colonne;
    ligne = 3;
    colonne = 3;
    vector<vector<int>> matrice(ligne, vector<int>(colonne));

    // Remplir la matrice avec des valeurs;
    for (int i = 0; i <ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            matrice[i][j] = i+j;
        }
    }
    
    // Afficher la matrice 
    cout << "Affichage de matrice" << ligne << " * " << colonne << endl;
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            cout << matrice[i][j];
        }
        cout << endl;
    }
    return 0;
}