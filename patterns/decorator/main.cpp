#include <iostream>

#include "header.hpp"

int main(int argc, char *argv[]) {
  String s("hello world!");

  std::cout << "string has " << s.length << " characters" << std::endl;

  return 0;
}