#include <vector>
#include <stack>
using namespace std;

// 单调递增栈
class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> ans(nums.size(), -1);
        stack<int> incStack;
        for (int i = 0; i < nums.size() * 2; ++i) {
            while (!incStack.empty() && nums[i % nums.size()] > nums[incStack.top()]) {
                ans[incStack.top()] = nums[i % nums.size()];
                incStack.pop();
            }
            incStack.push(i % nums.size());
        }
        return ans;
    }
};
