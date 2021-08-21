#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      if (map.count(nums[i])) {
        return true;
      } else {
        map[nums[i]] = 1;
      }
    }
    return false;
  }
};

class Solution1 {
public:
  bool containsDuplicate(vector<int> &nums) {
    set<int> numSet(nums.begin(), nums.end());
    if (numSet.size() < nums.size()) {
      return true;
    } else {
      return false;
    }
  }
};