//https://leetcode-cn.com/problems/longest-palindromic-substring/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        string res = s.substr(0, 1);;
        int maxLen = 1;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), 0));
        for (int i = 0; i < s.size(); i++) dp[i][i] = true;
        for (int len = 2; len <= s.size(); len++) {
            for (int i = 0; i < s.size(); i++) {
                int j = i + len - 1;
                if (j >= s.size()) break;
                if (s[i] != s[j]) dp[i][j] = false;
                else {
                    if (len > 2) dp[i][j] = dp[i + 1][j - 1];
                    else dp[i][j] = true;
                }
                if (dp[i][j] && len > maxLen) {
                    maxLen = len;
                    res = s.substr(i, len);
                } 
            }
        }
        return res;
    }
};