#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> res;
    if (intervals.size() <= 0) {
      return res;
    }
    std::sort(intervals.begin(), intervals.end(),
              [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
    for (int i = 0; i < intervals.size() - 1; ++i) {
      if (intervals[i + 1][0] <= intervals[i][1]) {
        // merge and update
        intervals[i + 1][0] = intervals[i][0];
        intervals[i + 1][1] = intervals[i + 1][1] > intervals[i][1]
                                  ? intervals[i + 1][1]
                                  : intervals[i][1];
      } else {
        res.push_back(intervals[i]);
      }
    }
    res.push_back(intervals[intervals.size() - 1]);
    return res;
  }
};

class Solution1 {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.size() <= 1) {
      return intervals;
    }
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
      if (result.back()[1] >= intervals[i][0]) {
        // 合并区间
        result.back()[1] = max(result.back()[1], intervals[i][1]);
      } else {
        result.push_back(intervals[i]);
      }
    }
    return result;
  }
};