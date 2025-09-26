#include "utils/brainfuck_utils.h"

#include <stack>
#include <stdexcept>

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