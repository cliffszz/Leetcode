//https://leetcode-cn.com/problems/product-of-array-except-self/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> front(n, 1);
        vector<int> back(n, 1);
        front[1] = nums[0];
        for (int i = 2; i < n; i++) {
            front[i] = front[i - 1] * nums[i - 1];
        }
        back[n - 2] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            back[i] = back[i + 1] * nums[i + 1];
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = front[i] * back[i];
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        res[1] = nums[0];
        for (int i = 2; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int back = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= back;
            back *= nums[i];
        }
        return res;
    }
};