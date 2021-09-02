#include <vector>
using namespace std;

class Solution {
public:
  int count(int n) {
    int i = 0;
    while (n) {
      i += (n & 1);
      n >>= 1;
    }
    return i;
  }
  vector<int> countBits(int n) {
    vector<int> ans(n + 1);
    for (int i = 0; i <= n; ++i) {
      ans[i] = count(i);
    }
    return ans;
  }
};