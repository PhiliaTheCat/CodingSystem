/*
    This header file is for function declarations connected to display
    All relative declarations should be here (or in other header files with clear notifications)
*/

#ifndef F_DISPLAY_INCLUDED
    #define F_DISPLAY_INCLUDED

    void colour(int); //Change colour of texts

    void notice(char *); //Use red texts to alert

    int mainmenu(); //Display mainmenu

    void encryption(); //Encryption preparation

    void decryption(); //Decryption preparation

    void readlog(); //Read logs from logs.txt
#endif