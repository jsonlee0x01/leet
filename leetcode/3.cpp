#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int res = 0;
    int l = 0;
    int r = -1;
    int flag[256] = {0};
    while (l < s.size()) {
      if (r + 1 < s.size() && flag[s[r + 1]] == 0) {
        ++r;
        ++flag[s[r]];
      } else {
        --flag[s[l]];
        ++l;
      }
      res = max(res, r - l + 1);
    }
    return res;
  }
};