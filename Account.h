#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountID;
    string accountPIN;
    double balance;

public:
    Account();
    Account(const string& id, const string& pin, double bal);

    // Getters
    string getAccountId() const;
    string getAccountPin() const;
    double getAccountBalance() const;
    // Setters
    void setAccountId(const string& id);
    void setAccountPin(const string& pin);
    void setAccountBalance(double bal);


    void printBalance() const;
    void Deposit(double bal);
    void withdraw(double bal);
};

#endif // ACCOUNT_H
