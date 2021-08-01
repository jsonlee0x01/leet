#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    string ans = "";
    int curStart = 0;
    string curStr;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') {
        curStr = s.substr(curStart, i - curStart);
        // cout << "==> "<< curStr << endl;
        reverse(curStr.begin(), curStr.end());
        ans += curStr;
        ans += " ";
        curStart = i + 1;
      }
    }
    curStr = s.substr(curStart, s.size() - curStart);
    reverse(curStr.begin(), curStr.end());
    ans += curStr;
    return ans;
  }
};