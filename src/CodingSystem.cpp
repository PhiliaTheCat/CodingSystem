#include <iostream>
#include <cstdlib>

#include "../include/Settings"
#include "../include/Main_Menu"
#include "../include/Encryption"

using namespace std;

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
    
    return 0;
}
