#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<pair<int, int>> rightStack;
        stack<pair<int, int>> leftStack;
        for (int i = 0; i < asteroids.size(); ++i) {
            if (asteroids[i] >= 0) {
                rightStack.push({asteroids[i], i});
            } else {
                int left = asteroids[i];
                if (rightStack.empty()) {
                    leftStack.push({left, i});
                } else {
                    while (!rightStack.empty()) {
                        int right = rightStack.top().first;
                        if (abs(left) > abs(right)) {
                            rightStack.pop();
                            if (rightStack.empty()) {
                                leftStack.push({left, i});
                                break;
                            }
                        } else if (abs(left) == abs(right)) {
                            rightStack.pop();
                            break;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        vector<pair<int, int>> res;
        while (!rightStack.empty()) {
            res.push_back(rightStack.top());
            rightStack.pop();
        }
        while (!leftStack.empty()) {
            res.push_back(leftStack.top());
            leftStack.pop();
        }
        sort(res.begin(), res.end(), [](pair<int, int> &a, pair<int, int> &b) { return a.second < b.second; });
        vector<int> ans;
        for (int i = 0; i < res.size(); ++i) {
            ans.push_back(res[i].first);
        }
        return ans;
    }
};
