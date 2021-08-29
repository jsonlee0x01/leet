#include <algorithm>
#include <cctype>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> findWords(vector<string> &words) {
    // for (int i = 0; i < words.size(); ++i) {
    //   transform(words[i].begin(), words[i].end(), words[i].begin(),
    //             [](unsigned char c) { return std::tolower(c); });
    // }
    unordered_map<char, int> charLineMap{
        {'q', 1}, {'w', 1}, {'e', 1}, {'r', 1}, {'t', 1}, {'y', 1}, {'u', 1},
        {'i', 1}, {'o', 1}, {'p', 1}, {'a', 2}, {'s', 2}, {'d', 2}, {'f', 2},
        {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2}, {'l', 2}, {'z', 3}, {'x', 3},
        {'c', 3}, {'v', 3}, {'b', 3}, {'n', 3}, {'m', 3}, {'Q', 1}, {'W', 1},
        {'E', 1}, {'R', 1}, {'T', 1}, {'Y', 1}, {'U', 1}, {'I', 1}, {'O', 1},
        {'P', 1}, {'A', 2}, {'S', 2}, {'D', 2}, {'F', 2}, {'G', 2}, {'H', 2},
        {'J', 2}, {'K', 2}, {'L', 2}, {'Z', 3}, {'X', 3}, {'C', 3}, {'V', 3},
        {'B', 3}, {'N', 3}, {'M', 3}};
    vector<string> ans;
    for (int i = 0; i < words.size(); ++i) {
      int flag = true;
      for (int j = 1; j < words[i].size(); ++j) {
        if (charLineMap[words[i][j]] != charLineMap[words[i][0]]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        ans.push_back(words[i]);
      }
    }
    return ans;
  }
};
