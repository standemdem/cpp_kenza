#include <iostream>
#include <string>
using namespace std;

void displayMenu()
{
    cout << "########################################" << endl;
    cout << "[0] - Entrez le nombre d'étudiants total" << endl;
    cout << "[1] - Ajouter un étudiant" << endl;
    cout << "[2] - Rechercher un étudiant" << endl;
    cout << "[3] - Afficher les étudiants" << endl;
    cout << "[4] - Trier les étudiants" << endl;
    cout << "[5] - Afficher la moyenne générale" << endl;
    cout << "[6] - Quitter le programme" << endl;
    cout << "#######################################" << endl;
}

int get_number(){
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

string get_string(){
    string input;
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
    int totalStudents;
    bool start = true;
    int choice;
    displayMenu();
    while(start)
    {

        choice = get_number();
    }
    return 0;
}