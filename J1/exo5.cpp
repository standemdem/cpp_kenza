#include <iostream>
#include <string>
#include <bits/stdc++.h> 

std::string get_input()
{
    std::string input;
    std::cout << "Enter a string: " << std::endl;
    getline(std::cin, input);
    return input;
}

void display_length(std::string chain)
{
    std::cout << "Length: " << chain.length() << std::endl;
}

void display_size(std::string chain1, std::string chain2)
{
    bool result = (chain1.size() == chain2.size());
    if(result == 0)
    {
        std::cout << "Les chaines sont différentes" << std::endl;
    }
    else
    {
        std::cout << "Les chaines sont identiques" << std::endl;
    }
}

void display_first(std::string chain)
{
    std::cout << "1er char = " << chain[0] << std::endl;
}


void display_last(std::string chain)
{
    int longueur= chain.length();
    std::cout << "dernier char = " << chain[longueur - 1] << std::endl;
}

void display_with_at(std::string chain)
{
    int longueur= chain.length() / 2 ;
    std::cout << "Char at position " << longueur << " is " << chain[longueur] << std::endl;
}
void find_substr_in_str(std::string chain1, std::string chain2)
{
    std::string substr = get_input();
    std::size_t index1 = chain1.find(substr);
    std::size_t index2 = chain2.find(substr);
    if (index1 != std::string::npos) 
    {
        std::cout << "La sous-chaîne est à l'indice : " << index1 << " de chain1" << std::endl; // Affiche 8
    } 
    else 
    {
        std::cout << "Sous-chaîne non trouvée dans chain1" << std::endl;
    }
    if (index2 != std::string::npos) 
    {
        std::cout << "La sous-chaîne est à l'indice : " << index2 << " de chain2" << std::endl; // Affiche 8
    } 
    else 
    {
        std::cout << "Sous-chaîne non trouvée dans chain2" << std::endl;
    }
}
int main()
{
    std::string input1, input2;
    input1 = get_input();
    input2 = get_input();
    display_length(input1);
    display_length(input2);
    display_size(input1, input2);
    display_first(input1);
    display_first(input2);
    display_last(input1);
    display_last(input2);
    display_with_at(input1);
    display_with_at(input2);
    find_substr_in_str(input1, input2);
}