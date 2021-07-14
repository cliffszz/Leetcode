//https://leetcode-cn.com/problems/container-with-most-water/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;
        while (left < right) {
            int water = min(height[left], height[right]) * (right - left);
            maxWater = max(maxWater, water);
            if (height[left] >= height[right]) right--;
            else left++;
        }
        return maxWater;
    }
};