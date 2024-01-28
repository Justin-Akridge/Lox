#include "token.h"
#include <string>
#include <iostream>

namespace Lox {

Token::Token(Token_Type type, std::string lexeme, std::string literal, int line)
  : type(type), lexeme(lexeme), literal(literal), line(line) {}

std::string Token::token_type_to_string(Token_Type type) {
  switch (type) {
    case Token_Type::LEFT_PARAM: return "LEFT_PARAM";
    case Token_Type::RIGHT_PARAM: return "RIGHT_PARAM";
    case Token_Type::LEFT_BRACE: return "LEFT_BRACE";
    case Token_Type::RIGHT_BRACE: return "RIGHT_BRACE";
    case Token_Type::COMMA: return "COMMA";
    case Token_Type::DOT: return "DOT";
    case Token_Type::MINUS: return "MINUS";
    case Token_Type::PLUS: return "PLUS";
    case Token_Type::SEMICOLON: return "SEMICOLON";
    case Token_Type::SLASH: return "SLASH";
    case Token_Type::STAR: return "STAR";
    case Token_Type::BANG: return "BANG";
    case Token_Type::BANG_EQUAL: return "BANG_EQUAL";
    case Token_Type::EQUAL: return "EQUAL";
    case Token_Type::EQUAL_EQUAL: return "EQUAL_EQUAL";
    case Token_Type::GREATER_THAN: return "GREATER_THAN";
    case Token_Type::GREATER_THAN_EQUAL: return "GREATER_THAN_EQUAL";
    case Token_Type::LESS_THAN: return "LESS_THAN";
    case Token_Type::LESS_THAN_EQUAL: return "LESS_THAN_EQUAL";
    case Token_Type::IDENTIFIER: return "IDENTIFIER";
    case Token_Type::STRING: return "STRING";
    case Token_Type::NUMBER: return "NUMBER";
    case Token_Type::AND: return "AND";
    case Token_Type::CLASS: return "CLASS";
    case Token_Type::ELSE: return "ELSE";
    case Token_Type::FALSE: return "FALSE";
    case Token_Type::FUN: return "FUN";
    case Token_Type::FOR: return "FOR";
    case Token_Type::IF: return "IF";
    case Token_Type::NIL: return "NIL";
    case Token_Type::OR: return "OR";
    case Token_Type::PRINT: return "PRINT";
    case Token_Type::RETURN: return "RETURN";
    case Token_Type::SUPER: return "SUPER";
    case Token_Type::THIS: return "THIS";
    case Token_Type::TRUE: return "TRUE";
    case Token_Type::VAR: return "VAR";
    case Token_Type::WHILE: return "WHILE";
    case Token_Type::E_O_F: return "EOF";
  }
}

std::string Token::to_string() {
  return token_type_to_string(type) +  " " + lexeme + " " + literal;
}
}
