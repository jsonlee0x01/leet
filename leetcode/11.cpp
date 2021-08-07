#include <algorithm>
#include <vector>
using namespace std;

// naive，超时
class Solution {
public:
  int maxArea(vector<int> &height) {
    int ans = 0;
    int left = 0;
    int right = 0;
    for (int i = 0; i < height.size(); ++i) {
      for (int j = i; j >= 0; --j) {
        // 尽可能找到最左边小于等于height[i]
        if (height[j] >= height[i]) {
          left = j;
        }
      }
      for (int j = i; j < height.size(); ++j) {
        // 尽可能找到最右边小于等于height[i]
        if (height[j] >= height[i]) {
          right = j;
        }
      }
      ans = max(ans, (right - left) * height[i]);
    }
    return ans;
  }
};

class Solution {
public:
  int maxArea(vector<int> &height) {
    if (height.size() < 1) {
      return 0;
    }
    int l = 0;
    int r = height.size() - 1;
    int ans = 0;
    while (l < r) {
      int h = min(height[l], height[r]);
      ans = max(ans, h * (r - l));
      if (height[l] < height[r]) {
        ++l;
      } else {
        --r;
      }
    }
    return ans;
  }
};