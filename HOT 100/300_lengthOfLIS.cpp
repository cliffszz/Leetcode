//https://leetcode-cn.com/problems/longest-increasing-subsequence/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        vector<int> tail;
        tail.push_back(nums[0]);
        int end = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > tail[end]) {
                tail.push_back(nums[i]);
                end++;
            } else {
                int left = 0;
                int right = end;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (tail[mid] < nums[i]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                tail[left] = nums[i];
            }
        }
        return end + 1;
    }
};