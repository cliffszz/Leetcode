//https://leetcode-cn.com/problems/paint-house/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i - 1][2];
        }
        return min(min(dp[n][0], dp[n][1]), dp[n][2]);
    }
};