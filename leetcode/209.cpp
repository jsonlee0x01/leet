#include <vector>
#include <algorithm>
using namespace std;

// 暴力求解
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int ans = nums.size() + 1;
        int sum = 0;
        for (int left = 0; left < nums.size(); ++left) {
            sum = 0;
            for (int right = left; right < nums.size(); ++right) {
                sum += nums[right];
                if (sum >= target) {
                    ans = min(ans, right - left + 1);
                    break;
                }
            }
        }
        if (ans > nums.size()) {
            ans = 0;
        }
        return ans;
    }
};

// 滑动窗口
class Solution1 {
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int ans = nums.size() + 1;
        int left = 0;
        int sum = 0;
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                ++left;
            }
        }
        if (ans > nums.size()) {
            ans = 0;
        }
        return ans;
    }
};
