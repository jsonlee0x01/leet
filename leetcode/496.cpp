#include <vector>
#include <stack>
#include <map>
using namespace std;

// 暴力解法
class Solution1 {
public:
    vector<int> nextGreaterElement(vector<int> &numsShort, vector<int> &numsLong)
    {
        map<int, int> hashNextMap;
        int last = numsLong.size() - 1;
        hashNextMap[numsLong[last]] = -1;
        for (int i = 0; i < numsLong.size() - 1; ++i) {
            hashNextMap[numsLong[i]] = -1;
            for (int j = i + 1; j < nums2.size(); ++j) {
                if (numsLong[j] > numsLong[i]) {
                    hashNextMap[numsLong[i]] = numsLong[j];
                    break;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < numsShort.size(); ++i) {
            ans.push_back(hashNextMap[numsShort[i]]);
        }
        return ans;
    }
};

// 单调栈，维护的是单调递增栈，每次弹出的时候，记录相应的结果
class Solution2 {
public:
    vector<int> nextGreaterElement(vector<int> &numsShort, vector<int> &numsLong)
    {
        map<int, int> hashNextMap;
        int last = numsLong.size() - 1;
        hashNextMap[numsLong[last]] = -1;
        stack<int> incStack;
        for (int i = 0; i < numsLong.size(); ++i) {
            while (!incStack.empty() && numsLong[i] > incStack.top()) {
                hashNextMap[incStack.top()] = numsLong[i];
                incStack.pop();
            }
            incStack.push(numsLong[i]);
        }
        vector<int> ans;
        for (int i = 0; i < numsShort.size(); ++i) {
            if (hashNextMap.count(numsShort[i])) {
                ans.push_back(hashNextMap[numsShort[i]]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
