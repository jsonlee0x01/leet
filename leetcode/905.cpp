#include <vector>
using namespace std;

// naive
class Solution {
public:
  vector<int> sortArrayByParity(vector<int> &nums) {
    vector<int> ans;
    vector<int> tmp;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] % 2 == 0) {
        ans.push_back(nums[i]);
      } else {
        tmp.push_back(nums[i]);
      }
    }
    for (int i = 0; i < tmp.size(); ++i) {
      ans.push_back(tmp[i]);
    }
    return ans;
  }
};

// 双指针
class Solution1 {
public:
  vector<int> sortArrayByParity(vector<int> &nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
      if ((nums[l] & 1) == 0) {
        ++l;
      } else if ((nums[r] & 1) == 1) {
        --r;
      } else if ((nums[l] & 1) == 1 && (nums[r] & 1) == 0) {
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
        ++l;
        --r;
      }
    }
    return nums;
  }
};