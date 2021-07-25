#include <unordered_map>
#include <vector>

using namespace std;

class Solution01 {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> ans;
    // 注意：由于答案是唯一的，且输出的结果必须有序，所以这里必须使用unordered_map
    unordered_map<int, int> idxMap;
    for (int i = 0; i < numbers.size(); ++i) {
      idxMap[numbers[i]] = i;
    }
    for (int i = 0; i < numbers.size(); ++i) {
      if (idxMap.count(target - numbers[i]) &&
          (i != idxMap[target - numbers[i]])) {
        ans.push_back(i + 1);
        ans.push_back(idxMap[target - numbers[i]] + 1);
        break;
      }
    }
    return ans;
  }
};

// 解法 2: 由于输入是有序的，所以利用俩指针也能解决
class Solution02 {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> ans;
    int i = 0;
    int j = numbers.size() - 1;
    while (i < j) {
      if (numbers[i] + numbers[j] == target) {
        ans.push_back(i + 1);
        ans.push_back(j + 1);
        break;
      } else if (numbers[i] + numbers[j] < target) {
        ++i;
      } else {
        --j;
      }
    }
    return ans;
  }
};