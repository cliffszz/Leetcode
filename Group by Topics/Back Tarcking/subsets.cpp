//https://leetcode-cn.com/problems/subsets/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int>& nums, int startIndex) {
        result.push_back(path);
        if(startIndex >= nums.size()) {
            return;
        }
        for(int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        path.clear();
        backTracking(nums, 0);
        return result;
    }
};