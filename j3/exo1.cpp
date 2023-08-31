#include <iostream>
#include <fstream>
using namespace std;

string get_input(){
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
int get_number(){
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


int main()
{
    string file_name;
    string file_text;
    int choice;

    // Recupère input utilisateur
    cout << "Entrez un nom de fichier: ";
    file_name = get_input();

    // Crée un objet fstream avec l'input
    ofstream file1(file_name);
    if(file1.is_open()){
        cout << "Entrez du texte: ";
        file_text = get_input();
        file1 << file_text << endl;
        cout << "Le message a été écrit avec succès" << endl;
        file1.close();
    }else{
        cout << "Erreur d'ouverture de fichier" << endl;
    }
    

    cout << "[1] - Lire le contenu du fichier" << endl;
    cout << "[2] - A tchao Bonsoir" << endl;
    fstream file2(file_name);
    choice = get_number();
    switch (choice)
    {
    case 1:
        if (file2) {
            string ligne;
            while (getline(file2, ligne)) {
            cout << ligne << std::endl;
            }
            file1.close();
        } else {
            cout << "Erreur à l'ouverture du fichier" << std::endl;
        }
        break;
    case 2:
        cout << "Aurevoir coco";
        break;
    default:
        break;
    }
    return 0;
}