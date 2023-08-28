#include <iostream>
#include <iomanip>

void convert()
{
    float temp_to_convert;
    char choice[1];
    double result;
    std::cout << "Choose a conversion" << std::endl;
    std::cout << "[C] convert Celsius To Farenheit" << std::endl;
    std::cout << "[F] convert Farenheit to Celsius" << std::endl;
    std::cin >> choice;

    if (choice[0] == 'C')
    {
        std::cout << "Enter a temp to convert" << std::endl;
        std::cin >> temp_to_convert;
        result = (temp_to_convert * 9/5) + 32;
        std::cout << std::fixed << std::setprecision(2) << temp_to_convert << " C = " << result << "F" << std::endl;
    }
    else if (choice[0] == 'F')
    {
        std::cout << "Enter a temp to convert" << std::endl;
        std::cin >> temp_to_convert;
        result = (temp_to_convert - 32) * 5 / 9;
        std::cout << std::fixed << std::setprecision(2) << temp_to_convert << " F = " << result << "C" <<std::endl;
    }
    else
    {
        std::cerr << "Wrong choice, try again" << std::endl;
        convert();
    }
    
}


int main()
{
    convert();
    return 0;
}