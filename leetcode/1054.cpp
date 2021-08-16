#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        int size = barcodes.size();
        unordered_map<int, int> map;
        for (auto b : barcodes) {
            ++map[b];
        }
        // 将map数据转入vector数组进行排序
        vector<pair<int, int>> slt;
        for (auto it = map.begin(); it != map.end(); ++it) {
            slt.push_back({it->first, it->second});
        }
        sort(slt.begin(), slt.end(), [](pair<int, int> &lhs, pair<int, int> &rhs) { return lhs.second > rhs.second; });
        int index = 0, res_index = 0;
        while (index < slt.size()) {
            // 隔一填一，依此填入数据即可。
            barcodes[res_index] = slt[index].first;
            res_index += 2;
            --slt[index].second;
            if (!slt[index].second)
                ++index;
            if (res_index >= size)
                res_index = 1;
        }
        return barcodes;
    }
};
