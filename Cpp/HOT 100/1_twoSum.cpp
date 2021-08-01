//https://leetcode-cn.com/problems/two-sum/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) return {map[target - nums[i]], i};
            //else map[nums[i]] = i;
            else map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};