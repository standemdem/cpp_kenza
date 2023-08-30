#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

void ajouterEtudiant(string name, string grade, string students[100][2], int longueur, int *nbEtudiants)
{
    for (int j = 0; j < 2; j++)
    {
        if (students[*nbEtudiants][j] == "\0")
        {
            students[*nbEtudiants][j] = name;
            students[*nbEtudiants][j+1] = grade;
            *nbEtudiants +=1;
            cout <<"HELLO"<<endl;
            break;
        }
    }
    
    cout << name << " with grade " << grade << " has been added" << endl;
}

bool rechercherEtudiant(string name, string table[100][2], int nbEtudiants)
{
    bool temp = false;
    int i = 0;
    for ( i = 0; i < nbEtudiants +1; i++)
    {
        if(name == table[i][0])
        {
            cout << "student " << name << " exists at index " << i << endl; 
            return true;
        }
    }
    cout << "No student named " << name << " exists" << endl;
    return false;    
}

void display_students(string table[100][2], int nbEtudiants)
{
    if ( nbEtudiants == 0)
    {
        cout << "No students added yet" << endl;
    }
    else{
        for (int i = 0; i <nbEtudiants; i++)
        {
            cout << "name: " << table[i][0]<< "     ";
            cout << "mean: " << table[i][1]<<endl;
        }
    }
    
}

void trierEtudiant(string arr[100][2], int nbEtudiants) {
    for (int i = 0; i < nbEtudiants - 1; ++i) {
        for (int j = 0; j < nbEtudiants - i - 1; ++j) {
            if (arr[j][0] > arr[j + 1][0]) {
                std::swap(arr[j][0], arr[j + 1][0]);
                std::swap(arr[j][1], arr[j + 1][1]);
            }
        }
    }
}
void displayMenu()
{
    cout << "#################################" << endl;
    cout << "[1] - Ajouter un étudiant" << endl;
    cout << "[2] - Rechercher un étudiant" << endl;
    cout << "[3] - Afficher les étudiants" << endl;
    cout << "[4] - Trier les étudiants" << endl;
    cout << "[5] - Afficher la moyenne générale" << endl;
    cout << "[6] - Quitter le programme" << endl;
    cout << "#################################" << endl;
}

int get_choice(){
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

string get_name(){
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
void get_mean(string table[100][2], int nbEtudiants)
{
    int acc = 0;
    if(nbEtudiants == 0)
    {
        cout << "No students = no class mean";
    }
    else
    {
        for (int i = 0; i <nbEtudiants; i++)
        {
            acc += stoi(table[i][1]);
        }
        cout << "The class mean is: " << fixed << setprecision(2) << acc / nbEtudiants << endl;
    }
}

int main()
{
    displayMenu();
    string students[100][2];
    int longueur = sizeof(students) / sizeof(students[0]);
    int nbEtudiants=0;
    string stud_name;
    string stud_grade;
    string search_stud;
    bool start=true;
    while (start)
    {
        int choice = get_choice();
        switch (choice)
        {
        case 1:
            system("clear");
            displayMenu();
            cout << "Enter a name ";
            stud_name = get_name();
            cout << "Enter a grade ";
            stud_grade = get_name();
            ajouterEtudiant(stud_name, stud_grade, students, longueur, &nbEtudiants);
            break;
        case 2:
            system("clear");
            displayMenu();
            cout << "search student: ";
            search_stud = get_name();
            rechercherEtudiant(search_stud, students, nbEtudiants);
            break;
        case 3:
            system("clear");
            displayMenu();
            display_students(students, nbEtudiants);
            break;
        case 4:
            system("clear");
            displayMenu();
            trierEtudiant(students, nbEtudiants);
            break;
        case 5:
            system("clear");
            displayMenu();
            get_mean(students, nbEtudiants);
            break;
        case 6:
            start = false;
        default:
            break;
        }
    }
    return 0;
}