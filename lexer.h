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
  void identifier();
  bool is_alpha_numeric(char);
  char peek_next();
  void number();
  bool isdigit(char);
  bool isalpha(char);
  char peek();
  bool match(char);
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
