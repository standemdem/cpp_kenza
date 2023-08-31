#include <iostream>
#include <string>

using namespace std;

const char *SOURCE = "Ma string";

void echange(int *a, int *b){
    int temp;
    temp = *a;
    *a=*b;
    *b=temp;
}

void sommeTableau(int *tab, int taille){
    int acc = 0;
    for (int i = 0; i < taille; i++)
    {
        acc += tab[i];
    }
    cout << "somme = " << acc << endl;
}

void copieChaine(const char *source, char *destination){

    while(*source != '\0'){
        *destination = *source ;
        cout << *destination ;
        destination++;
        source++;
    }
    cout << endl;
}
// https://h-deb.clg.qc.ca/Sujets/Divers--cplusplus/CPP--Tableaux-2D.html 
void creerMatrice(int **matrice, int m, int n){
   if ( m, n) {
      for (int i = 0; i < m; i++)
         matrice[i] = nullptr;
      for (int i = 0; i < m; i++)
         matrice[i] = new int[n];      
   }
}

void detruireMatrice(int **matrice, int m){
    for (int i = 0; i < m; i++)
        delete [] matrice[i];
    delete [] matrice;
}

void displayMatrice(int **matrice, int m, int n){
    int acc = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrice[i][j] = acc;
            acc++;
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }
}

void display_adress(int *ptr){
    cout << "adresse de la valeur du ptr = " << ptr << endl; 
    cout << "adresse du ptr = " << &ptr << endl; 
}

int main(){
    int a,b;
    a=2;
    b=3;
    int tabOfInt[5] = {1, 2, 3, 4, 5};
    int taille = sizeof(tabOfInt) / sizeof(tabOfInt[0]);
    char destination[8];

    // exo1
    cout << "a = " << a << " b = " << b << endl;
    echange(&a, &b);
    cout << "a = " << a << " b = " << b << endl;
    // exo2
    sommeTableau(tabOfInt, taille);
    // exo 3
    copieChaine(SOURCE, destination);
    // Exo 4
    int m = 5;
    int n = 5;
    int **matrice = new int* [m];
    creerMatrice(matrice, m, n);
    displayMatrice(matrice, m, n);  
    detruireMatrice(matrice, m);
    // Exo 5
    int c = 2;
    int* ptr1 = &c;

    display_adress(ptr1);
}