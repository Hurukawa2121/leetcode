#include <string>
#include <stack>
#include <map>

class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> open_bracket;
    for (char bracket : s) {
      if (open_to_close.contains(bracket)) {
        open_bracket.emplace(bracket);
        continue;
      }
      if (open_bracket.empty()) {
        return false;
      }
      if (open_to_close[open_bracket.top()] == bracket) {
        open_bracket.pop();
        continue;
      }
      return false;
    }
    return open_bracket.empty();
  }

private:
  std::map<char, const char> open_to_close = {
    {'{', '}'},
    {'[', ']'},
    {'(', ')'},
  };
};
