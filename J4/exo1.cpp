#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sommeVecteurs(vector<int> vec1, vector<int> vec2){

    vector<int> vecTemp(3);
    cout << "Somme de 2 vecteurs" << endl;
    for (int i = 0; i < vec1.size(); i++)
    {
        vecTemp[i] = vec1[i] + vec2[i];
        cout << vecTemp[i] << ", ";
    }
    cout<<endl;
}

void supprDoublons(vector<int> vec){
    vector<int> vectemp;
    cout << "Suppression des doublons" << endl;
    for(int elem : vec){
        if(find(vectemp.begin(), vectemp.end(), elem) == vectemp.end()){
            vectemp.push_back(elem);
        }
    }
    for(int elem : vectemp){
        cout << elem;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    // exo1 Somme de 2 vecteurs
    vector<int> vector1{1,2,3,4};
    vector<int> vector2{5,6,7,8};
    sommeVecteurs(vector1, vector2);

    // exo2 Suppression des doublons

    vector<int> vector3{1,2,2,3,4,4,4,0,0,0};
    supprDoublons(vector3);
    return 0;
}
