#include <iostream>


void exo1()
{
    int x, y;
    float z;
    std::cout << "Entrez 2 nombres entier et un float" << std::endl;
    std::cin >> x >> y >> z;
    if (y==0)
    {
        std::cerr << "Entrez un nombre différent de 0" << std::endl;
    }
    else
    {
        std::cout << "La somme de " << x << " et " << y << " : "<< x + y << std::endl;
        std::cout << "La différence de " << x << " et " << y << " : "<< x - y << std::endl;
        std::cout << "La multiplication de " << x << " par " << z << " : "<< x * z << std::endl;
        std::cout << "La division entière de " << x << " par " << y << " : "<< x / y << std::endl;
        std::cout << "Le reste de la division de " << x << " par " << y << " : "<< x % y << std::endl;

        // Partie 2
        if (x == y)
        {
            std::cout << x << " est égal à " << y << std::endl;
        }
        if (x != y)
        {
            std::cout << x << " est différent de " << y << std::endl;
        }
        if (x >y)
        {
            std::cout << x << " est strictement supérieur à " << y << std::endl;
        }
        if (x < y)
        {
            std::cout << x << " est strictement inférieur à " << y << std::endl;
        }
        if (x >= y)
        {
            std::cout << x << " est supérieur ou égal à " << y << std::endl;
        }
        else if (x <= y)
        {
            std::cout << x << " est inférieur ou égal à " << y << std::endl;
        }
        
        // partie 3

        if (x>=0 && y>=0)
        {
            std::cout << x << " et " << y << " sont positifs" << std::endl; 
        }
        if (x <= 0 || y <= 0)
        {
            std::cout << x << " est inférieur à 0 ou " << y << " est inférieur à 0" << std::endl; 
        }
        if (x % 2 == 0 && z > 10)
        {
            std::cout << x << " est divisible par 2 et " << z << " est supérieur à 10" << std::endl; 
        }
    }    
}



int main()
{
    exo1();
    return 0;
}