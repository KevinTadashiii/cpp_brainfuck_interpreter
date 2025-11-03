#include "../../include/utils/clean_the_code.h"

#include <array>
#include <string>

using namespace std;

string clean_the_code(string &raw_code) {
    array<char, 8> valid_characters = {'<', '>', '+', '-', '.', ',', '[', ']'};

    for (int i = 0; i < raw_code.length(); i++) {
        if (ranges::find(valid_characters, raw_code[i]) == end(valid_characters)) {
            raw_code.erase(i, 1);
            i--;
        }
    }
    string clean_code = raw_code;

    return clean_code;
}