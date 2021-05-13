//https://leetcode-cn.com/problems/longest-valid-parentheses/
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        auto matcj = [&](char p, char q) {
            if (p == '(' && q == ')') return true;
            return false;
        };
        int maxLen = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxLen = max(maxLen, dp[i]);
            }
        }
        return maxLen;
    }
};

class Solution2 {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    maxLen = max(maxLen, i - stk.top());
                }
            }
        }
        return maxLen;
    }
};