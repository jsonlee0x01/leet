#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool cmpFlags(int *sFlag, int *pFlag) {
    for (int i = 0; i < 26; ++i) {
      if (pFlag[i] != sFlag[i]) {
        return false;
      }
    }
    return true;
  }
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    if (s.size() < p.size()) {
      return ans;
    }
    int sFlag[26] = {0};
    int pFlag[26] = {0};
    for (int i = 0; i < p.size(); ++i) {
      ++pFlag[p[i] - 'a'];
      ++sFlag[s[i] - 'a'];
    }
    int left = 0;
    int right = p.size() - 1;
    while (right + 1 < s.size()) {
      if (cmpFlags(sFlag, pFlag)) {
        ans.push_back(left);
      }
      // 更新窗口
      --sFlag[s[left] - 'a'];
      ++left;
      ++right;
      ++sFlag[s[right] - 'a'];
    }
    if (cmpFlags(sFlag, pFlag)) {
      ans.push_back(left);
    }
    return ans;
  }
};