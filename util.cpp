#include "util.h"
#include "lexer.h"
#include <iostream>
#include <fstream>
#include <sstream>
// TODO [_] create a reporter class for reporting errors
namespace Lox {

bool Util::had_error = false;

void Util::run_file(const std::string& path) {
  std::ifstream file(path);
  if (!file.is_open()) {
    std::cerr << "Error: could not open file " << path << '\n';
    exit(1);
  } else {
    std::cerr << "Success: opened file " << path << '\n';
  }
    
  std::string buffer;
  std::string line;
  while (std::getline(file >> std::ws, line)) {
    buffer += line + '\n';
  }
  std::cout << buffer << std::endl;
  run(buffer);

  if (had_error) {
    exit(65);
  }
}

void Util::run_prompt() {
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

void Util::run(const std::string& source) {
  Lexer lexer(source);
  std::vector<Token> tokens = lexer.scan_tokens();

  for (Token &token : tokens) {
    std::cout << token.to_string() << '\n';
  }
}


void Util::error(int line, std::string message) {
  // TODO [_] convert string to variable, pass address through reporter
  report(line, "", message);
}

void Util::report(int line, std::string where, std::string message) {
  std::cout << "[line " + std::to_string(line) + "] Error" + where + ": " + message;
}
}
