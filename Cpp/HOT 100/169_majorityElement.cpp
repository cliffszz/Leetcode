//https://leetcode-cn.com/problems/majority-element/
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        for (int n : nums) {
            map[n]++;
        }
        for (auto m : map) {
            if (m.second > (n / 2)) return m.first;
        }
        return -1;
    }
};

//有序数组nums[n/2]一定是众数
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

