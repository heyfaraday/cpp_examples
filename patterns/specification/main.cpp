#include <iostream>

#include "header.hpp"

int main(int argc, char* argv[]) {
  Product apple{"Apple", Color::Green, Size::Small};
  Product tree{"Tree", Color::Green, Size::Large};
  Product house{"House", Color::Blue, Size::Large};

  std::vector<Product*> all{&apple, &tree, &house};

  ProductFilter pf;
  ColorSpecification green(Color::Green);

  auto green_things = pf.filter(all, green);
  for (auto& x : green_things) {
    std::cout << x->name << " is green" << std::endl;
  }

  SizeSpecification big(Size::Large);
  AndSpecification<Product> green_and_big{big, green};

  auto big_green_things = pf.filter(all, green_and_big);
  for (auto& x : big_green_things) {
    std::cout << x->name << " is big and green" << std::endl;
  }

  return 0;
}