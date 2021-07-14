//https://leetcode-cn.com/problems/sliding-window-maximum/
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; i++) {
            q.push({nums[i], i});
            //q.emplace(nums[i], i);
        }
        vector<int> res = {q.top().first};
        for (int i = k; i < n; i++) {
            q.push({nums[i], i});
            //q.emplace(nums[i], i);
            while (q.top().second <= i - k) {
                q.pop();
            }
            res.push_back(q.top().first);
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < n; i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i - k) {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};