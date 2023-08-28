#include <iostream>

void display_menu()
{
    std::cout << "Beverages" << std::endl;
    std::cout << "1 - coffee: 1.5€" << std::endl;
    std::cout << "2 - coca: 2€" << std::endl;
    std::cout << "3 - fanta: 2€" << std::endl;
    std::cout << "4 - redbull: 2€" << std::endl;
    std::cout << "5 - Beer: 5€" << std::endl;
}

int get_beverage()
{
    int choice;
    std::cout << "Enter the number of the desired beverage" << std::endl;
    std::cin >> choice;
    return choice;
}

float get_money()
{
    float money;
    std::cin >> money;
    return money;
}

int check_money(float money, float price)
{
    float remain;
    remain = 0;
    int new_choice;
    if (money >= price)
    {
        remain = money - price;
        if (remain > 0)
        {
            std::cout << "Thank you for your purchase" << std::endl;
            std::cout << "Your beverage is being prepared" << std::endl;
            std::cout << "Do not forget to get your money back " << remain << "€" << std::endl;
            return 0;
        }
        else
        {
            std::cout << "Thank you for your purchase" << std::endl;
            std::cout << "Your beverage is being prepared" << std::endl;
            return 0;
        }
    }
    else
    {
        std::cout << "Press 1 to enter a new amount" << std::endl;
        std::cout << "Press 2 to cancel your purchase" << std::endl;
        std::cin >> new_choice;
        if (new_choice == 1)
        {
            std::cout << "Please enter a new amount" << std::endl;
            money = get_money();

            check_money(money, price);
        }
        else
        {
            return -1;
        }
    }
    return 0;
    
}

int main()
{
    int choice;
    float prices[5] = {1.5, 2, 2, 2, 5};
    float price;
    float money_paid;
    int result;
    while (true)
    {
        display_menu();
        choice = get_beverage();
        if (choice < 1 || choice > 6)
        {
            std::cout << "Pick an available beverage" << std::endl;
        }
        else
        {
            std::cout << "You picked number: " << choice << std::endl;
            std::cout << "It costs: " << prices[choice - 1] << " €"<< std::endl;
            std:: cout << "Please enter the desired amount" << std::endl;
            money_paid = get_money();
            result = check_money(money_paid, prices[choice - 1]);
            if (result == 0 || result == -1)
            {
                break;
            }
        }
        
    }
    
    return 0;
}