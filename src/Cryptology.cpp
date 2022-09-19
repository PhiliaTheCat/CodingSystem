#include <iostream>

#include "../include/Cryptology"

using namespace std;

void Capitalize(char key[])
{
    int i = 0;
    while (key[i] != 0)
    {
        if (key[i] >= 'a' && key[i] <= 'z')
            key[i] -= 32;
    }
}

void Format(char key[])
{
    bool flag[26] = {false};
    int i = 0, j = 0;
    while (key[j] != 0)
    {
        if (key[i] == ' ')
            j += 1;
        else if (flag[key[j] - 65] == false && i != j)
        {
            flag[i] = flag[j];
            i += 1;
            j += 1;
        }
        else if (flag[key[j] - 65] == true)
            j += 1;
    }
}

bool Deny_Key()
{
    char res;
    cout << "Enter Y/N to Confirm/Deny: ";
    cin >> res;
    if (res == 'Y' || res == 'y')
        return true;
    else 
        return false;
}
