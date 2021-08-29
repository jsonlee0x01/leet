#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    int sFlag[256] = {0};
    int tFlag[256] = {0};
    for (int i = 0; i < s.size(); ++i) {
      ++sFlag[s[i]];
      ++tFlag[t[i]];
    }
    for (int i = 0; i < 256; ++i) {
      if (sFlag[i] != tFlag[i]) {
        return false;
      }
    }
    return true;
  }
};

class Solution1 {
public:
  bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
  }
};