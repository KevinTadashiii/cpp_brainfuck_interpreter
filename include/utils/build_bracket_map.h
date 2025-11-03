#pragma once
#include <string>
#include <unordered_map>

using namespace std;

pair<unordered_map<int,int>, unordered_map<int,int>>
build_bracket_map(const string& clean_code);