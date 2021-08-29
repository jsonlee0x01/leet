#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int repeatedNTimes(vector<int> &nums) {
    unordered_map<int, int> numCountMap;
    for (int i = 0; i < nums.size(); ++i) {
      if (numCountMap.count(nums[i]) == 0) {
        numCountMap[nums[i]] = 1;
      } else {
        numCountMap[nums[i]] += 1;
        return nums[i];
      }
    }
    return nums[0];
  }
};