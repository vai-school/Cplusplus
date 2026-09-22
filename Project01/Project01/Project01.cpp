// Project01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main() {
    float bal = 0;
    int ID = 0;
    std::string name = "";

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Enter your balance: ";
    std::cin >> bal;

    bool done = false;
    int input = 3;
    float desposit = 0;
    float withdraw = 0;
    while (!done)
    {
        std::cout << "\n";
        std::cout << "Account Menu:\n";
        std::cout << "Quit Menu: 0\n";
        std::cout << "Display Account Info: 1\n";
        std::cout << "Desposit: 2\n";
        std::cout << "Withdraw: 3\n";
        std::cout << "Your choice: ";
        std::cin >> input;

        if (input == 0)
        {
            done = true;
        }

        if (input == 1) 
        {
            std::cout << "Account ID: " << ID << " Account Name: " << name << " Account Balance: " << bal << "\n";
        }

        if (input == 2)
        {
            std::cout << "How much do you want to Desposit?: ";
            std::cin >> desposit;
            bal = bal + desposit;
        }

        if (input == 3)
        {
            std::cout << "How much do you want to Withdraw?: ";
            std::cin >> withdraw;
            bal = bal - withdraw;
        }

    }


    return 0;
}
