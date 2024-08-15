#include "Settings"
#include "GeneralInterface"
#include "DecisionSupport"

int main()
{
    preset();
    
    switch (makeDecision())
    {
    case Decision::ENCRYPTION:
        encryption();
        break;

    case Decision::DECRYPTION:
        decryption();
        break;

    case Decision::LOGS:
        displayLogs();
        break;

    case Decision::SETTINGS:
        settings();
        break;

    default: break;
    }
    
    return 0;
}
