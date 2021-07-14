//https://leetcode-cn.com/problems/subsets-ii/
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> temp;
            bool flag = false;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    if (i > 0 && (mask >>(i - 1) & 1) == 0 && nums[i] == nums[i - 1]) {
                        flag = true;
                        break;
                    }
                    temp.push_back(nums[i]);
                }
            }
            if (!flag) ret.push_back(temp);
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