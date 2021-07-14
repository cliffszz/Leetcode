//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            //只能买一次
            dp[i][1] = max(dp[i - 1][1], - prices[i]);
        }
        return dp[n - 1][0];
    }
};

//滚动数组优化
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int a = 0;
        int b = -prices[0];
        for (int i = 1; i < n; i++) {
            a = max(a, b + prices[i]);
            b = max(b, -prices[i]);
        }
        return a;
    }
};