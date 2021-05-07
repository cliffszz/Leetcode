//https://leetcode-cn.com/problems/longest-palindromic-substring/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int maxLen = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), 0));
        for (int i = 0; i < s.size(); i++) dp[i][i] = true;
        for (int len = 2; len <= s.size(); len++) {
            for (int i = 0; i < s.size() - len; i++) {
                int j = i + len - 1;
                if (j >= s.size()) break;
                if (s[i] != s[j]) dp[i][j] = false;
                else {
                    if (j - i > 3) dp[i][j] = dp[i + 1][j - 1];
                    else dp[i][j] = true;
                }
            }
        }
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                if (dp[i][j] && j - i + 1 > maxLen) {
                    res = s.substr(i, j - i + 1);
                    maxLen = j - i + 1;
                }
            }
        }
        return res;
    }
};