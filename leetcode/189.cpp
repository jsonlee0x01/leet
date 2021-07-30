#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k % nums.size() - 1);
    reverse(nums, k % nums.size(), nums.size() - 1);
  }
  void reverse(vector<int> &nums, int start, int end) {
    int tmp;
    while (start < end) {
      tmp = nums[end];
      nums[end] = nums[start];
      nums[start] = tmp;
      ++start;
      --end;
    }
  }
};

// 注意：STL中的reverse左开右闭，[start, end)
class Solution1 {
public:
  void rotate(vector<int> &nums, int k) {
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};