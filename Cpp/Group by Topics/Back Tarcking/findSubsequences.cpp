//https://leetcode-cn.com/problems/increasing-subsequences/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int>& nums, int startIndex) {
        if(path.size() > 1) {
            result.push_back(path);
        }
        unordered_set<int> uset; // 使用set来对本层元素进行去重
        for (int i = startIndex; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back())
                    || uset.find(nums[i]) != uset.end()) {
                    continue;
            }
        uset.insert(nums[i]); // 记录这个元素在本层用过了，本层后面不能再用了
        path.push_back(nums[i]);
        backTracking(nums, i + 1);
        path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        path.clear();
        backTracking(nums, 0);
        return result; 
    }
};