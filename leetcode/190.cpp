#include <cstdint>
#include <iostream>

using namespace std;

// 颠倒二进制位
// 00000010100101000001111010011100 -> 00111001011110000010100101000000
class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    int i = 32;
    while (i) {
      ans <<= 1;
      // n & 1相当于取得最低位的二进制位取值
      ans += n & 1;
      n >>= 1;
      --i;
    }
    return ans;
  }
};

// 解法2: 更加容易理解的版本
class Solution1 {
  uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    int i = 32;
    while (i) {
      --i;
      // 先获得最低二进制位的取值，最低位左移i位相当于最高位
      ans += ((n & 1) << i);
      n >>= 1;
    }
    return ans;
  }
};

int main() {
  cout << "2 & 1 = " << (2 & 1) << endl;
  cout << "3 & 1 = " << (3 & 1) << endl;
  cout << "15 & 1 = " << (15 & 1) << endl;
  return 0;
}