//https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                left = mid;
                right = mid;
                break;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        while (left >= 0) {
            if (nums[left] != target) {
                left++;
                break;
            } else {
                if (left == 0) break;
                left--;
            }
        }
        while (right < nums.size()) {
            if (nums[right] != target) {
                right--;
                break;
            } else {
                if (right == nums.size() - 1) break;
                right++;
            }
        }
        if (nums[left] == target && nums[right] == target) {
            return {left, right};
        } else return {-1, -1};
    }
};