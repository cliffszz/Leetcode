//https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/submissions/
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int p = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > arr[p]) p = i;
        }
        return p;
    }
};

class Solution2 {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0; 
        int right = arr.size() - 1;
        int res = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1]) {
                right = mid - 1;
                res = mid;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
};