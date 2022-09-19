#include <iostream>
#include <cstdlib>

#include "../include/Settings"
#include "../include/Main_Menu"
#include "../include/Encryption"

using namespace std;

extern GlobalSet global;

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