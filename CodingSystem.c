#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int mainmenu();
void getkey(char *);
void merge(char *);
int main()
{
    int selected;
    selected = mainmenu();
    //char *key = (char *)calloc(27, sizeof(char));
    //getkey(key);
}

int mainmenu()
{
    int selected = -1;
    while (selected < 0)
    {
        printf("----------------Coding System---------------\n");
        printf("0 --- Encryption            1 --- Decryption\n");
        switch (selected)
        {
            case -1:
                printf("Please type in the number attached to your option\n");
                break;
            case -2:
                printf("\033[0;31m");
                printf("Invalid option input\n");
                printf("\033[0m");
                printf("Please type in the number again\n");
                break;
        }
        printf("Option: ");
        scanf("%d", &selected);
        if (selected >= 2)
        {
            selected = -2;
            system("cls");
        }
    }
    return selected;
}

void getkey(char *key)
{
    printf("Please type in your key\nONE WORD ONLY\nNO SPECIAL SIGNAL ALLOWED\n");
    printf("Key: ");
    scanf("%s", key);
    merge(key);
}

void merge(char *key)
{
    for (int i = 1; i <= 26; i += 1)
    {
        char check = *(key + i - 1);
        if (check == 0)
            break;
        for (int k = i + 1; k <= 26; k += 1)
        {
            if (check == *(key + k - 1))
            {
                *(key + k - 1) = 0;
                strcat(key, (key + k));
            }
        }
    }
}