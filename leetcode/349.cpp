#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> Set1(nums1.begin(), nums1.end());
    unordered_set<int> Set2(nums2.begin(), nums2.end());
    unordered_set<int> ResSet;
    for (auto it : Set1) {
      if (Set2.count(it)) {
        ResSet.insert(it);
      }
    }
    return vector<int>(ResSet.begin(), ResSet.end());
  }
};