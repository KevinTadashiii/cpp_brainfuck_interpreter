#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    string raw_code, clean_code;
    array<char, 8> valid_characters = {'<', '>', '+', '-', '.', ',', '[', ']'};

    if (argc > 1) {
        string filename = argv[1];
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            return 1;
        }

        stringstream buffer;
        buffer << file.rdbuf();
        raw_code = buffer.str();

    } else {
        cerr << "Usage : {program} {brainfuck file}";
        return 1;
    }

    for (int i = 0; i <= raw_code.length(); i++) {
        if (ranges::find(valid_characters, raw_code[i]) == end(valid_characters)) {
            raw_code.erase(i, 1);
            i--;
        }
    }

    clean_code = raw_code;
}