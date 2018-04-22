#include "header.hpp"

int main(int argc, char* argv[]) {
  
  Person p {14};
  ConsoleListener cl;
  p.subscribe(&cl);
  p.set_age(15);
  p.set_age(16);
  
  return 0;
}