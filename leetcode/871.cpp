#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        if (startFuel >= target) {
            return 0;
        }
        int currentFuel = startFuel;
        if (stations.size() > 0 && currentFuel < stations[0][0]) {
            return -1;
        }
        stations.push_back({target, 0});
        priority_queue<int> que;
        int ans = 0;
        int pos = 0;
        for (int i = 0; i < stations.size(); ++i) {
            currentFuel -= (stations[i][0] - pos);
            pos = stations[i][0];
            while (currentFuel < 0 && !que.empty()) {
                currentFuel += que.top();
                que.pop();
                ++ans;
            }
            if (currentFuel < 0) {
                return -1;
            }
            que.push(stations[i][1]);
        }
        return ans;
    }
};
