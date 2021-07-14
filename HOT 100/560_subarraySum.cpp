//https://leetcode-cn.com/problems/subarray-sum-equals-k/
#include <vector>
#include <unordered_map>
using namespace std;

//时间复杂度O(n^2)，不能通过全部测试用例
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j >= 0; j--) {
                sum += nums[j];
                if (sum == k) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        int pre = 0;
        for (int& n : nums) {
            pre += n;
            if (map.find(pre - k) != map.end()) {
                cnt += map[pre - k];
            }
            map[pre]++;
        }
        return cnt;
    }
};