#include <string>
#include <unordered_map>
using namespace std;

// s="badc"
// t="baba"
class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> s2tMap;
    unordered_map<char, char> t2sMap;
    for (int i = 0; i < s.size(); ++i) {
      if ((s2tMap.count(s[i]) != 0 && s2tMap[s[i]] != t[i]) ||
          (t2sMap.count(t[i]) != 0 && t2sMap[t[i]] != s[i])) {
        return false;
      }
      t2sMap[t[i]] = s[i];
      s2tMap[s[i]] = t[i];
    }
    return true;
  }
};