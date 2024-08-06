#include "Settings"
#include "GeneralInterface"
#include "DecisionSupport"

using namespace std;

int main()
{
    preset();
    
    switch (makeDecision())
    {
    case Decision::ENCRYPTION:
        encryption();
        break;

    case Decision::DECRYPTION:
        // decryption();
        break;

    case Decision::LOGS:

    case Decision::SETTINGS:

    default:;
    }
    
    return 0;
}
