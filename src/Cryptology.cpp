#include <iostream>
#include <cstdlib>

#include "../include/Cryptology"

using namespace std;

void Capitalize(char str[])
{
    int i = 0;
    while (str[i] != 0)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    }
}

void Format(char str[])
{
    bool flag[26] = {false};
    int i = 0, j = 0;
    while (str[j] != 0)
    {
        if (str[i] == ' ')
            j += 1;
        else if (flag[str[j] - 65] == false && i != j)
        {
            flag[i] = flag[j];
            i += 1;
            j += 1;
        }
        else if (flag[str[j] - 65] == true)
            j += 1;
    }
}

bool Deny_Str(char str[], int branch)
{
    while (1)
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
        cin.get();
        if (res == 'Y' || res == 'y')
            return true;
        else if (res == 'N' || res == 'n')
            return false;
    }
}
