#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    // 分割字符串s
    vector<string> strData;
    int startPos = 0;
    int len = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') {
        // cout << s.substr(startPos, i-startPos) << endl;
        strData.push_back(s.substr(startPos, i - startPos));
        startPos = i + 1;
      }
    }
    strData.push_back(s.substr(startPos));
    // cout << strData.size() << endl;
    if (pattern.size() != strData.size()) {
      return false;
    }
    // 模式匹配
    unordered_map<char, string> char2StrMap;
    unordered_map<string, char> str2CharMap;
    for (int i = 0; i < pattern.size(); ++i) {
      if ((char2StrMap.count(pattern[i]) != 0 &&
           char2StrMap[pattern[i]] != strData[i]) ||
          (str2CharMap.count(strData[i]) != 0 &&
           str2CharMap[strData[i]] != pattern[i])) {
        return false;
      }
      char2StrMap[pattern[i]] = strData[i];
      str2CharMap[strData[i]] = pattern[i];
    }
    return true;
  }
};