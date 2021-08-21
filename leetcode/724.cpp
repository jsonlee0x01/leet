#include <vector>
using namespace std;
class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
    }
    int tmpSum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (tmpSum * 2 + nums[i] == sum) {
        return i;
      }
      tmpSum += nums[i];
    }
    return -1;
  }
};