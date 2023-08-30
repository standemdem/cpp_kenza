#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Livre {
public:
    string titre;
    string auteur;
    int anneePublication;
    int nbrPages;
    bool estEmprunte = false;

    Livre(string titre, string auteur, int anneePublication, int nbrPages)
    {
        this->titre = titre;
        this->auteur = auteur;
        this->anneePublication = anneePublication;
        this->nbrPages = nbrPages;
    }

    
    // getters
    string get_titre()
    {
        return titre;
    }
    string get_auteur()
    {
        return auteur;
    }
    int get_anneePublication()
    {
        return anneePublication;
    }
    int get_nbrPages()
    {
        return nbrPages;
    }
    // setters
    void set_titre(string new_titre)
    {
        titre = new_titre;
    }
    void set_auteur(string new_auteur)
    {
        auteur = new_auteur;
    }
    void set_anneePublication(int new_annee)
    {
        anneePublication = new_annee;
    }
    void set_pages(int new_pages)
    {
        nbrPages = new_pages;
    }

    // methodes
    void afficherInfo()
    {
        cout << "Titre : " << titre << ", Auteur : " << auteur 
        << ", Annee de publication : " << anneePublication 
        << ", Nombre de pages : " << nbrPages
        << ", Emprunté : " << estEmprunte << endl; 
    }

    bool estAncien()
    {
        if(anneePublication<1993)
        {
            return true;
        }
        return false;
    }


    ~Livre() 
    {
        cout << "Destroying Book : " << this->titre << endl;
    }
};


class Emprunteur 
{
public:
    string nom;
    string listeLivres[10];
    int nblLivres=0;

    Emprunteur(string nom)
    {
        this->nom = nom;
    }

    void emprunter_livre(Livre *livre)
    {
        listeLivres[nblLivres] =  livre->titre;
        nblLivres+=1;
        livre->estEmprunte = true;
    }

    void rendre_livre(Livre *livre, string titre)
    {
        for (int i = 0; i < nblLivres; i++)
        {
            if (listeLivres[i] == titre)
            {
                livre->estEmprunte = false;

                for (int j = i; j < nblLivres - 1; j++)
                {
                    listeLivres[j] = listeLivres[j + 1];
                }

                nblLivres--;
                cout << "Livre " << titre << " a été rendu par " << nom << endl;
                return;
            }
        }
        cout << "Livre " << titre << " n'est pas emprunté par " << nom << endl;
    }



    void afficher_emprunts()
    {
        if (nblLivres == 0)
        {
            cout << "Aucun livre emprunté." << endl;
        }
        else
        {
            cout << "livres empruntés : " << endl;
            for (int i = 0; i < nblLivres; i++)
            {
                cout << listeLivres[i] << endl;
            }
        }
    }

    ~Emprunteur()
    {
        cout << this->nom << " a été détruit" << endl;
    }
};

int main()
{
    Livre livre1("Harry Potter", "J.K Rowling", 1997, 450);
    cout << livre1.estAncien() << endl;
    livre1.set_anneePublication(1938);
    livre1.set_titre("Boulbi Plage");
    livre1.set_auteur("Bob le pingouin");
    livre1.set_pages(12);
    Livre livre2("Les Misérables", "Victor Hugo", 1862, 1500);
    Livre livre3("Dune", "Frank Herbert", 1965, 800);

    Emprunteur emprunteur1("Stan");
    emprunteur1.afficher_emprunts();
    emprunteur1.emprunter_livre(&livre1);
    emprunteur1.afficher_emprunts();
    emprunteur1.rendre_livre(&livre1, "Boulbi Plage");

    livre1.afficherInfo();
    livre2.afficherInfo();
    livre3.afficherInfo();
    return 0;
}