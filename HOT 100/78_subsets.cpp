//https://leetcode-cn.com/problems/subsets/
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void backTrack(vector<int>& nums, int begin) {
        if (begin == nums.size()) {
            res.push_back(path);
            return;
        }
        //取当前位置的元素
        path.push_back(nums[begin]);
        backTrack(nums, begin + 1);
        path.pop_back();
        //不取当前位置元素，直接进入下一步
        backTrack(nums, begin + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        backTrack(nums, 0);
        return res;
    }
};