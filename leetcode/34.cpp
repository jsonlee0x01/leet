#include <vector>
using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> ans(2, -1);
    if (nums.size() == 0) {
      return ans;
    }
    int left = 0;
    int right = nums.size() - 1;
    // 注意: left <= right是为了保证单元素数组也能进入循环！
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        // 找到左边界
        int i = mid;
        // 注意：i>=0要放在前面，否则会出现踩内存错误！！！
        while (i >= 0 && nums[i] == target) {
          --i;
        }
        ans[0] = i + 1;
        // 找到右边界
        int j = mid;
        // 注意：j<nums.size()要放在前面，否则会出现踩内存错误！！！
        while (j < nums.size() && nums[j] == target) {
          ++j;
        }
        ans[1] = j - 1;
        return ans;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return ans;
  }
};

class Solution1 {
public:
  // 找左边界的时候，由右侧逼近；找右边界的时候，由左侧逼近
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> ans(2, -1);
    if (nums.size() == 0) {
      return ans;
    }
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] >= target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    if (nums[left] != target) {
      return ans;
    }
    ans[0] = left;
    right = nums.size();
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    ans[1] = left - 1;
    return ans;
  }
};