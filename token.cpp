// When converted add pragma once to header
#include "token-type.h"
#include <string>
#include <iostream>

namespace Lox {

class Token {
public:
  const Token_Type type;
  const std::string lexeme;
  const std::string literal;
  const int line;

  Token(Token_Type type, const std::string& lexeme, std::string& literal, int line)
    : type(type), lexeme(lexeme), literal(literal), line(line) {}

  std::string type_to_string() const {
    switch(type) {
      case Token_Type::LEFT_PARAM: return "LEFT_PARAM";
      case Token_Type::RIGHT_PARAM: return "RIGHT_PARAM";
      // TODO [_] WORK ON THIS
      case Token_Type::LEFT_: return "LEFT_PARAM";
      case Token_Type::LEFT_PARAM: return "LEFT_PARAM";
      case Token_Type::LEFT_PARAM: return "LEFT_PARAM";
      case Token_Type::LEFT_PARAM: return "LEFT_PARAM";
      case Token_Type::LEFT_PARAM: return "LEFT_PARAM";
      case Token_Type::LEFT_PARAM: return "LEFT_PARAM";
      case Token_Type::LEFT_PARAM: return "LEFT_PARAM";
      case Token_Type::LEFT_PARAM: return "LEFT_PARAM";
      case Token_Type::LEFT_PARAM: return "LEFT_PARAM";
      case Token_Type::LEFT_PARAM: return "LEFT_PARAM";
      case Token_Type::LEFT_PARAM: return "LEFT_PARAM";
      case Token_Type::LEFT_PARAM: return "LEFT_PARAM";

    }
  }

  std::string to_string() const {
    return std::to_string(type) +  " " + lexeme + " " + literal;
  }
};
}

int main() {
  std::string one = "example";
  std::string two = "42";

  Lox::Token myToken(Token_Type::PLACEHOLDER, one, two, 1);
  std::cout << myToken.to_string() << '\n';
}
