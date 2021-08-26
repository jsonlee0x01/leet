class Solution {
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
