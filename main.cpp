#include "util.h"
#include <iostream>
// todo
namespace Lox {
// TODO [_] use a define variable for running prompt or file
  void init_file(char **argv) {
    Util::run_file(argv[1]);
  }
  void init_prompt() {
    Util::run_prompt();
  }
}

int main(int argc, char** argv) {
  if (argc> 2) {
    std::cerr << "Usage: jlox [script]" << std::endl;
    return 64;
  } else if (argc == 2) {
    Lox::init_file(argv);
  } else {
    Lox::init_prompt();
  }
}
