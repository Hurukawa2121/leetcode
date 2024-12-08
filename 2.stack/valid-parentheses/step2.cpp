#include <string>
#include <stack>
#include <map>

class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> open_brackets;
    for (char bracket : s) {
      if (isOpen(bracket)) {
        open_brackets.emplace(bracket);
      } else {
        if (open_brackets.empty()) {
          return false;
        }
        char partner_open_bracket = open_brackets.top();
        if (open_to_close[partner_open_bracket] == bracket) {
          open_brackets.pop();
        } else {
          return false;
        }
      }
    }
    return open_brackets.empty();
  }
private:
  std::map<char, const char> open_to_close = {
    {'{', '}'},
    {'[', ']'},
    {'(', ')'},
  };
  bool isOpen(char bracket) {
    for (auto [open_b, _] : open_to_close) {
      if (open_b == bracket) return true;
    }
    return false;
  }
};