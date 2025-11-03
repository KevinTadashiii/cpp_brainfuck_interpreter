#pragma once
#include <string>

using namespace std;

string open_brainfuck_file(int argc, char **argv);
int is_file_valid(const string &raw_code);
