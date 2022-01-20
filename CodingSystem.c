#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define MODE_EN 0 //Main Menu: Encryption Mode
#define MODE_DE 1 //Main Menu: Decryption Mode
#define MODE_LOG 2 //Main Menu: Logs Mode
#define MODE_EX 3 //Main Menu: Exit programme
#define RED 4
#define WHITE 7
#define INVALID_DEFAULT -1 //Default value for invalid status
#define INVALID_IE -2 //Invalid: Input Exceeded
#define INVALID_SPEC -3 //Invalid: Special character
#define INVALID_NUM -4 //Invalid: Number
#define VALID 0 //Default value for valid status
#define MODE_KEY 0 //Get String: Key
#define MODE_MES 1 //Get String: Message
#define MAX_KEY 53 //Maximum length of keys: 2 * 26 + 1
#define MAX_STR 201 //Maximum length of strings: 200 + 1
#define EOS 0 //End of a string

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

void colour(int);
void notice(char *);
int mainmenu(); //Display mainmenu
void encryption(); //Encryption preparation
void decryption(); //Decryption preparation
void getstr(char *, int *, int); //Get string from stdin
void tolow(char *); //Turn all the uppercases into lowercases
void merge(char *); //Merge all the repeating characters in a string
void process(char *, char *, char *, int); //Process encryption or decryption, 0 for encryption, 1 for decryption
void writelog(char *, char *, char *, int); //Write logs into logs.txt
void readlog(); //Read logs from logs.txt

int main()
{
    while (TRUE)
    {
        int decision = mainmenu();
        switch (decision)
        {
            case MODE_EN:
                encryption();
                break;
            case MODE_DE:
                decryption();
                break;
            case MODE_LOG:
                readlog();
                break;
            case MODE_EX:
                system("cls");
                printf("Programme Exited\n");
                system("pause");
                exit(EXIT_SUCCESS);
        }
    }
}

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
        printf("2 --- Read logs             3 --- Exit\n");
        switch (status)
        {
            case INVALID_DEFAULT:
                printf("Please type in the number attached to your option\n");
                break;
            case INVALID_IE:
                notice("Invalid option input\n");
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

void getstr(char *str, int *strstatus, int condition)
{
    switch (*strstatus) //Notice varies based on strstatus
    {
        case INVALID_DEFAULT:
            if (condition == MODE_KEY)
                printf("Please type in your key in ");
            else if (condition == MODE_MES)
                printf("Please type in your message in ");
            notice("English\nALL CHARCTERS AFTER THE FIRST SPACE WILL BE IGNORED\n");
            notice("NO SPECIAL CHARACTERS OR NUMBER ALLOWED\n");
            if (condition == MODE_KEY)
                printf("Key: ");
            else if (condition == MODE_MES)
                printf("Message: ");
            scanf("%s", str);
            fflush(stdin);
            break;
        case INVALID_SPEC:
            notice("Invalid: Special character detected\n");
            if (condition == MODE_KEY)
            {
                printf("Please type in your key again\n");
                printf("Key: ");
            }
            else if (condition == MODE_MES)
            {
                printf("Please type in your message again\n");
                printf("Message: ");
            }
            scanf("%s", str);
            fflush(stdin);
            break;
        case INVALID_NUM:
            notice("Invalid: Number detected\n");
            if (condition == MODE_KEY)
            {
                printf("Please type in your key again\n");
                printf("Key: ");
            }
            else if (condition == MODE_MES)
            {
                printf("Please type in your message again\n");
                printf("Message: ");
            }
            scanf("%s", str);
            fflush(stdin);
            break;
    }
    *strstatus = VALID; //Preset that the string is valid
    for (int i = 1; ; i += 1) //String validation
    {
        if (*(str + i - 1) == EOS) //Stop at the end of the string
            break;
        else if (*(str + i - 1) >= '0' && *(str + i - 1) <= '9') //Invalid: Number
        {
            *strstatus = INVALID_NUM;
            break;
        }
        else if (!((*(str + i - 1) >= 'A' && *(str + i - 1) <= 'Z') || (*(str + i - 1) >= 'a' && *(str + i - 1) <= 'z'))) //Invalid: Special character
        {
            *strstatus = INVALID_SPEC;
            break;
        }
    }
}

void tolow(char *str)
{
    for (int i = 1; ; i += 1)
    {
        if (*(str + i - 1) == EOS)
            break;
        if (*(str + i - 1) >= 'A' && *(str + i - 1) <= 'Z')
            *(str + i - 1) += 32;
    }
}

void merge(char *key)
{
    for (int i = 1; ; i += 1)
    {
        char check = *(key + i - 1);
        if (check == EOS) //Stop at the end of string
            break;
        for (int k = i + 1; ; k += 1)
        {
            if (*(key + k - 1) == EOS) //Stop at the end of string
                break;
            if (check == *(key + k - 1)) //Search for repeating character
            {
                *(key + k - 1) = EOS; //Break the string at that character
                strcat(key, (key + k)); //Connect two strings
                k -= 1; //Roll back to previous character
            }
        }
    }
}

void process(char *mes, char *key, char *res, int condition)
{
    int keysize = strlen(key);
    switch (condition)
    {
        case MODE_EN:
            for (int i = 1; ; i += 1)
            {
                if (*(mes + i - 1) == EOS) //Stop at the end of message
                    break;
                int result = (int)*(mes + i - 1) + (int)*(key + (i - 1) % keysize) - 97; //res = mes + key - 97
                if (result > 'z')
                    result = result - 26;
                *(res + i - 1) = (char)result;
            }
            break;
        case MODE_DE:
            for (int i = 1; ; i += 1)
            {
                if (*(mes + i - 1) == EOS) //Stop at the end of message
                    break;
                int result = (int)*(mes + i - 1) - (int)*(key + (i - 1) % keysize) + 97; //res = mes - key + 97
                if (result < 'a')
                    result = result + 26;
                *(res + i - 1) = (char)result;
            }
            break;
    }
    writelog(mes, key, res, condition);
}

void writelog(char *mes, char *key, char *res, int condition)
{
    FILE *WRITELOG = fopen("logs.txt", "a+b");
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
        case MODE_EN:
            fprintf(WRITELOG, "ENCRYPTION ");
            break;
        case MODE_DE:
            fprintf(WRITELOG, "DECRYPTION ");
            break;
    }
    fprintf(WRITELOG, "%s %s %s\n", mes, key, res);
    fclose(WRITELOG);
}

