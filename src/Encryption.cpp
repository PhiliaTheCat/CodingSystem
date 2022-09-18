#include <iostream>
#include <cstdlib>

#include "../include/Encryption"
#include "../include/Settings"
#include "../include/Cryptology"

using namespace std;

extern GlobalSet global;

void Encryption()
{
    char *key = new char [global.max_key + 1];
    char *mes = new char [global.max_str + 1];
    char *res = new char [global.max_str + 1];

    do 
    {
        cout << "---------------Encryption Mode---------------\n";
        cout << "Please type in your key\n";
        cout << "Your key: ";
        cin.getline(key, global.max_key + 1);
        Capitalize(key);
        Format(key);
    }
    while (1);

    delete [] key;
    delete [] mes;
    delete [] res;
}