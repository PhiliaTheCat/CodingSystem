// Don't forget to free(the returned char*)
#define _CRT_SECURE_NO_WARNINGS
#define WITH_MAIN 0

#include <stdio.h>
#include <stdlib.h>

#if WITH_MAIN
#include <ctype.h>
#endif

#define EXIT_CHECK(pointer, str_sentence) \
    if (pointer == NULL)                  \
    {                                     \
        puts(str_sentence);               \
        puts("Programe will exit.");      \
        system("PAUSE");                  \
        exit(EXIT_FAILURE);               \
    }

/*need pre-declared "int  i" and "char alone"*/
#define STR_SUBTRACT(str, source, end_sign)                 \
    i = 0;                                                  \
    while (1)                                               \
    {                                                       \
        alone = source;                                     \
        str = (char *)realloc(str, (i + 1) * sizeof(char)); \
        EXIT_CHECK(str, #str "ALLOC FAILED")                \
        if (alone != end_sign)                              \
            str[i] = alone;                                 \
        else                                                \
        {                                                   \
            str[i] = '\0';                                  \
            break;                                          \
        }                                                   \
        i++;                                                \
    }

char *read_file(void)
{
    FILE *src_file;
    char *directory = NULL, *content = NULL;
    char alone;
    int i;

    puts("Enter the direcory to the source file pls:");

    STR_SUBTRACT(directory, getchar(), '\n')

    src_file = fopen(directory, "r");
    free(directory);
    EXIT_CHECK(src_file, "FILE OPEN FAILED");

    STR_SUBTRACT(content, fgetc(src_file), EOF)

    EXIT_CHECK((void *)(!fclose(src_file)), "FILE CLOSE FAILED")

    puts("The content of the file is shown as follows:");
    puts("\n");

    puts(content);
    puts("\n");

    return content;
}

#if WITH_MAIN
int main()
{
    char choice;

    while (1)
    {
        read_file();
        puts("Read another file?(Y/N)");
        choice = toupper(getchar());
        if (choice == 'Y')
        {
            system("CLS");
            setbuf(stdin, NULL);
        }
        else if (choice == 'N')
        {
            EXIT_CHECK(NULL, NULL)
        }
        else
            EXIT_CHECK(NULL, "Wrong input, down to default:exit")
    }
}
#endif
