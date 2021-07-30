#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

// Pass: O(nlog(n))
class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    auto cmp = [](const int &a, const int &b) { return abs(a) < abs(b); };
    vector<int> ans(nums.begin(), nums.end());
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); ++i) {
      ans[i] *= ans[i];
    }
    return ans;
  }
};

class Solution1 {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    vector<int> ans(nums.size());
    int i = 0;
    int j = nums.size() - 1;
    int count = nums.size() - 1;
    while (i <= j) {
      if (abs(nums[i]) > abs(nums[j])) {
        ans[count] = nums[i] * nums[i];
        ++i;
      } else {
        ans[count] = nums[j] * nums[j];
        --j;
      }
      --count;
    }
    return ans;
  }
};
