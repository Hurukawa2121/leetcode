#include <string>
#include <map>

class Solution {
public:
  int firstUniqChar(std::string s) {
    std::map<char, int> character_to_frequency;
    for (char c : s) {
      character_to_frequency[c]++;
    }
    for (int index = 0; index < s.size(); ++index) {
      if (character_to_frequency[s[index]] == 1) {
        return index;
      }
    }
    return -1;
  }
};
