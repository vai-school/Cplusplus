#include <iostream>
#include "account.h"
#include <list>
#include <algorithm>
#include <numeric>
#include <iomanip>

int main() {
    std::list<Account> accounts;

    bool done = false;
    int choice;
    float amount;
    int id;

    while (!done) {
        std::cout << "\nAccount Menu:\n";
        std::cout << "0. Quit Program\n";
        std::cout << "1. Display Account Information\n";
        std::cout << "2. Add a deposit to an account\n";
        std::cout << "3. Withdraw from an account\n";
        std::cout << "4. Add new account\n";
        std::cout << "5. Find account by ID\n";
        std::cout << "6. Remove account\n";
        std::cout << "7. Show total balance for all accounts\n";
        std::cout << "8. Add a dividend to all accounts\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (choice == 0) {
            done = true;
        }
        else if (choice == 1) {
            std::for_each(accounts.begin(), accounts.end(), [](const Account& a) {
                a.display();
            });
        }
        else if (choice == 2) {
            std::cout << "Enter the ID of the account to find: ";
            std::cin >> id;

            std::list<Account>::iterator it = findAccount(accounts, id);

            if (it == accounts.end()) {
                std::cout << "Account not found.\n";
            }
            else {
                std::cout << "Found account: ";
                it->display();

                std::cout << "Amount to deposit: ";
                std::cin >> amount;

                it->deposit(amount);
            }
        }
        else if (choice == 3) {
            std::cout << "Enter the ID of the account to find: ";
            std::cin >> id;

            std::list<Account>::iterator it = findAccount(accounts, id);

            if (it == accounts.end()) {
                std::cout << "Account not found.\n";
            }
            else {
                std::cout << "Found account: ";
                it->display();

                std::cout << "Amount to withdraw: ";
                std::cin >> amount;

                it->withdraw(amount);
            }
        }
        else if (choice == 4) {
            Account newAccount;

            newAccount.getInfo();

            accounts.push_back(newAccount);
        }
        else if (choice == 5) {
            std::cout << "Enter the ID of the account to find: ";
            std::cin >> id;

            std::list<Account>::iterator it = findAccount(accounts, id);

            if (it == accounts.end()) {
                std::cout << "Account not found.\n";
            }
            else {
                std::cout << "Found account: ";
                it->display();
            }

        }
        else if (choice == 6) {
            std::cout << "Enter account ID to remove: ";
            std::cin >> id;

            auto newEnd = std::remove_if(accounts.begin(), accounts.end(), [id](const Account& a) {
                return a.get_id() == id;
                });
            accounts.erase(newEnd, accounts.end());
        }
        else if (choice == 7) {
            float total = std::accumulate(accounts.begin(), accounts.end(), 0.0f,
                [](float sum, const Account& a) {
                    return sum + a.get_balance();
                });

            std::cout << "Total in all accounts: $" << std::fixed << std::setprecision(2) << total << "\n";
        }
        else if (choice == 8) {
            float percent;
            std::cout << "Enter the dividend as a percentage: ";
            std::cin >> percent;

            std::transform(accounts.begin(), accounts.end(), accounts.begin(),
                [percent](Account a) {
                    a.deposit(a.get_balance() * percent / 100.0f);
                    return a;
                });
        }
    }
    return 0;
}