#pragma once

#include "token-type.h"
#include <string>

namespace Lox {

class Token {
public:
  Token(Token_Type type, const std::string lexeme, std::string literal, int line);
  std::string token_type_to_string(Token_Type type);
  std::string to_string();
  
  Token_Type type;
  std::string lexeme;
  std::string literal;
  int line;
};

}
