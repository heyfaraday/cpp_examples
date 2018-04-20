#pragma once

#include <string>
#include <vector>

struct HtmlElement {
  std::string name;
  std::string text;
  std::vector<HtmlElement> elements;
  const size_t indent_size = 2;

  std::string str(int indent = 0) const;  // pretty-print

  //   static HtmlBuilder build(std::string root_name) {
  //     return HtmlBuilder{root_name};
  //   }
};

struct HtmlBuilder {
  HtmlElement root;
  HtmlBuilder(std::string root_name) { root.name = root_name; }
  HtmlBuilder& add_child(std::string child_name, std::string child_text) {
    HtmlElement e{child_name, child_text};
    root.elements.emplace_back(e);
    return *this;
  }
  std::string str() { return root.str(); }
};