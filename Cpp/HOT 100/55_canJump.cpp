//https://leetcode-cn.com/problems/jump-game/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxLen) break;
            maxLen = max(maxLen, i + nums[i]);
            if (maxLen >= (nums.size() - 1)) return true;
        }
        return false;
    }
};