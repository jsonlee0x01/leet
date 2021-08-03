#include <map>
#include <string>
using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) {
      return false;
    }
    bool ans = false;
    int left = 0;
    int right = s1.size() - 1;
    int s1Count[256] = {0};
    int s2Count[256] = {0};
    for (int i = 0; i < s1.size(); ++i) {
      ++s1Count[s1[i]];
      ++s2Count[s2[i]];
    }
    while (right < s2.size()) {
      bool flag = true;
      for (int i = 0; i < s1.size(); ++i) {
        if (s1Count[s2[i + left]] != s2Count[s2[i + left]]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        return true;
      } else {
        // 不匹配，更新窗口
        --s2Count[s2[left]];
        ++left;
        ++right;
        ++s2Count[s2[right]];
      }
    }
    return ans;
  }
};