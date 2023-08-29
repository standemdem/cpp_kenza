#include <iostream>
#include <iomanip>

using namespace std;

int somme(int a, int b)
{
    return a + b;
}

double diviser(double a, double b)
{
    return a / b;
}

string concatenation(string a, string b)
{
    string c = a;
    return c.append(" ").append(b);
}

void afficherInfos(int age, string nom)
{
    cout << "Nom : " << nom << ", Age: " << age << endl;
}


int main()
{
    int num1, num2;
    double num3, num4;
    string str1, str2;
    num1 = 2;
    num2 = 3;
    num3 = 3.6;
    num4 = 4.9;
    str1 = "Hello";
    str2 = "World !";

    cout << "somme = " << somme(num1, num2) << endl;
    std::cout << "Type : " << typeid(somme(num1, num2)).name() << std::endl;
    
    cout << "division = " << fixed << setprecision(2) << diviser(num3, num4) << endl;
    std::cout << "Type : " << typeid(diviser(num3, num4)).name() << std::endl;

    cout << "concatenation = " << concatenation(str1, str2) << endl;
    std::cout << "Type : " << typeid(concatenation(str1, str2)).name() << std::endl;
    
    afficherInfos(12, "Stan");
    return 0;
}