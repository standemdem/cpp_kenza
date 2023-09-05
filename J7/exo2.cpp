#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class StockageDonnees {
private:
    T data;
    vector<T>datacenter;

public:
    StockageDonnees(){
        vector<T>datacenter;
    }

    void ajouterDonne(T data){        
        datacenter.push_back(data);
        cout << data << " a bien été ajouté au datacenter" <<endl;
    }

    void obtenirDonnee(int index){
        if(!(datacenter.empty())){
            cout<< "A l'index " << index << " : " << datacenter[index] << endl;

        }else{
            cout << "Rien à l'index " << index << endl;
        }
    }

    void taille(){
        cout << "Le stockage est de taille: " << datacenter.size()<<endl; 
    }
    
};

int main(){
    StockageDonnees<int> data1;
    data1.ajouterDonne(42);
    data1.ajouterDonne(42);
    
    StockageDonnees<string> data2;
    data2.ajouterDonne("stan");
    data2.obtenirDonnee(0);
    data1.taille();
    return 0;
}