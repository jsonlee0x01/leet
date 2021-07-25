#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// [1, 3, 2, 6], 9
// [2, 2], 4
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> ans;
    unordered_map<int, int> idxMap;
    for (int i = 0; i < nums.size(); ++i) {
      // 注意：这题本身的限制太多，题目说了只会有一个答案，
      // 所以，即使有重复的话，也只会重复一次！
      // 如果有重复的话，idxMap的索引会把前一个覆盖掉；
      // 例如对于[2, 2]这种情况，idxMap[2] = 1;
      idxMap[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); ++i) {
      // 注意：遍历是从前往后的遍历的，对于[2, 2]这种情况，
      // 先出现的2其索引为0，而后一个2的索引在前面的遍历中已经将0覆盖了，
      // 所以结果是[0, 1] 所以，这种写法可以处理带有重复的情况！
      if (idxMap.count(target - nums[i]) && (i != idxMap[target - nums[i]])) {
        ans.push_back(i);
        ans.push_back(idxMap[target - nums[i]]);
        break;
      }
    }
    return ans;
  }
};

int main() {
  vector<int> nums{2, 2};
  int target = 4;
  Solution s;
  vector<int> ans = s.twoSum(nums, target);
  for (auto &it : ans) {
    cout << it << ' ';
  }
  return 0;
}