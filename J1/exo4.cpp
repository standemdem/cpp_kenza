#include <iostream>
#include <string>

int main()
{
    std::string film1 = "Bienvenue à Zombieland";
    std::string film2 = "Pirate des Caraibes";

    // concatenation
    std::string film_concate_1;
    std::string film_concate_2 = film1;
    film_concate_1 = film1 + '\n' + film2;
    film_concate_2.append("\n").append(film2);

    std::cout << "film1: " << film_concate_1 << std::endl;
    std::cout << "film2: " << film_concate_2 << std::endl;

    // Longueur de la chaine
    std::cout << "longueur film1: " << film_concate_1.length() << std::endl;
    std::cout << "longueur film2: " << film_concate_2.length() << std::endl;

    // Comparer les chaines
    bool equal1;
    int equal2;
    equal1 = (film_concate_1 == film_concate_2);
    equal2 = film_concate_1.compare(film_concate_2);

    std::cout << "La valeur d'equal1 est: " << equal1 << std::endl;
    std::cout << "La valeur d'equal2 est: " << equal2 << std::endl;

    // Comparer film1 et film2
    bool equal3 = (film1 != film2);
    std::cout << "equal4: " << equal3 << std::endl;
}