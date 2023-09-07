#include <fstream>
#include <limits>

#include "../include/Settings" 

using namespace std;

Global_Settings global;

void Preset()
{
    ifstream fin;
    fin.open("./settings/presettings.txt");
    fin >> global.max_key >> global.max_str >> global.logs_sequence;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');
    fin.close();
    return;
}
