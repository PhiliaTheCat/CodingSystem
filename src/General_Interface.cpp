#include <iostream>
#include <cstdlib>
#include <limits>

#include "../include/General_Interface"
#include "Settings"
#include "../include/Utilities"
#include "../include/Decision_Support"

Decision Make_Decision()
{
    Decision decision = Decision::DECISION_INVALID_DEFAULT;

    while (!Decision_Is_Valid(decision))
    {
        system("cls");

        std::cout << "----------------Coding System---------------\n";
        std::cout << "0 --- Encryption            1 --- Decryption\n";
        std::cout << "2 --- Logs                  3 --- Settings\n";
        std::cout << "4 --- Exit\n";

        switch (decision)
        {
        case Decision::DECISION_INVALID_DEFAULT:
            std::cout << "Please type in the number attached to your option\n";
            break;
        case Decision::DECISION_INVALID_NUMBER_EXCEEDED:
            std::cerr << "Invalid: Number Exceeded\n";
            std::cout << "Please type in a number again\n";
            break;
        }

        std::cout << "Your Option: ";
        int t;
        std::cin >> t;

        decision = Decision_Update(t);

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return decision;
}

void Encryption()
{
    char *key = new char [global.max_key + 1] {};
    char *mes = new char [global.max_str + 1] {};
    char *res = new char [global.max_str + 1] {};

    do 
    {
        system("cls");
        std::cout << "---------------Encryption Mode---------------\n";
        std::cout << "Please type in your key\n";
        std::cout << "Your key: ";
        std::cin.getline(key, global.max_key + 1);
        Remove_Invalid(key);
        Capitalize(key);
        Remove_Replication(key);
    }
    while (Deny_Str(0));

    do 
    {
        system("cls");
        std::cout << "---------------Encryption Mode---------------\n";
        std::cout << "Please type in your message\n";
        std::cout << "Your message: ";
        std::cin.getline(mes, global.max_str + 1);
        Remove_Invalid(mes);
        Capitalize(mes);
    }
    while (Deny_Str(1));

    Complete_Key(key);
    
    delete [] key;
    delete [] mes;
    delete [] res;
}
