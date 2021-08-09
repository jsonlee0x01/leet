#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    unordered_map<int, int> hash;
    int len = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
      ++hash[nums[i]];
      if (hash[nums[i]] > len / 2) {
        return nums[i];
      }
    }
    return nums[0];
  }
};

// 摩尔投票法：前提是多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素！
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int major = nums[0];
    int count = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (major == nums[i]) {
        ++count;
      } else {
        --count;
      }
      if (count == 0) {
        major = nums[i];
        count = 1;
      }
    }
    return major;
  }
};