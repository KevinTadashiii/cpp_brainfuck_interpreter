//
// Created by abay on 03/11/2025.
//

#include "../include/interpreter.h"

#include <string>
#include <iostream>

#include "utils/build_bracket_map.h"

using namespace std;

void interpret(const string &clean_code) {
    int tape[30000] = {0};
    int pointer = 0;
    int pc = 0;

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
