#include <string>
#include <stack>
#include <map>

class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> open_bracket;
    for (char bracket : s) {
      if (isOpen(bracket)) {
        open_bracket.emplace(bracket);
      } else {
        if (open_bracket.empty()) {
          return false;
        }
        char partner_open_bracket = open_bracket.top();
        if (open_to_close[partner_open_bracket] == bracket) {
          open_bracket.pop();
        } else {
          return false;
        }
      }
    }
    return open_bracket.empty();
  }
private:
  std::map<char, const char> open_to_close = {
    {'{', '}'},
    {'[', ']'},
    {'(', ')'},
  };
  bool isOpen(char bracket) {
    for (auto [open_b, _] :open_to_close) {
      if (open_b == bracket) return true;
    }
    return false;
  }
};