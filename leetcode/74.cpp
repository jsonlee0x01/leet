#include <vector>
using namespace std;

class Solution {
public:
    // 一个naive的解法：先确定所在的行，然后在行内进行二分查找，时间复杂度O(m + log(n))，也不会超时
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int count = 0;
        int colSize = matrix[0].size();
        bool findRow = false;
        for (int i = 0; i < matrix.size(); ++i) {
            if (target < matrix[i][colSize - 1]) {
                findRow = true;
                break;
            } else if (target == matrix[i][colSize - 1]) {
                return true;
            }
            ++count;
        }
        if (!findRow) {
            return false;
        }
        int left = 0;
        int right = colSize - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[count][mid] == target) {
                return true;
            } else if (matrix[count][mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};
