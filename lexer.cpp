#include "lexer.h"
#include "util.h"
#include "token-type.h"
#include "token.h"
#include <iostream>
#include <vector>
#include <string>

namespace Lox {

Lexer::Lexer(std::string source) {
  this->source = source;
}


std::vector<Token> Lexer::scan_tokens() {
  while (!is_at_end()) {
    start = current;
    read_tokens();
  }
   
  Token new_token(Token_Type::E_O_F, "", "", line);
  tokens.push_back(new_token);
  return tokens;
}

bool Lexer::is_at_end() {
  if (current >= source.size()) {
    return true;
  }
  return false;
}

void Lexer::read_tokens() {
  char c = advance();
  switch(c) {
    // TODO [_] parser doesn't understand '\n' character
    case ')': add_token(Token_Type::LEFT_PARAM); break;
    case '(': add_token(Token_Type::RIGHT_PARAM); break;
    case '{': add_token(Token_Type::LEFT_BRACE); break;
    case '}': add_token(Token_Type::RIGHT_BRACE); break;
    case ',': add_token(Token_Type::COMMA); break;
    case '.': add_token(Token_Type::DOT); break;
    case '-': add_token(Token_Type::MINUS); break;
    case '+': add_token(Token_Type::PLUS); break;
    case '*': add_token(Token_Type::STAR); break;
    case ';': add_token(Token_Type::SEMICOLON); break;
    case '!': add_token(match('=') ? BANG_EQUAL : BANG); break;
    case '=': add_token(match('=') ? EQUAL_EQUAL : EQUAL); break;
    case '<': add_token(match('=') ? LESS_THAN_EQUAL : LESS_THAN); break;
    case '>': add_token(match('=') ? GREATER_THAN_EQUAL : GREATER_THAN); break;
    case '/': 
      if (match('/')) {
        while (peek() != '\n' && !is_at_end()) advance();
      } else {
        add_token(Token_Type::SLASH);
      }
      break;
    default:
      std::cout << c << '\n';
      Util::error(line, "Unexpected character.\n");
      break;
  }
}

bool Lexer::match(char equal_sign) {
  if (is_at_end()) return false;
  if (source[current] != equal_sign) return false;
  current++;
  return true;
}

char Lexer::peek() {
  if(is_at_end()) return '\0';
  return source[current];
}

char Lexer::advance() {
  return source[current++];
}

void Lexer::add_token(Token_Type type) {
  add_token(type, "");
}

void Lexer::add_token(Token_Type type, std::string literal) {
  std::string text = source.substr(start, current - start);
  Token new_token(type,text,literal, line);
  tokens.push_back(new_token);
}

}
