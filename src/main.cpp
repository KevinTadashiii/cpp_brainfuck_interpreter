#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
    string raw_code, clean_code;
    array<char, 8> valid_characters = {'<', '>', '+', '-', '.', ',', '[', ']'};
    stack<int> bracket_stack;
    map<int, int> jump_fwd;
    map<int, int> jump_bwd;

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

    for (int i = 0; i <= clean_code.length(); i++) {
        if (clean_code[i] == '[') {
            bracket_stack.push(i);
        } else if (clean_code[i] == ']') {
            if (bracket_stack.empty()) {
                cerr << "Unmatched ']' at position" << i << endl;
                return 1;
            }
            int j = bracket_stack.top();
            jump_fwd[j] = i;
            jump_bwd[i] = j;
        }
    }
    if (!bracket_stack.empty()) {
        cerr << "Unmatched ']' at position " << bracket_stack.top() << endl;
    }
}