#include <vector>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int> &nums) {
    vector<int> tmp(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); ++i) {
      tmp[nums[i]] = 1;
    }
    for (int i = 0; i < tmp.size(); ++i) {
      if (tmp[i] == 0) {
        return i;
      }
    }
    return 0;
  }
};

class Solution1 {
public:
  int missingNumber(vector<int> &nums) {
    int ans = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
      ans ^= nums[i];
      ans ^= i;
    }
    return ans;
  }
};