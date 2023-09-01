#include <iostream>
#include <vector>

using namespace std;

const int TACHES_MAX = 100;

class Tache {

public:
    Tache(string nom, bool terminee){
        this->nom = nom;
        this->terminee = terminee;
    }
    void afficherDetails(){
        cout << "nom : " << nom << endl;
        if(terminee? cout<< "Terminee!" : cout<<"A faire"); 
        cout<<endl;
    }

    ~Tache(){
        cout << "Tache supprimée"<<endl;
    }

private:
    string nom;
    bool terminee;
};

void displayMenu(){
    cout << "[1] - Ajouter une nouvelle tache " << endl;
    cout << "[2] - Afficher la liste de taches" << endl;
    cout << "[3] - Marquer une tache comme terminée" << endl;
    cout << "[4] - Supprimer une tache avec son num" << endl;
    cout << "[5] - Quitter le programme" << endl;
}
int main(){
    vector<Tache> listeTaches;

    return 0;
}