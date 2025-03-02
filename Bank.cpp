
#include "Bank.h"
#include "Account.h"
#include <iostream>
#include <fstream>
using namespace std;

Account &Bank::findAcct(const string &id, const string &pin) {
    for (Account &acc : allAccounts) {
        if(acc.getAccountId() == id && acc.getAccountPin() == pin) {
            return acc;
        }
    }
    return dummyAccount;

}

void Bank::addAcct(Account &acct) {
    allAccounts.push_back(acct );
}

void Bank::loadAccounts(ifstream &inf){
    string id;
    string pin;
    double bal;
    while (inf >> id >> pin >> bal){
        Account newAccount(id, pin, bal);
        addAcct(newAccount);
    }

   cout <<allAccounts.size() <<" " <<"Account Loaded Successfully \n" << endl;
}
















