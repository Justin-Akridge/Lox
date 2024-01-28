#include "lexer.h"
#include <iostream>
#include <fstream>
#include <sstream>
// TODO [_] create a reporter class for reporting errors
namespace Lox {

bool Lexer::had_error = false;

void Lexer::run_file(const std::string& path) {
  std::ifstream file(path);
  if (!file.is_open()) {
    std::cerr << "Error: could not open file " << path << '\n';
    exit(1);
  }
    
  std::stringstream buffer;
  buffer << file.rdbuf();
  run(buffer.str());

  if (had_error) {

    exit(65);
  }
}

void Lexer::run_prompt() {
  for (;;) {
    std::cout << "> ";
    std::string line;
    std::getline(std::cin, line);

    if (std::cin.eof()) {
      break;
    }
    run(line);
    had_error = false;
  }
}

void Lexer::run(const std::string& source) {
  Scanner scanner;
  std::vector<Token> tokens = scanner.scan_tokens();

  for (Token &token : tokens) {
    std::cout << token.data << '\n';
  }
}


void Lexer::error(int line, std::string &message) {
  // TODO [_] convert string to variable, pass address through reporter
  report(line, "", message);
}

void Lexer::report(int line, std::string where, std::string& message) {
  std::cout << "[line " + std::to_string(line) + "] Error" + where + ": " + message;
}
}
