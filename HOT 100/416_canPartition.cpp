//https://leetcode-cn.com/problems/partition-equal-subset-sum/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;
        sum = sum / 2;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= 0; j--) {
                if (j - nums[i] >= 0) {
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
            }   
        }
        return dp[sum];
    }
};