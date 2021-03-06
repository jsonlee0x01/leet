class Solution {
public:
  int hammingDistance(int x, int y) {
    int z = x ^ y;
    int sum = 0;
    while (z) {
      sum += z & 1;
      z >>= 1;
    }
    return sum;
  }
};