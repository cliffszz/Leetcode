//https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int left = nums.size() - 1, right = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != sorted[i]) {
                left = min(left, i);
                right = max(right, i);
            }
        }
        return (right - left > 0) ? right - left + 1 : 0;
    }
};

class Solution2 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> stk;
        int left = nums.size() - 1, right = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                left = min(left, stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            stk.pop();
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                right = max(right, stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        return (right - left > 0) ? right - left + 1 : 0;
    }
};

class Solution3 {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int minNum = nums[n - 1], maxNum = nums[0];
        int left = n - 1, right = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > minNum) {
                left = i;
            }
            minNum = min(minNum, nums[i]);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] < maxNum) {
                right = i;
            }
            maxNum = max(maxNum, nums[i]);
        }
        return (right - left > 0) ? right - left + 1 : 0;
    }
};