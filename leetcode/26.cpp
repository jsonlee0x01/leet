#include <vector>

using namespace std;

// 原地删除有序数组中的重复元素
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int i = 0;
    int j = 0;
    int tmp;
    while (i < nums.size() - 1) {
      tmp = nums[i];
      if (nums[i + 1] != tmp) {
        nums[++j] = nums[i + 1];
      }
      ++i;
    }
    return j + 1;
  }
};

// 简洁一些的写法
class Solution1 {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() < 2) {
      return nums.size();
    }
    int j = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[j] != nums[i]) {
        nums[++j] = nums[i];
      }
    }
    return ++j;
  }
};