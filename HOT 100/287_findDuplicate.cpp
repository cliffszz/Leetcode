//https://leetcode-cn.com/problems/find-the-duplicate-number/
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int res = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += nums[i] <= mid;
            }
            if (cnt <= mid) {
                left = mid + 1;
            } else  {
                right = mid - 1;
                res = mid;
            }
        }
        return res;
    }
};

class Solution2 {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);
        int finder = 0;
        while (finder != slow) {
            finder = nums[finder];
            slow = nums[slow];
        }
        return finder;
    }
};