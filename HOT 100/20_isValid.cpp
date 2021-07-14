//https://leetcode-cn.com/problems/valid-parentheses/
#include <stack>
using namespace std;

class Solution {
public:
    bool match(char p, char q) {
        if (p == '(' && q == ')') return true;
        if (p == '{' && q == '}') return true;
        if (p == '[' && q == ']') return true;
        return false;
    }
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        stack<char> stk;
        for (auto ch : s) {
            if (!stk.empty() && match(stk.top(), ch)) stk.pop();
            else stk.push(ch);
        }
        return stk.empty();
    }
};