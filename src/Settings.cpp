#include <fstream>

#include "../include/Settings" 

using namespace std;

GlobalSet global;

void Preset()
{
    ifstream fin;
    fin.open("settings/presettings.txt");
    fin >> global.max_key >> global.max_str >> global.logs_seque;
    fin.close();
}