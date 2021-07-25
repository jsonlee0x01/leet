#include <unordered_set>
#include <vector>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// 方法1: 中序遍历BST得到结果，俩指针扫描寻找两数之和为k
class Solution {
public:
  void midOrderAccess(TreeNode *root, vector<int> &dataList) {
    if (!root)
      return;
    midOrderAccess(root->left, dataList);
    dataList.push_back(root->val);
    midOrderAccess(root->right, dataList);
  }

  bool findTarget(TreeNode *root, int k) {
    // 中序遍历
    vector<int> dataList;
    midOrderAccess(root, dataList);
    int i = 0;
    int j = dataList.size() - 1;
    while (i < j) {
      if (dataList[i] + dataList[j] == k) {
        return true;
      } else if (dataList[i] + dataList[j] < k) {
        ++i;
      } else {
        --j;
      }
    }
    return false;
  }
};

// 方法2：遍历BST+HashSet
class Solution1 {
public:
  bool preOrder(TreeNode *root, const int &k, unordered_set<int> &hashSet) {
    if (!root) {
      return false;
    }
    if (hashSet.count(k - root->val)) {
      return true;
    }
    hashSet.insert(root->val);
    return preOrder(root->left, k, hashSet) ||
           preOrder(root->right, k, hashSet);
  }

  bool findTarget(TreeNode *root, int k) {
    unordered_set<int> hashSet;
    return preOrder(root, k, hashSet);
  }
};