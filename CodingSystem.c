#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

typedef struct line
{
    char *d, *t;
    char *condition;
    char *mes, *key, *res;
    struct line *next;
}
LINE;

void colour(int);
int mainmenu();
void encryption();
void decryption();
void getstr(char *, int *, int);
void merge(char *);
void process(char *, char *, char *, int);
void writelog(char *, char *, char *, int);
void readlog();

int main()
{
    int selected;
    selected = mainmenu(); //User Decision
    switch (selected) //Function switching
    {
        case 0:
            encryption();
            break;
        case 1:
            decryption();
            break;
        case 2:
            readlog();
    }
}

void colour(int col)
{
    HANDLE colout;
    colout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colout, col); //4 for red, and 7 for white
}

int mainmenu()
{
    int selected = -1;
    while (selected < 0)
    {
        printf("----------------Coding System---------------\n");
        printf("0 --- Encryption            1 --- Decryption\n");
        printf("2 --- Read logs\n");
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
        if (selected >= 3)
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
    char *key = (char *)calloc(53, sizeof(char)); //2 * 26 + 1
    char *mes = (char *)calloc(201, sizeof(char)); //200 + 1
    char *res = (char *)calloc(201, sizeof(char));
    int keystatus = -1, messtatus = -1; //Initiate string status as not set (default)
    while (keystatus < 0) //Waiting for valid key
    {
        printf("---------------Encryption Mode---------------\n");
        getstr(key, &keystatus, 0); //Initiate key
        if (keystatus < 0) //Clear screen if failed
            system("cls");
    }
    merge(key);
    printf("Please confirm your key: %s\n", key);
    system("pause");
    system("cls");
    while (messtatus < 0) //Waiting for valid message
    {
        printf("---------------Encryption Mode---------------\n");
        getstr(mes, &messtatus, 1); //Initiate message
        if (messtatus < 0) //Clear screen if failed
            system("cls");
    }
    process(mes, key, res, 0); //Process encryption, 0 for encryption
    system("cls");
    printf("---------------Encryption Mode---------------\n");
    printf("Encrypted message: %s\n", res);
    system("pause");
}

void decryption()
{
    system("cls");
    char *key = (char *)calloc(53, sizeof(char)); //2 * 26 + 1
    char *mes = (char *)calloc(201, sizeof(char)); //200 + 1
    char *res = (char *)calloc(201, sizeof(char));
    int keystatus = -1, messtatus = -1; //Initiate string status as not set (default)
    while (keystatus < 0) //Waiting for valid key string
    {
        printf("---------------Decryption Mode---------------\n");
        getstr(key, &keystatus, 0); //Initiate key
        if (keystatus < 0) //Clear screen if failed
            system("cls");
    }
    merge(key);
    printf("Please confirm your key: %s\n", key);
    system("pause");
    system("cls");
    while (messtatus < 0) //Waiting for valid message
    {
        printf("---------------Decryption Mode---------------\n");
        getstr(mes, &messtatus, 1); //Initiate message
        if (messtatus < 0) //Clear screen if failed
            system("cls");
    }
    process(mes, key, res, 1); //Process decryption, 1 for decryption
    system("cls");
    printf("---------------Decryption Mode---------------\n");
    printf("Decrypted message: %s\n", res);
    system("pause");
}

void getstr(char *str, int *strstatus, int condition)
{
    switch (*strstatus) //Notice varies based on strstatus
    {
        case -1:
            if (condition == 0)
                printf("Please type in your key in ");
            else if (condition == 1)
                printf("Please type in your message in ");
            colour(4); //Trun the texts into red
            printf("LOWERCASE\nNO SPACE, SPECIAL SIGNAL OR NUMBER ALLOWED\n");
            colour(7); //Turn the texts back to white
            if (condition == 0)
                printf("Key: ");
            else if (condition == 1)
                printf("Message: ");
            scanf("%s", str);
            break;
        case -2:
            colour(4);
            printf("Invalid: Uppercase detected\n");
            colour(7);
            if (condition == 0)
            {
                printf("Please type in your key again\n");
                printf("Key: ");
            }
            else if (condition == 1)
            {
                printf("Please type in your message again\n");
                printf("Message: ");
            }
            scanf("%s", str);
            break;
        case -3:
            colour(4);
            printf("Invalid: Special signal detected\n");
            colour(7);
            if (condition == 0)
            {
                printf("Please type in your key again\n");
                printf("Key: ");
            }
            else if (condition == 1)
            {
                printf("Please type in your message again\n");
                printf("Message: ");
            }
            scanf("%s", str);
            break;
        case -4:
            colour(4);
            printf("Invalid: Number detected\n");
            colour(7);
            if (condition == 0)
            {
                printf("Please type in your key again\n");
                printf("Key: ");
            }
            else if (condition == 1)
            {
                printf("Please type in your message again\n");
                printf("Message: ");
            }
            scanf("%s", str);
            break;
    }
    *strstatus = 0; //Assumption that the string is valid
    for (int i = 1; ; i += 1) //String validation
    {
        if (*(str + i - 1) == 0) //Stop at the end of the string
            break;
        else if (*(str + i - 1) >= 48 && *(str + i - 1) <= 57) //Invalid: Number
        {
            *strstatus = -4;
            break;
        }
        if (*(str + i - 1) >= 65 && *(str + i - 1) <= 90) //Invalid: Uppercase
        {
            *strstatus = -2;
            break;
        }
        else if (*(str + i - 1) < 65 || *(str + i - 1) > 122) //Invalid: Special signal
        {
            *strstatus = -3;
            break;
        }
    }
}

void merge(char *key)
{
    for (int i = 1; ; i += 1)
    {
        char check = *(key + i - 1);
        if (check == 0) //Stop at the end of string
            break;
        for (int k = i + 1; ; k += 1)
        {
            if (check == *(key + k - 1)) //Search for repeating characters
            {
                *(key + k - 1) = 0; //Turn the repeating character into a blank
                strcat(key, (key + k)); //Remove the blank
                k -= 1; //Roll back to previous character
            }
            if (*(key + k) == 0) //Stop at the end of string
                break;
        }
    }
}

void process(char *mes, char *key, char *res, int condition)
{
    int keysize;
    keysize = strlen(key);
    switch (condition)
    {
        case 0: //Encryption
            for (int i = 1; ; i += 1)
            {
                if (*(mes + i - 1) == 0) //Stop at the end of message
                    break;
                int result = 0;
                result = (int)*(mes + i - 1) + (int)*(key + (i - 1) % keysize) - 97; //res = mes + key - 97
                if (result > 122)
                    result = result - 26;
                *(res + i - 1) = (char)result;
            }
            break;
        case 1: //Decryption
            for (int i = 1; ; i += 1)
            {
                if (*(mes + i - 1) == 0) //Stop at the end of message
                    break;
                int result = 0;
                result = (int)*(mes + i - 1) - (int)*(key + (i - 1) % keysize) + 97; //res = mes - key + 97
                if (result < 97)
                    result = result + 26;
                *(res + i - 1) = (char)result;
            }
            break;
    }
    writelog(mes, key, res, condition);
}

void writelog(char *mes, char *key, char *res, int condition)
{
    FILE *WRITELOG;
    WRITELOG = fopen("logs.txt", "a+b");
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    int year = local -> tm_year + 1900;
    int month = local -> tm_mon + 1;
    int day = local -> tm_mday;
    int hour = local -> tm_hour;
    int min = local -> tm_min;
    int sec = local -> tm_sec;
    fprintf(WRITELOG, "%d/%02d/%02d %02d:%02d:%02d ", year, month, day, hour, min, sec);
    switch (condition)
    {
        case 0:
            fprintf(WRITELOG, "ENCRYPTION ");
            break;
        case 1:
            fprintf(WRITELOG, "DECRYPTION ");
            break;
    }
    fprintf(WRITELOG, "%s %s %s\n", mes, key, res);
}

void readlog()
{
    FILE *READLOG;
    READLOG = fopen("logs.txt", "rb");
    LINE *head, *local;
    local = (LINE *)calloc(1, sizeof(LINE));
    head = local;
    while (1)
    {
        local -> d = calloc(11, sizeof(char));
        local -> t = calloc(9, sizeof(char));
        local -> condition = calloc(11, sizeof(char));
        local -> mes = calloc(201, sizeof(char));
        local -> key = calloc(53, sizeof(char));
        local -> res = calloc(201, sizeof(char));
        fscanf(READLOG, "%s", local -> d);
        fscanf(READLOG, "%s", local -> t);
        fscanf(READLOG, "%s", local -> condition);
        fscanf(READLOG, "%s", local -> mes);
        fscanf(READLOG, "%s", local -> key);
        fscanf(READLOG, "%s", local -> res);
        READLOG->_ptr += 1;
        if (*(READLOG->_ptr) == 0)
        {
            local -> next = NULL;
            break;
        }
        else
        {
            local -> next = (LINE *)calloc(1, sizeof(LINE));
            local = local -> next;
        }
    }
    local = head;
    system("cls");
    while (1)
    {
        printf("%s %s ", local -> d, local -> t);
        printf("%s ", local -> condition);
        printf("%s %s %s\n", local -> mes, local -> key, local -> res);
        if (local -> next == NULL)
            break;
        else
            local = local -> next;
    }
    system("pause");
}