make: main.cpp lexer.cpp token.cpp
	clear && clang++ -std=c++20 main.cpp token.cpp lexer.cpp -o Lox && ./Lox && rm -f Lox

