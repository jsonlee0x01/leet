#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> ans;
        reverse(digits.begin(), digits.end());
        int carry = 0;
        for (int i = 0; i < digits.size(); ++i) {
            int xa = digits[i];
            int xb = (i == 0) ? 1 : 0;
            int curDigit = xa + xb + carry;
            carry = curDigit / 10;
            ans[i] = curDigit % 10;
        }
        if (carry) {
            ans.push_back(1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
