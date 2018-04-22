#pragma once

#include <sstream>
#include <string>
#include <vector>

struct Token {
  enum Type { integer, plus, minus, lparen, rparen };
  Type type;
  std::string text;
  explicit Token(Type type, const std::string& text) : type(type), text(text){};
};

std::vector<Token> lex(const std::string& input) {
  std::vector<Token> result;
  for (int i = 0; i < input.size(); ++i) {
    switch (input[i]) {
      case '+':
        result.push_back(Token{Token::plus, "+"});
        break;
      case '-':
        result.push_back(Token{Token::minus, "+"});
        break;
      case '(':
        result.push_back(Token{Token::lparen, "+"});
        break;
      case ')':
        result.push_back(Token{Token::rparen, "+"});
        break;
      default:
        std::ostringstream buffer;
        buffer << input[i];
        for (int j = i + 1; j < input.size(); j++) {
          if (std::isdigit(input[i])) {
            buffer << input[j];
            ++i;
          } else {
            result.push_back(Token{Token::integer, buffer.str()});
            break;
          }
        }
    }
  }
  return result;
}