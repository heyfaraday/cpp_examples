#pragma once

#include <boost/any.hpp>
#include <iostream>
#include <string>
#include <vector>

class Person;

struct PersonListener {
  virtual ~PersonListener() = default;
  virtual void person_changed(Person& p, const std::string& property_name,
                              const boost::any new_value) = 0;
};

class Person {
 private:
  int age;
  std::vector<PersonListener*> listeners;

 public:
  Person(int age) : age(age){};

  void subscribe(PersonListener* pl) { listeners.push_back(pl); }

  void notify(const std::string& property_name, const boost::any new_value) {
    for (const auto listener : listeners) {
      listener->person_changed(*this, property_name, new_value);
    }
  }

  void set_age(int age) {
    if (this->age == age) return;
    this->age = age;
    notify("age", this->age);
  }
  int get_age() const { return age; }
};

struct ConsoleListener : PersonListener {
  void person_changed(Person& p, const std::string& property_name,
                      const boost::any new_value) override {
    std::cout << "person's " << property_name << " has been changed to ";
    if (property_name == "age") {
      std::cout << boost::any_cast<int>(new_value);
    }
    std::cout << "\n";
  }
};