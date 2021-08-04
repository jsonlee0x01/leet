#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  string getEvenPalindrome(const string &s, int start) {
    int left = start;
    int right = start;
    while (left >= 0 && right <= s.size()) {
      if (s[left] == s[right]) {
        --left;
        ++right;
      } else {
        break;
      }
    }
    return s.substr(left + 1, right - left - 1);
  }
  string getOddPalindrome(const string &s, int start) {
    int left = start;
    int right = start + 1;
    while (left >= 0 && right <= s.size()) {
      if (s[left] == s[right]) {
        --left;
        ++right;
      } else {
        break;
      }
    }
    return s.substr(left + 1, right - left - 1);
  }
  string longestPalindrome(string s) {
    if (s.size() == 1) {
      return s;
    }
    string ans = getOddPalindrome(s, 0);
    string tmp1;
    string tmp2;
    string tmp;
    for (int i = 0; i < s.size(); ++i) {
      tmp1 = getOddPalindrome(s, i);
      tmp2 = getEvenPalindrome(s, i);
      tmp = tmp1.size() > tmp2.size() ? tmp1 : tmp2;
      ans = ans.size() > tmp.size() ? ans : tmp;
    }
    return ans;
  }
};