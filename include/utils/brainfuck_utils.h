#pragma once
#include <string>
#include <unordered_map>

std::pair<std::unordered_map<int,int>, std::unordered_map<int,int>>
build_bracket_map(const std::string& clean_code);