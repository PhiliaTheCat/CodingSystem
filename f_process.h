/*
    This header file is for function declarations connected to process
    All relative declarations should be here (or in other header files with clear notifications)
*/
#ifndef F_PROCESS_INCLUDED
    #define F_PROCESS_INCLUDED

    void getstr(char *, int *, int); //Get string from stdin

    void tolow(char *); //Turn all the uppercases into lowercases

    void merge(char *); //Merge all the repeating characters in a string

    void process(char *, char *, char *, int); //Process encryption or decryption, 0 for encryption, 1 for decryption

    void writelog(char *, char *, char *, int); //Write logs into logs.txt
#endif