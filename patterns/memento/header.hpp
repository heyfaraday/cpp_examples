#pragma once

#include <vector>

class Memento {
  int balance;

 public:
  Memento(int balance) : balance(balance) {}
  friend class BankAccount;
};

class BankAccount {
  int balance{0}, current;
  std::vector<std::shared_ptr<Memento>> changes;

 public:
  BankAccount(const int balance) : balance(balance) {
    changes.emplace_back(std::make_shared<Memento>(balance));
    current = 0;
  }

  std::shared_ptr<Memento> deposit(int amount) {
    balance += amount;
    auto m = std::make_shared<Memento>(balance);
    changes.push_back(m);
    ++current;
    return m;
  }

  std::shared_ptr<Memento> withdraw(int amount) {
    balance -= amount;
    auto m = std::make_shared<Memento>(balance);
    changes.push_back(m);
    ++current;
    return m;
  }

  std::shared_ptr<Memento> undo() {
    if (current > 0) {
      --current;
      auto m = changes[current];
      balance = m->balance;
      return m;
    }
    return {};
  }

  int get_balance() { return balance; }
};
