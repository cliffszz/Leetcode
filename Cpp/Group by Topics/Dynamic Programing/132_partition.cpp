//https://leetcode-cn.com/problems/palindrome-partitioning-ii/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> isHuiWen(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && (j - i <= 1 || isHuiWen[i + 1][j - 1])) {
                    isHuiWen[i][j] = true;
                }
            }
        }
        vector<int> dp(s.size(), 0);
        for (int i = 0; i < s.size(); i++) dp[i] = i;
        for (int i = 1; i < s.size(); i++) {
            if (isHuiWen[0][i]) {
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (isHuiWen[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[s.size() - 1];
    }
};