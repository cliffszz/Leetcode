//https://leetcode-cn.com/problems/distinct-subsequences/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m < n) return 0;

        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        for(int i = 0; i <= m; i++) {
            dp[i][n] = 1; 
        }

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(s[i] == t[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                }
                else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};

int main(){

    Solution solution;

    string s = "rabbbit";
    string t = "rabbit";

    int ret = solution.numDistinct(s, t);

    cout << ret << endl;

    return 0;
}


