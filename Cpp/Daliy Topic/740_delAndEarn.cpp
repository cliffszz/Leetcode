//https://leetcode-cn.com/problems/delete-and-earn/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = 0;
        for (int n : nums) {
            maxVal = max(maxVal, n);
        }
        vector<int> sum(maxVal + 1, 0);
        for (int n : nums) {
            sum[n] += n;
        }
        vector<int> dp(maxVal + 1, 0);
        dp[0] = sum[0];
        dp[1] = max(sum[0], sum[1]);
        for (int i = 2; i < maxVal + 1; i++) {
            dp[i] = max(dp[i - 2] + sum[i], dp[i - 1]);
        }
        return dp[maxVal];
    }
};