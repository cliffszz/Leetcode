//https://leetcode-cn.com/problems/sort-colors/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[p]);
                p++;
            }
        }
        for (int i = p; i < nums.size(); i++) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p]);
                p++;
            }
        }
    }
};

class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                //把1换走了，要再把1换回来
                if (p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                p0++;
                p1++;
            } else if (nums[i] == 1) {
                swap(nums[i], nums[p1]);
                p1++;
            }
        }
    }
};

class Solution3 {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        for (int i = 0; i <= p2; i++) {
            while (i <= p2 && nums[i] == 2) {
                swap(nums[i], nums[p2]);
                p2--;
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                p0++;
            }
        }
    }
};