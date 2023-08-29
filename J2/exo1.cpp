#include <iostream>
// #include <cctype>
#include <string>
#include <algorithm>
#include <limits>
#include <ios>

using namespace std;

void display_menu()
{
    cout << "**********************************************" << endl;
    cout << "Choose what you want to do" << endl;
    cout << "[1] -  display phrase" << endl;
    cout << "[2] -  display length of phrase" << endl;
    cout << "[3] -  display 5th char" << endl;
    cout << "[4] -  replace last word and display" << endl;
    cout << "[5] -  display phrase inverted" << endl;
    cout << "[6] -  convert phrase to maj and display" << endl;
    cout << "[7] -  convert phrase to min and display" << endl;
    cout << "**********************************************" << endl;

}

int main()
{
    system("chcp 65001");

    string texte = "La programmation en C++ est très amusante !";
    int choice;
    display_menu();
    while(true)
    {        
        cin >> choice;
        int longueur = texte.length();

        if (std::cin.fail()) {
        std::cout << "Error: Invalid input. Please enter an integer." << std::endl;

        // Clear the fail state of the cin stream and ignore any remaining characters in the input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }else{
            switch (choice)
            {
            case 1:
                system("clear");
                display_menu();
                cout << texte << endl;
                break;
            case 2:
                system("clear");
                display_menu();
                cout << "Length of text: " << longueur << endl;
                break;
            case 3:
                system("clear");
                display_menu();
                cout << "5th char: " << texte[4] << endl;

                break;
            case 4:
                system("clear");
                display_menu();
                texte.replace(34, 8, "intéressante");
                cout << "new phrase: " << texte << endl;
                break;
            case 5:
                system("clear");
                display_menu();
                reverse(texte.begin(), texte.end());
                cout << "Reversed phrase" << endl;
                cout << texte << endl;
                break;
            case 6:
                system("clear");
                display_menu();
                for (int i = 0; i < texte.length(); i++)
                {
                    texte[i] = toupper(texte[i]);
                }
                cout << "phrase en MAJ: "<< endl;
                cout << texte << endl;
                break;
            case 7:
                system("clear");
                display_menu();
                for (int i = 0; i < texte.length(); i++)
                {
                    texte[i] = tolower(texte[i]);
                }
                cout << "phrase en MIN: "<< endl;
                cout << texte << endl;
                break;
            default:
                cout << "Don't break my balls with your silly attempts" << endl;
                break;
            }
        }
    }
        
  

}