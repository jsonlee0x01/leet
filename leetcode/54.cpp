#include <vector>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ans;
    if (matrix.size() == 0) {
      return ans;
    }
    int beginX = 0;
    int endX = matrix[0].size() - 1;
    int beginY = 0;
    int endY = matrix.size() - 1;
    while (true) {
      // 外围从左到右
      for (int i = beginX; i <= endX; ++i) {
        ans.push_back(matrix[beginY][i]);
      }
      if (++beginY > endY) {
        break;
      }
      // 从上到下
      for (int i = beginY; i <= endY; ++i) {
        ans.push_back(matrix[i][endX]);
      }
      if (beginX > --endX) {
        break;
      }
      // 从右到左
      for (int i = endX; i >= beginX; --i) {
        ans.push_back(matrix[endY][i]);
      }
      if (beginY > --endY) {
        break;
      }
      // 从下到上
      for (int i = endY; i >= beginY; --i) {
        ans.push_back(matrix[i][beginX]);
      }
      if (++beginX > endX) {
        break;
      }
    }
    return ans;
  }
};