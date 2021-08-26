#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> symbol;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                symbol.push(s[i]);
            } else if (s[i] == ')') {
                if (symbol.empty() || symbol.top() != '(') {
                    return false;
                }
                symbol.pop();
            } else if (s[i] == ']') {
                if (symbol.empty() || symbol.top() != '[') {
                    return false;
                }
                symbol.pop();
            } else if (s[i] == '{') {
                if (symbol.empty() || symbol.top() != '}') {
                    return false;
                }
                symbol.pop();
            }
        }
        return symbol.empty();
    }
};

class Solution1 {
public:
    bool isValid(string s)
    {
        stack<char> symbol;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                symbol.push(')');
            } else if (s[i] == '[') {
                symbol.push(']');
            } else if (s[i] == '{') {
                symbol.push('}');
            } else if (symbol.empty() || symbol.top() != s[i]) {
                return false;
            } else {
                symbol.pop();
            }
        }
        return symbol.empty();
    }
};
