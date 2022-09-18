#include <iostream>
#include <cstdlib>

#include "../include/Settings"
#include "../include/Main_Menu"
#include "../include/Encryption"

using namespace std;

extern GlobalSet global;

const int DECISION_ENCRYPTION = 0;
const int DECISION_DECRYPTION = 1;
const int DECISION_LOGS = 2;
const int DECISION_SETTINGS = 3;
const int DECISION_EXIT = 4;

int main()
{
    Preset();

    int decision = Make_Decision();
    
    switch (decision)
    {
        case DECISION_ENCRYPTION:
            Encryption();
            break;
    }
}