#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#include "custom_def.h"
#include "f_display.h"
#include "f_process.h"

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
            notice("Invalid: Special Character\n");
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
            notice("Invalid: Number\n");
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
    for (int i = 1; *(str + i - 1) != EOS; i += 1) //String validation
    {
        if (*(str + i - 1) >= '0' && *(str + i - 1) <= '9') //Invalid: Number
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
    for (int i = 1; *(str + i - 1) != EOS; i += 1)
    {
        if (*(str + i - 1) >= 'A' && *(str + i - 1) <= 'Z')
            *(str + i - 1) += 32;
    }
}

void merge(char *key)
{
    for (int i = 1; *(key + i - 1) != EOS; i += 1)
    {
        char check = *(key + i - 1);
        for (int k = i + 1; *(key + k - 1) != EOS; k += 1)
        {
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
            for (int i = 1; *(mes + i - 1) != EOS; i += 1)
            {
                int result = (int)*(mes + i - 1) + (int)*(key + (i - 1) % keysize) - 97; //res = mes + key - 97
                if (result > 'z')
                    result = result - 26;
                *(res + i - 1) = (char)result;
            }
            break;
        case MODE_DE:
            for (int i = 1; *(mes + i - 1) != EOS; i += 1)
            {
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