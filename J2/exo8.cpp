#include <iostream>
#include <string>
using namespace std;
class CreatureMythique {
public:
    CreatureMythique(string _nom, double _taille, string _pouvoir){
        nom = _nom;
        taille = _taille;
        pouvoir = _pouvoir;
    }

    void afficherDetails(){
        cout << "###################################" << endl;
        cout << "nom : " << nom << endl;
        cout << "taille : " << taille << " metre" << endl;
        cout << "pouvoir : " << pouvoir << endl;   
    }

    ~CreatureMythique(){
            cout << this->nom << " a été détruit" << endl;
        }

private:
    string nom;
    double taille;
    string pouvoir;    
};

class Serpigeon : public CreatureMythique {
public:
    Serpigeon(string nom, double taille, string pouvoir, int nbPlumesEcailles)
    :CreatureMythique(nom, taille, pouvoir){
        this->nbPlumesEcailles = nbPlumesEcailles;
    }

    void afficherDetails(){
        CreatureMythique::afficherDetails();
        cout << "Nombre de plumes et d'écailles: " << nbPlumesEcailles << endl;
    }
    ~Serpigeon(){
        cout << "###################################" << endl;
        cout << "Serpirouu rou rouuuuuuu *couic*" << endl;
    }
private:
    int nbPlumesEcailles;
};

class PigeonGarou : public CreatureMythique {
public:
    PigeonGarou(string nom, double taille, string pouvoir, bool pleineLune)
    :CreatureMythique(nom, taille, pouvoir){
        this->pleineLune = pleineLune;
    }

    void afficherDetails(){
        CreatureMythique::afficherDetails();
        if(pleineLune){
            cout << "La lune est pleine, tremblez pauvres mortels!"  << endl;
        }else{
            cout << "Rourourou"<< endl;
        }
    }

    bool setLune(){
        if (pleineLune)
        {
            pleineLune = false;
            return pleineLune;
        }
        pleineLune = true;     
        return pleineLune;
    }

    ~PigeonGarou(){
        // CreatureMythique::~CreatureMythique();
        cout << "###################################" << endl;
        cout << "Awoooooooooooo ... Bobo :'(" << endl;
    }
private:
    bool pleineLune;
};


class PigeonauzorusRex : public CreatureMythique {
public:
    PigeonauzorusRex(string nom, double taille, string pouvoir, string cri)
    :CreatureMythique(nom, taille, pouvoir){
        this->cri = cri;
    }

    void afficherDetails(){
        CreatureMythique::afficherDetails();
        cout << cri << endl;
    }

    ~PigeonauzorusRex(){
        // CreatureMythique::~CreatureMythique();
        cout << "###################################" << endl;
        cout << "I'll be back with even more swag !" << endl;
    }
private:
    string cri;
};


int main()
{
    Serpigeon crea1("Serpico", 0.5, "Empoisonne ses victimes par laché de guano", 42);
    PigeonGarou crea2("Garourou", 2.2, "Se transforme les soirs de pleines lune", true);
    PigeonauzorusRex crea3("Pigzilla", 59, "Vole malgrè ses ailes minuscules", "Pousse un roucoulement terrible" );
    crea1.afficherDetails();
    crea2.afficherDetails();
    crea2.setLune();
    crea2.afficherDetails();
    crea3.afficherDetails();
    
    return 0;
}