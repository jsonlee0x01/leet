#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int ArrangeBoxes(const vector<int> &boxes)
    {
        int n = boxes.size();
        int ans = 0;
        int cur = 0;
        vector<int> preSum(n, 0);
        InitPreSum(boxes, preSum);
        for (int j = 1; j < boxes.size(); ++j) {
            for (int i = 0; i < j; ++i) {
                int left = preSum[i];
                int right = preSum[n - 1] - preSum[j];
                int mid = preSum[j] - preSum[i];
                if (left <= mid && mid <= right) {
                    ans = (ans + 1) % 1000000007;
                }
            }
        }
        return ans;
    }
    void InitPreSum(const vector<int> &boxes, vector<int> &preSum)
    {
        preSum[0] = boxes[0];
        for (int i = 1; i < boxes.size(); ++i) {
            preSum[i] = preSum[i - 1] + boxes[i];
        }
    }
};

// Case1: preSum[left] <= preSum[right] - preSum[left], so we have preSum[right] >= 2 *preSum[left];
// Case2: preSum[right] - preSum[left] <= preSum[total] - preSum[right],
// so we have preSum[right] <= (preSum[total] + preSum[left]) / 2;
class Solution1 {
public:
    int ArrangeBoxes(const vector<int> &boxes)
    {
        int n = boxes.size();
        vector<long long> preSum(n + 1);
        preSum[0] = 0;
        long long total = 0;
        for (int i = 1; i <= n; ++i) {
            preSum[i] = preSum[i - 1] + boxes[i - 1];
            total += boxes[i - 1];
        }
        long long ans;
        for (int i = 0; i < n; ++i) {
            long long left = preSum[i + 1];
            int begin = lower_bound(preSum.begin(), preSum.end(), (long long)2 * left) - preSum.begin();
            int end = upper_bound(preSum.begin(), preSum.end(), (long long)(total + left) / 2) - preSum.begin();
            if (end > begin) {
                ans += (end - begin);
            }
            ans = ans % 1000000007;
        }
        return ans;
    }
};
