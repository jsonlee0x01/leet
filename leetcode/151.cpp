#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s)
    {
        string ans;
        vector<string> wordsList;
        int i = 0;
        // 去除前面的空格
        while (s[i] == ' ' && i < s.size()) {
            ++i;
        }
        int start = i;
        while (i < s.size()) {
            if (s[i] == ' ') {
                string tmp = s.substr(start, i - start);
                wordsList.push_back(tmp);
                // 找到下一个不是空格的
                while (s[i] == ' ' && i < s.size()) {
                    ++i;
                }
                start = i;
            } else {
                ++i;
            }
        }
        if (start < s.size()) {
            wordsList.push_back(s.substr(start, s.size() - start));
        }
        int len = wordsList.size();
        for (int i = 0; i < len; ++i) {
            if (i == (len - 1)) {
                ans += wordsList[0];
            } else {
                ans += wordsList[len - 1 - i];
                ans += " ";
            }
        }
        return ans;
    }
};
