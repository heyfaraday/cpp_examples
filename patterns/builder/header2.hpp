#pragma once

#include <string>
#include <utility>
#include <vector>

struct Tag {
  std::string name;
  std::string text;
  std::vector<Tag> children;

  std::vector<std::pair<std::string, std::string>> attributes;

 protected:
  Tag(const std::string& name, const std::string& text)
      : name{name}, text{text} {}
  Tag(const std::string& name, const std::vector<Tag>& children)
      : name{name}, children{children} {}
};

struct P : Tag {
  explicit P(const std::string& text) : Tag{"p", text} {}
  P(std::initializer_list<Tag> children) : Tag{"p", children} {}
};

struct IMG : Tag {

    explicit IMG(const std::string& url) : Tag {"img", ""} {
        attributes.emplace_back(std::make_pair("src", url));
    }

};