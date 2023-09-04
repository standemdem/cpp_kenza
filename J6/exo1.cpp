#include <iostream>

using namespace std;

class Date{

private:
    int jour;
    int mois;
    int annee;
public:
    Date(int jour, int mois, int annee){
        this->jour = jour;
        this->mois = mois;
        this->annee = annee;
    }

    bool operator==(const Date& autre){
        if(this->jour==autre.jour, 
        this->mois == autre.mois,
        this->annee == autre.annee)
            return true; 
        return false;
    }

    void display(){
        cout << "jour: "<< jour <<endl;
        cout << "mois: "<< mois <<endl;
        cout << "année: "<< annee <<endl;
    }
};


int main(){
    Date date1(12, 11, 1986);
    Date date2(12, 11, 1985);
    bool test = (date1==date2);
    cout << test;
    return 0;
}