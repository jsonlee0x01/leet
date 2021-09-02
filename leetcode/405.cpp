#include <algorithm>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
  string toHex(int num) {
    if (num == 0) {
      return "0";
    }
    map<int, string> hexMap{{0, "0"},  {1, "1"},  {2, "2"},  {3, "3"},
                            {4, "4"},  {5, "5"},  {6, "6"},  {7, "7"},
                            {8, "8"},  {9, "9"},  {10, "a"}, {11, "b"},
                            {12, "c"}, {13, "d"}, {14, "e"}, {15, "f"}};
    string ans = "";
    while (num && ans.size() < 8) {
      ans = hexMap[num & 0xf] + ans;
      num >>= 4;
    }
    // reverse(ans.begin(), ans.end());
    return ans;
  }
};

class Solution1 {
  string toHex(int num) {
    if (num == 0)
      return "0";
    string hex = "0123456789abcdef", ans = "";
    while (num && ans.size() < 8) {
      ans = hex[num & 0xf] + ans;
      num >>= 4;
    }
    return ans;
  }
};