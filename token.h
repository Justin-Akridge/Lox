#pragma once

#include "token-type.h"
#include <string>

namespace Lox {

class Token {
public:
  // Java uses Object for lexeme and literal, here I am using string. Converions of numbers may happen later.
  // Might need to use a template here to detinguish between number and string
  Token(Token_Type type, const std::string lexeme, std::string literal, int line);
  std::string token_type_to_string(Token_Type type);
  std::string to_string();
  
  Token_Type type;
  std::string lexeme;
  std::string literal;
  int line;
};

}
