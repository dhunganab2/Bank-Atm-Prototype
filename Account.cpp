#include "Account.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <iomanip>
using namespace std;


Account::Account() {
    accountID = "";
    accountPIN = "";
    balance = 0.00;
}

Account::Account(const string& id, const string& pin, double bal) {
    if (id.length() == 8 && pin.length() == 4 && all_of(pin.begin(), pin.end(), ::isdigit) && bal >= 0) {
        accountID = id;
        accountPIN = pin;
        balance = bal;
    } else {
        cout << "Invalid Credentials, returning default values\n";
        accountID = "";
        accountPIN = "";
        balance = 0.0;
    }
}


void Account::setAccountId(const string& id) {
    if (id.length() == 8) {
        accountID = id;
    } else {
        cout << "Error: Account ID must be exactly 8 characters long!\n";
    }
}


string Account::getAccountId() const {
    return accountID;
}


void Account::setAccountPin(const string& pin) {
    if (pin.length() == 4 && all_of(pin.begin(), pin.end(), ::isdigit)) {
        accountPIN = pin;
    } else {
        cout << "Error: Account PIN must be 4 digits and should be numeric\n";
    }
}

string Account::getAccountPin() const {
    return accountPIN;
}


void Account::setAccountBalance(double bal) {
    if (bal >= 0) {
        balance = bal;
    } else {
        cout << "Balance should always be greater than zero\n";
    }
}

double Account::getAccountBalance() const {
    return balance;
}

void Account::printBalance() const {
    cout << "Balance: $" << fixed << setprecision(2) << balance <<  endl;
}

void Account::Deposit(double bal) {
    if (bal >= 0) {
        setAccountBalance(balance + bal);
        cout << "Deposit successful. New Balance is $" << balance << endl;
    } else {
        cout << "Deposit should be greater than 0.\n";
    }
}

void Account::withdraw(double bal) {
    if (bal <= 0 || bal> balance)  {
        cout << "insufficient fund\n";
        return ;

    }
    setAccountBalance(balance -= bal);
}
