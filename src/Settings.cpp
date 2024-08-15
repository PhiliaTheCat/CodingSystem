#include <fstream>
#include <limits>

#include "Settings"

void preset()
{
    std::ifstream fin;
    fin.open("./settings/presettings.txt");

    fin >> global.max_key >> global.max_str >> global.logs_sequence;
    fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    fin.close();
}
