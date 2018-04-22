#include <iostream>

#include "header.hpp"

int main(int argc, char *argv[]) {

  BankAccount ba(100);
  auto m1 = ba.deposit(50);  // 150
  auto m2 = ba.deposit(25);  // 175
  auto m3 = ba.withdraw(10); // 165

  auto m4 = ba.undo();
  std::cout << ba.get_balance() << std::endl;

  return 0;
}