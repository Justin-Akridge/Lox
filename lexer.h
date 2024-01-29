#pragma once

#include "token-type.h"
#include "token.h"
#include <vector>
#include <string>

namespace Lox {

class Lexer {
public:
  Lexer(std::string source);
  //This function starts the lexing
  std::vector<Token> scan_tokens();

private:
  char peek_next();
  void number();
  bool isdigit(char c);
  char peek();
  bool match(char equal_sign);
  char advance();
  bool is_at_end();
  void read_tokens();
  void string();
  void add_token(Token_Type type);
  void add_token(Token_Type type, std::string literal);

  std::string source;
  std::vector<Token> tokens;
  int start = 0;
  int current = 0;
  int line = 1;
};
}
