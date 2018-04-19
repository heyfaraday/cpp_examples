#pragma once

#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>

class String
{
  private:
    std::string s;

  public:
    String(const std::string &s) : s(s) {}
    std::vector<std::string> split(std::string input)
    {
        std::vector<std::string> result;
        boost::split(result, s, boost::is_any_of(input), boost::token_compress_on);
        return result;
    }
    size_t get_length() const { return s.length(); }

    // non-standart!
    __declspec(property(get = get_length)) size_t length;
};