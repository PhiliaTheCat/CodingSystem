#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

#include "custom_def.h"
#include "f_display.h"
#include "f_process.h"

#define _CRT_SECURE_NO_WARNINGS

typedef struct node
{
    char *d; //Date
    char *t; //Time
    char *condition; //Programme mode
    char *mes; //Message
    char *key; //Key
    char *res; //Result
    struct node *next; //Next node
}
NODE;

void colour(int col)
{
    HANDLE colout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(colout, col);
}

void notice(char *string)
{
    colour(RED);
    printf("%s", string);
    colour(WHITE);
}

int mainmenu()
{
    system("cls");
    int decision = INVALID_DEFAULT;
    int status = INVALID_DEFAULT;
    while (status != VALID)
    {
        printf("----------------Coding System---------------\n");
        printf("0 --- Encryption            1 --- Decryption\n");
        printf("2 --- Logs                  3 --- Settings\n");
        printf("4 --- Exit\n");
        switch (status)
        {
            case INVALID_DEFAULT:
                printf("Please type in the number attached to your option\n");
                break;
            case INVALID_IE:
                notice("Invalid: Input Exceeded\n");
                printf("Please type in a number again\n");
                break;
        }
        printf("Option: ");
        scanf("%d", &decision);
        rewind(stdin);
        if (decision < MODE_EN || decision > MODE_EX)
        {
            status = INVALID_IE;
            system("cls");
        }
        else
            status = VALID;
    }
    return decision;
}

void encryption()
{
    system("cls");
    char *key = (char *)calloc(MAX_KEY, sizeof(char));
    char *mes = (char *)calloc(MAX_STR, sizeof(char));
    char *res = (char *)calloc(MAX_STR, sizeof(char));
    int keystatus = INVALID_DEFAULT, messtatus = INVALID_DEFAULT; //Initialize string status
    while (keystatus != VALID)
    {
        printf("---------------Encryption Mode---------------\n");
        getstr(key, &keystatus, MODE_KEY); //Initialize key
        if (keystatus != VALID) //Clear screen if failed
            system("cls");
    }
    system("cls");
    tolow(key);
    merge(key);
    printf("Confirm your key: %s\n", key);
    system("pause");
    system("cls");
    while (messtatus != VALID) //Waiting for valid message
    {
        printf("---------------Encryption Mode---------------\n");
        getstr(mes, &messtatus, MODE_MES); //Initiate message
        if (messtatus != VALID) //Clear screen if failed
            system("cls");
    }
    tolow(mes);
    printf("Confirm the message: %s\n", mes);
    system("pause");
    process(mes, key, res, MODE_EN); //Process encryption, 0 for encryption
    system("cls");
    printf("---------------Encryption Mode---------------\n");
    printf("Encrypted message: %s\n", res);
    system("pause");
}

void decryption()
{
    system("cls");
    char *key = (char *)calloc(MAX_KEY, sizeof(char));
    char *mes = (char *)calloc(MAX_STR, sizeof(char));
    char *res = (char *)calloc(MAX_STR, sizeof(char));
    int keystatus = INVALID_DEFAULT, messtatus = INVALID_DEFAULT; //Initiate string status as not set (default)
    while (keystatus != VALID) //Waiting for valid key string
    {
        printf("---------------Decryption Mode---------------\n");
        getstr(key, &keystatus, MODE_KEY); //Initiate key
        if (keystatus != VALID) //Clear screen if failed
            system("cls");
    }
    system("cls");
    tolow(key);
    merge(key);
    printf("Confirm your key: %s\n", key);
    system("pause");
    system("cls");
    while (messtatus != VALID) //Waiting for valid message
    {
        printf("---------------Decryption Mode---------------\n");
        getstr(mes, &messtatus, MODE_MES); //Initiate message
        if (messtatus != VALID) //Clear screen if failed
            system("cls");
    }
    tolow(mes);
    process(mes, key, res, MODE_DE); //Process decryption, 1 for decryption
    system("cls");
    printf("---------------Decryption Mode---------------\n");
    printf("Decrypted message: %s\n", res);
    system("pause");
}

void readlog()
{
    system("cls");
    printf("----------------------Logs---------------------");
    FILE *READLOG = fopen("logs.txt", "rb");
    if (READLOG == NULL)
    {
        notice("No logs\n");
        system("pause");
        return;
    }
    NODE *temp = NULL;
    do
    {
        NODE *local = (NODE *)calloc(1, sizeof(NODE));
        local -> d = calloc(11, sizeof(char));
        local -> t = calloc(9, sizeof(char));
        local -> condition = calloc(11, sizeof(char));
        local -> mes = calloc(MAX_STR, sizeof(char));
        local -> key = calloc(MAX_KEY, sizeof(char));
        local -> res = calloc(MAX_STR, sizeof(char));
        local -> next = temp;
        fscanf(READLOG, "%s", local -> d);
        fscanf(READLOG, "%s", local -> t);
        fscanf(READLOG, "%s", local -> condition);
        fscanf(READLOG, "%s", local -> mes);
        fscanf(READLOG, "%s", local -> key);
        fscanf(READLOG, "%s", local -> res);
        READLOG -> _ptr += 1;
        temp = local;
    }
    while (*(READLOG -> _ptr) != EOS);
    fclose(READLOG);
    printf("Example: yyyy/mm/dd hh:mm:ss mode mes --key--> res\n");
    NODE *head = temp;
    NODE *local = head;
    while (local != NULL)
    {
        printf("%s %s ", local -> d, local -> t);
        printf("%s ", local -> condition);
        printf("%s --%s--> %s\n", local -> mes, local -> key, local -> res);
        local = local -> next;
    }
    system("pause");
}