#include <unordered_map>
#include <string>
#include <iostream>
#include "token-type.h"
int main() {
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

  std::cout << keywords["to"]; 
}
