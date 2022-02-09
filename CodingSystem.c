#include <stdio.h>
#include <windows.h>
#include "custom_def.h"
#include "f_display.h"
#include "f_settings.h"

int main()
{
    preset();
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
            //case MODE_SET:
                //settings();
                //break;
            case MODE_EX:
                system("cls");
                printf("Programme Exited\n");
                system("pause");
                exit(EXIT_SUCCESS);
        }
    }
}

void preset()
{
    global.max_key = 52; //2 * 26
    global.max_str = 200;
    global.logs_seque = SEQUE_TIME_DE;
}