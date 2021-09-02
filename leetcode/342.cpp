class Solution {
public:
  bool isPowerOfFour(int n) {
    int count = 0;
    while (n >= 2 && (n & 0x1) == 0) {
      n = n >> 1;
      count++;
    }
    return n == 1 && count % 2 == 0;
  }
};

class Solution1 {
public:
  bool isPowerOfFour(int n) {
    if (n <= 0) {
      return false;
    }
    if (n & (n - 1) != 0) {
      return false;
    }
    int count = 0;

    while (n >= 2 && ((n & (n - 1)) == 0)) {
      n = n >> 1;
      ++count;
    }
    return n == 1 && (count % 2) == 0;
  }
};