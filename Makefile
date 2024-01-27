make:
	clear && clang++ -std=c++20 main.cpp Lox.cpp Lexer.cpp -o Lox && ./Lox
clean:
	clean
