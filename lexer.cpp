#include "lexer.h"
#include "util.h"
#include "token-type.h"
#include "token.h"
#include <vector>
#include <string>
#include <unordered_map>

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

std::unordered_map<std::string, Token_Type> keywords = {
  { "and",    AND },
  { "class",  CLASS },
  { "else",   ELSE },
  { "false",  FALSE },
  { "for",    FOR },
  { "fun",    FUN },
  { "if",     IF },
  { "nil",    NIL },
  { "or",     OR },
  { "print",  PRINT },
  { "return", RETURN },
  { "super",  SUPER },
  { "this",   THIS },
  { "true",   TRUE },
  { "var",    VAR },
  { "while",  WHILE },
};

void Lexer::identifier() {
  while (is_alpha_numeric(peek())) advance();
  std::string text = source.substr(start, current);
  Token_Type type = keywords[text];
  if (type == 0) type = IDENTIFIER;
  add_token(IDENTIFIER);
}

char Lexer::peek_next() {
  if (current + 1 >= source.size()) return '\0';
  return source[current + 1];
}

bool Lexer::isalpha(char c) {
  return (c >= 'a' && c <= 'z' || c >= 'A' || c <= 'Z' || c == '_');
}

bool Lexer::is_alpha_numeric(char c) {
  return isalpha(c) || isdigit(c);
}

void Lexer::number() {
  while (isdigit(peek())) advance();
  
  if (peek() == '.' && isdigit(peek_next())) {
    advance();

    while (isdigit(peek())) advance();
  }
  add_token(Token_Type::NUMBER, source.substr(start, current));
}

void Lexer::string() {
  while (peek() != '"' && !is_at_end()) {
    if (peek() == '\n') line++;
    advance();
  }

  if (is_at_end()) {
    Util::error(line, "Unterminated string\n");
    return;
  }

  advance();
  std::string value = source.substr(start + 1, current - 1);
  add_token(Token_Type::STRING, value);
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
    case ' ':
    case '\r':
    case '\t':
      break;
    case '\n':
      line++;
      break;
    case '"': string(); break;
    case 'o':
      if (match('r')) {
        add_token(Token_Type::OR);
      }
      break;
    default:
      if (isdigit(c)) {
        number();
      } else if (isalpha(c)) {
        identifier(); 
      } else {
        Util::error(line, "Unexpected character.\n");
      }
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

bool Lexer::isdigit(char c) {
  return (c >= '0' && c <= '9');
}

char Lexer::advance() {
  return source[current++];
}

void Lexer::add_token(Token_Type type) {
  add_token(type, "");
}

void Lexer::add_token(Token_Type type, std::string literal) {
  std::string text = source.substr(start, current - start);
  Token new_token(type, text, literal, line);
  tokens.push_back(new_token);
}

}
