//https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
#include <type_traits>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//O(N^2)，暴力法超时
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            int minHeight = heights[i];
            for(int j = i; j < n; j++) {
                minHeight = min(minHeight, heights[j]);
                res = max(res, (j - i + 1)* minHeight);
            }
        }
        return res;
    }
};

class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        vector<int> minLeft(n);
        vector<int> minRight(n);
        minLeft[0] = -1;
        for (int i = 0; i < n; i++) {
            int t = i - 1;
            while (t >= 0 && heights[i] <= heights[t]) {
                t = minLeft[t];
            }
            minLeft[i] = t;
        }
        minRight[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            int t = i + 1;
            while (t < n && heights[i] <= heights[t]) {
                t = minRight[t];
            }
            minRight[i] = t;
        }
        for (int i = 0; i < n; i++) {
            res = max(res, heights[i] * (minRight[i] - minLeft[i] - 1));
        }
        return res;
    }
};

class Solution3 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        for (int i = 0; i < n; i++) {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }
        return res;
    }
};