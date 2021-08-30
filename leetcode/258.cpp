class Solution {
public:
  int addDigits(int num) { return (num - 1) % 9 + 1; }
};

class Solution1 {
public:
  int addDigits(int num) {
    int ans = 0;
  L:
    while (num) {
      ans += num % 10;
      num /= 10;
    }
    if (ans >= 0 && ans <= 9) {
      return ans;
    } else {
      num = ans;
      ans = 0;
      goto L;
    }
    return ans;
  }
};

class Solution2 {
public:
  int addDigits(int num) {
    if (num >= 0 && num <= 9) {
      return num;
    }
    int ans = 0;
    while (num >= 10) {
      ans = 0;
      while (num) {
        ans += num % 10;
        num /= 10;
      }
      num = ans;
    }
    return ans;
  }
};