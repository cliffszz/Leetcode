//https://leetcode-cn.com/problems/maximum-product-subarray/
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2));
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        int maxPro = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i][0] = max(nums[i], max(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]));
            dp[i][1] = min(nums[i], min(dp[i - 1][0] * nums[i], dp[i - 1][1] * nums[i]));
            maxPro = max(maxPro, max(dp[i][0], dp[i][1]));
        }
        return maxPro;
    }
};

//滚动数组优化
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int a = nums[0], b = nums[0];
        int maxPro = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int at = a, bt = b;
            a = max(nums[i], max(at * nums[i], bt * nums[i]));
            b = min(nums[i], min(at * nums[i], bt * nums[i]));
            maxPro = max(maxPro, max(a, b));
        }
        return maxPro;
    }
};