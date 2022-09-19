#include <cstdlib>
#include <iostream>

#include "../include/Main_Menu"

using namespace std;

int Make_Decision()
{
    int decision = DECISION_INVALID_DEFAULT;

    while (!Decision_Is_Valid(decision))
    {
        system("cls");

        cout << "----------------Coding System---------------\n";
        cout << "0 --- Encryption            1 --- Decryption\n";
        cout << "2 --- Logs                  3 --- Settings\n";
        cout << "4 --- Exit\n";

        switch (decision)
        {
            case DECISION_INVALID_DEFAULT:
                cout << "Please type in the number attached to your option\n";
                break;
            case DECISION_INVALID_NUMBER_EXCEEDED:
                cout << "Invalid: Number Exceeded\n";
                cout << "Please type in a number again\n";
                break;
        }
        
        cout << "Your Option: ";
        cin >> decision;
    }
    return decision;
}

inline bool Decision_Is_Valid(int &decision)
{
    if (decision >= 0 && decision <= 4)
        return true;
    else if (decision == DECISION_INVALID_DEFAULT)
        return false;
    else 
    {
        decision = DECISION_INVALID_NUMBER_EXCEEDED;
        return false;
    }
}