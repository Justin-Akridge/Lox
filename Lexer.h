#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace Lox {

struct Token {
  int data;
};

struct Scanner {
  std::vector<Token> scan_tokens() {};
};

class Lexer {
  public:
    static void run_file(const std::string& path);
    static void run_prompt();
    static void run(const std::string& source);
    static void error(int line, std::string& message);
    static void report(int line, std::string where, std::string& message);
    static bool had_error;
};

} 

