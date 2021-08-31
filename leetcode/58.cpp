#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int count = 0;
    reverse(s.begin(), s.end());
    if (s[0] == ' ') {
      // 从第一个不是空格的地方开始count
      int i = 1;
      while (s[i] == ' ') {
        ++i;
      }
      while (i < s.size() && s[i] != ' ') {
        ++i;
        ++count;
      }
    } else {
      int i = 0;
      while (i < s.size() && s[i] != ' ') {
        ++count;
        ++i;
      }
    }
    return count;
  }
};
