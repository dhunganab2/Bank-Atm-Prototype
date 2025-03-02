//
// Created by Bijay Dhungana on 2/9/25.
//

#ifndef ATM_H
#define ATM_H
#include "Account.h"
#include "Bank.h"


class ATM {
private:
    Bank &bank;
public:
    ATM(Bank &bankObject);
    int start();
    void transactions(Account &acct);
};
#endif //ATM_H
