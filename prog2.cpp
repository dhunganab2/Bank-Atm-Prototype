#include "Account.h"
#include <iostream>
#include <fstream>
#include "Bank.h"
#include "Atm.h"
using namespace std;

int main() {
    string filename;
    cout <<"Enter the path of the file:";
    cin >> filename;
    cout <<"loading Data.....\n";

    ifstream inf(filename);
    if(!inf) {
        cerr<<"Error opening the file ";
        exit(-1);
    }
    Bank mybank;
    mybank.loadAccounts(inf);


    ATM myatm(mybank);

    int result =myatm.start();
    switch (result) {
        case 0:
            cout << "Normal Exit" << endl;
            break;
        case 1:
            cout << "Account not found – system shutting down" << endl;
            break;
        default:
            cout << "Unknown error occurred" << endl;
    }
}