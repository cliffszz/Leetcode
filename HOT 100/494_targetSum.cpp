//https://leetcode-cn.com/problems/target-sum/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int cnt = 0;

    void backTracking(vector<int>& nums, int i, int sum, int target) {
        if (i == nums.size()) {
            if (sum == target) {
                cnt++;
            }
            return;
        } else {
            backTracking(nums, i + 1, sum - nums[i], target);
            backTracking(nums, i + 1, sum + nums[i], target);
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        backTracking(nums, 0, 0, target);
        return cnt;
    }
};

class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        if ((sum + target) % 2 == 1) {
            return 0;
        }
        //加法和
        int bag = (sum + target) / 2;
        vector<int> dp(bag + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bag; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bag];
    }
};