//https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        nums.push_back(0);
        for(int i=0;i<nums.size();i++){
            while(nums[i] != nums[nums[i]])
            swap(nums[i],nums[nums[i]]);
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i] != i)
            ans.push_back(i);
        }
        return ans;
    }
};