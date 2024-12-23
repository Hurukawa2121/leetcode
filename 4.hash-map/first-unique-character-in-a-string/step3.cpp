#include <map>
#include <string>

class Solution {
public:
  int firstUniqChar(std::string s) {
    std::map<char, int> character_to_frequency;
    for (char c : s) {
      character_to_frequency[c]++;
    }
    for (int index = 0; index < s.size(); ++index) {
      if (character_to_frequency.contains(s[index])) {
        return character_to_frequency[s[index]];
      }
    }
    return -1; // Not Found
  }
};
