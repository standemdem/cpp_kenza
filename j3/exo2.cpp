#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    fstream meteo("meteo.csv");
    string total[100];
    string headers[4];
    string jour[4];
    string tempMin[4];
    string tempMax[4];
    string precipitation[4];
    int counter = 0; 
    string ligne;

    if(!meteo){
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
    }


    if (meteo) {
        while (getline(meteo, ligne, ',')) {
            total[counter] = ligne;
        counter ++;
        }
        meteo.close();
    } else {
        cout << "Erreur à l'ouverture du fichier" << endl;
    }
    getline(meteo, ligne)


    for (int i = 0; i < 13; i++)
    {
        cout << total[i]<<endl;
        if(i<3){
            headers[i]=total[i];
        }else if(i>=3 && i<6){
            jour[i]=total[i];
        }else if(i>=6 && i<9){
            tempMin[i]=total[i];
        }else if(i>=9 && i<12){
            tempMax[i]=total[i];
        }else{
            precipitation[i]=total[i];
        }
    }
    cout << *min_element(tempMin, tempMin + 4) << endl;
    
    return 0;
}