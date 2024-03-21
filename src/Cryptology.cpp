#include <iostream>
#include <limits>

#include "../include/Cryptology"

void Remove_Invalid(char str[])
{
    int i = 0, j = 0;
    while (str[j] != 0)
    {
        if (!(str[j] >= 'a' && str[j] <= 'z' || str[j] >= 'A' && str[j] <= 'Z'))
            j += 1;
        else 
        {
            if (i != j)
                str[i] = str[j];
            i += 1;
            j += 1;
        }
    }
    str[i] = str[j];
    return;
}

void Remove_Replication(char str[])
{
    bool flag[26] = {false};
    int i = 0, j = 0;
    while (str[j] != 0)
    {
        if (flag[str[j] - 65] == false)
        {
            if (i != j)
                flag[i] = flag[j];
            flag[str[j] - 65] = true;
            i += 1;
            j += 1;
        }
        else
            j += 1;
    }
    str[i] = str[j]; 
    return;
}

bool Deny_Str(char str[], int branch)
{
    system("cls");
    char res;
    switch (branch)
    {
        case 0:
        std::cout << "Enter Y/N to CONFIRM/DENY your key: ";
        break;
        case 1:
        std::cout << "Enter Y/N to CONFIRM/DENY your message: ";
        break;
    }
    std::cin.get(res);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
