#include <iostream>
#include <sstream>
#include <string>

// #include "header.hpp"
#include "header2.hpp"

int main(int argc, char *argv[]) {
  // header
  // <ul><li>hello</li><li>world</li></ul>

  // std::string words[] = {"hello", "world"};

  // std::ostringstream oss;

  // oss << "<ul>" << std::endl;
  // for (auto w : words)
  //     oss << "  <li>" << w << "</li>" << std::endl;
  // oss << "</ul>";
  // std::cout << oss.str().c_str() << std::endl;

  // HtmlBuilder builder{"ul"};
  // builder.add_child("li", "hello");
  // builder.add_child("li", "world");
  // std::cout << builder.str() << std::endl;

  // HtmlBuilder builder{"ul"};
  // builder.add_child("li", "hello").add_child("li", "world");

  // HtmlElement::build("ul").add_child("li", "hello").add_child("li", "world");

  // header2 - Groovy-Style Builders
  P my_tag{IMG{"http://pokemon.com"}};

  return 0;
}