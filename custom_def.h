/*
    This header file is for custom definitions
    All custom definations should be here (or in other header files with clear notifications)
*/
#ifndef CUSTOM_DEF_INCLUDED
    #define CUSTOM_DEF_INCLUDED
    
    #define MODE_EN 0 //Main Menu: Encryption Mode
    #define MODE_DE 1 //Main Menu: Decryption Mode
    #define MODE_LOG 2 //Main Menu: Logs Mode
    #define MODE_SET 3 //Main Menu: Settings
    #define MODE_EX 4 //Main Menu: Exit programme

    #define RED 4
    #define WHITE 7

    #define INVALID_DEFAULT -1 //Default value for invalid status
    #define INVALID_IE -2 //Invalid: Input Exceeded
    #define INVALID_SPEC -3 //Invalid: Special character
    #define INVALID_NUM -4 //Invalid: Number

    #define VALID 0 //Default value for valid status

    #define MODE_KEY 0 //Get String: Key
    #define MODE_MES 1 //Get String: Message

    #define MAX_KEY (global.max_key + 1) //Maximum memory size of keys
    #define MAX_STR (global.max_str + 1) //Maximum memory size of strings

    #define EOS 0 //End of a string

    #define SEQUE_TIME_DE 0 //Logs Reading Sequence: Timestamp Decreasing (Default)
    #define SEQUE_TIME_IN 1 //Logs Reading Sequence: Timestamp Increasing
#endif

struct setting
{
    int max_key;
    int max_str;
    int logs_seque;
}
global;