#include <vector>
using namespace std;

// naive
class Solution {
public:
  vector<int> sortArrayByParityII(vector<int> &nums) {
    vector<int> odd;
    vector<int> even;
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
      if ((nums[i] & 1) == 0) {
        even.push_back(nums[i]);
      } else {
        odd.push_back(nums[i]);
      }
    }
    for (int i = 0; i < odd.size(); ++i) {
      ans.push_back(even[i]);
      ans.push_back(odd[i]);
    }
    return ans;
  }
};

// 双指针
class Solution {
public:
  vector<int> sortArrayByParityII(vector<int> &nums) {
    int i = 0;
    int j = 1;
    int len = nums.size();
    while (i < len && j < len) {
      while (i < len && nums[i] % 2 == 0) {
        i += 2;
      }
      while (j < len && nums[j] % 2 == 1) {
        j += 2;
      }
      if (i >= len || j >= len) {
        break;
      }
      int tmp = nums[i];
      nums[i] = nums[j];
      nums[j] = tmp;
      i += 2;
      j += 2;
    }
    return nums;
  }
};