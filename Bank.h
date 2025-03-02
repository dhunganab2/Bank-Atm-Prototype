#ifndef BANK_H
#define BANK_H

#include <vector>
#include "Account.h"
using namespace std;

class Bank {
protected:
    vector<Account> allAccounts;
    Account dummyAccount;

public:
    Account& findAcct(const string& id, const string& pin);
    void addAcct(Account& acct);
    void loadAccounts(std::ifstream& inf);
};

#endif // BANK_H

