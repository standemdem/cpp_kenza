#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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

    // ~Tache(){
    //     cout << "Tache supprimée"<<endl;
    // }

private:
    string nom;
    bool terminee;
};
bool get_input_bool(){
    bool input;
    while (true){
        if (cin >> input){
            return input;
        }else{
            cin.clear();
            cin.ignore();
            cout << "Entrée invalide, veuillez réessayer";
        }
    }
}
int get_input_int(){
    int input;
    while (true){
        if (cin >> input){
            return input;
        }else{
            cin.clear();
            cin.ignore();
            cout << "Entrée invalide, veuillez réessayer";
        }
    }
}
string get_input_string(){
    string input;
    while (true){
        if (cin >> input){
            return input;
        }else{
            cin.clear();
            cin.ignore();
            cout << "Entrée invalide, veuillez réessayer";
        }
    }
}


void displayMenu(){
    cout << "################################################" << endl;
    cout << "[1] - Ajouter une nouvelle tache " << endl;
    cout << "[2] - Afficher la liste de taches" << endl;
    cout << "[3] - Marquer une tache comme terminée" << endl;
    cout << "[4] - Supprimer une tache avec son num" << endl;
    cout << "[5] - Quitter le programme" << endl;
    cout << "################################################" << endl;
}

void creer_ajouter_tache_to_list(vector<Tache> liste ,string name, bool terminee){
    Tache tache(name, terminee);
    liste.push_back(tache);
    cout << "Tache crée avec succés"<< endl;
}

void display_liste_taches(vector<Tache> liste){
    for(Tache elem : liste){
        elem.afficherDetails();
    }
}
int main(){
    vector<Tache> listeTaches;

    int choice;
    bool start;
    start = true;
    displayMenu();
    while(start){
        choice = get_input_int();
        string tache;
        bool terminee;
        switch (choice)
        {
        case 1:
            system("clear");
            displayMenu();
            cout << "ajouter une tache";
            tache = get_input_string();
            cout << "0 si non fini, 1 si terminé";
            terminee = get_input_bool();
            creer_ajouter_tache_to_list(listeTaches, tache, terminee);

            break;
        case 2:
            system("clear");
            displayMenu();
            display_liste_taches(listeTaches);

            break;
        case 3:
            system("clear");
            displayMenu();
            
            break;
        case 4:
            system("clear");
            displayMenu();
            
            break;
        case 5:
            start = false;
            break;
        
        default:
            break;
        }
    }

    return 0;
}