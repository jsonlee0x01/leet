#include <vector>
using namespace std;

class Solution {
public:
  bool canThreePartsEqualSum(vector<int> &arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); ++i) {
      sum += arr[i];
    }
    if (sum % 3 != 0) {
      return false;
    }
    int avg = sum / 3;
    int curSum = 0;
    int cnt = 0;
    for (int i = 0; i < arr.size() - 1; ++i) {
      curSum += arr[i];
      if (curSum == avg) {
        ++cnt;
        if (cnt == 2) {
          return true;
        }
        curSum = 0;
      }
    }
    return false;
  }
};