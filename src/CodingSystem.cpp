#include <iostream>
#include <fstream>

#include "../include/Settings"
#include "../include/Main_Menu"

using namespace std;

extern GlobalSet global;

int main()
{
    Preset();
    int decision = Make_Decision();
    ofstream fout;
    fout.open("../output.txt");
    fout << decision << endl;
}