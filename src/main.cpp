#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    string program;
    string filename;

    if (argc > 1) {
        filename = argv[1];
        ifstream file(filename);

        if (!file.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            return 1;
        }

        stringstream buffer;
        buffer << file.rdbuf();
        program = buffer.str();

    } else {
        cerr << "Usage : {program} {brainfuck file}";
        return 1;
    }

    cout << "Successfully read " << program.size() << " characters from " << filename << endl;
}