#include <string>

#include "utils/open_brainfuck_file.h"
#include "utils/clean_the_code.h"
#include "interpreter.h"

using namespace std;

int main(int argc, char *argv[]) {
    string raw_code = open_brainfuck_file(argc, argv);
    is_file_valid(raw_code);

    string clean_code = clean_the_code(raw_code);

    interpret(clean_code);
}
