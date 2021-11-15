#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *key;
void inikey();
int main()
{
    int a;
    inikey();
}

void inikey()
{
    key = (char *)malloc(sizeof(char) * 26);
    for (int i = 1; i <= 26; i += 1)
    {
        scanf("%c", key + i - 1);
        if (*(key + i - 1) == '\n')
        {
            *(key + i - 1) = '\0';
            break;
        }
    }
    
}