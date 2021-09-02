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

// dp
class Solution1 {
public:
  vector<int> countBits(int n) {
    int i = 1;
    vector<int> ans(n + 1);
    ans[0] = 0;
    for (int i = 1; i <= n; ++i) {
      if (i % 2 == 0)
        ans[i] = ans[i / 2];
      else
        ans[i] = ans[i / 2] + 1;
    }
    return ans;
  }
};