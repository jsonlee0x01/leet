#include <stack>
#include <string>

using namespace std;
class Solution {
public:
  bool isValid(string s) {
    stack<char> match;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
        match.push(s[i]);
      } else if (s[i] == ')') {
        if (!match.empty()) {
          if (match.top() == '(') {
            match.pop();
          } else {
            return false;
          }
        } else {
          return false;
        }
      } else if (s[i] == ']') {
        if (!match.empty()) {
          if (match.top() == '[') {
            match.pop();
          } else {
            return false;
          }
        } else {
          return false;
        }
      } else if (s[i] == '}') {
        if (!match.empty()) {
          if (match.top() == '{') {
            match.pop();
          } else {
            return false;
          }
        } else {
          return false;
        }
      }
    }
    if (match.empty()) {
      return true;
    } else {
      return false;
    }
  }
};