void readlog()
{
    system("cls");
    FILE *READLOG = fopen("logs.txt", "rb");
    if (READLOG == NULL)
    {
        notice("No logs file detected\n");
        system("pause");
        return;
    }
    NODE *head, *local;
    local = (NODE *)calloc(1, sizeof(NODE));
    head = local;
    while (TRUE)
    {
        local -> d = calloc(11, sizeof(char));
        local -> t = calloc(9, sizeof(char));
        local -> condition = calloc(11, sizeof(char));
        local -> mes = calloc(MAX_STR, sizeof(char));
        local -> key = calloc(MAX_KEY, sizeof(char));
        local -> res = calloc(MAX_STR, sizeof(char));
        fscanf(READLOG, "%s", local -> d);
        fscanf(READLOG, "%s", local -> t);
        fscanf(READLOG, "%s", local -> condition);
        fscanf(READLOG, "%s", local -> mes);
        fscanf(READLOG, "%s", local -> key);
        fscanf(READLOG, "%s", local -> res);
        READLOG->_ptr += 1;
        if (*(READLOG->_ptr) == EOS)
        {
            local -> next = NULL;
            break;
        }
        else
        {
            local -> next = (NODE *)calloc(1, sizeof(NODE));
            local = local -> next;
        }
    }
    printf("Example: yyyy/mm/dd hh:mm:ss mode mes --key--> res\n");
    local = head;
    while (TRUE)
    {
        printf("%s %s ", local -> d, local -> t);
        printf("%s ", local -> condition);
        printf("%s --%s--> %s\n", local -> mes, local -> key, local -> res);
        if (local -> next == NULL)
            break;
        else
            local = local -> next;
    }
    fclose(READLOG);
    system("pause");
}