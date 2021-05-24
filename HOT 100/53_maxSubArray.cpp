//https://leetcode-cn.com/problems/maximum-subarray/
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int maxSum = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};

class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int a = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            a = max(a + nums[i], nums[i]);
            maxSum = max(maxSum, a);
        }
        return maxSum;
    }
};