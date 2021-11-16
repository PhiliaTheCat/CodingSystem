#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void inikey(char *);
void merge(char *);
int main()
{
    char *key = (char *)calloc(27, sizeof(char));
    inikey(key);
    int keysize = strlen(key);
}

void inikey(char *key)
{
    printf("Please type in your key\nONE WORD ONLY\nNO SPECIAL SIGNAL ALLOWED\nKey: ");
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