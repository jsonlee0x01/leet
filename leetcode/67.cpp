#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b)
    {
        string ans;
        int na = a.size();
        int nb = b.size();
        int carry = 0;
        for (int i = 0; i < max(na, nb); ++i) {
            char xa = i < na ? a[na - i - 1] : '0';
            char xb = i < nb ? b[nb - i - 1] : '0';
            int x = carry + (xa - '0') + (xb - '0');
            carry = (x) / 2;
            x %= 2;
            ans.push_back(x + '0');
        }
        if (carry) {
            ans.push_back(carry + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
