//https://leetcode-cn.com/problems/single-number/
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int n : nums) {
            map[n]++;
        }
        for (auto& n : map) {
            if (n.second == 1) return n.first;
        }
        return 0;
    }
};

//位运算，自己异或自己等于0
class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int n : nums) {
            res ^= n;
        }
        return res;
    }
};