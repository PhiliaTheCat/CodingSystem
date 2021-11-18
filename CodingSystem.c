#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

void colour(int);
int mainmenu();
void encryption();
void getkey(char *, int *);
void merge(char *);

int main()
{
    int selected;
    selected = mainmenu(); //User Decision
    switch (selected) //Function switching
    {
        case 0:
            encryption();
            break;
        /*case 1:
            decryption();
            break;*/
    }
}

void colour(int col)
{
    HANDLE colout;
    colout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colout, col);
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
            case -1: //Default
                printf("Please type in the number attached to your option\n");
                break;
            case -2:
                colour(4); //Turn the texts into red
                printf("Invalid option input\n");
                colour(7); //Turn the texts back to white
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

void encryption()
{
    system("cls");
    char *key = (char *)calloc(27, sizeof(char));
    int keystatus = -1; //Initiate keystatus as not set
    while (keystatus < 0) //Waiting for valid key
    {
        printf("---------------Encryption Mode---------------\n");
        getkey(key, &keystatus);
        if (keystatus < 0)
            system("cls");
    }
    printf("Key accepted\n");
    colour(4);
    printf("ANY REPEATING CHARACTERS WILL BE MERGED\n");
    colour(7);
    system("pause");
    merge(key);
    printf("Processed Key: %s\n", key);
    system("pause");
}

void getkey(char *key, int *keystatus)
{
    switch (*keystatus) //Notice varies based on keystatus
    {
        case -1:
            printf("Please type in your key in ");
            colour(4);
            printf("lowercase\nONE WORD ONLY\nNO SPECIAL SIGNAL OR NUMBER ALLOWED\n");
            colour(7);
            printf("Key: ");
            scanf("%s", key);
            break;
        case -2:
            colour(4);
            printf("Invalid: Uppercase in key detected\n");
            colour(7);
            printf("Pleas type in your key again\n");
            printf("Key: ");
            scanf("%s", key);
            break;
        case -3:
            colour(4);
            printf("Invalid: Special signal in key detected\n");
            colour(7);
            printf("Pleas type in your key again\n");
            printf("Key: ");
            scanf("%s", key);
            break;
        case -4:
            colour(4);
            printf("Invalid: Number in key detected\n");
            colour(7);
            printf("Pleas type in your key again\n");
            printf("Key: ");
            scanf("%s", key);
            break;
    }
    *keystatus = 0; //Assumption that key is valid
    for (int i = 1; i <= 26; i += 1) //Key validation
    {
        if (*(key + i - 1) == 0) //Stop at the end of the key string
            break;
        else if (*(key + i - 1) >= 48 && *(key + i - 1) <= 57) //Invalid: Number
        {
            *keystatus = -4;
            break;
        }
        if (*(key + i - 1) >= 65 && *(key + i - 1) <= 90) //Invalid: Uppercase
        {
            *keystatus = -2;
            break;
        }
        else if (*(key + i - 1) < 65 || *(key + i - 1) > 122) //Invalid: Special signal
        {
            *keystatus = -3;
            break;
        }
    }
}

void merge(char *key)
{
    for (int i = 1; i <= 26; i += 1)
    {
        char check = *(key + i - 1);
        if (check == 0) //Stop at the end of the key string
            break;
        for (int k = i + 1; k <= 26; k += 1)
        {
            if (check == *(key + k - 1)) //Search for repeating characters
            {
                *(key + k - 1) = 0; //Turn the repeating character into a blank
                strcat(key, (key + k)); //Remove the blank
            }
        }
    }
}