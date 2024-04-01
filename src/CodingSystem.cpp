#include "../include/Settings"
#include "../include/Main_Menu"
#include "../include/Encryption"

Global_Settings global;

using namespace std;

int main()
{
    Preset();

    Decision decision = Make_Decision();
    
    switch (decision)
    {
    case Decision::DECISION_ENCRYPTION:
        Encryption();
        break;

    case Decision::DECISION_DECRYPTION:
        Decryption();
        break;

    case Decision::DECISION_LOGS:

    case Decision::DECISION_SETTINGS:

    default:;
    }
    
    return 0;
}
