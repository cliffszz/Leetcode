//https://leetcode-cn.com/problems/longest-consecutive-sequence/submissions/
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

//排序时间复杂度O(n^2)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        sort(nums.begin(), nums.end());
        int maxLen = 1;
        int len = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) len++;
            else if (nums[i] == nums[i - 1]) continue;
            else {
                maxLen = max(maxLen, len);
                len = 1;
            }
        }
        maxLen = max(maxLen, len);
        return maxLen;
    }
};

//哈希表时间复杂度O(n)
class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int len = 1;
        int maxLen = 1;
        for (auto n : nums) {
            set.insert(n);
        }
        for (auto s : set) {
            if (set.count(s - 1) == 0) {
                int cur = s;
                int len = 1;
                while (set.count(cur + 1)) {
                    cur++;
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};