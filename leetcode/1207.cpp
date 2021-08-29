#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> numCount;
    for (int i = 0; i < arr.size(); ++i) {
      if (numCount.count(arr[i]) == 0) {
        numCount[arr[i]] = 1;
      } else {
        numCount[arr[i]] += 1;
      }
    }
    unordered_map<int, int> repeatMap;
    for (auto it : numCount) {
      if (repeatMap.count(it.second) == 0) {
        repeatMap[it.second] == 1;
      } else {
        return false;
      }
    }
    return true;
  }
};

class Solution1 {
public:
  bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> numCount;
    for (int i = 0; i < arr.size(); ++i) {
      ++numCount[arr[i]];
    }
    unordered_set<int> timesSet;
    for (auto it : numCount) {
      timesSet.insert(it.second);
    }
    return timesSet.size() == numCount.size();
  }
};