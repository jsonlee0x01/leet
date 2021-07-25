#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int minPairSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
      ans = max(nums[i] + nums[j], ans);
    }
    return ans;
  }
};