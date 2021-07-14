//https://leetcode-cn.com/problems/subsets/
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    temp.push_back(nums[i]);
                }
            }
            ret.push_back(temp);
        }
        return ret;
    }
};

using namespace std;

int main() {
    vector<int> nums = {1,2,2};
    vector<vector<int>> ret = Solution().subsetsWithDup(nums);
    return 0;
}