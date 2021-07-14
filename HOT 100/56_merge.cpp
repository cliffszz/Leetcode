//https://leetcode-cn.com/problems/merge-intervals/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            int left = intervals[i][0], right = intervals[i][1];
            if (merged.back()[1] < left) {
                merged.push_back({left, right});
            } else {
                merged.back()[1] = max(right, merged.back()[1]);
            }
        }
        return merged;
    }
};