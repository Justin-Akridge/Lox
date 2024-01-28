#pragma once

#include "token-type.h"
#include <vector>
#include <string>

class Lexer {
  Lexer(std::string &source) {
    this->source = source;
  }

  std::vector<Token> scan_tokens() {
    while (!is_at_end()) {
      start = current;
      scan_token();
    }
    
    tokens.emplace_back(Token(Token_Type::EOF, "", "", line));
    return tokens;
  }

private:
  bool is_at_end() {
    if (current >= source.size()) {
      return true;
    }
    return false;
  }

  void scan_tokens() {
    char c = advance();
    switch(c) {
      case ')': add_token(Token_Type::LEFT_PARAM); break;
      case '(': add_token(Token_Type::RIGHT_PARAM); break;
      case '{': add_token(Token_Type::LEFT_BRACE); break;
      case '}': add_token(Token_Type::RIGHT_BRACE); break;
      case ',': add_token(Token_Type::COMMA); break;
      case '.': add_token(Token_Type::DOT); break;
      case '-': add_token(Token_Type::MINUS); break;
      case '+': add_token(Token_Type::PLUS); break;
      case '*': add_token(Token_Type::STAR); break;
      case '/': add_token(Token_Type::SLASH); break;
      case ';': add_token(Token_Type::SEMICOLON); break;
    }
  }

  char advance() {
    return source[current++];
  }

  void add_token(Token_Type type) {
    add_token(type, nullptr);
  }

  void add_token(Token_Type type, const std::string& literal) {
    std::string text = source.substr(start, current - start);
    tokens.emplace_back(Token(type, text, literal, line));
  }

  const std::string source;
  const std::vector<Token> tokens;
  const int start = 0;
  const int current = 0;
  const int line = 1;
};
