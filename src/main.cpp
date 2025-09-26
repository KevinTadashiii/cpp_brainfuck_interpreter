#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

pair<unordered_map<int,int>, unordered_map<int,int>>
build_bracket_map(const string& clean_code) {
    stack<int> bracket_stack;
    unordered_map<int, int> jump_fwd;
    unordered_map<int, int> jump_bwd;

    for (int i = 0; i < clean_code.length(); i++) {
        if (clean_code[i] == '[') {
            bracket_stack.push(i);
        } else if (clean_code[i] == ']') {
            if (bracket_stack.empty()) {
                throw runtime_error("Unmatched ']' at position " + to_string(i));
            }
            int j = bracket_stack.top();
            bracket_stack.pop();
            jump_fwd[j] = i;
            jump_bwd[i] = j;
        }
    }
    if (!bracket_stack.empty()) {
        throw runtime_error("Unmatched '[' at position " + to_string(bracket_stack.top()));
    }
    return {jump_fwd, jump_bwd};
}

int main(int argc, char* argv[]) {
    string raw_code, clean_code;
    array<char, 8> valid_characters = {'<', '>', '+', '-', '.', ',', '[', ']'};
    int tape[30000] = {0};
    int pointer = 0;
    int pc = 0;

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

    for (int i = 0; i < raw_code.length(); i++) {
        if (ranges::find(valid_characters, raw_code[i]) == end(valid_characters)) {
            raw_code.erase(i, 1);
            i--;
        }
    }

    clean_code = raw_code;

    auto [jump_fwd, jump_bwd] = build_bracket_map(clean_code);
    while (pc < clean_code.length()) {
        char instr = clean_code[pc];

        if (instr == '>') {
            if (pointer == 30000 - 1) {
                pointer = 0;
            } else {
                pointer++;
            }
            pc++;
        }

        if (instr == '<') {
            if (pointer == 0) {
                pointer = 30000 - 1;
            } else {
                pointer--;
            }
            pc++;
        }

        if (instr == '+') {
            tape[pointer] = (tape[pointer] + 1) % 256;
            pc++;
        }

        if (instr == '-') {
            tape[pointer] = (tape[pointer] - 1 + 256) % 256;
            pc++;
        }

        if (instr == '.') {
            cout << static_cast<char>(tape[pointer]) << flush;
            pc++;
        }

        if (instr == ',') {
            char c;
            cin.get(c);
            tape[pointer] = static_cast<unsigned char>(c);
            pc++;
        }

        if (instr == '[') {
            if (tape[pointer] == 0) {
                pc = jump_fwd[pc] + 1;
            } else {
                pc++;
            }
        }

        if (instr == ']') {
            if (tape[pointer] != 0) {
                pc = jump_bwd[pc];
            } else {
                pc++;
            }
        }
    }
}