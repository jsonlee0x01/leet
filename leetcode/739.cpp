#include <vector>
#include <stack>
using namespace std;

// 单调栈，维护单调递增栈，每次pop的时候记录相关信息
class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> ans(temperatures.size(), 0);
        stack<pair<int, int>> incStack;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!incStack.empty() && temperatures[i] > incStack.top().first) {
                ans[incStack.top().second] = i - incStack.top().second;
                incStack.pop();
            }
            incStack.push({temperatures[i], i});
        }
        return ans;
    }

    vector<int> dailyTemperatures1(vector<int> &temperatures)
    {
        vector<int> ans(temperatures.size(), 0);
        stack<int> incStack;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!incStack.empty() && temperatures[i] > temperatures[incStack.top()]) {
                ans[incStack.top()] = i - incStack.top();
                incStack.pop();
            }
            incStack.push(i);
        }
        return ans;
    }
};

class Solution1 {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> ans(temperatures.size(), 0);
        ans[temperatures.size() - 1] = 0;
        for (int i = temperatures.size() - 2; i >= 0; --i) {
            for (int j = i + 1; j < temperatures.size(); j += ans[j]) {
                if (temperatures[j] > temperatures[i]) {
                    ans[i] = j - i;
                    break;
                } else if (ans[j] == 0) {
                    ans[i] = 0;
                    break;
                }
            }
        }
        return ans;
    }
};
