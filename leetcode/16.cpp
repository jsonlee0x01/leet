#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int closestSum = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size() - 2; ++i) {
      int l = i + 1;
      int r = nums.size() - 1;
      while (l < r) {
        int threeSum = nums[i] + nums[l] + nums[r];
        if (abs(threeSum - target) < abs(closestSum - target)) {
          closestSum = threeSum;
        }
        if (threeSum > target) {
          --r;
        } else if (threeSum < target) {
          ++l;
        } else {
          return target;
        }
      }
    }
    return closestSum;
  }
};