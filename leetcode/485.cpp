#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int ans = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i]) {
        ++count;
      } else {
        ans = max(ans, count);
        count = 0;
      }
    }
    ans = max(ans, count);
    return ans;
  }
};