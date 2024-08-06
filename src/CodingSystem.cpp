#include "Settings"
#include "../include/General_Interface"
#include "../include/Decision_Support"

using namespace std;

int main()
{
    preset();

    Decision decision = Make_Decision();
    
    switch (decision)
    {
    case Decision::DECISION_ENCRYPTION:
        Encryption();
        break;

    case Decision::DECISION_DECRYPTION:
        // Decryption();
        break;

    case Decision::DECISION_LOGS:

    case Decision::DECISION_SETTINGS:

    default:;
    }
    
    return 0;
}
