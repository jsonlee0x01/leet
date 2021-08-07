#include <vector>
using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    vector<int> data;
    while (x) {
      data.push_back(x % 10);
      x /= 10;
    }
    int i = 0;
    int j = data.size() - 1;
    while (i < j) {
      if (data[i] != data[j]) {
        return false;
      } else {
        ++i;
        --j;
      }
    }
    return true;
  }
};

// 整数反转
class Solution1 {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    long y = 0;
    int _x = x;
    while (_x) {
      int tmp = _x % 10;
      y = y * 10 + tmp;
      _x = _x / 10;
    }
    return y == x;
  }
};