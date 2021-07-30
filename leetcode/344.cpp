#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) { reverse(s.begin(), s.end()); }
};

class Solution1 {
public:
  void reverseString(vector<char> &s) {
    int start = 0;
    int end = s.size() - 1;
    char tmp;
    while (start < end) {
      tmp = s[end];
      s[end] = s[start];
      s[start] = tmp;
      ++start;
      --end;
    }
  }
};