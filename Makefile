make: main.cpp util.cpp token.cpp lexer.cpp
	clear && clang++ -Wzero-as-null-pointer-constant -std=c++20 main.cpp lexer.cpp token.cpp util.cpp -o Lox 

