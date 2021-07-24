#include <algorithm>
#include <deque>
#include <queue>
#include <vector>

using namespace std;
#if 0
// O(N*log(k))
class Solution {
public:
  using PairT = pair<int, int>;
  using ContainerT = vector<pair<int, int>>;

  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    auto cmp = [](const PairT &a, const PairT &b) { return a.first < b.first; };
    vector<int> ans;
    priority_queue<PairT, ContainerT, decltype(cmp)> maxHeap(cmp);
    for (size_t i = 0; i < k; ++i) {
      maxHeap.push({nums[i], i});
    }
    ans.push_back(maxHeap.top().first);
    int leaveIdx = 0;
    int newComeIdx = 0;
    for (int i = 0; i < nums.size() - k; ++i) {
      leaveIdx = i;
      newComeIdx = i + k;
      vector<PairT> tmp;
      // adjust the heap
      while (!maxHeap.empty()) {
        PairT top = maxHeap.top();
        if (top.second == leaveIdx) {
          maxHeap.pop();
          break;
        } else {
          tmp.push_back(top);
          maxHeap.pop();
        }
      }
      // maintain the heap
      maxHeap.push({nums[newComeIdx], newComeIdx});
      for (auto &it : tmp) {
        maxHeap.push(it);
      }
      tmp.clear();
      ans.push_back(maxHeap.top().first);
    }
    return ans;
  }
};
#endif

// deque
class Solution {
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> res;
    deque<int> window;
    for (int i = 0; i < nums.size(); i++) {
      if (!window.empty() && window.front() == i - k) {
        window.pop_front();
      }
      while (!window.empty() && nums[i] > nums[window.back()]) {
        window.pop_back();
      }
      window.push_back(i);
      if (i >= k - 1) {
        res.push_back(nums[window.front()]);
      }
    }
    return res;
  }
};