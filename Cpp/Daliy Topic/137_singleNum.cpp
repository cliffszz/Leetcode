//https://leetcode-cn.com/problems/single-number-ii/
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int n : nums) {
            map[n]++;
        }
        for (auto it = map.begin(); it != map.end(); it++) {
            if (it->second != 3) return it->first;
        }
        return 0;
    }
};

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int bit[32] = {0};
        int res;
        for (int n :nums) {
            for (int i = 0; i < 32; i++) {
                if ((n >> i) & 1) bit[i]++;
            }
        }
        for (int i = 0; i < 32; i++) {
            if (bit[i] % 3) res += (1 << i);
        }
        return res;
    }
};