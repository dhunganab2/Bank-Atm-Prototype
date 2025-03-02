
#include <iostream>
#include "Account.h"
#include <string>
#include "Atm.h"
#include "Bank.h"
using namespace std;

ATM::ATM(Bank &bankObject) : bank(bankObject) {}
int ATM::start() {
    string command;
    while (true) {
        cout << "Please enter your command" << endl;
        cout << "Q - quit/exit" << endl;
        cout << "L - login to account " << endl;
        cin >> command;

        if (command == "L") {
            int loginAttempts = 0;

            while (loginAttempts < 3) {
                string accountId, accountPin;
                cout << endl<<"Please enter Account id" << endl;
                cin >> accountId;
                cout << "Please enter PIN" << endl;
                cin >> accountPin;
                Account &foundAccount = bank.findAcct(accountId, accountPin);

                if (!foundAccount.getAccountId().empty() && !foundAccount.getAccountPin().empty()) {
                    cout << "Account found." << endl;
                    transactions(foundAccount);
                    break;
                } else {
                    cout << "Sorry - No match" << endl;
                    loginAttempts++;
                    if(loginAttempts == 3) return 1;
                }
            }
        }
        else if (command == "Q") {
            break;
        }
        else {
            cout << "Unrecognized command " << command << endl;
        }
    }
    return 0;
}

void ATM::transactions(Account &acct) {
    char choice;
    while (true) {
        cout <<endl<< "Please enter your selection or Q to quit:" << endl;
        cout << "W - withdraw funds" << endl;
        cout << "D - deposit funds" << endl;
        cout << "B - check balance" << endl;
        cout << "Q - quit/exit" << endl;

        cin >> choice;

        if (choice == 'W') {
            double amount;
            cout << "Please enter the amount of withdrawal ";
            cin >> amount;
            acct.withdraw(amount);
        } else if (choice == 'D') {
            double amount;
            cout << "Enter the amount to deposit: ";
            cin >> amount;
            acct.Deposit(amount);
        } else if (choice == 'B') {
            acct.printBalance();
        } else if (choice == 'Q') {
            cout << "Goodbye" << endl;
            break;
        } else {
            cout << "Invalid selection. Please try again." << endl;
        }
    }
}
