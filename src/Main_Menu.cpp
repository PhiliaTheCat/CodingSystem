#include <cstdlib>
#include <iostream>
#include <limits>

#include "../include/Main_Menu"

using namespace std;

Decision Make_Decision()
{
    Decision decision = Decision::DECISION_INVALID_DEFAULT;

    while (!Decision_Is_Valid(decision))
    {
        system("cls");

        cout << "----------------Coding System---------------\n";
        cout << "0 --- Encryption            1 --- Decryption\n";
        cout << "2 --- Logs                  3 --- Settings\n";
        cout << "4 --- Exit\n";

        switch (decision)
        {
            case Decision::DECISION_INVALID_DEFAULT:
            cout << "Please type in the number attached to your option\n";
            break;
            case Decision::DECISION_INVALID_NUMBER_EXCEEDED:
            cerr << "Invalid: Number Exceeded\n";
            cout << "Please type in a number again\n";
            break;
        }
        
        cout << "Your Option: ";
        int t;
        cin >> t;

        decision = Decision_Update(t);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return decision;
}
