#include <iostream>

#include "../include/Settings"

using namespace std;

extern GlobalSet global;

int main()
{
    Preset();
    cout << global.max_key << endl;
    cout << global.max_str << endl;
    cout << global.logs_seque << endl;
}