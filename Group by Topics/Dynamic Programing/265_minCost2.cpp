//https://leetcode-cn.com/problems/paint-house-ii/
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(k, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < k; j++) {
                dp[i][j] = INT_MAX;
                for (int x = 0; x < k; x++) {
                    if (x != j) dp[i][j] = min(dp[i][j], dp[i - 1][x] + costs[i - 1][j]); 
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < k; i++) {
            res = min(res, dp[n][i]);
        }
        return res;
    }
};