//https://leetcode-cn.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 1;
        if (n <= 2) return n;
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

//滚动数组优化空间
class Solution2 {
public:
    int climbStairs(int n) {
        if (n == 0) return 1;
        if (n <= 2) return n;
        int pre = 1, cur = 2;
        for (int i = 3; i <= n; i++) {
            int tmp = cur;
            cur = pre + cur;
            pre = tmp;
        }
        return cur;
    }
};