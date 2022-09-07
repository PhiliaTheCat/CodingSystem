//Don't forget to free(the returned char*)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>

#define EXIT_CHECK(pointer, str_sentence) \
    if (pointer == NULL)                  \
    {                                     \
        puts(str_sentence "!!!");         \
        puts("Programe will exit.");      \
        system("PAUSE");                  \
        exit(EXIT_FAILURE);               \
    }

char *read_file(void)
{
    FILE *src_file;
    char *directory = NULL, *content = NULL;
    char alone;
    int i;
    puts("Enter the direcory to the source file pls:");

    i = 0;
    while (1)
    {
        alone = getchar();
        directory = (char *)realloc(directory, (i + 1) * sizeof(char));
        EXIT_CHECK(directory, "ALLOC FAILED")
        if (alone != '\n')
            directory[i] = alone;
        else
        {
            directory[i] = '\0';
            break;
        }
        i++;
    }

    src_file = fopen(directory, "r");
    free(directory);
    EXIT_CHECK(src_file, "FILE OPEN FAILED");

    i = 0;
    while ((alone = fgetc(src_file)) != EOF)
    {
        content = (char *)realloc(content, (i + 1) * sizeof(char));
        EXIT_CHECK(content, "ALLOC FAILED")
        content[i] = alone;
        i++;
    }
    content[i] = '\0';
    puts("The content of the file is shown as follows:");
    puts("\n");

    puts(content);
    puts("\n");

    return content;
}