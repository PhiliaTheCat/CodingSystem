#include <iostream>
#include <cstdlib>
#include <limits>

#include "../include/Cryptology"
#include "../include/Settings"

using namespace std;

bool Deny_Str(char str[], int branch)
{
    system("cls");
    char res;
    switch (branch)
    {
        case 0:
            cout << "Enter Y/N to CONFIRM/DENY your key: ";
            break;
        case 1:
            cout << "Enter Y/N to CONFIRM/DENY your message: ";
            break;
    }
    cin.get(res);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (res == 'Y' || res == 'y')
        return false;
    else
        return true;
}

void Complete_Key(char key[])
{
    bool flag[26] = {};
    int i = 0;
    while (key[i] != 0)
    {
        flag[key[i] - 'A'] = true;
        i += 1;
    }
    for (int j = 0; j < 26; j += 1)
    {
        if (!flag[j])
        {
            key[i] = 'A' + j;
            i += 1;
        }
    }
    key[i] = 0;
    return;
}
