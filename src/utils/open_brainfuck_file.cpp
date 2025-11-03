#include "../../include/utils/open_brainfuck_file.h"

#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;

string open_brainfuck_file(int argc, char **argv) {
    if (argc > 1) {
        string filename = argv[1];
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            return "";
        }

        stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();

    } else {
        cerr << "Usage : {program} {brainfuck file}" << endl;
        return "";
    }
}

int is_file_valid(const string &raw_code) {
    if (raw_code.empty()) {
        cerr << "No valid Brainfuck code loaded. Exiting program.\n";
        return 1;
    }
    return 0;
}
