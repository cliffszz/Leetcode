//https://leetcode-cn.com/problems/regular-expression-matching/
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        auto match = [&](int i, int j) {
            if (i == 0) return false;
            if (p[j - 1] == '.') return true;
            return s[i - 1] == p[j - 1];
        };
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, 0));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] != '*') {
                    if (match(i, j)) dp[i][j] = dp[i - 1][j - 1];
                    else dp[i][j] = false;
                }
                else {
                    if (match(i, j - 1)) dp[i][j] = dp[i][j - 2] | dp[i - 1][j];
                    else dp[i][j] = dp[i][j - 2];
                }
            }
        }
        return dp[m][n];
    }
};