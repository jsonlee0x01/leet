#include <vector>
using namespace std;

// naive方式直接求解也可以pass
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int> ans;
    int i = 0;
    int j = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] < nums2[j]) {
        ans.push_back(nums1[i]);
        ++i;
      } else {
        ans.push_back(nums2[j]);
        ++j;
      }
    }
    if (i < nums1.size()) {
      for (; i < nums1.size(); ++i) {
        ans.push_back(nums1[i]);
      }
    }
    if (j < nums2.size()) {
      for (; j < nums2.size(); ++j) {
        ans.push_back(nums2[j]);
      }
    }
    int len = ans.size();
    double result = 0;
    if (len % 2 == 0) {
      result = ((double)ans[len / 2 - 1] + ans[len / 2]) / 2;
    } else {
      result = double(ans[len / 2]);
    }
    return result;
  }
};

// TODO：二分查找
class Solution1 {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int> ans;
    int i = 0;
    int j = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] < nums2[j]) {
        ans.push_back(nums1[i]);
        ++i;
      } else {
        ans.push_back(nums2[j]);
        ++j;
      }
    }
    if (i < nums1.size()) {
      for (; i < nums1.size(); ++i) {
        ans.push_back(nums1[i]);
      }
    }
    if (j < nums2.size()) {
      for (; j < nums2.size(); ++j) {
        ans.push_back(nums2[j]);
      }
    }
    int len = ans.size();
    double result = 0;
    if (len % 2 == 0) {
      result = ((double)ans[len / 2 - 1] + ans[len / 2]) / 2;
    } else {
      result = double(ans[len / 2]);
    }
    return result;
  }
};